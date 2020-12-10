# Solutions for Tasksheet 9
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_09/html/tasksheet_09.html) for problem set.

A test program was created to executed all of the tasks described in tasksheet 9. This test program can be found in the test directory [here](../test/task9/task9.cpp). Each task enumerated below will contain an image of a section of the test program's output. All the source code used to implement the Linear Algebra operations are found [here](../src/linsolver.cpp).

See [here](../software_manual/README.md) for documentation of important methods in the `LinearAlgebra::Matrix` class that were used in this tasksheet.

<hr>

**Task 1**

The `LinearAlgebra::Matrix` class supports matrices of all sizes. Therefore, it can also support vectors. In the test code, the vector operation outputs were double-checked. The output below shows the resulting vector or matrix from the operation.

Here is the code that executes the operations (where the vectors are `LinearAlgebra::Matrix` objects):

    LinearAlgebra::Matrix sum = vector1 + vector2;
    LinearAlgebra::Matrix diff = vector1 - vector2;
    LinearAlgebra::Matrix scaled = vector1 * 5.0;
    LinearAlgebra::Matrix dot = vector1 * vector3;
    LinearAlgebra::Matrix outer = vector3.outerProd(vector1);

![](../images/tasksheet9_task1.JPG)

<hr>

**Task 2**

![](../images/tasksheet9_task2.JPG)

<hr>

**Task 3**

![](../images/tasksheet9_task3.JPG)

<hr>

**Task 4**

<hr>

**Task 5**

![](../images/tasksheet9_task5.JPG)

<hr>

**Task 6**
