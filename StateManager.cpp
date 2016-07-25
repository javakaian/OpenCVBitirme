#include "StateManager.h"

StateManager::StateManager()
{
    
}

StateManager::~StateManager()
{
}
void StateManager::render(Batcher *b)
{   
    this->stateStack.top()->render(b);
    
}
void StateManager::update()
{
    this->stateStack.top()->update();
}
void StateManager::loadState(State *state)
{
    this->stateStack.push(state);
}
State* StateManager::getState()
{
    return stateStack.top();
}
void StateManager::popState()
{
    this->stateStack.pop();
}