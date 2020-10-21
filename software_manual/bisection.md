# double bisection(const Function & function, double reduceconst, double leftbound, double rightbound)

**Function Name:**           bisection

**Namespace:**               Rootfinding

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ bisection.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ bisection.cpp -o bisection.exe

**Description/Purpose:** This routine will compute the root of functions using the bisection method. The root must be contained within the initial bracketed area.

**Input:** A function, tolerance constant, left bound, right bound

**Output:** One of the roots of the function

**Usage/Example:** A NewFunction class must be created that contains the function to be evaluated during the bisection iteration. The function should be placed as the return
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
    double tol = 1000;
    double leftbound = 0;
    double rightbound = 10;
    double root = Rootfinding::bisection(function, tol, leftbound, rightbound);
}
</pre></code>

**Implementation/Code:** The following is the code for bisection()

<pre><code>
 double Rootfinding::bisection(const Rootfinding::Function & function, double reduceconst, double leftbound, double rightbound)
{
    int setiterations = 0;

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

    return middle;
}
</pre></code>

**Last Modified:** October/2020
