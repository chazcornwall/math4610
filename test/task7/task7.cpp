#include "../../include/math4610lib.hpp"
#include <iostream>

int main()
{
    // Task 1
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 1" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    size_t squareSize = 10;
    LinearAlgebra::Matrix A(squareSize, squareSize, LinearAlgebra::UPPR);
    LinearAlgebra::Matrix b(squareSize, 0, 1.0);

    LinearAlgebra::Matrix x = A.solve(b);
    LinearAlgebra::verifySolution(A, x, b);

    // Task 2
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 2" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix A_LR(squareSize, squareSize, LinearAlgebra::LWR);
    A_LR.transpose();
    LinearAlgebra::Matrix x1 = A_LR.solve(b);
    LinearAlgebra::verifySolution(A_LR, x1, b);

    // Task 3
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 3" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    size_t squareSize2 = 7;
    LinearAlgebra::Matrix A_LWR(squareSize2, squareSize2, LinearAlgebra::LWR);
    A_LWR.print();
    LinearAlgebra::Matrix A_UPPR(squareSize2, squareSize2, LinearAlgebra::UPPR);
    A_UPPR.print();
    LinearAlgebra::Matrix A_ALL(squareSize2, squareSize2, LinearAlgebra::SQR);
    A_ALL.print();
    LinearAlgebra::Matrix A_DIAG(squareSize2, squareSize2, LinearAlgebra::DIAG);
    A_DIAG.print();

    // Task 4
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 4" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix x2 = A_DIAG.solve(b);
    LinearAlgebra::verifySolution(A_DIAG, x2, b);

    // Task 5
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 5" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    A_ALL.reduceRowEchelon();
    A_ALL.print();

    return 0;
}