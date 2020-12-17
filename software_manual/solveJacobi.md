# LinearAlgebra::Matrix LinearAlgebra::Matrix::solveJacobi(LinearAlgebra::Matrix & b, const double & tolerance, const size_t & maxIterations) const

**Function Name:**           solveJacobi

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine will solve a system of linear equations that is diagonally dominant using Jacobi Iteration. [See here for more details](https://en.wikipedia.org/wiki/Jacobi_method)

**Input:** A M x 1 matrix where M is the number of rows in A, the desired tolerance between iterations, and the max number of iterations

**Output:** A M x 1 matrix where M is the number of rows in A.

**Usage/Example:** An A and b matrix must be created. Values can easily be assigned to A by creating an array for each equation. 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    LinearAlgebra::Matrix Ajacobi(50, 50, LinearAlgebra::SQR, 1);
    LinearAlgebra::Matrix bjacobi(50, 1, 1.0);
    Ajacobi.makeDiagDominant(100.0);

    LinearAlgebra::Matrix xJacobi = Ajacobi.solveJacobi(bjacobi, 0.001, 300);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for solveJacobi()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::solveJacobi(const LinearAlgebra::Matrix & b, const double & tolerance, const size_t & maxIterations) const
{
    Matrix xOld(this->NUM_ROWS, 1, 0.0); // Initial guess;
    Matrix aLU = this->duplicate();
    Matrix aDiag(this->NUM_ROWS, this->NUM_COLS, 0.0);

    // Create inverse diagonal matrix
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            if(row == col)
            {
                aDiag[row][col] = 1 / this->data[row][col];
            }
        }
    }

    double error = 10.0 * tolerance;
    double pastError;
    size_t it = 0;

    // Execute Jacobi Iteration using residuals
    while(error > tolerance && it < maxIterations)
    {
        Matrix residual = b - (*this * xOld);
        Matrix xNew = xOld + (aDiag * residual);

        pastError = error;
        error = residual.vectorl2Norm();
        if(error > pastError)
        {
            std::cout << "WARNING: Jacobi iteration not converging!" << std::endl;
        }

        xOld.update(xNew);
        it++;
    }
    
    if(it == maxIterations && tolerance < error)
    {
        std::cout << "ERROR: Residual tolerance " << tolerance << " not met with " << maxIterations << " iterations!" << std::endl;
        std::cout << "ERROR: Residual l2norm is " << error << std::endl;
    }

    return xOld;
}
</pre></code>

**Last Modified:** December/2020

