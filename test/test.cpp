#include "../include/math4610lib.hpp"
#include <iostream>

int main(void)
{
    // Test MachineEpsilon namespace from library
    std::cout << "**************************************" << std::endl;
    std::cout << "Test MachineEpsilon namespace from libaray" << std::endl;
    std::cout << "**************************************" << std::endl;
    std::cout << "Call seps!" << std::endl;
    MachineEpsilon::seps();
    std::cout << "Call deps!" << std::endl;
    MachineEpsilon::deps();

    std::cout << std::endl;

    // Test Error namespace from library
    std::cout << "**************************************" << std::endl;
    std::cout << "Test Error namespace from libaray" << std::endl;
    std::cout << "**************************************" << std::endl;
    double approx = 53;
    double num = 67.34;
    std::cout << "Call abserror!" << std::endl;
    std::cout << "Approx: " << num << std::endl;
    std::cout << "Num: " << approx << std::endl;
    std::cout << "Error: " << Error::abserror(approx, num) << std::endl;
    std::cout << "Call relerror!" << std::endl;
    std::cout << "Approx: " << num << std::endl;
    std::cout << "Num: " << approx << std::endl;
    std::cout << "Error: " << Error::relerror(approx, num) << std::endl;
}