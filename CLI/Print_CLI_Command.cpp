//
// Created by claudio on 11/30/18.
//

#include "Print_CLI_Command.h"

void Print_CLI_Command::execute(Programmable_Calculator &programmable_calculator, std::istream &in,
                                std::ostream &out) {

    programmable_calculator.print_instructions(out);
    programmable_calculator.print_variables(out);

}