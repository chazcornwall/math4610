#include "../include/math4610lib.hpp"
#include <iostream>

using namespace MachineEpsilon;

int main(void)
{
    std::cout << "Call seps!" << std::endl;
    seps();
    std::cout << "Call deps!" << std::endl;
    deps();
}