//
// Created by Claudio Montanari on 28/11/2018.
//

#include "Register_Set.h"

/*
 * Builds a new instance of Register_Set from a vector of string variables
 * */
Register_Set::Register_Set(std::vector<std::string> variables) {

    for(auto it = variables.begin(); it != variables.end(); ++it){
        variables_.insert( std::pair<std::string, float>(*it, 0.0) );
    }
    variables_.insert( std::pair<std::string, float>(std::string("ip"), 0.0) );

};

float Register_Set::get_variable(std::string variable_name) {
    if(!variable_name.empty()) {
        auto it = this->variables_.find(variable_name);
        if(it != variables_.end())
            return it->second;
    }

    throw "Invalid Variable name";

}

void Register_Set::set_variable(std::string variable_name, float value) {
    if(!variable_name.empty()){
        auto it = this->variables_.find(variable_name);
        if(it != variables_.end()){
            variables_[variable_name] = value;
            return;
        }
    }
    throw "Invalid Variable name";

}

void Register_Set::initialize() {

    for(auto it = this->variables_.begin(); it != this->variables_.end(); ++it)
        it->second = 0.0;

}