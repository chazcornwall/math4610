# double LinearAlgebra::Matrix::vectorl1Norm() const

**Function Name:**           vectorl1Norm

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine calculates the l1 norm of a column or row vector.

**Input:** None

**Output:** None

**Usage/Example:** The desired column or row vector must be created as a 1D array. Then the function `createMatrixFromRowVector()` can be used to convert that array to a `LinearAlgebra::Matrix` object.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    double test[4] = {1, 3, 5, 6};
    LinearAlgebra::Matrix row = LinearAlgebra::createMatrixFromRowVector(test, 4, LinearAlgebra::ROW);
    
    // Use the following code to create a column vector
    // LinearAlgebra::Matrix col = LinearAlgebra::createMatrixFromRowVector(test, 4, LinearAlgebra::COL);
    
    double output = row.vectorl1Norm();
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for solve()

<pre><code>
 double LinearAlgebra::Matrix::vectorl1Norm() const
{
    double output = 0.0;
    if(NUM_ROWS == 1 || NUM_COLS == 1) // If the matrix is also a vector
    {
        if(NUM_ROWS == 1)
        {
            for(size_t col = 0; col < NUM_COLS; col++)
            {
                output += abs(this->data[0][col]);
            }
        }
        else
        {
            for(size_t row = 0; row < NUM_ROWS; row++)
            {
                output += abs(this->data[row][0]);
            }
        }
    }
    else
    {
       std::cerr << "Cannot take vector norm of a matrix!" << std::endl;
    }
    return output;
}
</pre></code>

**Last Modified:** December/2020

