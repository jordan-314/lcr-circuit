/* File contains abstract base class for all components as well as the initial
base class Component which overrides some of the common methods for the future
child component classes.
*/
#ifndef component
#define component

#include <complex>
#include <string>

class VirtualComponent {
    /*Defintion for all virtual compenents to override in
    subsequent classes.
    */

    public:
        virtual ~VirtualComponent() {};

        // Setters and getters
        virtual void set_frequency(double) = 0;
        virtual void set_impedence() = 0;
        virtual void set_series(size_t) = 0;
        virtual double get_reactance() = 0;

        // Standard functions
        virtual double impedence_magnitude() = 0;
        virtual double phase_difference() = 0;
};

class Compenent: public VirtualComponent {
    /* Definition of an abstract component, shall parent each
    unique circuit component later
    */

    protected:
        double frequency, resistance, capacitcance, inductance;
        std::complex<double> impedence;
        size_t series;

    public:
        Compenent() {};
        Compenent(
            double resistance,
            double capacitcance,
            double inductance,
        ) {
            this->resistance {resistance};
            this->capacitcance {capacitcance};
            this->inductance {inductance};
        }

        void set_frequency(double frequency) {
            this->frequency {frequency};
        };

        void set_series(size_t series) {
            this->series = {series};
        }

        double impedence_magnitude() {
            return std::abs(this->impedence);
        }

        double phase_difference() {
            return std::arg(this->impedence);
        }
};


#endif