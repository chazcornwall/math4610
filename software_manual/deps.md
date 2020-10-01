# void deps()

**Function Name:**           deps

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ deps.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ deps.cpp -o deps.exe

**Description/Purpose:** This function will compute the double precision value for the machine epsilon or the number of digits
in the representation of real numbers in double precision. This is a function for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** None

**Output:** None

**Usage/Example:**

<pre><code> 
#inclde "math4610lib.h" 

using namespace MachineEpsilon;

int main(void)
{
    deps();
}
</pre></code>

Output from the lines above:

<pre><code> 
Machine Precision: 1.11022e-16
Approximate Power: 2^54
</pre></code>

**Implementation/Code:** The following is the code for deps()

<pre><code>
 void MachineEpsilon::deps()
{
    double reference = 1.0;
    double epsilon = 1.0;
    double test = reference + epsilon;
    int power = 1;

    while (test != 1)
    {
        epsilon /= 2.0;
        test = reference + epsilon;
        power++;
    }

    std::cout << "Machine Presision: " << epsilon << std::endl;
    std::cout << "Approxmate Power: 2^" << power << std::endl;
}
</pre></code>

**Last Modified:** October/2020
