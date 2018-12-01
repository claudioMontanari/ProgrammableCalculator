//
// Created by Claudio Montanari on 28/11/2018.
//

#include "Command_Assignment_Inst.h"
#include <regex>
#include <iostream>

const std::regex Command_Assignment_Inst::instruction_regex("[ ]?([[:alpha:]]+)[ ]?[=][ ]?([[:print:]]+)");

Command_Assignment_Inst::Command_Assignment_Inst(std::string instruction) {

    std::smatch sm;

    if (std::regex_match(instruction, sm, this->instruction_regex)) {

    /*
        std::cout << "the matches were: ";
        for (unsigned i = 0; i < sm.size(); ++i) {
            std::cout << "[" << sm[i] << "] ";
        }
        std::cout << std::endl;
    */
        if(sm[1] == "ip")
            throw "Non valid assignment! ";

        this->receiver_ = sm[1];
        this->expression_ = new Command_Expression_Inst(sm[2]);
    }
    else
        throw "The input instruction does not respect the syntax of the language";

}

Command_Assignment_Inst::~Command_Assignment_Inst() {
    if(this->expression_ != NULL)
        delete(this->expression_);
}

float Command_Assignment_Inst::execute(Register_Set &register_set) {
    float result = this->expression_->execute(register_set);

    register_set.set_variable(this->receiver_, result);

    return 0.0;
}

void Command_Assignment_Inst::print(std::ostream &out) {

    out << this->receiver_ << " = ";
    this->expression_->print(out);

}