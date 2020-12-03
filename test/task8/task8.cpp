#include "../../include/math4610lib.hpp"
#include <iostream>

int main()
{
    // Task 1
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 1" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix A(4, 4, 0.0);
    LinearAlgebra::Matrix b(4, 1, 1.0);

    // Create a square, diagonally dominant matrix
    double equation0[4] = {200.0, 5.0, 54.0, 28.0};
    double equation1[4] = {2.0, 250.0, 2.0, 52.0};
    double equation2[4] = {3.0, 22.0, 489.0, 100.0};
    double equation3[4] = {23.0, 672.0, 63.0, 834.0};

    A.data[0] = equation0;
    A.data[1] = equation1;
    A.data[2] = equation2;
    A.data[3] = equation3;

    // Solve system of equations
    LinearAlgebra::Matrix x = A.solve(b);
    std::cout << "Diagonally dominant matrix A" << std::endl;
    A.print();
    std::cout << "Solution to Ax=b (where b is all ones)" << std::endl;
    x.print();
    std::cout << std::endl;
    LinearAlgebra::verifySolution(A, x, b);
    std::cout << std::endl;

    // Task 2
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 2" << std::endl;
    std::cout << "****************************************************" << std::endl;

    LinearAlgebra::Matrix A_LU(10, 10, LinearAlgebra::SQR);
    LinearAlgebra::Matrix A_LU_copy = A_LU.duplicate(); // For verification purposes
    LinearAlgebra::Matrix b_LU(10, 1, 1.0);
    LinearAlgebra::Matrix x_LU = A_LU.solveLUInPlace(b_LU); // A is in LU form now
    std::cout << "A" << std::endl;
    A_LU_copy.print();
    std::cout << "A after in-place LU factorization" << std::endl;
    A_LU.print();
    std::cout << "Solution to Ax=b (where b is all ones)" << std::endl;
    x_LU.print();
    std::cout << std::endl;
    LinearAlgebra::verifySolution(A_LU_copy, x_LU, b_LU);
    std::cout << std::endl;

    // Task 3
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 3" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    for(size_t dim = 4; dim < 11; dim++)
    {
        LinearAlgebra::Matrix A_Hilbert(dim, dim, LinearAlgebra::HILBERT);
        LinearAlgebra::Matrix x_Hilbert(dim, 1, 1.0);
        LinearAlgebra::Matrix b_Hilbert = A_Hilbert * x_Hilbert;
        LinearAlgebra::Matrix x_Hilbert_solved = A_Hilbert.solveLU(b_Hilbert);
        LinearAlgebra::verifySolution(A_Hilbert, x_Hilbert_solved, b_Hilbert);
        std::cout << "Using Hilbert Matrix of size " << dim << std::endl;
        std::cout << "original" << std::endl;
        x_Hilbert.print();
        std::cout << "solved" << std::endl;
        x_Hilbert_solved.print();
    }
    std::cout << std::endl;

    // Task 4
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 4" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix A_SPP(10, 10, LinearAlgebra::SQR);
    LinearAlgebra::Matrix b_SPP(10, 1, 1.0);
    LinearAlgebra::Matrix x_SPP = A_SPP.solveSPP(b_SPP);
    std::cout << "A" << std::endl;
    A_SPP.print();
    std::cout << "Solution to Ax=b (where b is all ones)" << std::endl;
    x_SPP.print();
    std::cout << std::endl;
    LinearAlgebra::verifySolution(A_SPP, x_SPP, b_SPP);
    std::cout << std::endl;

    // Task 5
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 5" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    for(size_t dim = 4; dim < 11; dim++)
    {
        LinearAlgebra::Matrix A_Hilbert(dim, dim, LinearAlgebra::HILBERT);
        LinearAlgebra::Matrix x_Hilbert(dim, 1, 1.0);
        LinearAlgebra::Matrix b_Hilbert = A_Hilbert * x_Hilbert;
        LinearAlgebra::Matrix x_Hilbert_solved = A_Hilbert.solveSPP(b_Hilbert);
        LinearAlgebra::verifySolution(A_Hilbert, x_Hilbert_solved, b_Hilbert);
        std::cout << "Using Hilbert Matrix of size " << dim << std::endl;
        std::cout << "original" << std::endl;
        x_Hilbert.print();
        std::cout << "solved" << std::endl;
        x_Hilbert_solved.print();
    }
    std::cout << std::endl;

    return 0;
}