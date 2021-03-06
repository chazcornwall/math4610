# Solutions for Tasksheet 8
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_08/html/tasksheet_08.html) for problem set.

A test program was created to executed all of the tasks described in tasksheet 8. This test program can be found in the test directory [here](../test/task8/task8.cpp). Each task enumerated below will contain an image of a section of the test program's output. All the source code used to implement the Linear Algebra operations are found [here](../src/linsolver.cpp).

See [here](../software_manual/README.md) for documentation of important methods in the `LinearAlgebra::Matrix` class that were used in this tasksheet.

<hr>

**Task 1**

The image below shows the output of using Gaussian Elimination to solve a diagonally dominant square matrix.

![](../images/tasksheet8_task1.JPG)

<hr>

**Task 2**

The image belows shows a system matrix A that was solved using LU factorization. I have two different functions for solving with LU factorization. `solveLU()` can be used on const objects and does not alter the original system matrix A. `solveLUInPlace()` implements the LU factorization within the same memory space as A, so the system matrix A is altered. The example in the image below uses the `solveLUInPlace()` method.

![](../images/tasksheet8_task2.JPG)

<hr>

**Task 3**

For Hilbert matrix of size n=4 to n=8, the original and the solved x matrix were exactly the same (all ones exactly). When n > 9, the numerical errors become noticeable. Most 
of the errors are smaller than 10^-4. This may appear to not be a large error, but when considering matrices with thousands or millions of entries, this small numerical error could quickly increase to the point where the output is garbage.

![](../images/tasksheet8_task3.JPG)

<hr>

**Task 4**

The image below shows an example of using scaled partial pivoting during gaussian elimination. The effects of the method are not noticeable in the example but become evident when comparing the results of Task 3 and Task 5. The method `scaledSPP()` was used.

![](../images/tasksheet8_task4.JPG)

<hr> 

**Task 5**

These two image compare the results of using typical Gaussian elimination with back-substitution without and with a pivoting strategy. Scaled partial pivotting was used in the second image. When n = 9, there are few improvements. When n = 10, some of the errors are decreased by a few thousandths or ten thousandths while other errors are decreased by an order of magnitude. 

![](../images/tasksheet8_task5a.JPG)

![](../images/tasksheet8_task5.JPG)

<hr>

**Task 6**

The Hilbert Matrix is known for being difficult to solve in numerical applications. This class of matrix is ill-conditioned, or has a high condition number ([https://en.wikipedia.org/wiki/Hilbert_matrix](https://en.wikipedia.org/wiki/Hilbert_matrix)). The condition number also increases very rapidly as n increases.([http://www.cs.unc.edu/~dm/UNC/COMP205/LECTURES/LINALG/lec10/node1.html](http://www.cs.unc.edu/~dm/UNC/COMP205/LECTURES/LINALG/lec10/node1.html)). The Hilbert Matrix is often used as a test matrix due to its poor conditioning. However, there are arguments against using the Hilbert Matrix as test matrix. Not only is the Hilbert Matrix poorly conditioned, it is special in a lot of other ways, which make it a poor choice for a test in a general linear solver ([https://nhigham.com/2020/06/30/what-is-the-hilbert-matrix/](https://nhigham.com/2020/06/30/what-is-the-hilbert-matrix/)).
