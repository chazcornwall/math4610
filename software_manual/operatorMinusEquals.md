# LinearAlgebra::Matrix LinearAlgebra::Matrix::operator-=(const LinearAlgebra::Matrix & operand) const

**Function Name:**           N/A (operator overload)

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This operator overload allows the user to subtract matrices of the same size by using the "-=" unary operator.

**Input:** Two matrices of the same size

**Output:** A matrix the same size as the input matrices that shows element-wise subtraction was performed on the input matrices

**Usage/Example:** 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t numRows = 10;
    size_t numCols = 10;
    LinearAlgebra::Matrix A(numRows, numCols, LinearAlgebra::SQR);
    LinearAlgebra::Matrix B(numRows, numCols, 1.0);
    
    A -= B;
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for operator-

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::operator-=(const LinearAlgebra::Matrix & operand) const
{
    size_t numRow = this->getNumRows();
    size_t numCol = this->getNumCols();

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            this->data[row][col] = this->data[row][col] - operand.data[row][col];
        }
    }

    return *this;
}
</pre></code>

**Last Modified:** December/2020
