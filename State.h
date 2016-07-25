#pragma once
#include "Batcher.h"

class State
{
public:
    State();
    ~State();
    virtual void render(Batcher *b);
    virtual void update();
   
    
    
};
