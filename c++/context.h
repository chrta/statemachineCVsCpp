#ifndef CONTEXT_H
#define CONTEXT_H

#ifdef PERFORMANCE              
#define printf(X)
#endif //PERFORMANCE 

class Context
{
private:
    class State
    {
    public:
        virtual void processInput(char input, Context* context) const = 0;

        virtual void onEnter(Context* context) const = 0;

        virtual void onLeave(Context* context) const = 0;
    };

    class IdleState : public State
    {
    public:
        virtual void processInput(char input, Context* context) const;
        virtual void onEnter(Context* context) const;
        virtual void onLeave(Context* context) const;
    };


    class FirstCharState : public State
    {
    public:
        virtual void processInput(char input, Context* context) const;
        virtual void onEnter(Context* context) const;
        virtual void onLeave(Context* context) const;
    };

    class SecondCharState : public State
    {
    public:
        virtual void processInput(char input, Context* context) const;
        virtual void onEnter(Context* context) const;
        virtual void onLeave(Context* context) const;
    };

public:
    Context();

    void processInput(char input);

    void setState(const State* state);

    static const IdleState idleState;
    static const FirstCharState firstCharState;
    static const SecondCharState secondCharState;

private:
    const State* m_state;
};

#endif // CONTEXT_H
