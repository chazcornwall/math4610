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
            virtual double getDerivOutput(double input) const {return input;};
    };
    double fixedPoint(const Function & function, double x0, double error, double epsilon, int stop);
    double bisection(const Function & function, double reduceconst, double leftbound, double rightbound);
    double newtonsMethod(const Function & function, double x0, double error, double maxiter, bool Debug);
    double secantMethod(const Function & function, double x0, double error, int maxiter, bool Debug);
    double hybridMethod(const Function & function, double x0, double error, double leftbound, double rightbound);
    double * hybridMethodAllRoots(const Function & function, int * numOfRoots, double error, double leftbound, double rightbound, double stepsize);
    double hybridMethodNearestToZero(const Function & function, double error, double leftbound, double rightbound, double stepsize);
    double hybridMethodNearestToZeroSecant(const Function & function, double error, double leftbound, double rightbound, double stepsize);
}

namespace Regression
{
    void linreg(const double * const inputs, double * x, const double * const b, int sizeInputs);
}

namespace LinearAlgebra
{
    enum MatrixType
    {
        UPPR,
        LWR,
        DIAG,
        SQR
    };

    class Matrix
    {
        private:
            const size_t NUM_ROWS;
            const size_t NUM_COLS;
            reduceRowEchelonPrivate() const;
            backSubstitution() const;
        public:
            double ** data;
            Matrix(const int & numRows, const int & numCols, const double & value, MatrixType type);
            Matrix(const int & numRows, const int & numCols, const double & value);
            size_t getNumRows() const;
            size_t getNumCols() const;
            Matrix solve(const LinearAlgebra::Matrix & b) const;
            reduceRowEchelon();
            Matrix operator+(const LinearAlgebra::Matrix & operand) const;
            Matrix operator+=(const LinearAlgebra::Matrix & operand) const;
            void print(int minRow, int maxRow, int minCol, int maxCol) const;
    };

}
#endif