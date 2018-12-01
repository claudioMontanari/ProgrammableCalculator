//
// Created by claudio on 11/29/18.
//

#include "Programmable_Calculator.h"
#include <regex>
#include <map>
#include <iostream>

/*
 * Constructor for the class Programmable Calculator: instantiate a new Register_Set
 * and the infrastructure used to build new instructions following the Command Pattern
 */
Programmable_Calculator::Programmable_Calculator(std::vector<std::string> variables ): register_set_(variables), VARIABLES(variables) {

    auto assignment = [] (std::string instruction_str) {
        if(std::regex_match(instruction_str, Command_Assignment_Inst::instruction_regex))
            return new Command_Assignment_Inst(instruction_str);
        else return (Command_Assignment_Inst*) ( nullptr );
    };

    auto conditional = [] (std::string instruction_str) {
        if(std::regex_match(instruction_str, Command_Conditional_Inst::instruction_regex))
            return new Command_Conditional_Inst(instruction_str);
        else return (Command_Conditional_Inst*) ( nullptr );
    };

    instruction_builders.push_back(assignment);
    instruction_builders.push_back(conditional);

}

/*
 * Delete all the instructions
 */
Programmable_Calculator::~Programmable_Calculator() {

    this->delete_instructions();

}

/*
 * Delete all the instructions in the Programmable Calculator instance
 */
void Programmable_Calculator::delete_instructions() {

    while ( !this->instructions_.empty() ) {
        delete(this->instructions_.back());
        this->instructions_.pop_back();
    }
}

/*
 * set to 0 all the variables, deletes previous instructions if present and reset the instruction counter
 */
void Programmable_Calculator::initialize() {

    if( !this->instructions_.empty() )
        this->delete_instructions();

    this->instruction_count_ = 0;
    this->register_set_.initialize();

}

/*
 * Returns a map of the variables that can be exposed and their values
 */
std::map<std::string, float >* Programmable_Calculator::get_variables() {

    std::map<std::string, float>* variable_map = new std::map<std::string, float>();

    for(auto it=this->VARIABLES.begin(); it != this->VARIABLES.end(); ++it){
        variable_map->insert( std::pair<std::string, float>(*it, this->register_set_.get_variable(*it)) );
    }

    return variable_map;
}


int Programmable_Calculator::get_program_counter() {
    return (int ) this->register_set_.get_variable("ip");
}

/*
 * Parse an input stream of instructions, each instruction should be placed in a new line and
 * should respect the language syntax, otherwise an exception is thrown
 */
void Programmable_Calculator::parse(std::istream& instruction_list) {

    std::string curr_instruction_str;
    std::smatch sm;
    Abst_Command_Instruction* curr_new_instruction = NULL;

    this->initialize();

    do {
        std::getline(instruction_list, curr_instruction_str);

        if( std::regex_match(curr_instruction_str, sm, this->INSTRUCTION) ) {

        /*
            std::cout << "the matches were: ";
            for (unsigned i = 0; i < sm.size(); ++i) {
                std::cout << "[" << sm[i] << "] ";
            }
            std::cout << std::endl;
        */
            auto it = this->instruction_builders.begin();
            while (it != this->instruction_builders.end() && curr_new_instruction == NULL) {
                curr_new_instruction = (*it)(sm[1]);
                ++it;
            }
            this->instructions_.push_back(curr_new_instruction);

            curr_new_instruction = NULL;

        }
    } while ( !instruction_list.eof() );

}

/*
 * Returns true if there is another instruction that can be executed
 */
bool Programmable_Calculator::has_next() {
    return ( this->register_set_.get_variable("ip") < this->instructions_.size() );
}

/*
 * Execute the next instruction pointed by the instruction pointer
 */
void Programmable_Calculator::execute_next_instruction() {

    this->instructions_[this->register_set_.get_variable("ip")]->execute(this->register_set_);
    this->register_set_.set_variable("ip", ( this->register_set_.get_variable("ip") + 1 ) );

}

/*
 * Execute up to MAX_INSTRUCTIONS and then halts
 */
void Programmable_Calculator::execute_instructions() {

    this->instruction_count_ = 0;

    while(this->has_next() && this->instruction_count_ < this->MAX_INSTRUCTIONS){

        this->execute_next_instruction();
        ++this->instruction_count_;
    }
}

/*
 * Execute just one instruction if possible
 */
void Programmable_Calculator::debug() {

    if(this->has_next())
        this->execute_next_instruction();

}


void Programmable_Calculator::print_variables(std::ostream &out) {

    out << " ================================== " << std::endl;
    out << " =========== REGISTERS ============" << std::endl;
    out << " ================================== " << std::endl;

    for(auto it = this->VARIABLES.begin(); it != this->VARIABLES.end(); ++it)
        out << "|    " << *it << " : " << this->register_set_.get_variable(*it) << std::endl;

    out << "|   next instruction : " << this->get_program_counter() << std::endl;

    out << "==================================" << std::endl;

}


void Programmable_Calculator::print_instructions(std::ostream &out) {
    int index = 1;
    out << " ================================== " << std::endl;
    out << " ========== INSTRUCTIONS ==========" << std::endl;
    out << " ================================== " << std::endl;

    for(auto it = this->instructions_.begin(); it != this->instructions_.end(); ++it) {
        out << "|   " << index << " : ";
        (*it)->print(out);
        out << std::endl;
        ++index;
    }

}