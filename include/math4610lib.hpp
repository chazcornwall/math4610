#ifndef MATH4610LIB_
#define MATH4610LIB_
#include <cmath>
#include <stdlib.h>  
#include <time.h>
#include <memory>
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
        SQR,
        HILBERT,
        SYM,
        ROW,
        COL
    };

    class Matrix
    {
        private:
            const size_t NUM_ROWS;
            const size_t NUM_COLS;
            size_t * swapArray;
            double * scalesSPP;
            Matrix reduceRowEchelon(LinearAlgebra::Matrix & b) const;
            Matrix reduceRowEchelonSPP(LinearAlgebra::Matrix & b) const;
            Matrix backSubstitutionSPP(const LinearAlgebra::Matrix & b);
            Matrix backSubstitution(const LinearAlgebra::Matrix & b) const;
            Matrix forwardSubstitution(const LinearAlgebra::Matrix & b, bool diagonalOnes) const;
            void decompLUPrivate(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const;
        public:
            double ** data;
            Matrix(const int & numRows, const int & numCols, const double & value, MatrixType type);
            Matrix(const int & numRows, const int & numCols, MatrixType type);
            Matrix(const int & numRows, const int & numCols, MatrixType type, const uint32_t & maxValue);
            Matrix(const int & numRows, const int & numCols, const double & value);
            size_t getNumRows() const;
            size_t getNumCols() const;
            void loadSwapArray(size_t * const swapArray);
            Matrix solve(LinearAlgebra::Matrix & b) const;
            Matrix solveSPP(LinearAlgebra::Matrix & b) const;
            Matrix solveLWR(LinearAlgebra::Matrix & b, bool diagonalOnes) const;
            Matrix solveDIAG(LinearAlgebra::Matrix & b) const;
            Matrix solveLU(LinearAlgebra::Matrix & b) const;
            Matrix solveLUInPlace(LinearAlgebra::Matrix & b);
            Matrix solveJacobi(const LinearAlgebra::Matrix & b, const double & tolerance, const size_t & maxIterations) const;
            void decompLU(LinearAlgebra::Matrix & L, LinearAlgebra::Matrix & U) const;
            void decompLU();
            Matrix duplicate() const;
            Matrix transpose() const;
            void reduceRowEchelon();
            double vectorl2Norm() const;
            double vectorl1Norm() const;
            double vectorlInfNorm() const;
            double vectorl2NormError(const LinearAlgebra::Matrix & y) const;
            double vectorl1NormError(const LinearAlgebra::Matrix & y) const;
            double vectorlInfNormError(const LinearAlgebra::Matrix & y) const;
            void print(int minRow, int maxRow, int minCol, int maxCol) const;
            void print() const;
            Matrix operator+(const LinearAlgebra::Matrix & operand) const;
            Matrix operator+=(const LinearAlgebra::Matrix & operand) const;
            Matrix operator-(const LinearAlgebra::Matrix & operand) const;
            Matrix operator-=(const LinearAlgebra::Matrix & operand) const;
            Matrix operator*(const double & operand) const;
            Matrix operator*(const LinearAlgebra::Matrix & operand) const;
            double * operator[](const size_t row) const;
            Matrix outerProd(const LinearAlgebra::Matrix & y) const;
            void update(const LinearAlgebra::Matrix & A);
            void makeDiagDominant(const double & increase);
            ~Matrix();
    };

    bool verifySolution(const LinearAlgebra::Matrix & A, const LinearAlgebra::Matrix & x, const LinearAlgebra::Matrix & b, const double & tolerance);
    Matrix createMatrixFromRowVector(const double * const rowVector, const size_t numRows, LinearAlgebra::MatrixType type);

}
#endif