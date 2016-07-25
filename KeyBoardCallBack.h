#pragma once
#include <GLFW/glfw3.h>
class KeyBoardCallBack
{
public:
	KeyBoardCallBack();
	~KeyBoardCallBack();
	static void key_CallBack(GLFWwindow * window,int key,int scancode ,int action, int mods);
	
};

