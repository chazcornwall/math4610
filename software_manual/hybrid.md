# double hybridMethod(const Function & function, double x0, double error, double leftbound, double rightbound)

**Function Name:**           hybridMethod

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ hybrid.cpp abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ hybrid.cpp abserror.cpp -o hybrid.exe

**Description/Purpose:** This routine will compute the root of functions using the newton method for 100 iterations at most. If at any point the error from using newton's method does not decrease, 
a 4 bisection iterations will be implemented to reduce the bracketing area by a factor of 10. The initial guess, x0, must be within the leftbound and rightbound brackets.

**Input:** A function, initial guess, desired error, leftbound bracket, rightbound bracket

**Output:** One of the roots of the function

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated during the secant method iteration. The function to be evaluated should be placed as the return
 statement for the getOutput() method. The root for this example should be 3.14159.

<pre><code> 
#inclde "math4610lib.h" 

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return sin(input);};
        double getDerivOutput(double input) const {return cos(input);};
};

int main(void)
{
    NewFunction function = NewFunction();
    double x0 = 5;
    double error = 0.01;
    double leftbound = -5.0;
    double rightbound = 10.0;
    double root = Rootfinding::hybridMethod(function, x0, error, leftbound, rightbound);
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to library>/math4610lib.a -o main.exe

**Implementation/Code:** The following is the code for hybridMethod()

<pre><code>
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
</pre></code>

**Last Modified:** October/2020
