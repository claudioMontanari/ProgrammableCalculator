//
// Created by Claudio Montanari on 28/11/2018.
//

#include "Command_Conditional_Inst.h"
#include <iostream>

const std::regex Command_Conditional_Inst::instruction_regex("[ ]?([[:alpha:]]+)[ ]?(\\?[ ]?(go)?)[ ]?([[:digit:]]+)[ ]?");

Command_Conditional_Inst::Command_Conditional_Inst(std::string instruction) {

    std::smatch sm;

    if (std::regex_match(instruction, sm, this->instruction_regex)) {

        /*
        std::cout << "the matches were: ";
        for (unsigned i = 0; i < sm.size(); ++i) {
            std::cout << "[" << sm[i] << "] ";
        }
        std::cout << std::endl;
        */

        this->condition_variable_ = sm[1];
        this->address_to_jump_ = std::stoi(sm[4]) - 2;
    }
    else
        throw "The input instruction does not respect the syntax of the language";

}

float Command_Conditional_Inst::execute(Register_Set &register_set) {

    if(register_set.get_variable(this->condition_variable_) != 0.0)
        register_set.set_variable("ip", this->address_to_jump_);
    return 0.0;
}

void Command_Conditional_Inst::print(std::ostream &out) {
    out << this->condition_variable_ << " ? " << this->address_to_jump_ + 2;
}