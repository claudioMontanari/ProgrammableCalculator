//
// Created by claudio on 11/30/18.
//

#include "Continue_CLI_Command.h"

/*
 * Keep executing other instructions until the Programmable Calculator stops
 */
void Continue_CLI_Command::execute(Programmable_Calculator &programmable_calculator, std::istream &in,
                                   std::ostream &out) {

    if( programmable_calculator.is_stopped() ) {
        try {

            programmable_calculator.execute_instructions();
            programmable_calculator.print_variables(out);

        } catch (const char* error){
            out << "An error occurred while executing in debug mode: " << error << std::endl;
        }
    }

}