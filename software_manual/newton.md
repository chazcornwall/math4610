# double newtonMethod(const Function & function, double x0, double error, double maxiter, bool Debug)

**Function Name:**           newtonMethod

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ newton.cpp abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ newton.cpp abserror.cpp -o newton.exe

**Description/Purpose:** This routine will compute the root of functions using newton's method. The initial guess, x0, must be sufficiently close to the root or
the iterations will not converge.

**Input:** A function, initial guess, desired error, maximum number of iterations, and a debug indicator

**Output:** One of the roots of the function

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated during the newton method iteration. The function to be evaluated should be placed as the return statement for the getOutput() method. The derivative of the function to be evaluated should be placed in the return statement for the getDerivOutput() method. The root for this example should be 0.08055.

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to library>/math4610lib.a -o main.exe

<pre><code> 
#inclde "math4610lib.h" 

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return input * exp(3 * input * input) - 7 * input;};
        double getDerivOutput(double input) const {return exp(3 * input *  input) * (6 * input * input + 1) - 7;};
};

int main(void)
{
    NewFunction function = NewFunction();
    double x0 = 2;
    double error = 0.01;
    double maxiter = 1000;
    double root = Rootfinding::newtonsMethod(function, x0, error, maxiter, true);
}
</pre></code>

**Implementation/Code:** The following is the code for newtonMethod()

<pre><code>
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
</pre></code>

**Last Modified:** October/2020
