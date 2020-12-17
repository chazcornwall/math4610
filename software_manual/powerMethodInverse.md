# double LinearAlgebra::Matrix::powerMethodInverse(const double & tolerance, const double & maxIterations) const

**Function Name:**           powerMethodInverse

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** C++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine will return a rough approximation for the smallest eigen value of the matrix.

**Input:** Acceptable tolerance between iterations, the max number of iterations

**Output:** The smallest eigen value as a double

**Usage/Example:** The larger the matrix and the more precision required in the matrix entries, the more inaccurate the approximation. This method is much more inaccurate than
the `LinearAlgebra::Matrix::powerMethod` routine because of precision error accumulation and propogation from solving a system of linear equations. The regular powerMethod routine only uses matrix multipliation,
which does not propogate any precision errors. This method should only be used for approximate matrix condition number calculations.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    LinearAlgebra::Matrix Apower(5, 5, LinearAlgebra::SQR, 10);
    double output = Apower.powerMethodInverse(0.001, 10000);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for powerMethodInverse()

<pre><code>
 double LinearAlgebra::Matrix::powerMethodInverse(const double & tolerance, const double & maxIterations) const
{
    Matrix b(this->NUM_ROWS, 1, LinearAlgebra::SQR, 10); // Create a random initial matrix
    Matrix v = (*this).solve(b);

    double error = 10.0 * tolerance;
    double pastLambda = 0.0;
    size_t it = 0;
    while(error > tolerance && it < maxIterations) // Solve using Raleigh Quotient (v.transpose() * A^-1 * v) / (v.transpose() * v)
    {
        Matrix vTemp = v * (1.0 / v.vectorl2Norm()); 
        v.update(vTemp); // Quotient now is v.transpose() * A^-1 * v
        Matrix z = (*this).solve(v);
        Matrix tempLambda = v.transpose() * z; // If v is an eigenvector of A^-1 (*this), the Raleigh Quotient simplifies to the largest eigen value, lambda
        double currLambda = tempLambda[0][0];

        error = abs(currLambda - pastLambda); // Calculate current error

        pastLambda = currLambda; // Updates for next iteration
        v.update(z);
        it++;
    }

    return 1.0 / pastLambda; // pastLambda is the largest eigen value for A^-1
}
</pre></code>

**Last Modified:** December/2020

