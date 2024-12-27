// Method definitions for circuit.

#include "circuit.hpp"

Circuit Circuit::operator+(Component const& c) {
    this->components.push_back(c.name);
    this->impedances.push_back(c.impedance);
    this->is_series.push_back(c.is_series);

    return *this;
}

Circuit Circuit::operator+=(Component const& c) {
    //TODO test this
    return *(this + c);
}

void calculate_impedance() {
    // Calculate the final impedance of the circuit.

    std::complex<double> ret;
    auto imp_it { this->impedances.cbegin() };
    auto is_it { this->is_series.cbegin() };

    for (
        imp_it, is_it; 
        imp_it != this->impedances.cend(), is_it != this->is_series.cend();
        imp_it++, is_it++
    ) {
        if (
            imp_it + 1 == this->impedances.cend() && 
            is_it + 1 == this->is_series.cend()
        ) {
            // If (idx + 1) == cend then there is no need to check if item is parallel
            ret += *imp_it;
        }

        // is the next comp in parallel with the current one?
        if (!*(is_it + 1)) {
            std::complex<double> parallel_sum { (1. / *imp_it) + (1. / *(imp_it+1)) };
            // Increment to account for use of next item
            imp_it++; is_it++;

            ret += parallel_sum;
        } else {
            ret += *imp_it;
        }
    }
    return ret;
}