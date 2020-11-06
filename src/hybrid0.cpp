#include "../include/math4610lib.hpp"
#include <iostream>

double Rootfinding::hybridMethodNearestToZero(const Function & function, double error, double leftbound, double rightbound, double stepsize)
{
    if (leftbound >= 0 || rightbound <= 0)
    {
        std::cout << "ERROR: leftbound must be negative and rightbound must be positive!" << std::endl;
        return 0.0;
    }

    int it = 0;
    const int MAX_ITERATIONS = 100;
    const double REDUCE_CONSTANT = 10.0;
    double currerror = error * 10.0;
    double lasterror = currerror;

    double currLeftbound = 0;
    double currRightbound = 0;
    double testForZeroNeg = function.getOutput(currLeftbound) * function.getOutput(0);
    double testForZeroPos = function.getOutput(0) * function.getOutput(currRightbound);

    // Find the closest point at which the function crosses the x axis
    while(testForZeroNeg > 0 && testForZeroPos > 0 && (currLeftbound < abs(leftbound) || currRightbound < abs(rightbound)))
    {
        currLeftbound -= stepsize;
        currRightbound += stepsize;
        testForZeroNeg = function.getOutput(currLeftbound) * function.getOutput(0);
        testForZeroPos = function.getOutput(0) * function.getOutput(currRightbound);
    }

    // Reassign bounds so that
    if(testForZeroNeg < 0 && currLeftbound < abs(leftbound))
    {
        leftbound = currLeftbound;
        rightbound = 0.0;
    }
    else if(testForZeroPos < 0 && currRightbound < abs(rightbound))
    {
        rightbound = currRightbound;
        leftbound = 0.0;
    }
    

    double xk = (leftbound + rightbound) / 2.0; // Calculate x0 as the middle of the bounds
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
        double getOutput(double input) const {return cos(input);};
        double getDerivOutput(double input) const {return -sin(input);};
};

int main()
{
    NewFunction function = NewFunction();
    std::cout << "Function: cos(x)" << std::endl;
    std::cout << "Root: " << Rootfinding::hybridMethodNearestToZero(function, 0.01, -20, 20, 0.1) << std::endl;
    std::cout << "Root should be + or - " << 3.14159 / 2.0 << std::endl;
    return 0;
}
#endif