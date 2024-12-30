// Define input methods.

#ifndef input
#define input

#include <vector>
#include <array>
#include <string>

#include "circuit.hpp"


std::vector<std::string> get_input(std::string &prompt, const char &delimeter);

double input_frequency();

std::array<double, 3> get_componet_values();

Component construct_component(const char &c, double &frequency, std::array<double, 3> &values);

Component generate_component();

Circuit generate_circuit();

#endif