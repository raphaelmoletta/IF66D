#include "ppos.h"
#include <stdlib.h>
#include <stdio.h>
#include "ucontext.h"
#include "queue.h"

#define STACKSIZE 2048		/* tamanho de pilha das threads */
#define DEBUG true

int ida = 0;	//vai somando pra cada tarefa ter id diferente
int userTasks = -1;
task_t ** tasks = 0;

int flag;
int memPC = 0;

task_t next;
task_t main_tsk;	// main task
task_t *current_tsk; // task sendo executada no momento
task_t dispacher_tsk;

// Inicializa o sistema operacional; deve ser chamada no inicio do main()
void ppos_init() {
	main_tsk.id = ida;	//comeca com id 0
	ida++;

	task_create(&dispacher_tsk, dispatcher_body,"");

	current_tsk = &main_tsk;
	//get_context_asm(&main_tsk.context);
	makecontext(&main_tsk.context, (int) (*ppos_init), 1, "        Dispacher");

	setvbuf(stdout, 0, _IONBF, 0);

	printf("inicializando main com id %d \n", (&main_tsk)->id);

}

// Cria uma nova tarefa. Retorna um ID> 0 ou erro.
int task_create(task_t *task,			// descritor da nova tarefa
		void (*start_routine)(void *),	// funcao corpo da tarefa
		void *arg)			// argumentos para a tarefa
{
	task_t *stack = malloc(STACKSIZE);
	queue_append(&stack, task);
	userTasks++;
	getcontext(&(task->context));	//pega contexto atual


	//fazendo o contexto
	if (stack) {
		task->context.uc_stack.ss_sp = stack;
		task->context.uc_stack.ss_size = STACKSIZE;
		task->context.uc_stack.ss_flags = 0;
		task->context.uc_link = 0;
		task->id = ida++;
		task->priority = 0;
	} else {
		perror("stack nao pode ser criado ");
		return -1;
	}

	//liga a funcao a este contexto
	makecontext(&task->context, (int) (*start_routine), 1, arg);

	printf("task_create: criou a tarefa %d\n", task->id);

	return task->id;
}

// alterna a execução para a tarefa indicada
int task_switch(task_t *task) {
	task_t *aux;
	aux = current_tsk;
	current_tsk = task;
	if (swapcontext(&aux->context, &task->context) < 0) {
		current_tsk = aux;
		return -1;

	}

	return 0;
}

// Termina a tarefa corrente, indicando um valor de status encerramento
void task_exit(int exitCode) {
	if (current_tsk->id == dispacher_tsk.id) {
		task_switch(&main_tsk);
	} else {
		userTasks--;
		queue_remove(tasks, current_tsk);
		task_switch(&dispacher_tsk);
	}

}

// retorna o identificador da tarefa corrente (main eh 0)
int task_id(void) {
	return current_tsk->id;
}

void task_yield(void) {
	task_switch(&dispacher_tsk);
}

// define a prioridade estática de uma tarefa (ou a tarefa atual)
void task_setprio(task_t *task, int prio) {
	task->priority = prio;
}

// retorna a prioridade estática de uma tarefa (ou a tarefa atual)
int task_getprio(task_t *task) {
	if (task == NULL) {
		return current_tsk->priority;
	}
	return task->priority;
}

task_t * scheduler(void) {
	task_t t = **tasks;
	next = **tasks;
	int min = 20;
	for(int i = 0; i < queue_size(*tasks); i++) {
		if((t.priority + t.priorityagin) < min) {
			next = t;
			min = t.priority + t.priorityagin;
		}
		t.priorityagin--;
	}
	return &next;
}

void dispatcher_body(void * arg) // dispatcher é uma tarefa
{
	task_t * next;
	while (userTasks > 0) {
		next = scheduler();  // scheduler é uma função
		if (next) {
			// ações antes de lançar a tarefa "next", se houverem
			task_switch(next); // transfere controle para a tarefa "next"
			// ações após retornar da tarefa "next", se houverem
		}
	}
	task_exit(0); // encerra a tarefa dispatcher
}
