#include "../include/math4610lib.hpp"
#include <iostream>

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return sin(input);};
};

int main(void)
{
    // Test MachineEpsilon namespace from library
    std::cout << "**************************************" << std::endl;
    std::cout << "Test MachineEpsilon namespace from library" << std::endl;
    std::cout << "**************************************" << std::endl;
    std::cout << "Call seps!" << std::endl;
    MachineEpsilon::seps();
    std::cout << "Call deps!" << std::endl;
    MachineEpsilon::deps();

    std::cout << std::endl;

    // Test Error namespace from library
    std::cout << "**************************************" << std::endl;
    std::cout << "Test Error namespace from library" << std::endl;
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

    std::cout << std::endl;

    // Test Rootfinding namespace from library
    std::cout << "**************************************" << std::endl;
    std::cout << "Test Rootfinding namespace from library" << std::endl;
    std::cout << "**************************************" << std::endl;
    NewFunction function = NewFunction();
    double x0 = 5;
    std::cout << "Call fixedPoint on sin(x)!" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::fixedPoint(function, x0, 0.001, 1.0, 100) << std::endl;
    double leftbound = 0.0;
    double rightbound = 10.0;
    std::cout << "Call Bisection on sin(x)!" << std::endl;
    std::cout << "leftbound: " << leftbound << std::endl;
    std::cout << "rightbound: " << rightbound << std::endl;
    std::cout << "Root: " << Rootfinding::bisection(function, 1000, leftbound, rightbound) << std::endl;
}