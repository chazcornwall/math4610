#include "../include/math4610lib.hpp"
#include <iostream>

double Error::abserror(double approx, double num)
{
    return std::abs(approx - num);
}

#ifdef TEST_
int main()
{
    double approx = 23;
    double num = 57.63;
    std::cout << "Approx: " << num << std::endl;
    std::cout << "Num: " << approx << std::endl;
    std::cout << "Error: " << Error::abserror(approx, num) << std::endl; 
    return 0;
}
#endif

