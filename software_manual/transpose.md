# LinearAlgebra::Matrix LinearAlgebra::Matrix::transpose() const

**Function Name:**           transpose

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine returns the transpose of the current matrix object.

**Input:** None.

**Output:** An N x M matrix where N is the number of columns of A and M is the number of rows of A.

**Usage/Example:** See below for usage.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t squareSize = 3;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::LWR); // Initializes A to random values
    LinearAlgebra::Matrix A_transpose = A.transpose();
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for solve()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::transpose() const
{
    Matrix output(this->NUM_COLS, this->NUM_ROWS, 0.0);

    for(size_t row = 0; row < this->NUM_ROWS; row++)
    {
        for(size_t col = 0; col < this->NUM_COLS; col++)
        {
            output.data[col][row] = this->data[row][col];
        }
    }

    return output;
}
</pre></code>

**Last Modified:** November/2020
