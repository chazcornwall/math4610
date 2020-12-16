# LinearAlgebra::Matrix LinearAlgebra::Matrix::solveSPP(LinearAlgebra::Matrix & b) const

**Function Name:**           solveSPP

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine will solve a system of linear equations using scaled partial pivoting when performing Gaussain Elimination. This pivoting strategy reduces the possibility of the matrix becoming singular from error accumulation. The system matrix must also be M x M (square).

**Input:** A M x 1 matrix where M is the number of rows in A.

**Output:** A M x 1 matrix where M is the number of rows in A.

**Usage/Example:** An A and b matrix must be created. Values can easily be assigned to A by creating an array for each equation. 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t squareSize = 3;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::SQR); // Initializes A to random values
    LinearAlgebra::Matrix b(squareSize, 1, 1.0);
    
    // The following commented lines show how to initialize each row of A
    // double equation0[3] = {1.0, 5.0, 54.0};
    // double equation1[3] = {2.0, 3.0, 2.0};
    // double equation2[3] = {3.0, 22.0, 63.0};
    
    // A.data[0] = equation0;
    // A.data[1] = equation1;
    // A.data[2] = equation2;
    
    // The following commented lines show how to initialize each value of b
    // double output0[1] = {1.0};
    // double output1[1] = {2.0};
    // double output2[1] = {3.0};
    
    // b.data[0] = output0;
    // b.data[1] = output1;
    // b.data[2] = output2;
   
    LinearAlgebra::Matrix x = A.solveSPP(b);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for solve()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::solveSPP(LinearAlgebra::Matrix & b) const
{
    // Check dimensions of b
    if(b.NUM_ROWS != this->NUM_ROWS || b.NUM_COLS > 1)
    {
        std::cout << "ERROR: b is an invalid size!" << std::endl;
    }

    // In the equation Ax = b, neither A nor b is changed in this function. 
    Matrix bDuplicate = b.duplicate();
    Matrix reduced = reduceRowEchelonSPP(bDuplicate); 
    Matrix x = reduced.backSubstitutionSPP(bDuplicate);
    return x;
}
</pre></code>

**Last Modified:** December/2020


