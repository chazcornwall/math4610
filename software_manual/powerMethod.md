# double LinearAlgebra::Matrix::powerMethod(const double & tolerance, const double & maxIterations) const

**Function Name:**           powerMethod

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** C++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine will return an approximation for the largest eigen value of the matrix.

**Input:** Acceptable tolerance between iterations, the max number of iterations

**Output:** The largest eigen value as a double

**Usage/Example:** The larger the matrix and the more precision required in the matrix entries, the more inaccurate the approximation. 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    LinearAlgebra::Matrix Apower(5, 5, LinearAlgebra::SQR, 10);
    double output = Apower.powerMethod(0.001, 10000);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for powerMethod()

<pre><code>
 double LinearAlgebra::Matrix::powerMethod(const double & tolerance, const double & maxIterations) const
{
    Matrix b(this->NUM_ROWS, 1, LinearAlgebra::SQR, 10); // Create a random initial matrix
    Matrix v = *this * b;

    double error = 10.0 * tolerance;
    double pastLambda = 0.0;
    size_t it = 0;
    while(error > tolerance && it < maxIterations) // Solve using Raleigh Quotient (v.transpose() * A * v) / (v.transpose() * v)
    {
        Matrix vTemp = v * (1.0 / v.vectorl2Norm()); 
        v.update(vTemp); // Quotient now is v.transpose() * A * v
        Matrix z = (*this * v);
        Matrix tempLambda = v.transpose() * z; // If v is an eigenvector of A (*this), the Raleigh Quotient simplifies to the largest eigen value, lambda
        double currLambda = tempLambda[0][0];

        error = abs(currLambda - pastLambda); // Calculate current error

        pastLambda = currLambda; // Updates for next iteration
        v.update(z);
        it++;
    }

    return pastLambda;
}
</pre></code>

**Last Modified:** December/2020

