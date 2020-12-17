# LinearAlgebra::Matrix LinearAlgebra::Matrix::reduceRowEchelonSPP(LinearAlgebra::Matrix & b) const

**Function Name:**           reduceRowEchelonSPP

**Namespace:**               LinearAlgebra

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).


**Description/Purpose:** This routine places the current matrix, while also updating the column vector b (Ax = b), into row echelon form using scaled partial pivoting.

**Input:** None.

**Output:** None.

**Usage/Example:** PRIVATE FUNCTION. This page is for reference only.

**Implementation/Code:** The following is the code for reduceRowEchelonSPP()

<pre><code>
 LinearAlgebra::Matrix LinearAlgebra::Matrix::reduceRowEchelonSPP(LinearAlgebra::Matrix & b) const
{
    LinearAlgebra::Matrix output = this->duplicate();

    // Create array of scales
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        double maxAbsValue = 0.0;
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            double tempAbsValue = abs(this->data[row][col]);
            if(tempAbsValue > maxAbsValue)
            {
                maxAbsValue = tempAbsValue;
            }
        }
        scalesSPP[row] = maxAbsValue;
        swapArray[row] = row; // Initialize swap array
    }

    for(size_t pivotRow = 0; pivotRow < NUM_ROWS; pivotRow++) // Do row reduction NUM_ROWS times
    {
        // Find which row has the largest scaled value in the current column
        double maxScale = 0.0; 
        size_t rowToSwap = pivotRow;
        for(size_t row = pivotRow; row < NUM_ROWS; row++)
        {
            double tempScale = abs(data[swapArray[row]][pivotRow]) / scalesSPP[swapArray[row]];
            if(tempScale > maxScale)
            {
                maxScale = tempScale;
                rowToSwap = row;
            }
        }

        // Swap rows with swapArray
        size_t tempRow = swapArray[pivotRow];
        swapArray[pivotRow] = swapArray[rowToSwap];
        swapArray[rowToSwap] = tempRow;

        for(size_t currRow = pivotRow + 1; currRow < NUM_ROWS; currRow++)
        {
            // Select a factor such that row operation R_curr -> R_curr - factor * R_pivot creates a zero in the [currRow][pivotRow] location
            if(output.data[swapArray[pivotRow]][pivotRow] == 0)
            {
                std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << pivotRow << ", " << pivotRow << ")" << std::endl;
                return output;
            }
            double factor = output.data[swapArray[currRow]][pivotRow] / output.data[swapArray[pivotRow]][pivotRow];
            for(size_t currCol = pivotRow + 1; currCol < NUM_COLS; currCol++)
            {
                output.data[swapArray[currRow]][currCol] = output.data[swapArray[currRow]][currCol] - factor * output.data[swapArray[pivotRow]][currCol];
            }

            b.data[swapArray[currRow]][0] = b.data[swapArray[currRow]][0] - factor * b.data[swapArray[pivotRow]][0];
        }
    }
    output.loadSwapArray(this->swapArray); // Load the current swapArray into the matrix that has been row reduced.
    return output;
}
</pre></code>

**Last Modified:** November/2020
