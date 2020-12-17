# LinearAlgebra::Matrix LinearAlgebra::Matrix::reduceRowEchelon(const LinearAlgebra::Matrix & b)

**Function Name:**           reduceRowEchelon

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ linsolver.cpp 

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ linsolver.cpp -o linsolver.exe

**Description/Purpose:** This routine places the current matrix, while also updating b (Ax = b), into row echelon form.

**Input:** A column vector b with M rows, where M is the number of rows in `this`

**Output:** None.

**Usage/Example:** PRIVATE FUNCTION. This page is for reference only.

**Implementation/Code:** The following is the code for reduceRowEchelon(b)

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::reduceRowEchelon(LinearAlgebra::Matrix & b) const
{
    LinearAlgebra::Matrix output = this->duplicate();

    for(size_t pivotRow = 0; pivotRow < NUM_ROWS; pivotRow++) // Do row reduction NUM_ROWS times
    {
        for(size_t currRow = pivotRow + 1; currRow < NUM_ROWS; currRow++)
        {
            // Select a factor such that row operation R_curr -> R_curr - factor * R_pivot creates a zero in the [currRow][pivotRow] location
            if(output.data[pivotRow][pivotRow] == 0)
            {
                std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << pivotRow << ", " << pivotRow << ")" << std::endl;
                return output;
            }
            double factor = output.data[currRow][pivotRow] / output.data[pivotRow][pivotRow];
            for(size_t currCol = pivotRow + 1; currCol < NUM_COLS; currCol++)
            {
                output.data[currRow][currCol] = output.data[currRow][currCol] - factor * output.data[pivotRow][currCol];
            }

            b.data[currRow][0] = b.data[currRow][0] - factor * b.data[pivotRow][0];
        }
    }

    return output;
}
</pre></code>

**Last Modified:** December/2020
