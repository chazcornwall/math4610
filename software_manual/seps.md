# void seps()

**Routine Name:**           seps

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ seps.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ seps.cpp -o eeps.exe

**Description/Purpose:** This routine will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** None

**Output:** None

**Usage/Example:**

<pre><code> 
#inclde "math4610lib.h" 

int main(void)
{
    seps();
}
</pre></code>

Output from the lines above:

<pre><code> 
Machine Precision: 5.96046e-08
Approximate Power: 2^25
</pre></code>

**Implementation/Code:** The following is the code for smaceps()

<pre><code>
 void MachineEpsilon::seps()
{
    float reference = 1.0;
    float epsilon = 1.0;
    float test = reference + epsilon;
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
