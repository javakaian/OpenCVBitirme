#pragma once
#include "State.h"
#include "Screen.h"
#include "StateManager.h"
class PlayingState:public State
{
public:
    PlayingState(Screen *screen,StateManager *sm);
    ~PlayingState();
    void render(Batcher *b);
    void update();
private:
    Screen *screen;
    StateManager *sm ;
};

