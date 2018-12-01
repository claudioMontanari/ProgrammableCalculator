//
// Created by Claudio Montanari on 28/11/2018.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_REGISTER_SET_H
#define PROGRAMMABLECALCULATORPROJECT_REGISTER_SET_H

#include <vector>
#include <string>
#include <map>
#include <exception>

class Register_Set {

public:
    Register_Set(std::vector<std::string> variables);

    float get_variable(std::string variable_name);
    void set_variable(std::string variable_name, float value);
    void initialize();

private:
    std::map<std::string, float> variables_;
};

#endif //PROGRAMMABLECALCULATORPROJECT_REGISTER_SET_H
