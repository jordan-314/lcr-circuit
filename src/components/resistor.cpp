/* File contains the non-ideal and ideal resistor classes
*/

#ifndef resistor
#define resistor

#include <compenent.cpp>

#include <string>


class Resistor: public Compenent {
    /*Class models a 'real' resistor, i.e. a non-ideal resistor
    taking into account the capacitance and inductance that would
    be seen in a real world resistor.
    
    args:
        double resistance -> Component resistance
        double capacitance -> Component capacitance
        double inducatnce -> Component inductance
    */

    public:
        Resistor(
            double resistance,
            double capacitance,
            double inductance,
        ): Compenent(resistance, capacitance, inductance) {
            this->set_impedance()
        }

        Resistor() {
            this->resistance {0};
            this->capacitcance {0};
            this->inductance {0};
            this->impedance {0, 0};
        }

        double get_reactance();
        void set_impedance();
};

double Resistor::get_reactance() {
    return this->resistance;
}

void Resistor::set_impedance() {
    /* Calculates the impedance of the resistor from the class fields.

    In the case of an ideal resistor, i.e R != 0, C = 0, L = 0, the following
    shall reduce to z = R + 0i.
    
    Formula:
    R := resistance, C := Capacitance, L := Inductance.
    w (angular frequency) = 2 * pi * f
    
    z (impedance) := Re + i * Im, where:
    i = sqrt(-1)
    Re = R / (1 + (wRC)^2)
    Im = (wL - wC(R^2) + (w^3)(C^2)(R^2)L) / (1+ (wRC^2))
    */

    double omega {2 * pi * this->frequency};
    // Common denomintor for both Re and Im
    double denominator {1 + std::pow(omega * this->resistance * 
        this->capacitance, 2)};
    double real {this->resistance / denominator};

    // Split Im up into three terms
    double term_one {omega * this->inductance};
    double term_two {omega * this->capacitance * std::pow(this->resistance, 2)};
    double term_three {std::pow(omega, 3) * std::pow(this->capacitance, 2) * 
                    std::pow(this->resistance, 2) * this->inductance};

    double imag {(term_one - term_two + term_three) / denominator };
    // set impedance
    this->impedance {real, imag};
}

class IdealResistor: public Resistor {
    /*Class models an ideal resistor, i.e. one that only has a
    resistance component.
    
    args:
        double resistance -> Component resistance
    */

    public:
        IdealResistor(double resistance): Resistor(resistance, 0, 0) {}
        IdealResistor(): Resistor() {}
};

#endif