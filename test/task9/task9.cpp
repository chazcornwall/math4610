#include "../../include/math4610lib.hpp"
#include <iostream>

void print(const double & value)
{
    std::cout << value << std::endl;
}

int main()
{
    // Task 1
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 1" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    double v[5] = {5, 20, 34, 65, -72};

    // Create vectors (Row or Column vectors)
    LinearAlgebra::Matrix vector1 = LinearAlgebra::createMatrixFromRowVector(v, 5, LinearAlgebra::ROW);
    LinearAlgebra::Matrix vector2 = LinearAlgebra::createMatrixFromRowVector(v, 5, LinearAlgebra::ROW);
    LinearAlgebra::Matrix vector3 = LinearAlgebra::createMatrixFromRowVector(v, 5, LinearAlgebra::COL);

    LinearAlgebra::Matrix sum = vector1 + vector2;
    LinearAlgebra::Matrix diff = vector1 - vector2;
    LinearAlgebra::Matrix scaled = vector1 * 5.0;
    LinearAlgebra::Matrix dot = vector1 * vector3;
    LinearAlgebra::Matrix outer = vector3.outerProd(vector1);

    bool correctAdd, correctSub, correctScale, correctDot, correctOuter;
    correctAdd = true;
    correctSub = true;
    correctScale = true;
    correctDot = true;
    correctOuter = true;
    double dotSum = 0.0;
    for(size_t col = 0; col < vector1.getNumCols(); col++)
    {
        if(sum[0][col] != vector1[0][col] + vector2[0][col])
        {
            correctAdd = false;
        }

        if(diff[0][col] != vector1[0][col] - vector2[0][col])
        {
            correctSub = false;
        }

        if(scaled[0][col] != vector1[0][col] * 5.0)
        {
            correctScale = false;
        }
        
        dotSum += vector1[0][col] * vector3[col][0];
        if(col == vector1.getNumCols() - 1 && dotSum != dot[0][0])
        {
            correctDot = false;
        }

        for(size_t row = 0; row < vector3.getNumRows(); row++)
        {
            if(outer[row][col] != vector3[col][0] * vector1[0][row])
            {
                correctOuter = false;
            }
        }
    }

    vector1.print();
    if(correctAdd)
    {
        sum.print();
        std::cout << "Vector add is correct!" << std::endl;
    }
    if(correctSub)
    {
        diff.print();
        std::cout << "Vector sub is correct!" << std::endl;
    }
    if(correctScale)
    {
        scaled.print();
        std::cout << "Vector scalar multiplication is correct!" << std::endl;
    }
    if(correctDot)
    {
        dot.print();
        std::cout << "Dot product is correct!" << std::endl;
    }
    if(correctOuter)
    {
        outer.print();
        std::cout << "Outer product is correct!" << std::endl;
    }
    
    std::cout << std::endl;
    // Task 2
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 2" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    double v1[5] = {23, 5, 10, -23, 62};
    double v2[5] = {23, 6, 10, -19, 65};

    LinearAlgebra::Matrix vector1Task2 = LinearAlgebra::createMatrixFromRowVector(v1, 5, LinearAlgebra::ROW);
    LinearAlgebra::Matrix vector2Task2 = LinearAlgebra::createMatrixFromRowVector(v2, 5, LinearAlgebra::ROW);

    std::cout << "vector1" << std::endl;
    vector1Task2.print();
    std::cout << "vector2" << std::endl;
    vector2Task2.print();

    std::cout << std::endl;

    double l1norm = vector1Task2.vectorl1Norm();
    double l2norm = vector1Task2.vectorl2Norm();
    double linfnorm = vector1Task2.vectorlInfNorm();

    std::cout << "L1norm: "; print(l1norm);
    std::cout << "L2norm: "; print(l2norm);
    std::cout << "LInfnorm: "; print(linfnorm);
    

    double l1error = vector1Task2.vectorl1NormError(vector2Task2);
    double l2error = vector1Task2.vectorl2NormError(vector2Task2);
    double linferror = vector1Task2.vectorlInfNormError(vector2Task2);

    std::cout << "L1norm error: "; print(l1error);
    std::cout << "L2norm error: "; print(l2error);
    std::cout << "LInfnorm error: "; print(linferror);
    
    std::cout << std::endl;
    // Task 3
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 3" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix A(5, 5, LinearAlgebra::SQR, 10); // Create a 10x10 matrix A with random values up to 100
    LinearAlgebra::Matrix B(5, 5, LinearAlgebra::SQR, 10);
    LinearAlgebra::Matrix x(5, 1, LinearAlgebra::SQR, 10);

    LinearAlgebra::Matrix sumMatrix = A + B;
    LinearAlgebra::Matrix diffMatrix = A - B;
    LinearAlgebra::Matrix scaleMatrix = A * 5.0;
    LinearAlgebra::Matrix transpose = A.transpose();
    LinearAlgebra::Matrix prodVectMat = A * x;
    LinearAlgebra::Matrix prod = A * B;

    correctAdd = true;
    correctSub = true;
    correctScale = true;
    bool correctTranspose = true;
    bool correctVectMatProd = true;
    bool correctProd = true;
    for(size_t row = 0; row < A.getNumRows(); row++)
    {
        double sumCol = 0.0;
        for(size_t col = 0; col < A.getNumCols(); col++)
        {
            if(sumMatrix[row][col] != A[row][col] + B[row][col])
            {
                correctAdd = false;
            }
            if(diffMatrix[row][col] != A[row][col] - B[row][col])
            {
                correctSub = false;
            }
            if(scaleMatrix[row][col] != A[row][col] * 5.0)
            {
                correctScale = false;
            }
            if(transpose[row][col] != A[col][row])
            {
                correctTranspose = false;
            }
            
            sumCol += A[row][col] * x[col][0];

            double sum = 0.0;
            for(size_t operandRow = 0; operandRow < B.getNumRows(); operandRow++)
            {
                sum += A[row][operandRow] * B[operandRow][col];
            }
            if(prod[row][col] != sum)
            {
                correctProd = false;
            }
        }
        if(prodVectMat[row][0] != sumCol)
        {
            correctVectMatProd = false;
        }
    }

    if(correctAdd)
    {
        sumMatrix.print();
        std::cout << "Matrix add is correct!" << std::endl;
    }
    if(correctSub)
    {
        diffMatrix.print();
        std::cout << "Matrix sub is correct!" << std::endl;
    }
    if(correctScale)
    {
        scaleMatrix.print();
        std::cout << "Matrix scalar multiplication is correct!" << std::endl;
    }
    if(correctTranspose)
    {
        transpose.print();
        std::cout << "Transpose is correct!" << std::endl;
    }
    if(correctVectMatProd)
    {
        prodVectMat.print();
        std::cout << "Vector-Matrix product is correct!" << std::endl;
    }
    if(correctProd)
    {
        prod.print();
        std::cout << "Matrix product is correct!" << std::endl;
    }
    
    std::cout << std::endl;
    // Task 4 and Task 5
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 4 and TASK 5" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix Ajacobi(100, 100, LinearAlgebra::SYM, 100);
    Ajacobi.makeDiagDominant(20.0);
    LinearAlgebra::Matrix xtest(100, 1, 1.0); // Make a test vector of ones;
    LinearAlgebra::Matrix bjacobi = Ajacobi * xtest;

    LinearAlgebra::Matrix xjacobi = Ajacobi.solveJacobi(bjacobi, 0.001, 100);
    LinearAlgebra::Matrix xgauss = Ajacobi.solve(bjacobi);

    double errorJacobi = xtest.vectorl2NormError(xjacobi);
    std::cout << "l2 error for Jacobi iteration: "; print(errorJacobi);

    double errorGauss = xtest.vectorl2NormError(xgauss);
    std::cout << "l2 error for Gaussain Elimination: "; print(errorGauss);
    
    std::cout << std::endl;
    return 0;
}

