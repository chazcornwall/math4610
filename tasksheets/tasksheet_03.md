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

