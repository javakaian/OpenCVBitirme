#include "KeyBoardCallBack.h"
#include "KeyBoard.h"


KeyBoardCallBack::KeyBoardCallBack()
{
}


KeyBoardCallBack::~KeyBoardCallBack()
{
}

void KeyBoardCallBack::key_CallBack(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{

		KeyBoard::UP = true;
		

	}
	if (key == GLFW_KEY_W && action == GLFW_RELEASE)
	{

		KeyBoard::UP = false;

	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		

		KeyBoard::DOWN = true;

	}
	if (key == GLFW_KEY_S && action == GLFW_RELEASE)
	{

		KeyBoard::DOWN = false;
		KeyBoard::runOnce = true;

	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{

		KeyBoard::LEFT = true;
		

	}
	if (key == GLFW_KEY_A && action == GLFW_RELEASE)
	{

		KeyBoard::LEFT = false;
		KeyBoard::runOnce = true;

	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{

		KeyBoard::RIGHT = true;

	}
	if (key == GLFW_KEY_D && action == GLFW_RELEASE)
	{

		KeyBoard::RIGHT = false;
		KeyBoard::runOnce = true;
	}
    
    
    if(key == GLFW_KEY_SPACE && action==GLFW_PRESS)
    {
        KeyBoard::SPACE=true;
    }
    if(key == GLFW_KEY_SPACE && action==GLFW_RELEASE)
    {
        KeyBoard::SPACE=false;
        KeyBoard::runOnce = true;
    }
    
   
}