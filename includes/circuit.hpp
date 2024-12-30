/* Defines the circuit class
*/

#include <vector>
#include <complex>

#include "components.hpp"

#ifndef circuit
#define circuit

class Circuit {
    /*Defines a container for the data of all components entered into the
    program.
    */

    private:
        // Order of the following three components must be preserved.
        std::vector<Component> comps;

    public:
        Circuit() {};

        Circuit operator+(const Component &c) {
            this->comps.push_back(c);
            return *this;
        }

        Circuit operator+=(const Component &c) {
            return *this + c;
        }

        std::complex<double> calculate_impedance() const {
            // Calculate the final impedance of the circuit.

            std::complex<double> ret;
            auto it { this->comps.cbegin() };
            for (it; it != this->comps.cend(); it++) {
                    ret += it->get_impedance();
            }
            return ret;
        }
};

#endif