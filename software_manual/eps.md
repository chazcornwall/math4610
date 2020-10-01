# void eps<T>()

**Function Name:**           deps

**Author:** Chaz Cornwall

**Language:** c++. The code can be compiled using the GNU C++ compiler (g++).

For example,

    g++ eps.cpp

will produce an executable **./a.exe** than can be executed. If you want a different name, the following will work a bit
better

    g++ eps.cpp -o eps.exe

**Description/Purpose:** This function will compute the the precision value for the machine epsilon of a primitive numerical type. This is a function for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** None

**Output:** None

**Usage/Example:**
This function cannot be used from the math4610lib.a archive. It can only be compiled directly. Please use typical C++ template syntax (not shown below due to markdown syntax).

<pre><code> 
#inclde "math4610lib.h" 

using namespace MachineEpsilon;

int main(void)
{
    eps<float>();
}
</pre></code>

Output from the lines above:

<pre><code> 
Machine Precision: 5.96046e-08
Approximate Power: 2^25
</pre></code>

**Implementation/Code:** The following is the code for eps()

<pre><code>
 template <typename T>
void MachineEpsilon::eps()
{
    T reference = 1;
    T epsilon = reference;
    T test = reference + epsilon;
    int power = 1;

    while (test != 1)
    {
        epsilon /= 2.0;
        test = reference + epsilon;
        power++;
    }

    std::cout << "Machine Precision: " << epsilon << std::endl;
    std::cout << "Approxmate Power: 2^" << power << std::endl;
}
</pre></code>

**Last Modified:** October/2020
