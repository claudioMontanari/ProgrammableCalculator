//
// Created by claudio on 11/30/18.
//

#include "Run_CLI_Command.h"

void Run_CLI_Command::execute(Programmable_Calculator &programmable_calculator, std::istream &in, std::ostream &out) {

    if( !programmable_calculator.is_ready() ){
        out << "Insert a valid input file before running the program!" << std::endl;
    }
    else if( programmable_calculator.is_stopped() ){
        out << "The program has already reached the max instructions allowed, execute using - c " << std::endl;
    }
    else {
        try {

            programmable_calculator.execute_instructions();

        } catch (const char *error) {
            out << "An error occurred while executing the instructions: " << error << std::endl;
        }
        if( programmable_calculator.is_stopped() )
            out << "Watch out: you reached the max instructions limit! Next time use - c " << std::endl;
    }
}