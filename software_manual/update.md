# void LinearAlgebra::Matrix::update(LinearAlgebra::Matrix & A) const

**Function Name:**           update

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine copies the values from one matrix into another

**Input:** A M x N matrix where M x N are the dimensions of `this`.

**Output:** None

**Usage/Example:** 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t squareSize = 10;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::SQR); // Initializes A to random values
    LinearAlgebra::Matrix B(squareSize, squareSize, LinearAlgebra::SQR); // Initializes A to random values
   
    A.update(B);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for update()

<pre><code>
 void LinearAlgebra::Matrix::update(const LinearAlgebra::Matrix & A)
{
    if(A.getNumCols() == this->NUM_COLS && A.getNumRows() == this->NUM_ROWS)
    {   
        for(size_t row = 0; row < NUM_ROWS; row++)
        {
            for(size_t col = 0; col < NUM_COLS; col++)
            {
                this->data[row][col] = A[row][col];
            }
        }
    }
    else
    {
        std::cout << "ERROR: Dimensions do not match!" << std::endl;
    }
}
</pre></code>

**Last Modified:** November/2020
