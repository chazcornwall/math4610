# LinearAlgebra::Matrix LinearAlgebra::Matrix::forwardSubstitution(const LinearAlgebra::Matrix & b, bool diagonalOnes) const

**Function Name:**           forwardSubstitution

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

**Description/Purpose:** This routine returns the matrix (a column vector) that results from solving for the top variable and using that variable to find the remaining entries of x, where Ax = b.
The system matrix A must be lower triangular.

**Input:** A M x 1 column vector b (Ax = b), An indicator stating whether the diagonal entries are ones or not.

**Output:** A M x 1 column vector x (Ax = b), where M is the number of rows/columns in `this`

**Usage/Example:** PRIVATE FUNCTION. This page is for reference only.

**Implementation/Code:** The following is the code for forwardSubstitution()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::forwardSubstitution(const LinearAlgebra::Matrix & b, bool diagonalOnes) const
{
    Matrix x(static_cast<int>(NUM_ROWS), 1, 0.0); // NUM_ROWS and NUM_COLS should be equal
    
    if(diagonalOnes)
    {
        x.data[0][0] = b.data[0][0] / 1.0; // Values along the diagonal are always 1.0
    }
    else
    {
        x.data[0][0] = b.data[0][0] / this->data[0][0];
    }
    
    for(size_t row = 1; row < NUM_ROWS; row++) // Start at the second to last row
    {
        double sum = 0.0;
        for(size_t col = 0; col < row; col++)
        {
            sum += this->data[row][col] * x.data[col][0]; // Calculate sum using results from past iterations
        }
        
        if(diagonalOnes)
        {
            x.data[row][0] = (b.data[row][0] - sum) / 1.0; // Values along the diagonal are always 1.0
        }
        else
        {
            x.data[row][0] = (b.data[row][0] - sum) / this->data[row][row];
        }
        
    }

    return x;
}
</pre></code>

**Last Modified:** December/2020
