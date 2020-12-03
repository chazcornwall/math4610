#include "../include/math4610lib.hpp"
#include <iostream>

LinearAlgebra::Matrix::Matrix(const int & numRows, const int & numCols, const double & value, LinearAlgebra::MatrixType type) : NUM_ROWS(static_cast<size_t>(numRows)),
                                                                                                                                NUM_COLS(static_cast<size_t>(numCols))
{
    this->data = new double*[numRows];
    this->swapArray = new size_t[numRows];
    this->scalesSPP = new double[numRows];
    
    // Allocate space for rows and initialize to zero
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        this->data[row] = new double[numCols];
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            switch(type)
            {
                UPPR:
                    if(col > row)
                    {
                        this->data[row][col] = value;
                    }
                    else
                    {
                        this->data[row][col] = 0.0;
                    }
                    break;
                LWR:
                    if(col < row)
                    {
                        this->data[row][col] = value;
                    }
                    else
                    {
                        this->data[row][col] = 0.0;
                    }
                    break;
                DIAG:
                    if(col == row)
                    {
                        this->data[row][col] = value;
                    }
                    else
                    {
                        this->data[row][col] = 0.0;
                    }
                    break;
                default:
                    this->data[row][col] = value;
                    break;
            }
            
        }
    }
}

LinearAlgebra::Matrix::Matrix(const int & numRows, const int & numCols, LinearAlgebra::MatrixType type) : NUM_ROWS(static_cast<size_t>(numRows)),
                                                                                                          NUM_COLS(static_cast<size_t>(numCols))
{
    this->data = new double*[numRows];
    this->swapArray = new size_t[numRows];
    this->scalesSPP = new double[numRows];

    srand(time(NULL)); // Initialize random number generator
    double value;
    
    // Allocate space for rows and initialize to zero
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        this->data[row] = new double[numCols];
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            int32_t randomNum = rand() % 1000 + 1;
            value = static_cast<double>(randomNum);
            switch(type)
            {
                case UPPR:
                    if(col >= row)
                    {
                        this->data[row][col] = value;
                    }
                    else
                    {
                        this->data[row][col] = 0.0;
                    }
                    break;
               case LWR:
                    if(col <= row)
                    {
                        this->data[row][col] = value;
                    }
                    else
                    {
                        this->data[row][col] = 0.0;
                    }
                    break;
                case DIAG:
                    if(col == row)
                    {
                        this->data[row][col] = value;
                    }
                    else
                    {
                        this->data[row][col] = 0.0;
                    }
                    break;
                case HILBERT:
                    this->data[row][col] = 1.0 / static_cast<double>(row + col + 1);
                    break;
                default:
                    this->data[row][col] = value;
                    break;
            }
            
        }
    }
}

LinearAlgebra::Matrix::Matrix(const int & numRows, const int & numCols, const double & value) : NUM_ROWS(static_cast<size_t>(numRows)),
                                                                                                NUM_COLS(static_cast<size_t>(numCols))
{
    this->data = new double*[numRows];
    this->swapArray = new size_t[numRows];
    this->scalesSPP = new double[numRows];
    
    // Allocate space for rows and initialize to zero
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        this->data[row] = new double[numCols];
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            this->data[row][col] = value;
        }
    }
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::duplicate() const
{
    LinearAlgebra::Matrix output(static_cast<int>(this->NUM_ROWS), static_cast<int>(this->NUM_COLS), 0.0);

    // Allocate space for rows and initialize to zero
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            output.data[row][col] = this->data[row][col];
        }
    }

    return output;
}

size_t LinearAlgebra::Matrix::getNumRows() const
{
    return this->NUM_ROWS;
}

size_t LinearAlgebra::Matrix::getNumCols() const
{
    return this->NUM_COLS;
}

void LinearAlgebra::Matrix::loadSwapArray(size_t * const swapArray)
{
    this->swapArray = swapArray;
}

/**********************************************************************************************************************
*SOLVING LINEAR SYSTEM OF EQUATIONS OPERATIONS
***********************************************************************************************************************/

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

// Using Doolittle's algorithm for LU Factorization
// https://www.geeksforgeeks.org/doolittle-algorithm-lu-decomposition/
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

void LinearAlgebra::Matrix::decompLU(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const
{
    this->decompLUPrivate(L, U);
}

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

LinearAlgebra::Matrix LinearAlgebra::Matrix::solveLU(LinearAlgebra::Matrix & b) const
{
    // Check dimensions of b
    if(b.NUM_ROWS != this->NUM_ROWS || b.NUM_COLS > 1)
    {
        std::cout << "ERROR: b is an invalid size!" << std::endl;
    }

    Matrix L(NUM_ROWS, NUM_COLS, 0.0);
    Matrix U(NUM_ROWS, NUM_COLS, 0.0);
    decompLUPrivate(L, U); // LU Factorization (A = LU) -> LUx = b 
    Matrix y = L.forwardSubstitution(b, true); // Ly = b
    Matrix x = U.backSubstitution(y); // Ux = y
    return x;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::solveLUInPlace(LinearAlgebra::Matrix & b)
{
    // Check dimensions of b
    if(b.NUM_ROWS != this->NUM_ROWS || b.NUM_COLS > 1)
    {
        std::cout << "ERROR: b is an invalid size!" << std::endl;
    }

    this->decompLU(); // LU Factorization (A = LU) -> LUx = b 
    Matrix y = this->forwardSubstitution(b, true); // Ly = b
    Matrix x = this->backSubstitution(y); // Ux = y
    return x;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::solve(LinearAlgebra::Matrix & b) const
{
    // Check dimensions of b
    if(b.NUM_ROWS != this->NUM_ROWS || b.NUM_COLS > 1)
    {
        std::cout << "ERROR: b is an invalid size!" << std::endl;
    }

    // In the equation Ax = b, neither A nor b is changed in this function. 
    Matrix bDuplicate = b.duplicate();
    Matrix reduced = reduceRowEchelon(bDuplicate); 
    Matrix x = reduced.backSubstitution(bDuplicate);
    return x;
}

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

LinearAlgebra::Matrix LinearAlgebra::Matrix::solveLWR(LinearAlgebra::Matrix & b, bool diagonalOnes) const
{
    // Check dimensions of b
    if(b.NUM_ROWS != this->NUM_ROWS || b.NUM_COLS > 1)
    {
        std::cout << "ERROR: b is an invalid size!" << std::endl;
    }

    // In the equation Ax = b, neither A nor b is changed in this function.
    Matrix bDuplicate = b.duplicate(); 
    Matrix copy = this->duplicate();
    Matrix x = copy.forwardSubstitution(bDuplicate, diagonalOnes);
    return x;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::solveDIAG(LinearAlgebra::Matrix & b) const
{
    Matrix x(static_cast<int>(NUM_ROWS), 1, 0.0); // NUM_ROWS and NUM_COLS should be equal

    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        if(this->data[row][row] != 0)
        {
            x.data[row][0] = b.data[row][0] / this->data[row][row];
        }
        else
        {
            std::cout << "ERROR: Column vectors are not linearly independent! Offending pivot location: (" << row << ", " << row << ")" << std::endl;
            return x;
        }
    }
    return x;
}

/**********************************************************************************************************************
*MISCELLANEOUS MATRIX OPERATIONS/TESTS
***********************************************************************************************************************/

LinearAlgebra::Matrix LinearAlgebra::Matrix::transpose() const
{
    Matrix output(this->NUM_COLS, this->NUM_ROWS, 0.0);

    for(size_t row = 0; row < this->NUM_ROWS; row++)
    {
        for(size_t col = 0; col < this->NUM_COLS; col++)
        {
            output.data[col][row] = this->data[row][col];
        }
    }

    return output;
}

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

bool LinearAlgebra::verifySolution(const LinearAlgebra::Matrix & A, const LinearAlgebra::Matrix & x, const LinearAlgebra::Matrix & b)
{
    bool testLinearSolver = true;
    for(size_t row = 0; row < A.getNumRows(); row++)
    {
        double sum = 0.0;
        for(size_t col = 0; col < A.getNumCols(); col++)
        {
            sum += A.data[row][col] * x.data[col][0];
        }

        testLinearSolver = (abs(sum - b.data[row][0]) < 0.001);
        if(!testLinearSolver)
        {
            std::cout << "Row " << row << " is not solved by x." << std::endl;
            std::cout << "Sum was " << sum << " , but should be " << b.data[row][0] << std::endl;
        }
    }

    if(testLinearSolver)
    {
        std::cout << "System solved correctly!" << std::endl;
    }

    return testLinearSolver;
}

/**********************************************************************************************************************
*PRINTING MATRIX TO CONSOLE
***********************************************************************************************************************/

void LinearAlgebra::Matrix::print(int minRow, int maxRow, int minCol, int maxCol) const
{
    // Make sure we do not go out of bounds
    if(minRow < 0)
    {
        minRow = 0;
    }
    if(minCol < 0)
    {
        minCol = 0;
    }
    if(maxRow > NUM_ROWS)
    {
        maxRow = static_cast<int>(NUM_ROWS);
    }
    if(maxCol > NUM_COLS)
    {
        maxCol = static_cast<int>(NUM_COLS);
    }

    std::cout << "*************Matrix**************" << std::endl;
    for(size_t row = static_cast<size_t>(minRow); row < static_cast<size_t>(maxRow); row++)
    {
        for(size_t col = static_cast<size_t>(minCol); col < static_cast<size_t>(maxCol); col++)
        {
            std::cout << this->data[row][col] << "\t";
        }
        std::cout << std::endl;
    }
}

void LinearAlgebra::Matrix::print() const
{
    std::cout << "*************Matrix**************" << std::endl;
    for(size_t row = 0; row < NUM_ROWS; row++)
    {
        for(size_t col = 0; col < NUM_COLS; col++)
        {
            std::cout << this->data[row][col] << "\t";
        }
        std::cout << std::endl;
    }
}

/**********************************************************************************************************************
*OPERATOR OVERLOADS
***********************************************************************************************************************/

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator+(const LinearAlgebra::Matrix & operand) const
{
    size_t numRow = operand.getNumRows();
    size_t numCol = operand.getNumCols();
    LinearAlgebra::Matrix output(static_cast<int>(numRow), static_cast<int>(numCol), 0.0, LinearAlgebra::SQR);

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            output.data[row][col] = this->data[row][col] + operand.data[row][col];
        }
    }

    return output;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator+=(const LinearAlgebra::Matrix & operand) const
{
    size_t numRow = this->getNumRows();
    size_t numCol = this->getNumCols();

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            this->data[row][col] = this->data[row][col] + operand.data[row][col];
        }
    }

    return *this;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator*(const double & operand) const
{
    size_t numRow = this->NUM_ROWS;
    size_t numCol = this->NUM_COLS;
    LinearAlgebra::Matrix output(static_cast<int>(numRow), static_cast<int>(numCol), 0.0);

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            output.data[row][col] = this->data[row][col] * operand;
        }
    }

    return output;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator*(const LinearAlgebra::Matrix & operand) const
{
    if(this->NUM_COLS != operand.NUM_ROWS)
    {
        std::cout << "ERROR: Invalid matrix sizes!" << std::endl;
    }
    
    size_t numRow = this->NUM_ROWS;
    size_t numCol = operand.NUM_COLS;
    LinearAlgebra::Matrix output(numRow, numCol, 0.0);

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            double sum = 0.0;
            for(size_t operandRow = 0; operandRow < this->NUM_ROWS; operandRow++)
            {
                sum += this->data[row][operandRow] * operand.data[operandRow][col];
            }
            output.data[row][col] = sum;
        }
    }

    return output;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator-(const LinearAlgebra::Matrix & operand) const
{
    size_t numRow = operand.getNumRows();
    size_t numCol = operand.getNumCols();
    LinearAlgebra::Matrix output(static_cast<int>(numRow), static_cast<int>(numCol), 0.0);

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            output.data[row][col] = this->data[row][col] - operand.data[row][col];
        }
    }

    return output;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator-=(const LinearAlgebra::Matrix & operand) const
{
    size_t numRow = this->getNumRows();
    size_t numCol = this->getNumCols();

    for(size_t row = 0; row < numRow; row++)
    {
        for(size_t col = 0; col < numCol; col++)
        {
            this->data[row][col] = this->data[row][col] - operand.data[row][col];
        }
    }

    return *this;
}

/**********************************************************************************************************************
*TESTING
***********************************************************************************************************************/

#ifdef TEST_
int main()
{
    size_t numRows = 10;
    size_t numCols = 10;
    LinearAlgebra::Matrix A(numRows, numCols, LinearAlgebra::SQR);
    LinearAlgebra::Matrix B(numRows, numCols, 1.0);
    LinearAlgebra::Matrix D(numRows, numCols, 1.0);
    LinearAlgebra::Matrix b(numRows, 1, 1.0);

    std::cout << "Testing for creation of different matrix types..." << std::endl;
    LinearAlgebra::Matrix Random(numRows, numCols, LinearAlgebra::SQR);
    Random.print();
    LinearAlgebra::Matrix Random1(numRows, numCols, LinearAlgebra::DIAG);
    Random1.print();
    LinearAlgebra::Matrix Random2(numRows, numCols, LinearAlgebra::LWR);
    Random2.print();

    LinearAlgebra::Matrix xdf = Random2.solveLWR(b, false);
    LinearAlgebra::verifySolution(Random2, xdf, b);

    LinearAlgebra::Matrix Random3(numRows, numCols, LinearAlgebra::UPPR);
    Random3.print();

    std::cout << "Testing reduction on already-reduced matrix..." << std::endl;
    Random3.reduceRowEchelon();
    Random3.print();

    // Test for "not linearly independent" error message
    std::cout << "Testing for linear dependendence..." << std::endl;
    D.reduceRowEchelon();

    Random.reduceRowEchelon();
    Random.print();

    /*
    double equation0[3] = {1.0, 5.0, 54.0};
    double equation1[3] = {2.0, 3.0, 2.0};
    double equation2[3] = {3.0, 22.0, 63.0};

    A.data[0] = equation0;
    A.data[1] = equation1;
    A.data[2] = equation2;
    */

    std::cout << "Testing transpose operation..." << std::endl;
    LinearAlgebra::Matrix E = A.transpose();
    E.print();

    std::cout << "Testing solution for matrix equation..." << std::endl;
    LinearAlgebra::Matrix x = A.solve(b);

    LinearAlgebra::verifySolution(A, x, b);

    std::cout << "Testing operator overloads..." << std::endl;
    LinearAlgebra::Matrix C = A + B;
    LinearAlgebra::Matrix F = A * 5.0;
    LinearAlgebra::Matrix J = F - A;
    F.print();
    J.print();
    std::cout << C.data[0][0] << std::endl;
    std::cout << A.data[0][0] << std::endl;
    C.print(0, 30, 0, 30);

    std::cout << "Testing LU Factorization..." << std::endl;
    size_t num = 5;
    LinearAlgebra::Matrix Apple(num, num, LinearAlgebra::SQR);
    LinearAlgebra::Matrix L(num, num, 0.0);
    LinearAlgebra::Matrix U(num, num, 0.0);
    Apple.decompLU(L, U);
    Apple.print();
    L.print();
    U.print();

    std::cout << "Testing solving with LU Factorization..." << std::endl;
    LinearAlgebra::Matrix bnew(num, 1, 1.0);
    LinearAlgebra::Matrix Apple2 = Apple.duplicate();
    LinearAlgebra::Matrix outputLU = Apple.solveLUInPlace(bnew);
    LinearAlgebra::verifySolution(Apple2, outputLU, bnew);

    num = 20;
    std::cout << "Testing solving with scaled partial pivoting..." << std::endl;
    LinearAlgebra::Matrix Orange(num, num, LinearAlgebra::SQR);
    LinearAlgebra::Matrix btest(num, 1, 1.0);
    LinearAlgebra::Matrix banana = Orange.solveSPP(btest);
    LinearAlgebra::verifySolution(Orange, banana, btest);

    std::cout << "Testing matrix multiplication..." << std::endl;
    LinearAlgebra::Matrix pomegr(3, 3, 2.0);
    LinearAlgebra::Matrix seed(3, 3, 2.0);
    LinearAlgebra::Matrix result = pomegr * seed;
    result.print();

    return 0;
}
#endif