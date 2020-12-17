# Software Manual Table of Contents

This software manual is for the math4610.a C++ library. The following functions are sorted according to their namespace. All C++ functions documented in this manual can be accessed from the `math4610lib.a` archive by using the following syntax when compiling driver code:

    g++ <name_of_cpp_file> <path>/math4610lib.a -o <name_of_executable>

**MachineEpsilon**

* [void seps()](https://github.com/chazcornwall/math4610/blob/master/software_manual/seps.md)
* [void deps()](https://github.com/chazcornwall/math4610/blob/master/software_manual/deps.md)
* [void eps<T>()](https://github.com/chazcornwall/math4610/blob/master/software_manual/eps.md)
  
**Error**

* [double abserror(double approx, double num)](https://github.com/chazcornwall/math4610/blob/master/software_manual/abserror.md)
* [double relerror(double approx, double num)](https://github.com/chazcornwall/math4610/blob/master/software_manual/relerror.md)

**Rootfinding**

* [double fixedpoint(const Function & function, double x0, double error, double epsilon, double stop)](https://github.com/chazcornwall/math4610/blob/master/software_manual/fixedpoint.md)
* [double bisection(const Function & function, double reduceconst, double leftbound, double rightbound)](https://github.com/chazcornwall/math4610/blob/master/software_manual/bisection.md)
* [double newtonsMethod(const Function & function, double x0, double error, double maxiter, bool Debug)](https://github.com/chazcornwall/math4610/blob/master/software_manual/newton.md)
* [double secantMethod(const Function & function, double x0, double error, double maxiter, bool Debug)](https://github.com/chazcornwall/math4610/blob/master/software_manual/secant.md)
* [double hybridMethod(const Function & function, double x0, double error, double leftbound, double rightbound)](https://github.com/chazcornwall/math4610/blob/master/software_manual/hybrid.md)
* [double hybridMethodNearestToZero(const Function & function, double error, double leftbound, double rightbound, double stepsize)](https://github.com/chazcornwall/math4610/blob/master/software_manual/hybrid0.md)
* [double hybridMethodNearestToZeroSecant(const Function & function, double error, double leftbound, double rightbound, double stepsize)](https://github.com/chazcornwall/math4610/blob/master/software_manual/hybrid0secant.md)
* [double * hybridMethodAllRoots(const Function & function, int * numOfRoots, double error, double leftbound, double rightbound, double stepsize)](https://github.com/chazcornwall/math4610/blob/master/software_manual/hybridAllRoots.md)

**Regression**
* [void linreg(double * inputs, double x0, double error, double leftbound, double rightbound)](https://github.com/chazcornwall/math4610/blob/master/software_manual/hybrid.md)

**LinearAlgebra**
* [Matrix Matrix::solve(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solve.md)
* [Matrix Matrix::solveLWR(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveLWR.md)
* [Matrix Matrix::solveDIAG(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveDIAG.md)
* [Matrix Matrix::solveLU(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveLU.md)
* [Matrix Matrix::solveLUInPlace(LinearAlgebra::Matrix & b)](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveLUInPlace.md)
* [Matrix Matrix::solveSPP(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveSPP.md)
* [Matrix Matrix::duplicate() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/duplicate.md)
* [Matrix Matrix::transpose() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/transpose.md)
* [Matrix Matrix::reduceRowEchelon(LinearAlgebra::Matrix & b)](https://github.com/chazcornwall/math4610/blob/master/software_manual/reduceRowEchelon.md)
* [Matrix Matrix::reduceRowEchelonSPP(LinearAlgebra::Matrix & b)](https://github.com/chazcornwall/math4610/blob/master/software_manual/reduceRowEchelonSPP.md)
* [double Matrix::vectorl1Norm() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/vectorl1Norm.md)
* [double Matrix::vectorl2Norm() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/vectorl2Norm.md)
* [double Matrix::vectorlInfNorm() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/vectorlInfNorm.md)
* [double Matrix::vectorl1NormError(const LinearAlgebra::Matrix & y) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/vectorl1NormError.md)
* [double Matrix::vectorl2NormError(const LinearAlgebra::Matrix & y) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/vectorl2NormError.md)
* [double Matrix::vectorlInfNormError(const LinearAlgebra::Matrix & y) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/vectorlInfNormError.md)
* [Matrix Matrix::operator+(const LinearAlgebra::Matrix & operand) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/operatorPlus.md)
* [Matrix Matrix::operator+=(const LinearAlgebra::Matrix & operand) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/operatorPlusEquals.md)
* [Matrix Matrix::operator-(const LinearAlgebra::Matrix & operand) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/operatorMinus.md)
* [Matrix Matrix::operator-=(const LinearAlgebra::Matrix & operand) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/operatorMinusEquals.md)
* [Matrix Matrix::operator*(const double & operand) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/operatorMultScalar.md)
* [Matrix Matrix::operator*(const LinearAlgebra::Matrix & operand) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/operatorMultMatrix.md)

*Miscellaneous (other programming languages)*

* [graph(formulas, start, stop, step)](https://github.com/chazcornwall/math4610/blob/master/software_manual/graph.md)


