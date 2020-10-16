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

namespace Rootfinding
{
    class Function
    {
        public:
            virtual double getOutput(double input) const {return input;};
    };
    double fixedPoint(const Function & function, double x0, double error, int stop);
    double bisection(const Function & function, double reduceconst, double leftbound, double rightbound);
    double newtonsMethod(const Function & function);
}
#endif