/*File defines non-ideal and ideal inductors.
*/

#ifndef inductor
#define inductor

#include <component.cpp>

class Inductor : public Component {
    /*Class defines a non-ideal inductor.
    
    args:
        double resistance: Components resistance
        double capacitance: Components capacitance
        double inductance: Components inductance
    */

    public:
        Inductor(
            double resistance,
            double capacitance,
            double inductance,
            ) : Component(resistance, capacitance, inductance) {
                this->set_impedance();
            };

        Inductor() {
            this->resistance {0};
            this->capacitcance {0};
            this->inductance {0};
            this->impedance {0, 0};
        }

        void set_impedance();
};

void Inductor::set_impedance() {
    /*Function calculates and sets inductor impedance.

    In the ideal limit this reduces to:
    z = 0 + wLi

    Formula:
    z = Re + Im * i, where:
    Re = R / ((1 - LC(w)^2)^2 + (wRC)^2)
    Im = (wL - (w^3)(L^2)C - wC(R^2)) / ((1 - LC(w)^2)^2 + (wRC)^2)
    */

    double omega {2 * pi * _frequency},
    // break up common denominator into two terms
    double term_one { std::pow(1 - this->inducatnce * this->capacitance * std::pow(omega, 2), 2)};
    double term_two {std::pow(omega * this->resistance * this->capacitance, 2)};
    
    double denominator {term_one + term_two};

    double real {this->resistance / denominator};
    // break up Im into three terms (overriding previous term variables)
    term_one = omega * this->inducatnce;
    term_two = std::pow(omega, 3) * std::pow(this->inducatnce, 2) * this->capacitance;
    double term_three {omega * this->capacitance * std::pow(this->resistance, 2)};

    double imag {term_one - term_two - term_three} / denominator

    this->impedance {real, imag};   
}

class IdealInductor: public Inductor {
    /*Class defines an ideal inductor based on the non-ideal inductor class.

    args:
        double inducatance: Components inductance.
    */

    public:
        IdealInductor(double inducatnce): Inductor(0, 0, inducatnce) {};
        IdealInductor(): Inductor() {};
};

#endif