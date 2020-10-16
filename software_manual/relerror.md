# double relerror(double approx, double num)

**Function Name:**           relerror

**Namespace:**               Error

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ relerror.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ relerror.cpp -o relerror.exe

**Description/Purpose:** This routine will return the relative error between the two passed-in values.

**Input:** The approximate value, the target value

**Output:** The error

**Usage/Example:** 

<pre><code> 
#inclde "math4610lib.h" 

int main(void)
{
    double approx = 52;
    double num = 63.75;
    double error = Error::relerror(approx, num);
}
</pre></code>

**Implementation/Code:** The following is the code for relerror()

<pre><code>
 double Error::relerror(double approx, double num)
{
    return std::abs(approx - num) / num;
}
</pre></code>

**Last Modified:** October/2020
