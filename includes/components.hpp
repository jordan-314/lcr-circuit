/* File defines all unique components that are children to Component.
*/

#ifndef components
#define compenents

#include "base_component.hpp"

class Resistor: public Component {
    /*Class models a non-ideal resistor.
    */

    public:
        Resistor() : Component() {
            this->set_impedance();
        }
        Resistor(double f, double r, double c, double l) : Component(f, r, c, l) {
            this->set_impedance();
        }
        Resistor(double f, std::array<double, 3> v) : Component(f, v) {
            this->set_impedance();
        }

        void set_impedance();
};

class Capacitor : public Component {
    /*Class defines a non-ideal capacitor
    */
    public:
        Capacitor() : Component() {
            this->set_impedance();
        }
        Capacitor(double f, double r, double c, double l) : Component(f, r, c, l) {
            this->set_impedance();
        }
        Capacitor(double f, std::array<double, 3> v) : Component(f, v) {
            this->set_impedance();
        }

        void set_impedance();
};

class Inductor : public Component {
    /*Class defines a non-ideal inductor.
    */

    public:
        Inductor() : Component() {
            this->set_impedance();
        }
        Inductor(double f, double r, double c, double l) : Component(f, r, c, l) {
            this->set_impedance();
        }
        Inductor(double f, std::array<double, 3> v) : Component(f, v) {
            this->set_impedance();
        }
        
        void set_impedance();
};

#endif