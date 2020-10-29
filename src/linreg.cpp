#include "../include/math4610lib.hpp"
#include <iostream>

void Regression::linreg(double * inputs, double * x, double * b, int sizeInputs)
{
    // Solve the normal equations: A^T*A*x = A^T*b -> x = (A^T*A)^(-1)*A^T*b
    // The vector x is mapped onto the column space of A

    double multAndAccummulateATA = 0.0;
    double multAndAccumulateATb = 0.0;
    double accumulateATA = 0.0;
    double accumulateB = 0.0; 
    for (int i = 0; i < sizeInputs; i++)
    {
        double tempInput = inputs[i];
        double tempB = b[i];

        // Create values for A^T * A (row-ordered)
        multAndAccummulateATA += tempInput * tempInput;
        accumulateATA += tempInput;

        // Create values for A^T * b (row-ordered)
        multAndAccumulateATb += tempB * tempInput;
        accumulateB += tempB;
    }

    /* Create A^T * A 
    1   1   1   1   1   *   1   x1 = A^T * A
    x1  x2  x3  x4  x5      1   x2
                            1   x3
                            1   x4  
                            1   x5  
    */
    double * ATA = new double[4];
    ATA[0] = (double)sizeInputs;
    ATA[1] = accumulateATA;
    ATA[2] = accumulateATA;
    ATA[3] = multAndAccummulateATA;

    /* Create A^T * b
    1   1   1   1   1   *   b1 = A^T * b
    x1  x2  x3  x4  x5      b2
                            b3
                            b4  
                            b5  
    */
    double * ATb = new double[2];
    ATb[0] = accumulateB;
    ATb[1] = multAndAccumulateATb;

    // Create (A^T * A)^(-1)
    double * ATAInv = new double[4];
    double determinant = 1 / (ATA[0] * ATA[3] - ATA[1] * ATA[2]);
    ATAInv[0] = determinant * ATA[3];
    ATAInv[1] = -determinant * ATA[1];
    ATAInv[2] = -determinant * ATA[2];
    ATAInv[3] = determinant * ATA[0];

    // Solve for x = (A^T*A)^(-1)*A^T*b
    x[0] = ATAInv[0] * ATb[0] + ATAInv[1] * ATb[1];
    x[1] = ATAInv[2] * ATb[0] + ATAInv[3] * ATb[1];
}

#ifdef TEST_

int main()
{
    double inputs[5] = {1, 2, 3, 4, 5};
    double y[5] = {23, 22, 23, 24, 25};
    double x[2]; // x[0] is the constant term and x[1] is the rate (y = x[0] + x[1] * input)

    Regression::linreg(inputs, x, y, 5);

    for(int i = 0; i < 2; i++)
    {
        std::cout << "constant" << i << ": " << x[i] << std::endl;
    }

    return 0;
}
#endif