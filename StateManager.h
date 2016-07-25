#pragma once
#include <iostream>
#include <stack>
#include "State.h"
class StateManager
{
public:
    StateManager();
    void render(Batcher *b);
    void update();
    ~StateManager();
    void loadState(State *state);
    State* getState();
    void popState();
private:

    std::stack<State*> stateStack;
    
};

