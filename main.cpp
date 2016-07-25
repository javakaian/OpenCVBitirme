#include <GLFW/glfw3.h>
#include <iostream>
#include "Screen.h"
#include "KeyBoardCallBack.h"
#include <exception>
#include <thread>
#include "Camera.h"
#include <opencv2/opencv.hpp>
#include "MatlabResultThread.h"
#include "StateManager.h"
#include "PlayingState.h"
#include "MenuState.h"
#include "FileSystem.h"
int main() 
{
	
	
    std::thread fileThread(FileSystem::readFromFile);
	std::thread kameraThread(Camera::loadCameraData);
    //std::thread matlabThread(MatlabResultThread::callExecutableAndGetData);
	int width = 400;
	int height = 800;
	Screen  *myScreen = new Screen(width,height);
	Batcher *batcher = new Batcher();
	GLFWwindow *window;
    StateManager *stateManager = new StateManager();
    //PlayingState *playingState = new PlayingState(myScreen,stateManager);
    //stateManager->loadState(playingState);
	MenuState *menuState = new MenuState(stateManager,myScreen);
    stateManager->loadState(menuState);
    if (!glfwInit()) 
	{
		return -1;
	}
	window = glfwCreateWindow(width,height, "Tetris Game",NULL,NULL);
	glfwSetWindowPos(window,1700,100);
	
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window,KeyBoardCallBack::key_CallBack);
	/* Loop until the user closes the window */


	
	while (!glfwWindowShouldClose(window))
	{
        
        
        
        
        
		/* Render here */
		glfwGetFramebufferSize(window,&width,&height);
        //myScreen->render(batcher);
        stateManager->render(batcher);
        stateManager->update();
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}
	delete myScreen;
	glfwTerminate();
    
    try
    {
        // do stuff
    }
    catch (std::exception const &exc)
    {
        std::cerr << "Exception caught " << exc.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught\n";
    }
	
	
	kameraThread.join();
    fileThread.join();
    // matlabThread.join();
	system("PAUSE");
	return 0;
}