#include "../../include/math4610lib.hpp"
#include <iostream>

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return exp(-(input * input)) * sin(4.0 * input * input - 1.0) + 0.051;};
        double getDerivOutput(double input) const {return 8.0 * input * exp(-(input * input)) * cos(4.0 * input * input - 1.0) - 2.0 * input * exp(-(input * input)) * sin(4.0 * input * input - 1.0);};
};

int main()
{
    NewFunction function = NewFunction();

    /*********************************/
    // Task 1: Try all four methods for finding roots
    /*********************************/
    std::cout << "TASK 1" << std::endl;
    double fixedPointRoot = Rootfinding::fixedPoint(function, 0.5, 0.01, 1.0, 10000 );
    double bisectionRoot = Rootfinding::bisection(function, 10000, -1.0, 2.0);
    double newtonRoot = Rootfinding::newtonsMethod(function, 0.2, 0.01, 1000, false);
    double secantRoot = Rootfinding::secantMethod(function, 0.2, 0.01, 1000, false);

    // Root should be + or - 0.4836
    std::cout << "Fixed Point Root: " << fixedPointRoot << std::endl;
    std::cout << "Bisection Root: " << bisectionRoot << std::endl;
    std::cout << "Newton's Root: " << newtonRoot << std::endl;
    std::cout << "Secant Root: " << secantRoot << std::endl;
    std::cout << std::endl;

    /*********************************/
    // Task 2: Try all four methods for finding roots
    /*********************************/
    std::cout << "TASK 2" << std::endl;
    double newtonRootneg5 = Rootfinding::newtonsMethod(function, -5.0, 0.01, 1000, false);
    double newtonRoot6 = Rootfinding::newtonsMethod(function, 6.0, 0.01, 1000, false);

    std::cout << "Newton's Root using x0 = -5.0: " << newtonRoot << std::endl;
    std::cout << "Newton's Root using x0 = 6.0: " << newtonRoot << std::endl;
    std::cout << std::endl;

    /*********************************/
    // Task 3: Create algorithm for finding roots closest to zero
    /*********************************/
    std::cout << "TASK 3" << std::endl;
    double hybridClosestToZeroRoot = Rootfinding::hybridMethodNearestToZero(function, 0.01, -5, 6, 0.01);

    std::cout << "Leftbound: -5.0, Rightbound: 6.0" << std::endl;
    std::cout << "Hybrid Method with newton's method for finding zero closest to root: " << hybridClosestToZeroRoot << std::endl;
    std::cout << std::endl;

    /*********************************/
    // Task 4: Create algorithm for finding roots closest to zero with secant method
    /*********************************/
    std::cout << "TASK 4" << std::endl;
    hybridClosestToZeroRoot = Rootfinding::hybridMethodNearestToZeroSecant(function, 0.01, -5, 6, 0.01);

    std::cout << "Leftbound: -5.0, Rightbound: 6.0" << std::endl;
    std::cout << "Hybrid Method with secant method for finding zero closest to root: " << hybridClosestToZeroRoot << std::endl;



    return 0;
}