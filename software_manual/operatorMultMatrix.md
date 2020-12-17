# LinearAlgebra::Matrix LinearAlgebra::Matrix::operator*(const LinearAlgebra::Matrix & operand) const

**Function Name:**           N/A (operator overload)

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This operator overload allows the user to multiply two matrics using the "*" binary operator. If the matrices are a row and column vector with the same number of entries, respectively, the
output will represent the dot product (even through the output type will still be `LinearAlgebra::Matrix`).

**Input:** Two matrices where the number of columns in the first matrix must equal the number of rows in the second matrix

**Output:** A matrix representing the matrix multiplication

**Usage/Example:** 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t numRows = 10;
    size_t numCols = 10;
    LinearAlgebra::Matrix A(numRows, numCols, LinearAlgebra::SQR);
    LinearAlgebra::Matrix B(numRows, numCols, LinearAlgebra::SQR);
    
    LinearAlgebra::Matrix C = A * B;
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for operator*

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::operator*(const LinearAlgebra::Matrix & operand) const
{
    if(this->NUM_COLS != operand.NUM_ROWS)
    {
        std::cout << "ERROR: Invalid matrix sizes!" << std::endl;
    }
    
    size_t numRow = this->NUM_ROWS;
    size_t numCol = operand.NUM_COLS;
    LinearAlgebra::Matrix output(numRow, numCol, 0.0);

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            double sum = 0.0;
            for(size_t operandRow = 0; operandRow < this->NUM_COLS; operandRow++)
            {
                sum += this->data[row][operandRow] * operand.data[operandRow][col];
            }
            output.data[row][col] = sum;
        }
    }

    return output;
}
</pre></code>

**Last Modified:** December/2020


