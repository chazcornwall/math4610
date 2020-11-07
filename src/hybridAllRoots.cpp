#include "../include/math4610lib.hpp"
#include <iostream>

double * Rootfinding::hybridMethodAllRoots(const Function & function, int * numOfRoots, double error, double leftbound, double rightbound, double stepsize)
{
    const int MAX_ITERATIONS = 100;
    const double REDUCE_CONSTANT = 10.0;

    double currLeftbound = 0;
    double currRightbound = 0;
    double currX = leftbound;
    double currValue = leftbound + stepsize;
    double prevValue = function.getOutput(leftbound);
    static double * roots; // Declare as static so values persist after this function is destroyed
    *numOfRoots = 0;

    // Loop through the entire bracketed region
    while(currX < rightbound)
    {
       currValue = function.getOutput(currX);
       if(currValue * prevValue < 0) // Find a point in the bracketed region where the root exists
       {
            currLeftbound = currX - stepsize;
            currRightbound = currX;
            double xk = (currLeftbound + currRightbound) / 2.0; // Calculate x0 as the middle of the bounds
            double xk_1;

            // Copy current roots into a larger array
            double * tempRoots = roots;
            for(int i = 0; i < *numOfRoots; i++)
            {
                tempRoots[i] = roots[i];
            }
            roots = new double[++(*numOfRoots)]; // Increment the number of roots
            for(int i = 0; i < (*numOfRoots - 1); i++)
            {
                roots[i] = tempRoots[i];
            }
            
            // Start finding the root with a hybrid method
            int it = 0;
            double currerror = error * 10.0;
            double lasterror = currerror;
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
                        middle = (currLeftbound + currRightbound) / 2.0;
                        if(function.getOutput(currLeftbound) * function.getOutput(middle) < 0) // If boundary contains a root
                        {
                            currRightbound = middle;
                        }
                        else
                        {
                            currLeftbound = middle;
                        }
                    }
                    xk = middle; // Do newton's method about the output of the bisection method
                }
                lasterror = currerror;
                it++;
            }
            roots[*numOfRoots - 1] = xk_1;

            if(it >= MAX_ITERATIONS && !(currerror < error))
            {
                std::cout << "ERROR: Hybrid Method did not converge!" << std::endl;
            }
       }
       prevValue = currValue;
       currX += stepsize;
    }
    return roots;
}

#ifdef TEST_
class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return cos(input);};
        double getDerivOutput(double input) const {return -sin(input);};
};

class NewFunction2 : public Rootfinding::Function
{
    public:
        NewFunction2(){}; 
        double getOutput(double input) const {return exp(-(input * input)) * sin(4.0 * input * input - 1.0) + 0.051;};
        double getDerivOutput(double input) const {return 8.0 * input * exp(-(input * input)) * cos(4.0 * input * input - 1.0) - 2.0 * input * exp(-(input * input)) * sin(4.0 * input * input - 1.0);};
};


int main()
{
    NewFunction function = NewFunction();
    NewFunction2 function2 = NewFunction2();
    std::cout << "Function: cos(x)" << std::endl;
    int * numOfRoots;
    double * roots;
    Rootfinding::hybridMethodAllRoots(function2, roots, numOfRoots, 0.01, -25, 24, 0.1);

    for(int i = 0; i < *numOfRoots; i++)
    {
        std::cout << "Root: " << roots[i] << std::endl;
    }
    
    return 0;
}
#endif