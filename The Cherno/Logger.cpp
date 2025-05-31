#include <iostream>
#include "Log.h"

void InitLog ()
{
    std::cout << "Initalizing Log" << std::endl;
}
void Log (const char* msg)
{
    std::cout << msg << std::endl;
}
void TerminateLog ()
{
    std::cout << "Terminating Log" << std::endl;
}
