#ifndef CONTEXT_H
#define CONTEXT_H

#ifdef PERFORMANCE		
#define printf(X)
#else //PERFORMANCE		
#include <stdio.h> 
#endif //PERFORMANCE		

enum State{IDLE, FIRST_CHAR, SECOND_CHAR};

struct Context
{
	enum State state;
};

void init(struct Context* context);

void setState(struct Context* context, enum State state);

void processInput(struct Context* context, char input);

#endif //CONTEXT_H