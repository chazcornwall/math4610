# Solutions for Tasksheet 2 
[See here](https://github.com/jvkoebbe/math4610/blob/master/tasksheets/tasksheet_02/pdf/tasksheet_02.pdf) for problem set.

**Task 1**

[See here](https://github.com/chazcornwall/math4610/blob/master/src/tasksheet2/derivativeApprox.cpp) for source code.

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

Since the least power will have the largest effect on the solution and error (i.e. when h is less than one, h squared is much greater than h cubed), this approximation is second order because 2 is the smallest power of h in the approximation.
