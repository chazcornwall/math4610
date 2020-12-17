# LinearAlgebra::Matrix LinearAlgebra::Matrix::backSubstitution(const LinearAlgebra::Matrix & b) const

**Function Name:**           backSubstitution

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

**Description/Purpose:** This routine returns the matrix (a column vector) that results from solving for the bottom variable and using that variable to find the remaining entries of x, where Ax = b.

**Input:** A M x 1 column vector b (Ax = b)

**Output:** A M x 1 column vector x (Ax = b), where M is the number of rows/columns in `this`

**Usage/Example:** PRIVATE FUNCTION. This page is for reference only.

**Implementation/Code:** The following is the code for backSubstitution()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::backSubstitution(const LinearAlgebra::Matrix & b) const
{
    Matrix x(static_cast<int>(NUM_ROWS), 1, 0.0); // NUM_ROWS and NUM_COLS should be equal
    
    if(this->data[NUM_ROWS - 1][NUM_COLS - 1] == 0)
    {
        std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << NUM_ROWS - 1 << ", " << NUM_ROWS - 1 << ")" << std::endl;
        return x;
    }
    x.data[x.NUM_ROWS - 1][0] = b.data[b.NUM_ROWS - 1][0] / this->data[NUM_ROWS - 1][NUM_COLS - 1];
    for(size_t row = NUM_ROWS - 2; row >= 0 && row < NUM_ROWS - 1; row--) // Start at the second to last row
    {
        double sum = 0.0;
        for(size_t col = row + 1; col < NUM_COLS; col++)
        {
            sum += this->data[row][col] * x.data[col][0]; // Calculate sum using results from past iterations
        }
        if(this->data[row][row] == 0)
        {
            std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << row << ", " << row << ")" << std::endl;
            return x;
        }
        x.data[row][0] = (b.data[row][0] - sum) / this->data[row][row];
    }

    return x;
}
</pre></code>

**Last Modified:** December/2020
