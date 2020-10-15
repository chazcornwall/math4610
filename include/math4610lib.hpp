#ifndef MATH4610LIB_
#define MATH4610LIB_
#include <cmath>
// #define TEST_ // Uncomment to run tests in main() functions
namespace MachineEpsilon 
{
    void deps();
    void seps();

    template <typename T>
    void eps();
}

namespace Error 
{
    double abserror(double approx, double num);
    double relerror(double approx, double num);
}
#endif