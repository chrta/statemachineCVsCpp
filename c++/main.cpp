
#ifndef PERFORMANCE	
#include  <StdIO.h>
#include  <Reg167.h>
#endif //PERFORMANCE

#include "context.h"

/**
C++ without new and delete.
hlarge mem model:  Program Size: data=4109(near=4109) const=802(near=0) code=2104
small mem model:   Program Size: data=4103(near=4103) const=764(near=730) code=1672
*/
int main (void)  {

	Context fsm;

#ifndef PERFORMANCE	
	for (;;)
#endif //PERFORMANCE	
	{
#ifndef PERFORMANCE		
		    printf("Enter character:\n");
        char input = getchar();
        printf("Processing character '%c'\n", input);
        fsm.processInput(input);
#else //PERFORMANCE
		char input = 'a';
		fsm.processInput(input);
		input = 'b';
		fsm.processInput(input);
		input = 'a';
		fsm.processInput(input);
		input = 'a';
		fsm.processInput(input);
		input = 'a';
		fsm.processInput(input);
		input = 'c';
		fsm.processInput(input);
#endif //PERFORMANCE		
	}
}

