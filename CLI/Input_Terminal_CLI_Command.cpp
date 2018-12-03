//
// Created by claudio on 12/2/18.
//

#include "Input_Terminal_CLI_Command.h"
#include <fstream>
#include <string>

void Input_Terminal_CLI_Command::execute(Programmable_Calculator &programmable_calculator, std::istream &in,
                                         std::ostream &out) {
    std::ofstream out_temp_file;
    std::ifstream in_file;
    std::string input_string;
    std::string program_string;
    std::string tmp_file_path(".keyboard_program.tmp");

    int index = 2;

    out << "Insert here the instructions of the program: (type ENTER to exit)" << std::endl;

    out << "1: ";
    std::getline(in, input_string);
    std::getline(in, input_string);
    program_string = input_string + "\n";

    while ( !input_string.empty() ){
        out << index << ": ";
        std::getline(in, input_string);
        program_string += input_string + "\n";

        ++index;
    }

    out_temp_file.open(tmp_file_path);
    out_temp_file << program_string;
    out_temp_file.close();

    in_file.open(tmp_file_path);

    programmable_calculator.parse(in_file);

    std::remove(tmp_file_path.c_str());

}