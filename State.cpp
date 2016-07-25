#include "State.h"
#include <iostream>
State::State()
{
}

State::~State()
{
}

void State::render(Batcher *b)
{
    std::cout<<"State is rendering.."<<std::endl;
}
void State::update()
{
    std::cout<<"State is updating.."<<std::endl;
}
