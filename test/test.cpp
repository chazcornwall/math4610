#include "../include/math4610lib.hpp"
#include <iostream>

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return sin(input);};
        double getDerivOutput(double input) const {return cos(input);};
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
    std::cout << "Call newtonsMethod on sin(x)!" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::newtonsMethod(function, x0, 0.01, 1000, true) << std::endl;
    std::cout << "Call secantMethod on sin(x)!" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::secantMethod(function, x0, 0.01, 1000, true) << std::endl;
    std::cout << "Call Hybrid Method on sin(x)!" << std::endl;
    leftbound = -5.0;
    rightbound = 10.0;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "leftbound: " << leftbound << std::endl;
    std::cout << "rightbound: " << rightbound << std::endl;
    std::cout << "Root: " << Rootfinding::hybridMethod(function, x0, 0.01, leftbound, rightbound) << std::endl;

    // Test Regression namespace from library
    std::cout << "**************************************" << std::endl;
    std::cout << "Test Regression namespace from library" << std::endl;
    std::cout << "**************************************" << std::endl;
    double inputs[5] = {1, 2, 3, 4, 5};
    double y[5] = {23, 22, 23, 24, 25};
    double x[2]; // x[0] is the constant term and x[1] is the rate (y = x[0] + x[1] * input)

    std::cout << "Call linreg()!" << std::endl;
    std::cout << "Inputs: ";
    for(int i = 0; i < 5; i++)
    {
        std::cout << inputs[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Outputs: ";
    for(int i = 0; i < 5; i++)
    {
        std::cout << y[i] << " ";
    }
    std::cout << std::endl;

    Regression::linreg(inputs, x, y, 5);
    std::cout << "Trend: y = " << x[1] << "x + " << x[0] << std::endl;
}