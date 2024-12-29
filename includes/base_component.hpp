/* File contains abstract base class for all components as well as the initial
base class Component which overrides some of the common methods for the future
child component classes. Contains all trivial method defintions.
*/

#include <complex>
#include <string>
#include <array>

#ifndef component
#define component

class VirtualComponent {
    /*ABC for all components to inherit from.
    */

    public:
        virtual ~VirtualComponent() {};

        // Setters and getters
        virtual std::complex<double> get_impedance() const = 0;

        // Standard functions
        virtual double impedance_magnitude() const = 0;
        virtual double phase_difference() const = 0;
};

class Component: public VirtualComponent {
    /* Definition of an abstract component, shall parent each unique circuit
    component later.
    */

    protected:
        double frequency;
        std::array<double, 3> parameters;
        std::complex<double> impedance;

    public:
        Component() {
            this->frequency = 0;
            std::fill(this->parameters.begin(), this->parameters.end(), 0);
        }

        Component(double f, double r, double c, double l) {
            this->frequency = f;
            this->parameters[0] = r;
            this->parameters[1] = c;
            this->parameters[2] = l;
        }

        Component(double f, std::array<double, 3> v) {
            this->frequency = f;
            this->parameters = v;
        }

        double impedance_magnitude() const {
            return std::abs(this->impedance);
        }

        double phase_difference() const {
            return std::arg(this->impedance);
        }

        std::complex<double> get_impedance() const {
            return this->impedance;
        }
};

#endif