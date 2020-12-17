# void LinearAlgebra::Matrix::decompLU() 

**Function Name:**           decompLU

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine will place store the LU factorization of `this` in `this`. This is the function used within `LinearAlgebra::Matrix::solveLUInPlace`.

**Input:** None

**Output:** None

**Usage/Example:** 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t num = 5;
    LinearAlgebra::Matrix A(num, num, LinearAlgebra::SQR);
    A.decompLU();
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for decompLU()

<pre><code>
 void LinearAlgebra::Matrix::decompLU()
{
    for(size_t pivotRow = 0; pivotRow < NUM_ROWS; pivotRow++) // Do row reduction NUM_ROWS times
    {
        for(size_t currRow = pivotRow + 1; currRow < NUM_ROWS; currRow++)
        {
            // Select a factor such that row operation R_curr -> R_curr - factor * R_pivot creates a zero in the [currRow][pivotRow] location
            if(this->data[pivotRow][pivotRow] == 0)
            {
                std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << pivotRow << ", " << pivotRow << ")" << std::endl;
                return;
            }
            double factor = this->data[currRow][pivotRow] / this->data[pivotRow][pivotRow];
            for(size_t currCol = pivotRow + 1; currCol < NUM_COLS; currCol++)
            {
                this->data[currRow][currCol] = this->data[currRow][currCol] - factor * this->data[pivotRow][currCol]; // Create Upper Triangular Matrix
            }
            this->data[currRow][pivotRow] = factor; // Create Lower Triangular Matrix
        }
    }
}
</pre></code>

**Last Modified:** December/2020
