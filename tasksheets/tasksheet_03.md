# Solutions for Tasksheet 3 
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_03/md/tasksheet_03.md) for problem set.

**Task 1 and Task 2**
From Tasksheet 2, is was shown that the error of the central difference approximation could be expressed as:
<img src="https://render.githubusercontent.com/render/math?math=error \leq Ch^{2}">
Seeing the error decrease at a rate of x^2 is difficult in a linear plot. However, when using a log-log plot, the explonential rate becomes linear. The following property of logarithms illustrates this point.
<img src="https://render.githubusercontent.com/render/math?math=log(h^{2}) = 2log(h)">
Therefore, if the error has a slope of 2 in a log-log plot, the central difference approximation is a second-order approximation. 
[Here](https://github.com/chazcornwall/math4610/blob/master/src/plotting/plotderiv.py) is the python script that shows the error and prints out the slope of the log-log plot.
The resulting plot can be seen below:

![](https://github.com/chazcornwall/math4610/blob/master/src/plotting/Figure.png)

Here is a table showing the first seventeen results of the printed output:

| h        | Error | Slope of log-log plot|
| ------------- |:-------------:| ------|
| 1    |  0.03354 | N/A |
| 0.5     | 0.008598 | 1.963988 |
| 0.25 | 0.002163 | 1.990987 |
| 0.125 | 0.000542 | 1.997746 |
| 0.0625 | 0.000135 | 1.999436 |
| 0.03125 | 0.000034 | 1.999859 |
| 0.015625 | 0.000008 | 1.999965 |
| 0.007812 | 0.000002 | 1.999991 |
| 0.003906 | 0.000001 | 2.000001 |
| 0.001953 | 0.000000 | 1.999997 |
| 0.000977 | 0.000000 | 2.002449 |
| 0.000488 | 0.000000 | 2.047455 |
| 0.000244 | 0.000000 | 2.693262 |
| 0.000122 | 0.000000 | -1.817635 |
| 0.000061 | 0.000000 | -0.892034 |
| 0.000031 | 0.000000 | -2.229332 |
| 0.000015 | 0.000000 | -2.052058 |
| 0.000008 | 0.000001 | -3.102423 |

<hr>

**Task 3**
The source code for the function that prints the single machine precision can be found in [seps.cpp](https://github.com/chazcornwall/math4610/blob/master/src/seps.cpp). The source code for the function that prints the double machine precision can be found in [deps.cpp](https://github.com/chazcornwall/math4610/blob/master/src/deps.cpp). The output of these two functions can be seen in the picture below:

![](https://github.com/chazcornwall/math4610/blob/master/images/task3_libexample.JPG)

<hr>

**Task 4**
The [software manual](https://github.com/chazcornwall/math4610/blob/master/software_manual/README.md) has been created.

<hr>

**Task 5**
The archive can be found [here](https://github.com/chazcornwall/math4610/blob/master/src). The figure in Task 3 shows the archive being used to compile test.cpp.

**Task 6**
Shared libraries can greatly reduce the amount of code needed on a computer by creating one copy of commonly used functions. Higher level applications that need to use these fucntions can then link to the shared library instead of declaring and defining the function again. One disadvantage is the extra time needed to retrieve functions that are located in a shared library. [This site](https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/performance/when_dyn_linking_static_linking.html) provides more details. When working with shared libraries, there is the option of static or dynamic linking. Static linkage is linking the library to an object file during compilation (which is done here in this tasksheet). Dynamic linking is linking the library to an executable during runtime. [See here] (https://en.wikipedia.org/wiki/Static_library).



