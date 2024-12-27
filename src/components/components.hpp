/* File defines all unique components that are children to Component.
*/

#ifndef components
#define compenents

#include "base_component.hpp"

class Resistor: public Compenent {
    /*Class models a non-ideal resistor.
    
    args:
        unsigned double r -> Component resistance
        unsigned double c -> Component capacitance
        unsigned double l -> Component inductance
    */

    public:
        Resistor() : Compenent() {
            this->set_impedance();
        }

        Resistor(
            unsigned double r,
            unsigned double c,
            unsigned double l,
        ) : Compenent(r, c, l) {
            this->set_impedence();
        }

        double get_reactance() {
            return this->resistance;
        }

        void set_impedance();
};

class Capacitor : public Component {
    /*Class defines a non-ideal capacitor

    args:
        unsigned double r -> Component resistance
        unsigned double c -> Component capacitance
        unsigned double l -> Component inductance
    */
    public:
        Capacitor()  : Compenent() {
            this->set_impedance();
        }

        Capacitor(
            unsigned double r,
            unsigned double c, 
            unsigned double l
        ) : Compenent(r, c, l) {
            this->set_impedance();
        }

        double get_reactance() {
            //TODO get formula.
            return 0.
        }

        void set_impedance();
};

class Inductor : public Component {
    /*Class defines a non-ideal inductor.
    
    args:
        unsigned double r: Components resistance
        unsigned double c: Components capacitance
        unsigned double l: Components inductance
    */

    public:
        Inductor();
        Inductor(
            unsigned double r,
            unsigned double c,
            unsigned double l
        ) : Component(r, c, l) {
            this->set_impedance
        }

        double get_reactance() {
            //TODO get formula.
        }
        
        void set_impedance();
};

#endif compenents