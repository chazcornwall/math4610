#include <math.h>
#include <iostream>
#include <iomanip>
#include "../../include/Derivative.hpp"

using namespace Derivative;

void print(derivativeApprox cosine, double h, double actual);

int main()
{
    double cos_2 = cos(2.0);
    double cos_2_deriv = -sin(2.0);
    double cos_2_2deriv = -cos(2.0);

    double h = 1.0;
    double a_minus_h = cos(2.0 - h);
    double a_plus_h = cos(2.0 + h);
    derivativeApprox cosine = derivativeApprox(h, a_minus_h, cos_2, a_plus_h);
    std::cout << "h" << "\t" << "Approx" << "\t" << "Actual" << "\t" << "Error" << std::endl;
    std::cout << "**********************************************" << std::endl;
    print(cosine, h, cos_2_2deriv);
    h = 0.5;
    print(cosine, h, cos_2_2deriv);
    h = 0.1;
    print(cosine, h, cos_2_2deriv);

    while (h > 0.0000000000000001)
    {
        h /= 10;
        print(cosine, h, cos_2_2deriv);
    }
    return 0;
}

void print(derivativeApprox cosine, double h, double actual)
{
    double a_minus_h = cos(2.0 - h);
    double a_plus_h = cos(2.0 + h);
    cosine.update(h, a_minus_h, a_plus_h);
    double approx = cosine.calculate2ndDerivative();
    std::cout << h << "\t" << std::setprecision(4) << approx << "\t" << actual << "\t" << abs(approx - actual) << std::endl;
}