//
// Created by claudio on 11/30/18.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_CONTINUE_CLI_COMMAND_H
#define PROGRAMMABLECALCULATORPROJECT_CONTINUE_CLI_COMMAND_H

#include "Abstract_CLI_Command.h"
#include "../Programmable_calculator/Programmable_Calculator.h"

class Continue_CLI_Command : public Abstract_CLI_Command {

public:
    Continue_CLI_Command() = default;
    void execute(Programmable_Calculator& programmable_calculator, std::istream& in, std::ostream& out) override;

private:

};

#endif //PROGRAMMABLECALCULATORPROJECT_CONTINUE_CLI_COMMAND_H
