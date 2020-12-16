# double LinearAlgebra::Matrix::vectorlInfNormError(const LinearAlgebra::Matrix & y) const

**Function Name:**           vectorlInfNormError

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine calculates the infinity norm error of two column vectors or row vectors.

**Input:** A 1 x M or M x 1 `LinearAlgebra::Matrix` that matches the dimensions of `this` 

**Output:** A double representing the error

**Usage/Example:** The vectors to be compared must both be row vectors or column vectors and have the same number of entries. These vectors can be created as 1D arrays. Then the function `createMatrixFromRowVector()` can be used to convert that array to a `LinearAlgebra::Matrix` object.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    double test[4] = {1, 3, 5, 6};
    double testCompare[4] = {8, 3, 12, 6};
    LinearAlgebra::Matrix row = LinearAlgebra::createMatrixFromRowVector(test, 4, LinearAlgebra::ROW);
    LinearAlgebra::Matrix rowCompare = LinearAlgebra::createMatrixFromRowVector(testCompare, 4, LinearAlgebra::ROW);
    
    // Use the following code to create a column vector
    // LinearAlgebra::Matrix col = LinearAlgebra::createMatrixFromRowVector(test, 4, LinearAlgebra::COL);
    
    double output = row.vectorlInfNormError(rowCompare);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for vectorlInfNormError()

<pre><code>
 double LinearAlgebra::Matrix::vectorlInfNormError(const LinearAlgebra::Matrix & y) const
{
    double output = 0.0;
    if(NUM_ROWS == 1 || NUM_COLS == 1) // If the matrix is also a vector
    {
        if(NUM_ROWS == 1)
        {
            for(size_t col = 0; col < NUM_COLS; col++)
            {
                double diff = this->data[0][col] - y.data[0][col];
                output = (output < abs(diff)) ? abs(diff) : output;
            }
        }
        else
        {
            for(size_t row = 0; row < NUM_ROWS; row++)
            {
                double diff = this->data[row][0] - y.data[row][0];
                output = (output < abs(diff)) ? abs(diff) : output;
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
