# Solutions for Tasksheet 5
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_05/pdf/tasksheet_05.pdf) for problem set.

<hr>

**Task 1**
This task has been completed. The image included in Task 3 shows the output of the example function 

**Task 2**
This task has been completed. The image included in Task 3 shows the output of the example function

**Task 3 and Task 4**
![](../test/newtonanalysis_trend.JPG)

The image above shows:
1. The output and current error of Rootfinding::newtonMethod()
2. The output and current error of Rootfinding::secantMethod()
3. The trend lines that match the error reduction rate

The error printed to the console is the log10() of the actual error. The trend data was produced by Regression::linreg(). In this instance, newton's method had an approximate computational convergence rate of 2.49, which is slightly better than quadratic convergence. The secant method's approximate rate of computational convergence was 1.87, which is also slightly better than its mathematical convergence rate of 1.62.

**Task 5**
This task has been completed.

**Task 6**
Rootfinding is a pratical task in field such as science and engineering. Due to the increasing difficulty of finding roots as the order of polynomials increase (no analytical solution exists for 5th order or greater), iteration must be used. Common methods for finding roots are bisection, newton's method, and secant method. The main drawback of newton's method is the necessity of calculating a derivative at every iteration. [http://www.math.niu.edu/~dattab/MATH435.2013/ROOT_FINDING.pdf](http://www.math.niu.edu/~dattab/MATH435.2013/ROOT_FINDING.pdf)
