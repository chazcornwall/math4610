# LinearAlgebra::Matrix LinearAlgebra::Matrix::backSubstitutionSPP(const LinearAlgebra::Matrix & b) const

**Function Name:**           backSubstitutionSPP

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

**Description/Purpose:** This routine returns the matrix (a column vector) that results from solving for the bottom variable and using that variable to find the remaining entries of x, where Ax = b.
The only distinction between this method and the vanilla `LinearAlgebra::Matrix::backSubstitution` method is this method is used after row-reducing with scaled partial pivoting.

**Input:** A M x 1 column vector b (Ax = b)

**Output:** A M x 1 column vector x (Ax = b), where M is the number of rows/columns in `this`

**Usage/Example:** PRIVATE FUNCTION. This page is for reference only.

**Implementation/Code:** The following is the code for backSubstitutionSPP()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::backSubstitutionSPP(const LinearAlgebra::Matrix & b)
{
    Matrix x(static_cast<int>(NUM_ROWS), 1, 0.0); // NUM_ROWS and NUM_COLS should be equal
    
    if(this->data[swapArray[NUM_ROWS - 1]][NUM_COLS - 1] == 0)
    {
        std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << swapArray[NUM_ROWS - 1] << ", " << swapArray[NUM_ROWS - 1] << ")" << std::endl;
        return x;
    }
    
    // Do not use swapArray for x. This makes x correspond with the correct rows of the original matrix A.
    x.data[NUM_ROWS - 1][0] = b.data[swapArray[NUM_ROWS - 1]][0] / this->data[swapArray[NUM_ROWS - 1]][NUM_COLS - 1];
    for(size_t row = NUM_ROWS - 2; row >= 0 && row < NUM_ROWS - 1; row--) // Start at the second to last row
    {
        double sum = 0.0;
        for(size_t col = row + 1; col < NUM_COLS; col++)
        {
            sum += this->data[swapArray[row]][col] * x.data[col][0]; // Calculate sum using results from past iterations
        }
        if(this->data[swapArray[row]][row] == 0)
        {
            std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << swapArray[row] << ", " << swapArray[row] << ")" << std::endl;
            return x;
        }
        x.data[row][0] = (b.data[swapArray[row]][0] - sum) / this->data[swapArray[row]][row];
    }

    return x;
}
</pre></code>

**Last Modified:** December/2020
