//
// Created by Claudio Montanari on 28/11/2018.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_ABST_COMMAND_INSTRUCTION_H
#define PROGRAMMABLECALCULATORPROJECT_ABST_COMMAND_INSTRUCTION_H

#include "Register_Set.h"

class Abst_Command_Instruction {

public:
    virtual ~Abst_Command_Instruction() {};

    virtual float execute(Register_Set& register_set)=0;
    virtual void print(std::ostream& out)=0;

protected:
    Abst_Command_Instruction()=default;
    //TODO: need to hide the copy constructor???

};

#endif //PROGRAMMABLECALCULATORPROJECT_ABST_COMMAND_INSTRUCTION_H
