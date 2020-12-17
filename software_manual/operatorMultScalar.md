# LinearAlgebra::Matrix LinearAlgebra::Matrix::operator*(const double & operand) const

**Function Name:**           N/A (operator overload)

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This operator overload allows the user to multiply a matrix by a scalar with the "+" binary operator. Scalar must be of type double.

**Input:** One matrix and one double

**Output:** A matrix scaled by the double value

**Usage/Example:** 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t numRows = 10;
    size_t numCols = 10;
    LinearAlgebra::Matrix A(numRows, numCols, LinearAlgebra::SQR);
    
    LinearAlgebra::Matrix C = A * 5.0;
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for operator*

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::operator*(const double & operand) const
{
    size_t numRow = this->NUM_ROWS;
    size_t numCol = this->NUM_COLS;
    LinearAlgebra::Matrix output(static_cast<int>(numRow), static_cast<int>(numCol), 0.0);

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            output.data[row][col] = this->data[row][col] * operand;
        }
    }

    return output;
}
</pre></code>

**Last Modified:** December/2020


