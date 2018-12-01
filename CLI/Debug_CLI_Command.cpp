//
// Created by claudio on 11/30/18.
//

#include "Debug_CLI_Command.h"

/*
 * Execute one instruction if possible and prints the variables value
 */
void Debug_CLI_Command::execute(Programmable_Calculator &programmable_calculator, std::istream &in,
                                std::ostream &out) {
    if( programmable_calculator.is_ready() ){

        programmable_calculator.debug();
        programmable_calculator.print_variables(out);

    } else
        out << "Insert a valid input file before debugging the program! " << std::endl;

}