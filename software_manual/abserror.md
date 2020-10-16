# double abserror(double approx, double num)

**Function Name:**           double

**Namespace:**               Error

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ abserror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ abserror.cpp -o abserror.exe

**Description/Purpose:** This routine will return the absolute error between the two passed-in values.

**Input:** The approximate value, the target value

**Output:** The error

**Usage/Example:** 

<pre><code> 
#inclde "math4610lib.h" 

int main(void)
{
    double approx = 52;
    double num = 63.75;
    double error = Error::abserror(approx, num);
}
</pre></code>

**Implementation/Code:** The following is the code for abserror()

<pre><code>
 double Error::abserror(double approx, double num)
{
    return std::abs(approx - num);
}
</pre></code>

**Last Modified:** October/2020

