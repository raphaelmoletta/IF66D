/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "MK64F12.h"
#include "stdio.h"
#include "stdlib.h"
#include <UART.h>

#include <assert.h>
#include <ppos.h>
#define MAXTASK 5

task_t task[MAXTASK+1] ;


void BodyTask (void * arg)
{
  int next ;

   printf ("Iniciei  tarefa %5d\n", task_id()) ;

   // passa o controle para a proxima tarefa
   next = (task_id() < MAXTASK) ? task_id() + 1 : 1 ;
   task_switch (&task[next]);

   printf ("Encerrei tarefa %5d\n", task_id()) ;

   task_exit (0) ;
}



void HardFault_Handler(void)
{ 
   printf("HardFault_Handler \n");	
  while(1);  
}

LDD_TDeviceData *PE_LDD_DeviceDataList[1] = {
    NULL  };

//uint8_t uart_getchar ();
//void put(char *ptr_str);
//void uart_putchar (char ch);

int main(void)
{
//		assert(0);

    /* Write your code here */
    (void)IO1_Init(NULL);
   	printf("UART inicializada !\n\n\n");
		ppos_init();
	int i;
		assert(1);

	

   // cria MAXTASK tarefas
   for (i=1; i<=MAXTASK; i++)
      task_create (&task[i], BodyTask, NULL) ;

   // passa o controle para cada uma delas em sequencia
   for (i=1; i<=MAXTASK; i++)
      task_switch (&task[i]) ;

   printf ("main: fimteste2\n");

//		assert(0);
   	printf("fimgeral!\n");	
    return 0;
}

