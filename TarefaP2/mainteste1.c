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

task_t Ping, Pong ;
//static int i = 0;
void BodyPing1 (void * arg)
{
   int i ;
   char* name = (char *) arg ;

   printf ("%s: inicio\n", name) ;
   for (i=0; i<4; i++)
   {
      printf ("%s: %d\n", name, i) ;
      task_switch (&Pong);
   }
   printf ("%s: fim\n", name) ;
   task_exit (0) ;
}

// corpo da thread Pong
void BodyPong1 (void * arg)
{
   int i ;
   char* name = (char *) arg ;

   printf ("%s: inicio\n", name) ;
   for (i=0; i<4; i++)
   {
      printf ("%s: %d\n", name, i) ;
      task_switch (&Ping);
   }
   printf ("%s: fim\n", name) ;
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
   	printf("UART inacializada !\n\n\n");
		ppos_init();

		assert(1);
   	printf("welcome to FRDM-64F !\n");	
	
	  printf ("main: inicio\n");

   ppos_init () ;

   task_create (&Ping, BodyPing1, "    Ping") ;
   task_create (&Pong, BodyPong1, "        Pong") ;

   task_switch (&Ping) ;
   task_switch (&Pong) ;

   printf ("main: fim\n");

   exit (0);

	exit(0);
//		assert(0);
   	printf("welcome to FRDM-64F !\n");	
    return 0;
}

//uint8_t uart_getchar ()
//{
///* Wait until character has been received */
//while (!(UART0_S1 & UART_S1_RDRF_MASK));
///* Return the 8-bit data from the receiver */
//return UART0_D;
//}

//void uart_putchar (char ch)
//{
///* Wait until space is available in the FIFO */
//while(!(UART0_S1 & UART_S1_TDRE_MASK));
///* Send the character */
//UART0_D = (uint8_t)ch;
//}

//void put(char *ptr_str)
//{
//	while(*ptr_str)
//		uart_putchar(*ptr_str++);
//}
