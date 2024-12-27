/*Define methods for associated header.
*/

#include <numbers>

#include "components.hpp"


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

    double omega { 2 * std::numbers::pi * this->frequency },
    // Common denomintor for both Re and Im
    denominator { 1 + std::pow(omega * this->resistance * this->capacitance, 2) };
    real { this->resistance / denominator };

    // Split Im up into three terms
    double term_one {omega * this->inductance},
    term_two {omega * this->capacitance * std::pow(this->resistance, 2)},
    term_three { std::pow(omega, 3) * std::pow(this->capacitance, 2) * 
                    std::pow(this->resistance, 2) * this->inductance },
    // Define imaginary component from previous terms
    imag {(term_one - term_two + term_three) / denominator };

    // set impedance
    this->impedance {real, imag};
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

    double omega {2 * std::numbers::pi * this->frequency},
    real {this->resistance},
    imag {omega * this->inducatnce - 1 / (omega * this->capacitance)};

    this->impedance {real, imag};
}


void Inductor::set_impedance() {
    /*Function calculates and sets inductor impedance.

    In the ideal limit this reduces to:
    z = 0 + wLi

    Formula:
    z = Re + Im * i, where:
    Re = R / ((1 - LC(w)^2)^2 + (wRC)^2)
    Im = (wL - (w^3)(L^2)C - wC(R^2)) / ((1 - LC(w)^2)^2 + (wRC)^2)
    */

    double omega {2 * std::numbers::pi * this->frequency},
    // break up common denominator into two terms
    term_one { std::pow(1 - this->inducatnce * this->capacitance * std::pow(omega, 2), 2) },
    term_two { std::pow(omega * this->resistance * this->capacitance, 2) },
    // Define denominator from both terms.
    denominator {term_one + term_two},
    // Define the real component of the impedance
    real {this->resistance / denominator};

    // break up Im into three terms (overriding previous term variables)
    term_one = omega * this->inducatnce;
    term_two = std::pow(omega, 3) * std::pow(this->inducatnce, 2) * this->capacitance;
    double term_three {omega * this->capacitance * std::pow(this->resistance, 2)},
    // construct imaginary component from all previous terms.
    imag {term_one - term_two - term_three} / denominator

    // set impedance
    this->impedance {real, imag};   
}
