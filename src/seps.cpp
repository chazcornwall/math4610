#include "../include/math4610lib.hpp"
#include <iostream>

using namespace MachineEpsilon;

void MachineEpsilon::seps()
{
    float reference = 1.0;
    float epsilon = 1.0;
    float test = reference + epsilon;
    int power = 1;

    while (test != 1)
    {
        epsilon /= 2.0;
        test = reference + epsilon;
        power++;
    }

    std::cout << "Machine Presision: " << epsilon << std::endl;
    std::cout << "Approxmate Power: 2^" << power << std::endl;
}

#ifdef TEST_
int main(void)
{
    seps();
}
#endif