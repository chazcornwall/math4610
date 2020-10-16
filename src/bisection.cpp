#include "../include/math4610lib.hpp"
#include <iostream>

double Rootfinding::bisection(const Rootfinding::Function & function, double reduceconst, double leftbound, double rightbound)
{
    int setiterations = 0;

    while(reduceconst > 1) 
    {
        reduceconst /= 2;
        setiterations++; // Counts how many iterations to reduce by a given constant
    }

    double middle;
    for(int it = 0; it < setiterations ; it++)
    {
        middle = (leftbound + rightbound) / 2.0;
        if(function.getOutput(leftbound) * function.getOutput(middle) < 0) // If boundary contains a root
        {
            rightbound = middle;
        }
        else
        {
            leftbound = middle;
        }
    }

    return middle;
}

#ifdef TEST_
class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return sin(input);};
};

int main()
{
    NewFunction function = NewFunction();
    double leftbound = 0.0;
    double rightbound = 10.0;
    std::cout << "Function: x^2" << std::endl;
    std::cout << "leftbound: " << leftbound << std::endl;
    std::cout << "rightbound: " << rightbound << std::endl;
    std::cout << "Root: " << Rootfinding::bisection(function, 1000, leftbound, rightbound) << std::endl; 
    return 0;
}
#endif