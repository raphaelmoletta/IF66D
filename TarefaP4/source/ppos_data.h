// PingPongOS - PingPong Operating System
// Prof. Carlos A. Maziero, DINF UFPR
// Versão 1.1 -- Julho de 2016

// Estruturas de dados internas do sistema operacional

#ifndef __PPOS_DATA__
#define __PPOS_DATA__

#include "ucontext.h"       // biblioteca POSIX de trocas de contexto
#include "queue.h"      	// biblioteca de filas genéricas

// estrutura que define um semáforo
typedef struct {
	// preencher quando necessário
} semaphore_t;

// estrutura que define um mutex
typedef struct {
	// preencher quando necessário
} mutex_t;

// estrutura que define uma barreira
typedef struct {
	// preencher quando necessário
} barrier_t;

// estrutura que define uma fila de mensagens
typedef struct {
	// preencher quando necessário
} mqueue_t;

#endif
