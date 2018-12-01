//
// Created by Claudio Montanari on 28/11/2018.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_COMMAND_ASSIGNMENT_INST_H
#define PROGRAMMABLECALCULATORPROJECT_COMMAND_ASSIGNMENT_INST_H

#include "Abst_Command_Instruction.h"
#include "Command_Expression_Inst.h"

class Command_Assignment_Inst : public Abst_Command_Instruction {
public:
    Command_Assignment_Inst(std::string instruction);
    ~Command_Assignment_Inst();

    virtual float execute(Register_Set& register_set);
    virtual void print(std::ostream& out);

    static const std::regex instruction_regex;

private:
    std::string receiver_;
    Command_Expression_Inst* expression_;

};

#endif //PROGRAMMABLECALCULATORPROJECT_COMMAND_ASSIGNMENT_INST_H
