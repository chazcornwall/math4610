# Solutions for Tasksheet 3 
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_03/md/tasksheet_03.md) for problem set.

**Task 1**
From Tasksheet 2, is was shown that the error of the central difference approximation could be expressed as:
<img src="https://render.githubusercontent.com/render/math?math=error \leq Ch^{2}">
Seeing the error decrease at a rate of x^2 is difficult in a linear plot. However, when using a log-log plot, the explonential rate becomes linear. The following property of logarithms illustrates this point.
<img src="https://render.githubusercontent.com/render/math?math=log(h^{2}) = 2log(h)">
Therefore, if the error has a slope of 2 in a log-log plot, the central difference approximation is a second-order approximation. 
[Here](https://github.com/chazcornwall/math4610/blob/master/src/plotting/plotderiv.py) is the python script that shows the error and prints out the slope of the log-log plot.
