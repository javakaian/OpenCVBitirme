#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <thread>
#include "KeyBoard.h"

bool FileSystem::dontMove=false;
bool FileSystem::left=false;
bool FileSystem::right=false;
bool FileSystem::runOnce=true;

void FileSystem::writeToFile()
{
     while(true)
        {

       //std::ofstream myfile;
       //myfile.open ("example.txt");
       //myfile << "Writing this to a file.\n";
       //myfile.close();
    
       //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
       
            
        }
    
    
    
     
    
}
void FileSystem::readFromFile()
{
     
    std::string line;
    while(true)
        {
            std::ifstream myfile ("/root/Documents/input.txt");
            line="zero";
            runOnce=true;
            if (myfile.is_open())
              {
                while ( getline (myfile,line) )
                {
                  std::cout << line << '\n';
                  
                  if(line=="1")
                    {
                        left=true;
                        right=false;
                        dontMove=false;
                    }
                     if(line=="2")
                    {
                        left=false;
                        right=true;
                        dontMove=false;
                    }
                     if(line=="0")
                    {
                        left=false;
                        right=false;
                        dontMove=true;
                    }
                    
                }
               myfile.close();
              }
              
              else std::cout << "Unable to open file"<<std::endl;
              
              std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
}
