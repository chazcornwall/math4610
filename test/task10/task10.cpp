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

    LinearAlgebra::Matrix A(100, 100, LinearAlgebra::SYM, 100);
    A.makeDiagDominant(5.0);
    double eigenMax = A.powerMethod(0.001, 1000);
    std::cout << "Largest eigen value of A (100x100, symmetric, diagonally dominant matrix): " << eigenMax << std::endl;
    
    std::cout << std::endl;
    // Task 2
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 2" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    double eigenMin = A.powerMethodInverse(0.001, 1000);
    std::cout << "Smallest eigen value of A (100x100, symmetric, diagonally dominant matrix): " << eigenMin << std::endl;
    
    std::cout << std::endl;
    // Task 3
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 3" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    double l1Norm = A.matrixl1Norm();
    std::cout << "1-matrix norm for A: " << l1Norm << std::endl;
    
    std::cout << std::endl;
    // Task 4
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 4" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    double lInfNorm = A.matrixlInfNorm();
    std::cout << "Inf-matrix norm for A: " << lInfNorm << std::endl;

    std::cout << std::endl;
    // Task 5
    std::cout << "****************************************************" << std::endl;
    std::cout << "TASK 5" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;

    double conditionNum2 = A.getConditionNum(0.001, 1000);
    std::cout << "2-condition number for A: " << conditionNum2 << std::endl;
    
    std::cout << std::endl;
    return 0;
}

