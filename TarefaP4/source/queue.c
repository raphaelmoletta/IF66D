#include "queue.h"
#include "ucontext.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila

void queue_append(task_t **queue, task_t *elem) {
	if (elem != 0 && elem->next == 0 && elem->prev == 0) {
		if (queue[0] == 0) {
			queue[0] = elem;
			queue[0]->prev = elem;
			queue[0]->next = elem;
		} else {
			elem->next = queue[0];
			elem->prev = queue[0]->prev;
			queue[0]->prev->next = elem;
			queue[0]->prev = elem;
		}
	}
}

//------------------------------------------------------------------------------
// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: apontador para o elemento removido, ou NULL se erro

task_t *queue_remove(task_t **queue, task_t *elem) {

// "*queue" aponta para o queue[0], alterando o conteudo aqui, altera-se quem é queue[0]
	if (elem == NULL)
		return NULL;

	if (queue == NULL)/*testes de entrada*/
		return NULL;

	task_t *curr;
	curr = queue[0];

	while (curr != elem) { /*verificar se o elemento está no vetor*/
		curr = curr->next;
		if (curr == elem)
			break;
		if (curr == queue[0])
			return NULL;

	}

	if (elem->next == *queue && elem == *queue) { /*verifica se o elemento é o primeiro e unico na*/
		*queue = NULL; /*fila*/
		elem->next = NULL;
		elem->prev = NULL;

		return elem;

	} else if (elem == *queue) { /*se é o primeiro e não unico*/

		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		*queue = elem->next;

		elem->next = NULL;
		elem->prev = NULL;

		return elem;

	} else { /*se não é o primeiro*/
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
		elem->next = NULL;
		elem->prev = NULL;

		return elem;

	}
}

//------------------------------------------------------------------------------
// Conta o numero de elementos na fila
// Retorno: numero de elementos na fila

int queue_size(task_t *queue) {
	if (queue == NULL)
		return 0;

	int i = 1;
	task_t *q = queue->next;
	while (q != queue) {
		i++;
		q = q->next;
	};
	return i;
}

//------------------------------------------------------------------------------
// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca.
//
// Essa função deve ter o seguinte protótipo:
//
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir

void queue_print(char *name, task_t *queue, void print_elem(void*)) {
	/*printa "[", se o vetor não for nulo, print_elem até que complete-se o ciclo (a lista é fechada)*/
	printf("[");

	if (queue == NULL) {
		printf("]");
	} else {
		task_t *q = queue;
		do {
			print_elem(q);
			q = q->next;
		} while (q != queue);
		printf("]");

	}
}
