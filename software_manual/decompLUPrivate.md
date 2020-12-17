# void LinearAlgebra::Matrix::decompLUPrivate(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const

**Function Name:**           decompLUPrivate

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine stores the LU factorization of `this` in two matrics L and U, where L and U are inputs to the routine. The system matrix `this` is not changed.
Uses Doolittle's Algorithm. [See here for more details](https://www.geeksforgeeks.org/doolittle-algorithm-lu-decomposition/)

**Input:** A M x N matrix that will hold the lower matrix and an M x N matrix that will hold the upper matrix (M x N are the dimensions of `this`)

**Output:** None

**Usage/Example:** PRIVATE FUNCTION.

**Implementation/Code:** The following is the code for decompLUPrivate()

<pre><code>
 void LinearAlgebra::Matrix::decompLUPrivate(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const
{
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        // Solve for Upper triangular matrix
        for(size_t col = row; col < NUM_COLS; col++)
        {
            double sum = 0.0;
            for(size_t rowUpper = 0; rowUpper < row; rowUpper++)
            {
                sum += L.data[row][rowUpper] * U.data[rowUpper][col];
            }
            U.data[row][col] = this->data[row][col] - sum;
        }

        // Solve for Lower triangular matrix
        for(size_t col = row; col < NUM_COLS; col++)
        {
            if (row == col)
            {
                L.data[row][row] = 1.0; // Set diagonal entries to 1
            }
            else
            {
                double sum = 0.0;
                for(size_t rowUpper = 0; rowUpper < row; rowUpper++)
                {
                    sum += L.data[col][rowUpper] * U.data[rowUpper][row];
                }
                L.data[col][row] = (this->data[col][row] - sum) / U.data[row][row];
            }
        }
    }
}
</pre></code>

**Last Modified:** December/2020
