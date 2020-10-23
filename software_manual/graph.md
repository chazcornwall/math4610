# graph(formulas, start, stop, step)

**Function Name:**           graph

**Namespace:**               N/A

**Author:** Chaz Cornwall

**Language:** Python. The code can run using python3 with matplotlib and numpy modules.

For example,

    python3 testplot.py

will produce a plot of the functions in plot.py

**Description/Purpose:** This method will plot a list of functions on the same plot using matplotlib.

**Input:** A function, starting value, ending value, size of step

**Output:** A plot

**Usage/Example:** Ensure ploy.py is in the same directory as testplot.py (or whatever the name of the python file is). Each String in *formulas* is an expression to be 
evaluated by python's eval() function. See this [link](https://realpython.com/python-eval-function/) for more details on eval().

<pre><code> 
import plot as pl

pl.graph(['x**2','2*x'], 0, 30, 1)
</pre></code>

**Implementation/Code:** The following is the code for graph()

<pre><code>
from matplotlib import pyplot as plt
import numpy as np

def graph(formulas, start, stop, step):  
    x = np.arange(start, stop, step)
    ax = plt.subplot(111)  
    for formula in formulas:
        y = eval(formula)
        ax.plot(x, y, label=formula)
    ax.legend()  
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()
</pre></code>

**Last Modified:** October/2020
