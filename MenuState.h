#pragma once
#include "State.h"
#include "Screen.h"
class StateManager ;
class MenuState:public State
{
public:
    MenuState(StateManager *sm,Screen *screen);
    ~MenuState();
    
    void render(Batcher *b);
    void update();
private:
    StateManager *sm;
    Screen *screen;
};

