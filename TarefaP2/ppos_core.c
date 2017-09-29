#include "ppos.h"
#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>

#define STACKSIZE 32000		/* tamanho de pilha das threads */
//#define DEBUG true

int ida = 0;	//vai somando pra cada tarefa ter id diferente
task_t main_tsk;	// main task
task_t *current_tsk; // task sendo executada no momento

// Inicializa o sistema operacional; deve ser chamada no inicio do main()
void ppos_init ()
{
    main_tsk.id = ida;	//comeca com id 0
		
	  ida++;
    current_tsk = &main_tsk;
		//get_context_asm(&main_tsk.context);
		makecontextMain (&main_tsk.context, (int)(*ppos_init), 1, "        teste");
		
	

    setvbuf (stdout, 0, _IONBF, 0) ;

    printf("inicializando main com id %d \n", (&main_tsk)->id);

}

// Cria uma nova tarefa. Retorna um ID> 0 ou erro.
int task_create (task_t *task,			// descritor da nova tarefa
                 void (*start_routine)(void *),	// funcao corpo da tarefa
                 void *arg)			// argumentos para a tarefa
{

   
        get_context_asm (&(task->context));	//pega contexto atual

        char *stack = malloc (STACKSIZE);
        //fazendo o contexto
        if (stack) {
            task->context.uc_stack.ss_sp = stack;
            task->context.uc_stack.ss_size = STACKSIZE;
            task->context.uc_stack.ss_flags = 0;
            task->context.uc_link = 0;
            task->id = ida++;
        } else {
            perror ("stack nao pode ser criado ");
            return -1;
        }
    

    //liga a funcao a este contexto
    makecontext (&task->context, (int)(*start_routine), 1, arg);

    printf("task_create: criou a tarefa %d\n", task->id);


    return task->id;
}

// alterna a execução para a tarefa indicada
int task_switch (task_t *task)
{	
			task_t *aux;
			aux = current_tsk;
			current_tsk = task;
			if(swap_context_asm(&aux->context,&task->context) < 0){
				current_tsk = aux;
				return -1;
			
			}
				
			return 0;
}

// Termina a tarefa corrente, indicando um valor de status encerramento
void task_exit (int exitCode)
{
    task_switch(&main_tsk);
}

// retorna o identificador da tarefa corrente (main eh 0)
int task_id ()
{
   return current_tsk->id;
}
























