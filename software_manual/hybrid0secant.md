# double hybridMethodNearestToZeroSecant(const Function & function, double error, double leftbound, double rightbound, double stepsize)

**Function Name:**           hybridMethodNearestToZeroSecant

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ hybrid0secant.cpp abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ hybrid0secant.cpp abserror.cpp -o hybrid0secant.exe

**Description/Purpose:** This routine will compute the root of a function that is closest to zero and within the initial leftbound and rightbound bracket given as input to hybridMethodNearestToZero. This routine finds the new bracket that contains the root closest to zero by stepping from zero up to the rightbound bracket and from zero down to the leftbound bracket. Once this bracket has been found, a hybrid method of secant method and bisection are used to find the root.

**Input:** A function, desired error, leftbound bracket, rightbound bracket, step size

**Output:** One of the roots of the function

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated. The function to be evaluated should be placed as the return
 statement for the getOutput() method. The bracket sent to the routine must contain zero. The root for this example should be 1.5708 (or PI/2).

<pre><code> 
#inclde "math4610lib.h" 
#include <iostream>

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
    std::cout << "Root: " << Rootfinding::hybridMethodNearestToZeroSecant(function, 0.001, -20, 20, 0.1) << std::endl;
    std::cout << "Root should be + or - " << 3.14159 / 2.0 << std::endl;
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to library>/math4610lib.a -o main.exe

**Implementation/Code:** Source code can be found [here](../src/hybrid0secant.cpp). The following is the code for hybridMethodNearerstToZero():

<pre><code>
 double Rootfinding::hybridMethodNearestToZeroSecant(const Function & function, double error, double leftbound, double rightbound, double stepsize)
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
    double xk_1 = xk + 0.01; // Approximation goes bad when this increment is smaller
    double xk_2;
    double fxk = function.getOutput(xk);
    double fxk_1 = function.getOutput(xk_1);
    while(currerror > error && it < MAX_ITERATIONS)
    {
        xk_2 = xk_1 - fxk_1 * (xk_1 - xk) / (fxk_1 - fxk);
        currerror = Error::abserror(xk_1, xk); // xk_1 and xk are the same when f(xk) is zero
        
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
            xk = middle; // Do secant method about the output of the bisection method
            xk_1 = xk + 0.01;
            fxk = function.getOutput(xk);
            fxk_1 = function.getOutput(xk_1);
        }
        else
        {
            xk = xk_1; // Shift x values
            xk_1 = xk_2;
            fxk = fxk_1; // Shift fx values
            fxk_1 = function.getOutput(xk_1);
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

}
</pre></code>

**Last Modified:** November/2020

