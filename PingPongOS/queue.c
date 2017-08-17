#include"queue.h"
#include<stdio.h>

//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila

void queue_append (queue_t **queue, queue_t *elem)
{
    if(elem != NULL && elem->next == NULL && elem->prev == NULL)
    {
        if (queue[0] == NULL)
        {
            queue[0] = elem;
            queue[0]->prev = elem;
            queue[0]->next = elem;
        } 
        else
        {
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

queue_t *queue_remove (queue_t **queue, queue_t *elem)
{
    
}

//------------------------------------------------------------------------------
// Conta o numero de elementos na fila
// Retorno: numero de elementos na fila

int queue_size (queue_t *queue)
{
    if(queue == NULL)
        return 0;
    int i = 1;
    queue_t *q = queue->next;
    while(q != queue)
    {
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

void queue_print (char *name, queue_t *queue, void print_elem (void*) )
{
    if(queue == NULL)
        return;
    queue_t *q = queue;
    do
    {
        print_elem(name);
        q = queue->next;
    }
    while(q != queue);
}