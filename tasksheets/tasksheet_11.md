# Solutions for Tasksheet 11
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_11/html/tasksheet_11.html) for problem set.

<hr>

**Task 1**

My computer has 4 cores and 8 logical processors. This means that there are 4 physical cores and each one can handle 2 threads. Therefore, 8 threads can be in operation simultaneously. [This article explains how the number of physical cores does not always match the number of threads that occur.](https://en.wikipedia.org/wiki/Hyper-threading) [See here](../open_mp/openmp.cpp) for my openmp program that prints out the thread numbers.

<hr>

**Task 2**

<hr>

**Task 3**

<hr>

**Task 4**

<hr>

**Task 5**

<hr>

**Task 6**

OpenMP enables shared-memory processing in multithreaded applications. This permits operations to be executed in parallel. ([https://en.wikipedia.org/wiki/OpenMP](https://en.wikipedia.org/wiki/OpenMP))The OpenMP library is used in the MATLAB NaN Toolboox. This toolbox enables the use of signal processing functions/operations when values are missing. GenASIS, an open source
astrophysical simulation tool, also uses OpenMP.([https://www.openmp.org/about/whos-using-openmp/#:~:text=OpenMP%20is%20used%20extensively%20for,distributed%20memory%20versions%20of%20OptiStruct.&text=Mac%20OS%2FX-,FEATURES%20OF%20OPENMP%20USED%3A,%2C%20synchronizations%2C%20scheduling%2C%20reduction%20%E2%80%A6](https://www.openmp.org/about/whos-using-openmp/#:~:text=OpenMP%20is%20used%20extensively%20for,distributed%20memory%20versions%20of%20OptiStruct.&text=Mac%20OS%2FX-,FEATURES%20OF%20OPENMP%20USED%3A,%2C%20synchronizations%2C%20scheduling%2C%20reduction%20%E2%80%A6)). There is also research into how to leverage OpenMP as a messaging system in distributed systems ([https://www.cs.rochester.edu/~cding/Announcements/HIPS07/openmp.pdf](https://www.cs.rochester.edu/~cding/Announcements/HIPS07/openmp.pdf)]. 
