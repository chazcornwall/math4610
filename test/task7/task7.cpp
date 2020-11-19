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
    std::cout << "A" << std::endl;
    A.print();
    std::cout << std::endl;
    LinearAlgebra::Matrix b(squareSize, 1, 1.0);
    std::cout << "b" << std::endl;
    b.print();

    LinearAlgebra::Matrix x = A.solve(b);
    std::cout << std::endl;
    std::cout << "x" << std::endl;
    x.print();
    LinearAlgebra::verifySolution(A, x, b);

    // Task 2
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 2" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    LinearAlgebra::Matrix A_LR(squareSize, squareSize, LinearAlgebra::LWR);
    std::cout << "A" << std::endl;
    A_LR.print();
    std::cout << std::endl;
    std::cout << "b" << std::endl;
    b.print();
    LinearAlgebra::Matrix x1 = A_LR.solveLWR(b);
    std::cout << std::endl;
    std::cout << "x" << std::endl;
    x1.print();
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

    std::cout << "A" << std::endl;
    A_DIAG.print();
    std::cout << std::endl;
    std::cout << "b" << std::endl;
    b.print();
    LinearAlgebra::Matrix x2 = A_DIAG.solveDIAG(b);
    std::cout << "x" << std::endl;
    x2.print();

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