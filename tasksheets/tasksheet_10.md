# Solutions for Tasksheet 10
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_10/html/tasksheet_10.html) for problem set.

A test program was created to executed all of the tasks described in tasksheet 9. This test program can be found in the test directory [here](../test/task10/task10.cpp). All the source code used to implement the Linear Algebra operations are found [here](../src/linsolver.cpp).

See [here](../software_manual/README.md) for documentation of important methods in the `LinearAlgebra::Matrix` class that were used in this tasksheet.

The image below depicts the output of the test program.

![](../images/tasksheet10.JPG)

<hr>

**Task 1**

The power method was implemented successfully. This method produces an output that has little error (on the order of 10^-3). This error was determined by using the `LinearAlgebra::verifyEigenVector()` method, which takes a calculated eigen vector as inputer and checks if the equation <img src="https://render.githubusercontent.com/render/math?math=Av = \lambda v"> is true.

<hr>

**Task 2**

The inverse power method was implemented successfully; however, there was a nuance that was difficult to resolve. When using the inverse power method, the equation mentioned in Task 2 becomes <img src="https://render.githubusercontent.com/render/math?math=A^{-1}v = frac{1}{\lambda}v">.

<hr>

**Task 3**

<hr>

**Task 4**

<hr>

**Task 5**

<hr>

**Task 6**
