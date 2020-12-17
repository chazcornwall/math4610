# void LinearAlgebra::Matrix::decompLU(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const

**Function Name:**           decompLU

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine stores the LU factorization of `this` in two matrics L and U, where L and U are inputs to the routine. The system matrix `this` is not changed.

**Input:** A M x N matrix that will hold the lower matrix and an M x N matrix that will hold the upper matrix (M x N are the dimensions of `this`)

**Output:** None

**Usage/Example:** 

<pre><code> 
#include "math4610lib.h" 

int main()
{
    size_t num = 5;
    LinearAlgebra::Matrix A(num, num, LinearAlgebra::SQR);
    LinearAlgebra::Matrix L(num, num, 0.0);
    LinearAlgebra::Matrix U(num, num, 0.0);
    A.decompLU(L, U);
    
    return 0;
}
</pre></code>

If this example was written in a file called "main.cpp", the file could be compiled with the following command:

    g++ main.cpp <path to source>/linsover.cpp -o main.exe

**Implementation/Code:** The following is the code for decompLU()

<pre><code>
 void LinearAlgebra::Matrix::decompLU(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const
{
    this->decompLUPrivate(L, U);
}
</pre></code>

**Last Modified:** December/2020
