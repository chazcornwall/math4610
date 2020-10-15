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