//
// Created by Claudio Montanari on 28/11/2018.
//

#ifndef PROGRAMMABLECALCULATORPROJECT_TEST_SUITE_H
#define PROGRAMMABLECALCULATORPROJECT_TEST_SUITE_H

#include "../Programmable_calculator/Register_Set.h"
#include "../Programmable_calculator/Command_Expression_Inst.h"
#include "../Programmable_calculator/Command_Assignment_Inst.h"
#include "../Programmable_calculator/Command_Conditional_Inst.h"
#include "../Programmable_calculator/Programmable_Calculator.h"
#include <iostream>

class Test_Suite{
public:
    static bool test_all();

    static bool test_register_set();
    static bool test_expression_instruction();
    static bool test_assignment_instruction();
    static bool test_conditional_instruction();
    static bool test_programmable_calculator();

};
#endif //PROGRAMMABLECALCULATORPROJECT_TEST_SUITE_H
