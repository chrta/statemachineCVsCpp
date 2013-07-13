#include "context.h"

void onEnter(enum State state)
{
	switch (state)
	{
		case IDLE: printf("Entering state IdleState\n"); break;
		case FIRST_CHAR: printf("Entering state FirstCharState\n"); break;
		case SECOND_CHAR: printf("Entering state SecondCharState\n"); break;
	}
}

void onLeave(enum State state)
{
	switch (state)
	{
		case IDLE: printf("Leaving state IdleState\n"); break;
		case FIRST_CHAR: printf("Leaving state FirstCharState\n"); break;
		case SECOND_CHAR: printf("Leaving state SecondCharState\n"); break;
	}
}


void init(struct Context* context)
{
	context->state = IDLE;
}

void setState(struct Context* context, enum State state)
{
	if (state != context->state)
	{
		onLeave(context->state);
		context->state = state;
		onEnter(context->state);
	}
}

void processInput(struct Context* context, char input)
{
	switch (context->state)
	{
		case IDLE:
			if (input != 'a')
			{
					printf("Got no 'a' in IdleState::processInput, keeping state\n");
					return;
			}

			printf("Got 'a' in IdleState::processInput, going to first char\n");
			setState(context, FIRST_CHAR);
			break;
		case FIRST_CHAR:
			if (input != 'a')
			{
					printf("Got no 'a' in FirstCharState::processInput, going to idle\n");
					setState(context, IDLE);
					return;
			}
			printf("Got 'a' in FirstCharState::processInput, going to second char\n");
			setState(context, SECOND_CHAR);
			break;
		case SECOND_CHAR:
			if (input != 'a')
			{
					 printf("Got no 'a' in SecondCharState::processInput, going to idle\n");
			}
			else
			{
					printf("Got 'a' in SecondCharState::processInput, going to idle\n");
			}
			setState(context, IDLE);
			break;
		default:
			setState(context, IDLE);
	}
}