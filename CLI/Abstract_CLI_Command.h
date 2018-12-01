//
// Created by claudio on 11/30/18.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_ABSTRACT_CLI_COMMAND_H
#define PROGRAMMABLECALCULATORPROJECT_ABSTRACT_CLI_COMMAND_H

#include "../Programmable_calculator/Programmable_Calculator.h"

class Abstract_CLI_Command {

public:
    virtual void execute(Programmable_Calculator& programmable_calculator, std::istream& out, std::ostream& in)=0;

protected:
    Abstract_CLI_Command() = default;
};

#endif //PROGRAMMABLECALCULATORPROJECT_ABSTRACT_CLI_COMMAND_H
