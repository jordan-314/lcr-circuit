/* Defines the circuit class
*/

#include <vector>
#include <complex>

#include "../components/components.hpp"

#ifndef circuit
#define circuit

class Circuit {
    /*Defines a container for the data of all components entered into the
    program.
    */

    private:
        // Order of the following three components must be preserved.
        std::vector<std::string> components;
        std::vector<std::complex<double>> impedances;
        std::vector<bool> is_series;

    public:
        Circuit() {};

        Circuit operator+(Component const& component);
        Circuit operator+=(Compenent const& component);

        void calculate_impedance();
};

#endif circuit