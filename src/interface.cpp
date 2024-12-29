/*File handles the user inputting a variable length Circuit.

I AM NEVER DOING FRONTEND-esq WORK IN C/C++ EVER AGAIN XD.
*/

#include <sstream>
#include <iostream>

#include <stdlib.h>

#include "interface.hpp"


std::vector<std::string> get_input(std::string &prompt, const char &delimeter = ' ') {
    /*Ingest a prompt and standardise the user input based on a delimeter.
    
    Args:
        prompt - The string to prompt the user with.
        delimeter - The delimeter to use in std::getline.
    */

    std::string buffer;
    std::vector<std::string> ret;

    std::cout << prompt;
    std::getline(std::cin, buffer);

    std::stringstream ss_buffer(buffer);
    buffer.clear(); // empty buffer to reuse.

    // Split the string on delimeter.
    while ( std::getline(ss_buffer, buffer, delimeter) && !buffer.empty() ) {
        ret.push_back(buffer);
    }

    return ret;
}

double input_frequency() {
    /*Prompt the user for the circuits frequency.
    */

    std::string prompt {"Enter the frequency of your circuit (in Hz): "},
        buffer;
    bool is_valid { false };
    double ret { 0 }; // let 0 be default.

    do {
        std::vector<std::string> user_input { get_input(prompt) };
        buffer = user_input[0];
        
        try {
            ret = std::stod(buffer);

            if (ret < 0) {
                std::cout << "Enter a value >= 0" << std::endl;
            } else {
                is_valid = true;
            }

        } catch (const std::invalid_argument& e) {
            buffer.clear();
            std::cout << "Invalid argument. Enter a valid number." << std::endl;
        }
    } while (!is_valid);
    
    return ret;
}

std::array<double, 3> get_componet_values() {
    /*Prompt user for resistance, capacitance, and inductance for the component
    */

    std::string 
        prompt {"Enter the resistance, capacitance, and inductance of your component: "};
    bool is_valid { false };
    std::array<double, 3> ret;

    do {
        std::vector<std::string> user_input { get_input(prompt) };

        if (user_input.size() > 3) {
            std::cout << "Too many values passed. Expected three doubles, space delimeted." << std::endl;
        } else if (user_input.size() < 3) {
            std::cout << "Too few values passed." << std::endl;
        } else {
            auto it = user_input.cbegin(); auto arr_it = ret.begin();
            int counter {0};
            while (counter < 3) {
                try {
                    *arr_it = std::stod(*it);
                    if (counter == 2) {
                        is_valid = true;
                    }
                } catch (const std::invalid_argument& e) {
                    std::cout << "Invalid argument. Enter a valid number." << std::endl;
                    break;
                }
                it++; arr_it++;
                counter++;
            }
        }
    } while(!is_valid);

    return ret;
}

Component construct_component(
    const char &c,
    double &frequency,
    std::array<double, 3> &values
) {
    /*Construct a Compoennt based on the users choice and values.
    */

    Component ret;

    switch(c) {
        case 'r':
            ret = Resistor(frequency, values);
            break;
        case 'c':
            ret = Capacitor(frequency, values);
            break;
        case 'i':
            ret = Inductor(frequency, values);
            break;
        default:
            // This should be handled prior to this functions scope.
            // exit() just incase of failure.
            std::cout << "Invalid component choice." << std::endl;
            exit(1);
    }
    return ret;
}

Component generate_component(double &frequency) {
    /*Have the user choose what component to add to the circuit.
    */

    std::string user_input,
        prompt { "Choose a component: Resistor (R), Capacitor (C), Inductor (I)? " };
    bool is_valid { false };
    char choice;
    Component ret;

    do {
        std::vector<std::string> user_input { get_input(prompt) };
        std::string string_input { user_input[0] }; // Ignore anything after first delim.

        choice = std::tolower(string_input[0]);

        if (choice == 'r' || choice == 'c' || choice == 'i') {
            std::array<double, 3> values { get_componet_values() };
            ret = construct_component(choice, frequency, values);
            is_valid = true;
        } else {
            std::cout << "Invalid component choice. Choice should be " <<
            "'R', 'C', or 'I'. Representing resistors, capacitors, and " <<
            "inductors respectively." << std::endl;
        }
    } while(!is_valid);

    return ret;
}

Circuit generate_circuit() {

    bool should_continue { true };
    std::string prompt {"Would you like to add another component? "};
    Circuit ret;

    double frequency { input_frequency() };
    int count {0};
    do {
        Component comp;
        if (count == 0) {
            comp = generate_component(frequency);
            ret += comp;
            count++;
        } else {
            bool good_answer { false };
            while (!good_answer) {
                std::vector<std::string> user_input { get_input(prompt) };
                std::string buffer = user_input[0];
                char answer { std::tolower(buffer[0]) };

                good_answer = answer == 'y' || answer == 'n' ? true : false; 

                switch(answer) {
                    case 'n':
                        should_continue = false;
                        break;
                    case 'y':
                        comp = generate_component(frequency);
                        ret += comp;
                        break;
                    default:
                        std::cout << "Enter Yes or No." << std::endl;
                        break;
                }
            }
        }
    } while (should_continue);

    return ret;
}
