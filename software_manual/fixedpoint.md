# double fixedpoint(const Function & function, double x0, double error, double stop)

**Function Name:**           fixedpoint

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ fixedpoint.cpp abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ fixedpoint.cpp abserror.cpp -o fixedpoint.exe

**Description/Purpose:** This routine will compute the root of functions using the fixed-point iteration method. 

**Input:** A function, an initial x0, the target error, and max allowable iterations

**Output:** One of the roots of the function

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated during the fixed-point iteration. The function should be place as the return
 statement for the getOutput() method.

<pre><code> 
#inclde "math4610lib.h" 

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return sin(input);};
};

int main(void)
{
    NewFunction function = NewFunction();
    double x0 = 10.0;
    double error = 0.0001;
    double stop = 10000
    double root = Rootfinding::fixedpoint(function, x0, error, stop);
}
</pre></code>

**Implementation/Code:** The following is the code for fixedpoint()

<pre><code>
 double Rootfinding::fixedPoint(const Rootfinding::Function & function, double x0, double error, int stop)
{
    double errorcurrent = 1000000;
    double xk = x0;
    double xk_1;
    int it = 0;
    while(errorcurrent > error && it < stop && errorcurrent <= 1000000)
    {
        double fxk = function.getOutput(xk);
        xk_1 = xk - fxk; // Perform fixed point iteration
        errorcurrent = Error::abserror(fxk, 0.0);
        xk = xk_1;
    }

    if(it == stop || errorcurrent >= 1000000)
    {
        std::cout << "Fixed point iteration does not converge!" << std::endl;
    }

    return xk_1;
}
</pre></code>

**Last Modified:** October/2020
