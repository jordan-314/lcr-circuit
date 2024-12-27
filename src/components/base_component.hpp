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
        virtual void set_frequency(double) = 0;
        virtual void set_impedence() = 0;
        virtual void set_series(bool) = 0;
        virtual double get_reactance() = 0;

        // Standard functions
        virtual double impedence_magnitude() = 0;
        virtual double phase_difference() = 0;
};

class Compenent: public VirtualComponent {
    /* Definition of an abstract component, shall parent each unique circuit
    component later.
    */

    protected:
        unsigned double frequency;
        std::array<unsigned double, 3> parameters;
        std::complex<double> impedence;
        bool is_series;

    public:
        Compenent() {
            std::fill(this->parameters.begin(), this->parameters.end(), 0)
        }

        Compenent(double resistance, double capacitcance, double inductance) {
            this->parameters[0] = resistance;
            this->parameters[1] = capacitance;
            this->parameters[2] = inducatnce;
        }

        void set_frequency(unsigned double frequency) {
            this->frequency = frequency;
        }

        void set_series(bool is_series) {
            this->is_series = is_series;
        }

        double impedence_magnitude() {
            return std::abs(this->impedence);
        }

        double phase_difference() {
            return std::arg(this->impedence);
        }
};

#endif