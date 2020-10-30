#include "../include/math4610lib.hpp"
#include <iostream>

class NewFunction : public Rootfinding::Function
{
    public:
        NewFunction(){}; 
        double getOutput(double input) const {return input * exp(3 * input * input) - 7 * input;};
        double getDerivOutput(double input) const {return exp(3 * input *  input) * (6 * input * input + 1) - 7;};
};

int main()
{
    NewFunction function = NewFunction();
    double x0 = 2.0;
    std::cout << "Function: xexp(3x^2) - 7x" << std::endl;
    std::cout << "x0: " << x0 << std::endl;
    std::cout << "Root (Newton Method): " << Rootfinding::newtonsMethod(function, x0, 0.01, 1000, true) << std::endl;
    std::cout << "Root (Secant Method): " << Rootfinding::secantMethod(function, x0, 0.01, 1000, true) << std::endl;
    // zero at 0.8055 
    double newtonInputs[12] = {-1.087,
                               -1.0633, 
                               -1.04461, 
                               -1.02456,
                               -1.00327, 
                               -0.981335, 
                               -0.960558, 
                               -0.945529,
                               -0.946943, 
                               -0.988299, 
                               -1.11976, 
                               -1.44828};
    double newtonOutputs[12] = {-1.0633, 
                                -1.04461, 
                                -1.02456,
                                -1.00327, 
                                -0.981335, 
                                -0.960558, 
                                -0.945529,
                                -0.946943, 
                                -0.988299, 
                                -1.11976, 
                                -1.44828,
                                -2.1894};
    double secantInputs[18] = {-1.33709,
                            -1.20175,
                            -1.2339,
                            -1.20344,
                            -1.19663,
                            -1.17984,
                            -1.16607,
                            -1.1505,
                            -1.13546,
                            -1.12102,
                            -1.10901,
                            -1.10212,
                            -1.10534,
                            -1.12717,
                            -1.18216,
                            -1.2953,
                            -1.51042,
                            -1.90352};
    
    double secantOutputs[18] = {-1.20175,
                            -1.2339,
                            -1.20344,
                            -1.19663,
                            -1.17984,
                            -1.16607,
                            -1.1505,
                            -1.13546,
                            -1.12102,
                            -1.10901,
                            -1.10212,
                            -1.10534,
                            -1.12717,
                            -1.18216,
                            -1.2953,
                            -1.51042,
                            -1.90352,
                            -2.59763};
    double newtonX[2];
    double secantX[2]; 
    Regression::linreg(newtonInputs, newtonX, newtonOutputs, 12);
    Regression::linreg(secantInputs, secantX, secantOutputs, 18);

    std::cout << "Trend of newton method: y = " << newtonX[1] << "x + " << newtonX[0] << std::endl;
    std::cout << "Trend of secant method: y = " << secantX[1] << "x + " << secantX[0] << std::endl; 
    return 0;
}