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
    // Task 5: Create algorithm for finding all roots within a given bracket
    /*********************************/
    
    std::cout << "TASK 5" << std::endl;
    int * numOfRoots;
    double * hybridAllRoots;
    hybridAllRoots = Rootfinding::hybridMethodAllRoots(function, numOfRoots, 0.01, -5.0, 6.0, 0.001);

    for(int i = 0; i < *numOfRoots; i++)
    {
        std::cout << "Root: " << hybridAllRoots[i] << std::endl;
    }

    return 0;
}