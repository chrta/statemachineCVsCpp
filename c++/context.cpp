#include "context.h"

//#include  <StdIO.h>

const Context::IdleState Context::idleState;
const Context::FirstCharState Context::firstCharState;
const Context::SecondCharState Context::secondCharState;

Context::Context()
: m_state(&idleState)
{
    m_state->onEnter(this);
}

void Context::processInput(char input)
{
    m_state->processInput(input, this);
}

void Context::setState(const State* state)
{
    if (m_state != state)
    {
        m_state->onLeave(this);
        m_state = state;
        m_state->onEnter(this);
    }
}

void Context::IdleState::processInput(char input, Context* context) const
{
    if (input != 'a')
    {
        printf("Got no 'a' in IdleState::processInput, keeping state\n");
        return;
    }

    printf("Got 'a' in IdleState::processInput, going to first char\n");
    context->setState(&Context::firstCharState);
}

void Context::IdleState::onEnter(Context* context) const
{
    printf("Entering state IdleState\n");
}

void Context::IdleState::onLeave(Context* context) const
{
    printf("Leaving state IdleState\n");
}

void Context::FirstCharState::processInput(char input, Context *context) const
{
    if (input != 'a')
    {
        printf("Got no 'a' in FirstCharState::processInput, going to idle\n");
        context->setState(&Context::idleState);
        return;
    }
    printf("Got 'a' in FirstCharState::processInput, going to second char\n");
    context->setState(&Context::secondCharState);
}

void Context::FirstCharState::onEnter(Context* context) const
{
    printf("Entering state FirstCharState\n");
}

void Context::FirstCharState::onLeave(Context* context) const
{
    printf("Leaving state FirstCharState\n");
}

void Context::SecondCharState::processInput(char input, Context *context) const
{
    if (input != 'a')
    {
         printf("Got no 'a' in SecondCharState::processInput, going to idle\n");
    }
    else
    {
        printf("Got 'a' in SecondCharState::processInput, going to idle\n");
    }
    context->setState(&Context::idleState);
}

void Context::SecondCharState::onEnter(Context* context) const
{
    printf("Entering state SecondCharState\n");
}

void Context::SecondCharState::onLeave(Context* context) const
{
    printf("Leaving state SecondCharState\n");
}

