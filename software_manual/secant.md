# double secantMethod(const Function & function, double x0, double error, double maxiter, bool Debug)

**Function Name:**           secantMethod

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ secantMethod.cpp abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ secantMethod.cpp abserror.cpp -o secantMethod.exe

**Description/Purpose:** This routine will compute the root of functions using the secant method. This method is the same as newton's method except that the derivative of the 
function is calculated numerically instead of analytically. The initial guess, x0, must be sufficiently close to the root or the iterations will not converge.

**Input:** A function, initial guess, desired error, maximum number of iterations, and a debug indicator

**Output:** One of the roots of the function

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated during the secant method iteration. The function to be evaluated should be placed as the return
 statement for the getOutput() method. The root for this example should be 0.08055.

<pre><code> 
#inclde "math4610lib.h" 

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return input * exp(3 * input * input) - 7 * input;};
};

int main(void)
{
    NewFunction function = NewFunction();
    double x0 = 2;
    double error = 0.01;
    double maxiter = 1000;
    double root = Rootfinding::secantMethod(function, x0, error, maxiter, true);
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to library>/math4610lib.a -o main.exe

**Implementation/Code:** The following is the code for secantMethod()

<pre><code>
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
</pre></code>

**Last Modified:** October/2020
