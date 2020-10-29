#include "../include/math4610lib.hpp"
#include <iostream>

double Rootfinding::hybridMethod(const Function & function, double x0, double error, double leftbound, double rightbound)
{
    int it = 0;
    const int MAX_ITERATIONS = 100;
    const double REDUCE_CONSTANT = 10.0;
    double currerror = error * 10.0;
    double lasterror = currerror;
    double xk = x0;
    double xk_1;
    while(currerror > error && it < MAX_ITERATIONS)
    {
        xk_1 = xk - function.getOutput(xk) / function.getDerivOutput(xk);
        currerror = Error::abserror(xk_1, xk); // xk_1 and xk are the same when f(xk) is zero
        xk = xk_1;
        if(currerror > lasterror) // If the error has not decreased, use bisection
        {
            int setiterations = 0;
            double reduceconst = REDUCE_CONSTANT;
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
            xk = middle; // Do newton's method about the output of the bisection method
        }
        lasterror = currerror;
        it++;
    }

    if(it >= MAX_ITERATIONS && !(currerror < error))
    {
        std::cout << "ERROR: Hybrid Method did not converge!" << std::endl;
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
    double x0 = -2;
    std::cout << "Function: xexp(3x^2) - 7x" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root: " << Rootfinding::hybridMethod(function, x0, 0.01, -5, 5) << std::endl; 
    return 0;
}
#endif