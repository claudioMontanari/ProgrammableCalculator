//
// Created by claudio on 11/30/18.
//

#include "Input_File_CLI_Command.h"
#include <fstream>

void Input_File_CLI_Command::execute(Programmable_Calculator &programmable_calculator, std::istream &in,
                                     std::ostream &out) {
    std::string path_to_file;
    std::ifstream file_input;

    out << "Input file name: ";
    in >> path_to_file;

    path_to_file = "../" + path_to_file;

    file_input.open(path_to_file);
    try {
        programmable_calculator.parse(file_input);
    } catch (const char* error){
        out << "An error occurred while parsing the input file: " << error << std::endl;
    }

    file_input.close();
}