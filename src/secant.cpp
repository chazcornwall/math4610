#include "../include/math4610lib.hpp"
#include <iostream>

double Rootfinding::secantMethod(const Function & function, double x0, double error, int maxiter, bool Debug)
{
    int it = 0;
    double currerror = error * 10.0;
    double xk = x0;
    double xk_1 = xk + 0.01;
    double xk_2;
    double fxk = function.getOutput(x0);
    double fxk_1 = function.getOutput(xk_1);
    while(currerror > error && it < maxiter)
    {
        xk_2 = xk_1 - fxk_1 * (xk_1 - xk) / (fxk_1 - fxk);
        currerror = Error::abserror(xk_2, xk_1); // xk_2 and xk_1 are the same when f(xk) is zero
        if(Debug)
            std::cout << "Current error (log): " << log10(currerror) << std::endl;
        xk = xk_1; // Shift x values
        xk_1 = xk_2;
        fxk = fxk_1; // Shift fx values
        fxk_1 = function.getOutput(xk_1);
        it++;
    }

    if(it >= maxiter && !(currerror < error))
    {
        std::cout << "ERROR: Secant Method did not converge!" << std::endl;
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
    double x0 = 1.0;
    std::cout << "Function: xexp(3x^2) - 7x" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::secantMethod(function, x0, 0.0001, 1000) << std::endl; 
    return 0;
}
#endif