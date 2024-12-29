#include <iostream>
#include <complex>

#include "interface.hpp"

int main() {
    std::cout << "Welcome to your simple RCL circuit builder." << std::endl;

    //TODO fix compiler error?
    Circuit circuit { generate_circuit() };
    std::cout << "Circuit Impedance = " << circuit.calculate_impedance();
}
