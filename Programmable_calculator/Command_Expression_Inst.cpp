//
// Created by Claudio Montanari on 28/11/2018.
//

#include "Command_Expression_Inst.h"
#include <regex>
#include <iostream>
#include <math.h>

const std::regex Command_Expression_Inst::instruction_regex("([[:alpha:]]+|-?[[:digit:]]+(.[[:digit:]]+)?)([ ]?(\\+|\\-|\\*|\\/|\\*\\*)[ ]?([[:alpha:]]+|[[:digit:]]+(.[[:digit:]]+)?))?");

/*
 * Build a new instance of Command_Expresion_Inst from the given input string according to the following syntax:
 * (id | [0-9]+[.[0-9]]) [op (id | [0-9]+[.[0-9]])]
 * Where id = [a-z; A-Z]+
 *      op = +, -, *, **, /
 */
Command_Expression_Inst::Command_Expression_Inst(std::string instruction) {

    std::smatch sm;

    if(std::regex_match(instruction, sm, this->instruction_regex)){
/*
        std::cout << "the matches were: ";
        for (unsigned i=0; i<sm.size(); ++i) {
            std::cout << "[" << sm[i] << "] ";
        }
        std::cout<<std::endl;
*/
        if( sm[1] == "ip")
            throw "Non valid operand! ";

        this->first_operator_ = sm[1];
        if(sm[4].length() != 0 ) {
            this->operation_ = sm[4];

            if( sm[5] == "ip" )
                throw "Non valid operand! ";
            this->second_operator_ = sm[5];
        }

        auto sum = [] (float op1, float op2) { return op1 + op2; };
        auto min = [] (float op1, float op2) { return op1 - op2; };
        auto mul = [] (float op1, float op2) { return op1 * op2; };
        auto div = [] (float op1, float op2) { return op1 / op2; };
        auto exp = [] (float op1, float op2) { return pow(op1, op2); };

        operations_list_.insert( std::pair<std::string, std::function<float(float, float)>>("+", sum));
        operations_list_.insert( std::pair<std::string, std::function<float(float, float)>>("-", min));
        operations_list_.insert( std::pair<std::string, std::function<float(float, float)>>("*", mul));
        operations_list_.insert( std::pair<std::string, std::function<float(float, float)>>("/", div));
        operations_list_.insert( std::pair<std::string, std::function<float(float, float)>>("**", exp));

    }
    else throw "String does not match the instruction syntax";

}

float Command_Expression_Inst::execute(Register_Set &register_set) {

    float val_1 = 0, val_2 = 0;
    try{
        val_1 = register_set.get_variable(this->first_operator_);
    }
    catch (const char* e){
        val_1 = std::stof(this->first_operator_);
    }

    if( !this->second_operator_.empty() ) {
        try {
            val_2 = register_set.get_variable(this->second_operator_);
        }
        catch (const char* e) {
            val_2 = std::stof(this->second_operator_);
        }

        auto it = this->operations_list_.find(this->operation_);
        if(it != operations_list_.end()){
            return it->second(val_1, val_2);
        }
        else throw "Something went wrong when executing the operation";
    }
    else return val_1;
}

void Command_Expression_Inst::print(std::ostream &out) {
    out << this->first_operator_ << " " << this->operation_ << " " << this->second_operator_;
}