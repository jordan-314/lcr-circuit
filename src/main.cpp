#include <iostream>
#include <complex>

#include "interface.hpp"

int main() {
    std::cout << "Welcome to your simple RCL circuit builder." << std::endl;
    Circuit c { generate_circuit() };
    std::cout << "Circuit Impedance = " << c.calculate_impedance() std::endl;
}
