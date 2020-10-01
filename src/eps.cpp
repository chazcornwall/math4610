#include "../include/math4610lib.hpp"
#include <iostream>

using namespace MachineEpsilon;

template <typename T>
void MachineEpsilon::eps()
{
    T reference = 1;
    T epsilon = reference;
    T test = reference + epsilon;
    int power = 1;

    while (test != 1)
    {
        epsilon /= 2.0;
        test = reference + epsilon;
        power++;
    }

    std::cout << "Machine Precision: " << epsilon << std::endl;
    std::cout << "Approxmate Power: 2^" << power << std::endl;
}

#ifdef TEST_
int main(void)
{
    eps<double>();
}
#endif