/*File defines both non-ideal and ideal capacitors
*/

#ifndef capacitor
#define capacitor

#include <component.cpp>

class Capacitor : public Component {
    /*Class defines a non-ideal capacitor

    args:
        double resistance -> Component resistance
        double capacitance -> Component capacitance
        double inductance -> Component inductance
    */
    public:
        Capacitor(
            double resistance,
            double capacitance,
            double inductance,
            ) : Compenent(resistance, capacitance, inductance) {
                this->set_impedance();
            };

        Capacitor() {
            this->resistance {0};
            this->capacitcance {0};
            this->inductance {0};
            this->impedance {0, 0};
        }

        double get_reactance();
        void set_impedance() {};
};

double Capacitor::get_reactance() {
    //TODO get formula.
}

void Capacitor::set_impedance() {
    /*Calculate and set impedance for the capcitor.

    For an ideal capacitor this reduces to:
    z = 0 - (wC)^-1

    Formula:
    z = Re + Im * i, where:
    Re = R
    Im = wL - (wC)^(-1)
    */

    double omega {2 * pi * this->frequency};
    double real {this->resistance};
    double imag {omega * this->inducatnce - 1 / (omega * this->capacitance)};

    this->impedance {real, imag};
}

class IdealCapacitor: public Capacitor {
    /*Class defines an ideal capacitor i.e. R = L = 0
    */

    public:
        IdealCapacitor(double capacitance): Capacitor(0, capacitance, 0) {};
        IdealCapacitor(): Capacitor() {};
};

#endif