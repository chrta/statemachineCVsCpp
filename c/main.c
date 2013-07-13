#include <stdio.h>                /* standard I/O .h-file              */
#include <reg167.h>               /* special function register 80C167  */

#include "context.h"

/**
 * Simpe state machine in c (quick and dirty)
 * small mem modell         Program Size: data=4097(near=4097) const=642(near=634) code=1502
 * huge (HLarge) mem modell Program Size: data=4097(near=4097) const=644(near=0) code=1704
 */
void main (void)  {               /* execution starts here               */
                                  /* initialize the serial interface     */
#ifndef MCB167          /* do not initialize if you use Monitor-166      */  
  P3  |= 0x0400;        /* SET PORT 3.10 OUTPUT LATCH (TXD)              */
  DP3 |= 0x0400;        /* SET PORT 3.10 DIRECTION CONTROL (TXD OUTPUT)  */
  DP3 &= 0xF7FF;        /* RESET PORT 3.11 DIRECTION CONTROL (RXD INPUT) */
  S0TIC = 0x80;         /* SET TRANSMIT INTERRUPT FLAG                   */
  S0RIC = 0x00;         /* DELETE RECEIVE INTERRUPT FLAG                 */
  S0BG  = 0x40;         /* SET BAUDRATE TO 9600 BAUD                     */
  S0CON = 0x8011;       /* SET SERIAL MODE                               */
#endif
#ifndef PERFORMANCE		
	for (;;)
#endif //PERFORMANCE			
  {
		struct Context fsm;
		char input;
		init(&fsm);
#ifndef PERFORMANCE				
		printf("Enter character:\n");
    input = getchar();
    printf("Processing character '%c'\n", input);
    processInput(&fsm, input);
#else //PERFORMANCE
		input = 'a';
		processInput(&fsm, input);
		input = 'b';
		processInput(&fsm, input);
		input = 'a';
		processInput(&fsm, input);
		input = 'a';
		processInput(&fsm, input);
		input = 'a';
		processInput(&fsm, input);
		input = 'c';
		processInput(&fsm, input);
#endif //PERFORMANCE		
  }
}
