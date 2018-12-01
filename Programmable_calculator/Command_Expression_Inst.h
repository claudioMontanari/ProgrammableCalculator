//
// Created by Claudio Montanari on 28/11/2018.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_COMMAND_EXPRESSION_INST_H
#define PROGRAMMABLECALCULATORPROJECT_COMMAND_EXPRESSION_INST_H

#include "Abst_Command_Instruction.h"
#include <functional>
#include <regex>

class Command_Expression_Inst : public Abst_Command_Instruction {
public:

    Command_Expression_Inst(std::string instruction);
     ~Command_Expression_Inst() = default;

    virtual float execute(Register_Set& register_set);
    virtual void print(std::ostream& out);

    const static std::regex instruction_regex;

private:
    std::string first_operator_;
    std::string second_operator_;
    std::string operation_;
    std::map<std::string, std::function<float(float, float)>> operations_list_;
};


#endif //PROGRAMMABLECALCULATORPROJECT_COMMAND_EXPRESSION_INST_H
