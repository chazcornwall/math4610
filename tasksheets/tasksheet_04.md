# Solutions for Tasksheet 4
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_04/pdf/tasksheet_04.pdf) for problem set.

<hr>

**Task 1**

This has been completed. The absolute error function can be found [here](https://github.com/chazcornwall/math4610/blob/master/software_manual/abserror.md) in my software manual. The relative error function can be found [here](https://github.com/chazcornwall/math4610/blob/master/software_manual/relerror.md) in my software manual. There is a test executable that executes all of the functions in the library mathlib4610.a. That executable can be found [here](https://github.com/chazcornwall/math4610/blob/master/test).

<hr>

**Task 2**

This has been completed. [Here](https://github.com/chazcornwall/math4610/blob/master/src/plotting/plot.py) is a link for the python code. The entry in my software manual for this function can be found [here](https://github.com/chazcornwall/math4610/blob/master/software_manual/graph.md).
<pre><code>
 import plot as pl

 pl.graph(['x**2','2*x'], 0, 30, 1)
</pre></code>
Below is the image generated from the above python code.

![](https://github.com/chazcornwall/math4610/blob/master/src/plotting/Figure_1.png)

<hr>

**Task 3**

The code for the fixed-point iteration root-finding method has been completed. [Here](https://github.com/chazcornwall/math4610/blob/master/src/fixedpoint.cpp) is a link to the source code, and [here](https://github.com/chazcornwall/math4610/blob/master/software_manual/fixedpoint.md) is a link to the entry in my software manual.

<hr>

**Task 4**

The fixed-point iteration method converges such that
<img src="https://render.githubusercontent.com/render/math?math=|g'(x)| \leq 1"> where

<img src="https://render.githubusercontent.com/render/math?math=g(x) = x - {\varepsilon}f(x)">.

In this problem, 
<img src="https://render.githubusercontent.com/render/math?math=g'(x) = 1 - \varepsilonexp{3x^2} - \varepsilon6x^2exp{3x^2} - 7\varepsilon ">
Setting the absolute error to 0.01 and epsilon to 0.15, the fixed point iteration method converges. When epsilon is 0.15, the returned root is 0.806. When epsilon is 0.1505, the returned root is 0.002.

<hr>

**Task 5**

The code for the bisection root-finding method has been completed. [Here](https://github.com/chazcornwall/math4610/blob/master/src/bisection.cpp) is a link to the source code, and [here](https://github.com/chazcornwall/math4610/blob/master/software_manual/bisection.md) is a link to the entry in my software manual.

<hr>

**Task 6**

Root finding is an area of numerical mathematics that is dedicated to finding the roots, or zeros, of functions. The methods that find these roots are designed to be implemented by a computer processor. Due to this implmentation, an inherent problem with these methods is the inability to use infinite precision. This makes it difficult to find the "exact" root. Many root finding methods leverage specific characteristics of functions, such as continuity or defferentiability. Some methods, such as bisection, must be given a bracket that surrounds a root or it will not converge. Other methods, such as Newton's Method, require the derviative of the function at a point, which can be difficult or time consuming to compute. The following sites were used as refereces: [https://en.wikipedia.org/wiki/Root-finding_algorithms](https://en.wikipedia.org/wiki/Root-finding_algorithms) and [http://www.math.niu.edu/~dattab/math435.2009/ROOT-FINDING.pdf](http://www.math.niu.edu/~dattab/math435.2009/ROOT-FINDING.pdf)
