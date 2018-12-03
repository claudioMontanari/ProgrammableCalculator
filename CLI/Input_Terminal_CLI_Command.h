//
// Created by claudio on 12/2/18.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_INPUT_TERMINAL_CLI_COMMAND_H
#define PROGRAMMABLECALCULATORPROJECT_INPUT_TERMINAL_CLI_COMMAND_H

#include "Abstract_CLI_Command.h"

class Input_Terminal_CLI_Command : public Abstract_CLI_Command {

public:
    Input_Terminal_CLI_Command() = default;
    void execute(Programmable_Calculator& programmable_calculator, std::istream& in, std::ostream& out) override;

private:

};


#endif //PROGRAMMABLECALCULATORPROJECT_INPUT_TERMINAL_CLI_COMMAND_H
