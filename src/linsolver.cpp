#include "../include/math4610lib.hpp"
#include <iostream>

LinearAlgebra::Matrix::Matrix(const int & numRows, const int & numCols, const double & value, LinearAlgebra::MatrixType type) : NUM_ROWS(static_cast<size_t>(numRows)),
                                                                                                                                NUM_COLS(static_cast<size_t>(numCols))
{
    this->data = new double*[numRows];
    
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
                    break;
                LWR:
                    if(col < row)
                    {
                        this->data[row][col] = value;
                    }
                    break;
                DIAG:
                    if(col == row)
                    {
                        this->data[row][col] = value;
                    }
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

size_t LinearAlgebra::Matrix::getNumRows() const
{
    return this->NUM_ROWS;
}

size_t LinearAlgebra::Matrix::getNumCols() const
{
    return this->NUM_COLS;
}

LinearAlgebra::Matrix LinearAlgebra::Matrix::solve(const LinearAlgebra::Matrix & b) const
{
    size_t numRow = b.getNumRows();
    size_t numCol = 1;
    LinearAlgebra::Matrix output(static_cast<int>(numRow), 1, 0.0);

    return output;
}

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
    for(size_t row = static_cast<size_t>(minRow); row <= static_cast<size_t>(maxRow); row++)
    {
        for(size_t col = static_cast<size_t>(minCol); col < static_cast<size_t>(maxCol); col++)
        {
            std::cout << this->data[row][col] << " ";
        }
        std::cout << std::endl;
    }
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

#ifdef TEST_
int main()
{
    LinearAlgebra::Matrix A(500, 500, 0.0);
    LinearAlgebra::Matrix B(500, 500, 0.0);

    A.data[0][0] = 1.0;
    B.data[0][0] = 1.0;

    LinearAlgebra::Matrix C = A + B;
    A += B;
    std::cout << C.data[0][0] << std::endl;
    std::cout << A.data[0][0] << std::endl;
    A.print(0, 30, 0, 30);

    return 0;
}
#endif