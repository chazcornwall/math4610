# double * hybridMethodAllRoots(const Function & function, int * numOfRoots, double error, double leftbound, double rightbound, double stepsize)

**Function Name:**           hybridMethodAllRoots

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ hybridAllRoots.cpp abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ hybridAllRoots.cpp abserror.cpp -o hybridAllRoots.exe

**Description/Purpose:** This routine will find all the roots for a given function given a leftbound and rightbound bracket, noninclusive. By using the stepsize parameter, the routine steps from the leftbound to the rightbound and finds smaller brackets where a roots must exist. Once one of these smaller brackets is found, a hybrid method of newton's method and bisection is used to compute the root.

**Input:** A function, pointer to the number of roots, desired error, leftbound bracket, rightbound bracket, step size

**Output:** All the roots of the function within the given bracket

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated. The function to be evaluated should be placed as the return
 statement for the getOutput() method. The roots for this example should be -1.32158, -1.03577, -0.483611, 0.483611, 1.03577, and 1.32158. An important note is this routine does not work properly when accessed from the math4610lib.a archive. This function must be used by compliling it with your main.cpp.

<pre><code> 
#include "math4610lib.h" 

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
    int * numOfRoots;
    double * roots;
    Rootfinding::hybridMethodAllRoots(function, roots, numOfRoots, 0.01, -25, 24, 0.1);

    for(int i = 0; i < *numOfRoots; i++)
    {
        std::cout << "Root: " << roots[i] << std::endl;
    }
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/hybridAllRoots.cpp <path to source>/abserror.cpp -o main.exe

**Implementation/Code:** The following is the code for hybridMethod()

<pre><code>
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
</pre></code>

**Last Modified:** November/2020
