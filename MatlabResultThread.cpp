#include "MatlabResultThread.h"
#include <iostream>
#include <thread>
MatlabResultThread::MatlabResultThread()
{
}

MatlabResultThread::~MatlabResultThread()
{
}

void MatlabResultThread::callExecutableAndGetData()
{
    while(true)
        {

        std::cout<<"matlab thread cagrildi.."<<std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
       // system("/home/javakaian/Masaüstü/Toplama");
            
        }
}
