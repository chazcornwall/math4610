# LinearAlgebra::Matrix LinearAlgebra::Matrix::duplicate() const

**Function Name:**           duplicate

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine creates a copy of the current matrix object.

**Input:** None

**Output:** A M x N matrix where M is the number of rows in A, and N is the number of columns in A.

**Usage/Example:** See below for usage.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t squareSize = 3;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::DIAG); // Initializes A to random values
    LinearAlgebra::Matrix copy = A.duplicate();
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for solve()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::duplicate() const
{
    LinearAlgebra::Matrix output(static_cast<int>(this->NUM_ROWS), static_cast<int>(this->NUM_COLS), 0.0);

    // Allocate space for rows and initialize to zero
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            output.data[row][col] = this->data[row][col];
        }
    }

    return output;
}
</pre></code>

**Last Modified:** November/2020

