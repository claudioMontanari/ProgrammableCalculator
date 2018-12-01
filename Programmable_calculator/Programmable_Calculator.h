//
// Created by claudio on 11/29/18.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_PROGRAMMABLE_CALCULATOR_H
#define PROGRAMMABLECALCULATORPROJECT_PROGRAMMABLE_CALCULATOR_H

#include "Register_Set.h"
#include "Command_Conditional_Inst.h"
#include "Command_Assignment_Inst.h"
#include <iostream>

class Programmable_Calculator {

public:

    Programmable_Calculator(std::vector<std::string> variables);
    ~Programmable_Calculator();

    void parse(std::istream& instruction_list);
    void debug();
    void execute_instructions();
    int get_program_counter();
    std::map<std::string, float >* get_variables();

    bool is_stopped() { return this->instruction_count_ == this->MAX_INSTRUCTIONS; };
    bool is_ready() { return !this->instructions_.empty(); };

    void print_variables(std::ostream& out);
    void print_instructions(std::ostream& out);

private:

    void execute_next_instruction();
    bool has_next();
    void delete_instructions();
    void initialize();

    const std::vector<std::string> VARIABLES;
    const std::regex INSTRUCTION = std::regex("([[:print:]]+).");

    const int MAX_INSTRUCTIONS = 100;
    Register_Set register_set_;
    int instruction_count_ = 0;
    std::vector<Abst_Command_Instruction*> instructions_;
    std::vector<std::function<Abst_Command_Instruction*(std::string)>> instruction_builders;

};

#endif //PROGRAMMABLECALCULATORPROJECT_PROGRAMMABLE_CALCULATOR_H
