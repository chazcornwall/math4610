# void LinearAlgebra::Matrix::reduceRowEchelon()

**Function Name:**           reduceRowEchelon

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine places the current matrix into row echelon form.

**Input:** None.

**Output:** None.

**Usage/Example:** Call the function from the object that needs to be row reduced.

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t squareSize = 3;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::SQR); // Initializes A to random values
    A.reduceRowEchelon();
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for solve()

<pre><code>
 void LinearAlgebra::Matrix::reduceRowEchelon()
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
            this->data[currRow][pivotRow] = 0.0;
            for(size_t currCol = pivotRow + 1; currCol < NUM_COLS; currCol++)
            {
                this->data[currRow][currCol] = this->data[currRow][currCol] - factor * this->data[pivotRow][currCol];
            }
        }
    }
}
</pre></code>

**Last Modified:** November/2020
