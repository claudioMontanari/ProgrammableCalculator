//
// Created by Claudio Montanari on 28/11/2018.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_COMMAND_CONDITIONAL_INST_H
#define PROGRAMMABLECALCULATORPROJECT_COMMAND_CONDITIONAL_INST_H

#include "Abst_Command_Instruction.h"
#include <string>
#include <regex>

class Command_Conditional_Inst : public Abst_Command_Instruction {
public:
    Command_Conditional_Inst(std::string instruction);
    ~Command_Conditional_Inst() = default;

    virtual float execute(Register_Set& register_set);
    virtual void print(std::ostream& out);
    static const std::regex instruction_regex;

private:

    int address_to_jump_;
    std::string condition_variable_;

};

#endif //PROGRAMMABLECALCULATORPROJECT_COMMAND_CONDITIONAL_INST_H
