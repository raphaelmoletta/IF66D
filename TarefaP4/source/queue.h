// PingPongOS - PingPong Operating System
// Prof. Carlos A. Maziero, DINF UFPR
// Versão 1.0 -- Março de 2015

// Definição e operações em uma fila genérica.
#include"ucontext.h"

#ifndef __QUEUE__
#define __QUEUE__

#ifndef NULL
#define NULL ((void *) 0)
#endif


// Estrutura que define um Task Control Block (TCB)
typedef struct task_t {
	struct task_t *prev, *next; // ponteiros para usar em filas
	int id;             		// identificador da tarefa
	ucontext_t context;         // contexto armazenado da tarefa
	void *stack;                // aponta para a pilha da tarefa
	int priority;			    // prioridade da tarefa
	int priorityagin;
	// ... (outros campos serão adicionados mais tarde)
} task_t;

//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila

void queue_append (task_t **queue, task_t *elem) ;

//------------------------------------------------------------------------------
// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: apontador para o elemento removido, ou NULL se erro

task_t *queue_remove (task_t **queue, task_t *elem) ;

//------------------------------------------------------------------------------
// Conta o numero de elementos na fila
// Retorno: numero de elementos na fila

int queue_size (task_t *queue) ;

//------------------------------------------------------------------------------
// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca.
//
// Essa função deve ter o seguinte protótipo:
//
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir

void queue_print (char *name, task_t *queue, void print_elem (void*) ) ;

#endif
