#ifndef DERIVATIVE
#define DERIVATIVE

namespace Derivative
{
    class derivativeApprox
    {
        public:
            derivativeApprox(double h, double minus_h, double a, double plus_h)
            {
                this->h = h;
                this->function_at_a = a;
                this->function_at_a_plus_h = plus_h;
                this->function_at_a_minus_h = minus_h;
            }

            void update(double h, double minus_h, double plus_h)
            {
                this->h = h;
                this->function_at_a_plus_h = plus_h;
                this->function_at_a_minus_h = minus_h;
            }

            double calculateDerivativeDiffQuo()
            {
                return (function_at_a_plus_h - function_at_a_minus_h) / (2.0 * h);
            }

            double calculateDerivativeSymDiffQuo()
            {
                return (function_at_a_plus_h - function_at_a) / h;
            }
        
            double calculate2ndDerivative()
            {
                return (function_at_a_plus_h - 2.0 * function_at_a + function_at_a_minus_h) / (h * h);
            }

        private: 
            double h;
            double function_at_a;
            double function_at_a_plus_h;
            double function_at_a_minus_h;
    };  
}

#endif