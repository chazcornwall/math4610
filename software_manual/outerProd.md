# LinearAlgebra::Matrix LinearAlgebra::Matrix::outerProd(const LinearAlgebra::Matrix & y) const

**Function Name:**           outerProd

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This function calculates the outer product of two vectors (given `this` is a column vector with M rows).

**Input:** A row vector with N columns

**Output:** A matrix with M rows and N columns where each row in the matrix is a scaled version of the input vector.

**Usage/Example:** Use the function `LinearAlgebra::createMaatrixFromRowVector` to create column and row vectors.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    double test[4] = {1, 3, 5, 6};
    LinearAlgebra::Matrix row = LinearAlgebra::createMatrixFromRowVector(test, 4, LinearAlgebra::ROW);
    LinearAlgebra::Matrix col = LinearAlgebra::createMatrixFromRowVector(test, 4, LinearAlgebra::COL);
    
    LinearAlgebra::Matrix outer = col.outerProd(row);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for outerProd

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::outerProd(const LinearAlgebra::Matrix & y) const
{
    LinearAlgebra::Matrix output(this->NUM_ROWS, y.NUM_COLS, 0.0);
    if(this->NUM_COLS == 1 && y.NUM_ROWS == 1) // If the matrix is also a vector
    {
        size_t numRow = this->NUM_ROWS;
        size_t numCol = y.NUM_COLS;

        for(size_t row = 0; row < numRow; row++)
        {
            for(size_t col = 0; col < numCol; col++)
            {
                output.data[row][col] = this->data[row][0] * y.data[0][col];
            }
        }
    }
    else
    {
       std::cerr << "Cannot take outer product of a matrix!" << std::endl;
    }
    return output;
}
</pre></code>

**Last Modified:** December/2020


