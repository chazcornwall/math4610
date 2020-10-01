from matplotlib import pyplot as plt
import numpy as np
    
# initialize the exact value of the 2nd derivative of cos()
aval = 2.0
exactVal = -np.cos(aval)
    
# set up the arrays for plotting the log-log plot we need
x = []
y = []
    
# initialize the array for the increment size and error in the finite
# difference approximation
h = []
error = []
    
# append the initial increment with a starting value - in this case, 1.0
h.append(1.0)
    
# compute the difference quotient for the increment value
dfVal = (np.cos(aval + h[0]) - 2.0 * np.cos(aval) + np.cos(aval - h[0])) / (h[0] * h[0])
error.append(np.abs(exactVal - dfVal))
    
# append the log-log point for plotting at the end
x.append(np.log(h[0]))
y.append(np.log(error[0]))

print('The exact derivative value is: ', exactVal)

# set a loop iterator
it = 1
    
# the loop over ndiv increments
ndiv = 44
while it<44:

    # append the next increment of h
    h.append(0.5 * h[it-1])
        
    # compute the numerator and denominator for the difference approximation
    # and compute the approximation from these
    numer = np.cos(aval + h[it]) - 2.0 * np.cos(aval) + np.cos(aval - h[it])
    denom = h[it] * h[it]
    dfVal = numer / denom
    
        
    # compute the error in the approximation
    error.append(np.abs(dfVal - exactVal))

    # print h and error to the terminal
    print('h ={:f} \t e ={:f}'.format(h[it],error[it]))
    
        
    # append the log-log point to the arrays for plotting below
    x.append(np.log(h[it]))
    y.append(np.log(error[it]))
    print('Slope of plot: {:f}'.format((y[it - 1] - y[it]) / (x[it - 1] - x[it])))
        
    # update the loop iterator
    it += 1

# set up a plot for the data generated
plt.title('Error in the Difference Quotient of the Derivative')
plt.xlabel('Increment Values: h')
plt.ylabel('Error in the Approximation')
plt.plot(x, y, label='Log-Log Plot of Error for f^(2)(2.0) when f(x) = cos(x)')
plt.legend()
plt.show()