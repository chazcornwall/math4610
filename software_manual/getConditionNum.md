# double LinearAlgebra::Matrix::getConditionNum(const double & tolerance, const double & maxIterations) const

**Function Name:**           getConditionNum

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** C++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine will return a rough approximation for the 2-condition number of a matrix. This is calculated by multiplying results from the `LinearAlgebra::Matrix::powerMethod` and
`LinearAlgebra::Matrix::powerMethodInverse` routines.

**Input:** Acceptable tolerance between iterations in the power method, the max number of iterations in the power method

**Output:** An approximation for the 2-condition number

**Usage/Example:** This routine should be used to determine how accurate a solution is for the given system matrix `this`. The higher the condition number, the more error present 
in the solution from the system matrix. 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    LinearAlgebra::Matrix Apower(5, 5, LinearAlgebra::SQR, 10);
    double output = Apower.getConditionNum(0.001, 10000);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for getConditionNum()

<pre><code>
 double LinearAlgebra::Matrix::getConditionNum(const double & tolerance, const double & maxIterations) const
{
    double eigenMax = (*this).powerMethod(tolerance, maxIterations);
    double eigenMin = (*this).powerMethodInverse(tolerance, maxIterations);

    return  abs(eigenMax) * abs(eigenMin);
}
</pre></code>

**Last Modified:** December/2020
