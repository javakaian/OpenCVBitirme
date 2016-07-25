#include "PlayingState.h"
#include <iostream>
#include "KeyBoard.h"
#include "MenuState.h"
PlayingState::PlayingState(Screen *screen,StateManager *sm)
{
    
    this->screen=screen;
    this->sm = sm;
    
}

PlayingState::~PlayingState()
{
}
void PlayingState::render(Batcher *b)
{
    screen->render(b);
}
void PlayingState::update()
{
    
    if(KeyBoard::SPACE && KeyBoard::runOnce)
    {
        MenuState *menu = new MenuState(this->sm,screen);
        this->sm->loadState(menu);
        
        KeyBoard::runOnce=false;
    }
}
