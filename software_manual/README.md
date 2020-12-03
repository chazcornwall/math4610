# Software Manual Table of Contents

This software manual is for the math4610.a C++ library. The following functions are sorted according to their namespace.

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
* [Matrix solve(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solve.md)
* [Matrix solveLWR(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveLWR.md)
* [Matrix solveDIAG(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveDIAG.md)
* [Matrix solveLU(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveLU.md)
* [Matrix solveLUInPlace(LinearAlgebra::Matrix & b)](https://github.com/chazcornwall/math4610/blob/master/software_manual/solveLUInPlace.md)
* [Matrix solveSPP(LinearAlgebra::Matrix & b) const](https://github.com/chazcornwall/math4610/blob/master/software_manual/solvePP.md)
* [Matrix duplicate() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/duplicate.md)
* [Matrix transpose() const](https://github.com/chazcornwall/math4610/blob/master/software_manual/transpose.md)
* [void reduceRowEchelon()](https://github.com/chazcornwall/math4610/blob/master/software_manual/reduceRowEchelon.md)

*Miscellaneous (other programming languages)*

* [graph(formulas, start, stop, step)](https://github.com/chazcornwall/math4610/blob/master/software_manual/graph.md)


