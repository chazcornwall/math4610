# Solutions for Tasksheet 10
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_10/html/tasksheet_10.html) for problem set.

A test program was created to executed all of the tasks described in tasksheet 9. This test program can be found in the test directory [here](../test/task10/task10.cpp). All the source code used to implement the Linear Algebra operations are found [here](../src/linsolver.cpp).

See [here](../software_manual/README.md) for documentation of important methods in the `LinearAlgebra::Matrix` class that were used in this tasksheet.

The image below depicts the output of the test program. The matrix A is a 100x100, symmetric, diagonally dominant, random matrix.

![](../images/tasksheet10.JPG)

<hr>

**Task 1**

The power method was implemented successfully. This method produces an output that has little error (on the order of 10^-3). This error was determined by using the `LinearAlgebra::verifyEigenVector()` method, which takes a calculated eigen vector as inputer and checks if the equation <img src="https://render.githubusercontent.com/render/math?math=Av = \lambda v"> is true.

<hr>

**Task 2**

The inverse power method was implemented successfully; however, there was a nuance that was difficult to resolve. When using the inverse power method, the equation mentioned in Task 2 becomes <img src="https://render.githubusercontent.com/render/math?math=A^{-1}v = \lambda^{-1}v">. The result of the inverse power method is the largest eigen value of the inverse of A. Since the largest eigen value occurs when lambda is at its smallest, lambda is the minimum eigen value of the matrix A. The output of the inverse power method must be inverted.

Despite the similarity with the power method, the inverse power method creates a result that has an error much larger than the error from the power method. This arises 
because noise is introduced into the system when the inverse of A is calculated (or when a linear system of equations is solved).

<hr>

**Task 3**

The 1-matrix norm was easily calculated by finding the l1 norms of the column vectors and selecting the largest l1 norm as the matrix norm.

<hr>

**Task 4**

The Inf-matrix norm was also easily calculated by finding the row with the largest absolute sum and using that sum as the matrix norm.

<hr>

**Task 5**

The 2-condition number was calculated by multiplying the absolute values of the largest eigen value of A and the smallest eigen value of A.

<hr>

**Task 6**

The condition number of a system matrix is used to evaluate the accuracy of a solution to that system matrix. [http://www.cse.iitd.ernet.in/~dheerajb/CS210_lect07.pdf](http://www.cse.iitd.ernet.in/~dheerajb/CS210_lect07.pdf) Round off error is naturally introduced into any computation that is conducted numerically on a computer. An ill-conditioned matrix means that a relatively small change in the input can cause a large change in the output. This behavior does not favor computational linear algebra. A well-conditioned matrix means that a relatively small change in the input usually causes a relatively small change in the output.  [http://faculty.nps.edu/rgera/ma3042/2009/ch7.4.pdf](http://faculty.nps.edu/rgera/ma3042/2009/ch7.4.pdf)

