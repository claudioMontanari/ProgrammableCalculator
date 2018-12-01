//
// Created by claudio on 11/30/18.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_PRINT_CLI_COMMAND_H
#define PROGRAMMABLECALCULATORPROJECT_PRINT_CLI_COMMAND_H

#include "Abstract_CLI_Command.h"
#include "../Programmable_calculator/Programmable_Calculator.h"

class Print_CLI_Command : public Abstract_CLI_Command {

public:
    void execute(Programmable_Calculator& programmable_calculator, std::istream& in, std::ostream& out) override;

private:

};
#endif //PROGRAMMABLECALCULATORPROJECT_PRINT_CLI_COMMAND_H
