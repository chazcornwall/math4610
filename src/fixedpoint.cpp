#include "../include/math4610lib.hpp"
#include <iostream>

double Rootfinding::fixedPoint(const Rootfinding::Function & function, double x0, double error, double epsilon, int stop)
{
    double errorcurrent = 100000000;
    double xk = x0;
    double xk_1;
    int it = 0;
    while(errorcurrent > error && it < stop && errorcurrent <= 100000000)
    {
        it++;
        double fxk = function.getOutput(xk);
        xk_1 = xk - epsilon * fxk; // Perform fixed point iteration
        errorcurrent = Error::abserror(fxk, 0.0);
        xk = xk_1;

        if(it == stop || errorcurrent >= 100000000)
        {
            std::cout << "Fixed point iteration does not converge!" << std::endl;
        }
    }

    return xk_1;
}

#ifdef TEST_
class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return input * exp(3 * input * input) - 7 * input;};
};

int main()
{
    NewFunction function = NewFunction();
    double x0 = 1;
    std::cout << "Function: x^2" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::fixedPoint(function, x0, 0.01, 0.15, 1000) << std::endl; 
    return 0;
}
#endif