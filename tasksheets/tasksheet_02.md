# Solutions for Tasksheet 2 
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_02/pdf/tasksheet_02.pdf) for problem set.

**Task 1**

[See here](https://github.com/chazcornwall/math4610/blob/master/src/task2/helloworld.cpp) for source code.

**Task 2**

Complete.

**Task 3**

Complete.

**Task 4**

<img src="https://render.githubusercontent.com/render/math?math=f^{'}(a) \approx \frac{f(a%2Bh) - f(a-h)}{2h}">

<img src="https://render.githubusercontent.com/render/math?math=f(a%2Bh) = \sum_{n=0}^{\infty}\frac{f^{(n)}(a)}{n!}(a%2Bh-a)^{n} \approx f(a) %2B f^{'}(a)h %2B \frac{1}{2}f^{''}(a)h^{2}  %2B \frac{1}{6}f^{'''}(a)h^{3} %2B ...">

<img src="https://render.githubusercontent.com/render/math?math=f(a-h) = \sum_{n=0}^{\infty}\frac{f^{(n)}(a)}{n!}(a-h-a)^{n} \approx f(a) - f^{'}(a)h %2B \frac{1}{2}f^{''}(a)h^{2}  - \frac{1}{6}f^{'''}(a)h^{3} %2B ...">

<img src="https://render.githubusercontent.com/render/math?math=f(a%2Bh) - f(a-h) = 2f^{'}(a)h %2B \frac{1}{3}f^{'''}(a)h^{3} %2B ...">

<img src="https://render.githubusercontent.com/render/math?math=\frac{f(a%2Bh) - f(a-h)}{2h} = f^{'}(a) %2B \frac{1}{6}f^{'''}(a)h^{2} %2B ...">

<img src="https://render.githubusercontent.com/render/math?math=e = f^{'}(a) -  \frac{f(a%2Bh) - f(a-h)}{2h}">

<img src="https://render.githubusercontent.com/render/math?math=e = \frac{1}{6}f^{'''}(\xi)h^{2} \leq Ch^{2}">

**Task 5**

<img src="https://render.githubusercontent.com/render/math?math=f^{''}(a) \approx \frac{f(a%2Bh) - 2f(a) %2B f(a-h)}{h^{2}}">

<img src="https://render.githubusercontent.com/render/math?math=f^{''}(a) \approx f^{''}(a) %2B \frac{1}{12}f^{(4)}(a)h^{2} %2B \frac{1}{360}f^{(6)}(a)h^{4} %2B ...">

<img src="https://render.githubusercontent.com/render/math?math=e = f^{''}(a) -  [f^{''}(a) %2B \frac{1}{12}f^{(4)}(a)h^{2} %2B \frac{1}{360}f^{(6)}(a)h^{4} %2B ...]">

<img src="https://render.githubusercontent.com/render/math?math=e = \frac{1}{12}f^{(4)}(\xi)h^{2} \leq Ch^{2}">

Since the least power will have the largest effect on the solution and error (i.e. when h is less than one, h squared is much greater than h cubed), this approximation is second order because 2 is the smallest power of h in the approximation. [See here](https://github.com/chazcornwall/math4610/blob/master/src/task2/derivativeapprox.cpp) for the code that executes this 2nd derivative approximation. 

**Task 6**

[This pdf](https://www.weatherclasses.com/uploads/1/3/1/3/131359169/lectfinitedifference.pdf) describes the derivations for 4th and 6th order finite derivative approximations. The approach used in this document is to use the Taylor Series Expansion of a centered difference approximation to create several different approximations of varying "delta x". For example, as shown in Task 4, the centered difference approximation can be expressed as:

<img src="https://render.githubusercontent.com/render/math?math=\frac{f(a%2Bh) - f(a-h)}{2h} = f^{'}(a) %2B \frac{1}{3!}f^{'''}(a)h^{2} %2B \frac{1}{5!}f^{(5)}(a)h^{4} %2B ...">

<img src="https://render.githubusercontent.com/render/math?math=\frac{f(a%2B2h) - f(a-2h)}{4h} = f^{'}(a) %2B \frac{1}{3!}f^{'''}(a)(2h)^{2} %2B \frac{1}{5!}f^{(5)}(a)(2h)^{4} %2B...">

By multiplying the second order centered difference approximation by 4 and substracting it from the 4h centered approximation

<img src="https://render.githubusercontent.com/render/math?math=\frac{8[f(a%2Bh) - f(a-h)] - [f(a%2B2h) - f(a-2h)]}{4h} = 3f^{'}(a) - \frac{1}{5!}f^{(5)}(a)12(h)^{4} - ...">

Then by multiplying everything by 3, we can see the 4th order difference approximation:

<img src="https://render.githubusercontent.com/render/math?math=\frac{8[f(a%2Bh) - f(a-h)] - [f(a%2B2h) - f(a-2h)]}{12h} = f^{'}(a) - \frac{1}{5!}f^{(5)}(a)4(h)^{4} - ...">

Similar ideas are also expressed in [this paper](https://www.dam.brown.edu/people/alcyew/handouts/numdiff.pdf) also.


