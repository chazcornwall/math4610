#include "../include/math4610lib.hpp"
#include <iostream>

double Rootfinding::newtonsMethod(const Function & function, double x0, double error, double maxiter, bool Debug)
{
    int it = 0;
    double currerror = error * 10.0;
    double xk = x0;
    double xk_1;
    while(currerror > error && it < maxiter)
    {
        xk_1 = xk - function.getOutput(xk) / function.getDerivOutput(xk);
        currerror = Error::abserror(xk_1, xk); // xk_1 and xk are the same when f(xk) is zero
        if(Debug)
            std::cout << "Current error (log): " << log10(currerror) << std::endl;
        xk = xk_1;
        it++;
    }

    if(it >= maxiter && !(currerror < error))
    {
        std::cout << "ERROR: Newton Method did not converge!" << std::endl;
    }

    return xk_1;
}

#ifdef TEST_
class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return input * exp(3 * input * input) - 7 * input;};
        double getDerivOutput(double input) const {return exp(3 * input *  input) + 6 * input * input - 7;};
};

int main()
{
    NewFunction function = NewFunction();
    double x0 = 2;
    std::cout << "Function: xexp(3x^2) - 7x" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::newtonsMethod(function, x0, 0.01, 1000) << std::endl; 
    return 0;
}
#endif