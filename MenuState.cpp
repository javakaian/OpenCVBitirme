#include "MenuState.h"
#include <iostream>
#include "GLFW/glfw3.h"
#include "KeyBoard.h"
#include "PlayingState.h"
#include "Screen.h"
#include <fstream>
MenuState::MenuState(StateManager *sm,Screen *screen)
{
    this->sm=sm;
    this->screen=screen;
}

void MenuState::render(Batcher *b)
{
    glViewport(0, 0, 400,800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 400,800, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1);
}
void MenuState::update()
{
    if(KeyBoard::SPACE ==true && KeyBoard::runOnce)
    {
        std::cout<<"MenuState"<<std::endl;
       //sm->popState();
        PlayingState *pState = new PlayingState(screen,sm);
       sm->loadState(pState);

       KeyBoard::runOnce=false;




    }
    
    std::string line;
       std::ifstream myfile2 ("/root/Documents/input2.txt");
              if (myfile2.is_open())
              {
                while ( getline (myfile2,line) )
                {


                  if(line=="1")
                    {
                         PlayingState *pState = new PlayingState(screen,sm);
                        sm->loadState(pState);
                    }



                }
               myfile2.close();
              }


}

MenuState::~MenuState()
{
    
}
