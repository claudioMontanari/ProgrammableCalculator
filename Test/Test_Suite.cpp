//
// Created by Claudio Montanari on 28/11/2018.
//

#include "Test_Suite.h"
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>

bool Test_Suite::test_all() {
    bool test_passed = true;

    test_passed = test_passed && Test_Suite::test_register_set();
    test_passed = test_passed && Test_Suite::test_expression_instruction();
    test_passed = test_passed && Test_Suite::test_assignment_instruction();
    test_passed = test_passed && Test_Suite::test_conditional_instruction();
    test_passed = test_passed && Test_Suite::test_programmable_calculator();
    return test_passed;
}

bool Test_Suite::test_register_set() {
    bool test_passed = true;
    std::vector<std::string> var_names;

    var_names.push_back(std::string("x"));
    var_names.push_back(std::string("y"));
    var_names.push_back(std::string("w"));
    var_names.push_back(std::string("z"));

    Register_Set register_set(var_names);

    test_passed = test_passed && (register_set.get_variable(std::string("x")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("y")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("w")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("z")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("ip")) == 0.0);

    try {
        register_set.get_variable(std::string("abc"));
        test_passed = false;
    }catch (const char* e){
        test_passed = test_passed && true;
    }

    register_set.set_variable(std::string("x"), 5.0);
    register_set.set_variable(std::string("ip"), 1);

    test_passed = test_passed && (register_set.get_variable(std::string("x")) == 5.0);
    test_passed = test_passed && (register_set.get_variable(std::string("y")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("w")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("z")) == 0.0);
    test_passed = test_passed && (register_set.get_variable(std::string("ip")) == 1.0);

    return  test_passed;
}

bool Test_Suite::test_expression_instruction() {

    bool test_passed = true;
    std::vector<std::string> var_names;

    var_names.push_back(std::string("x"));
    var_names.push_back(std::string("y"));
    var_names.push_back(std::string("w"));
    var_names.push_back(std::string("z"));

    Register_Set register_set(var_names);

    std::string inst1("x + y");
    try {
        Command_Expression_Inst inst_instance1(inst1);
        test_passed = test_passed && (inst_instance1.execute(register_set) == 0.0);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << "Inst 1 done" << std::endl;

    std::string inst2("z - 10.5");
    try {
        Command_Expression_Inst inst_instance2(inst2);
        test_passed = test_passed && (inst_instance2.execute(register_set) == -10.5);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << "Inst 2 done" << std::endl;

    std::string inst3("909.09**y");
    try {
        Command_Expression_Inst inst_instance3(inst3);
        test_passed = test_passed && (inst_instance3.execute(register_set) == 1.0);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << "Inst 3 done" << std::endl;

    std::string inst4("5 / b5");
    try {
        Command_Expression_Inst inst_instance4(inst4);
        test_passed = false;
    }catch(const char* error){

    }

    std::cout << "Inst 4 done" << std::endl;

    std::string inst5("a * ");
    try {
        Command_Expression_Inst inst_instance5(inst5);
        test_passed = false;

    }catch(const char* error){

    }

    std::cout << "Inst 5 done" << std::endl;

    std::string inst6("z");
    try {
        Command_Expression_Inst inst_instance6(inst6);
        test_passed = test_passed && (inst_instance6.execute(register_set) == 0.0);

    }catch(const char* error) {
        test_passed = false;
    }

    std::cout << "Inst 6 done" << std::endl;

    std::string inst7("-78.0");
    try {
        Command_Expression_Inst inst_instance7(inst7);
        test_passed = test_passed && (inst_instance7.execute(register_set) == -78.0);

    }catch(const char* error) {
        test_passed = false;
    }

    return test_passed;
}

bool Test_Suite::test_assignment_instruction(){
    bool test_passed = true;
    std::vector<std::string> var_names;

    var_names.push_back(std::string("x"));
    var_names.push_back(std::string("y"));
    var_names.push_back(std::string("w"));
    var_names.push_back(std::string("z"));

    Register_Set register_set(var_names);

    std::string inst1("x = x + 2");
    try {
        Abst_Command_Instruction* inst_instance1 = new Command_Assignment_Inst(inst1);
        inst_instance1->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("x") == 2.0);
        test_passed = test_passed && (register_set.get_variable("y") == 0.0);
        delete(inst_instance1);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << "Inst 1 done" << std::endl;

    std::string inst2("y = z - 10.5");
    try {
        Abst_Command_Instruction* inst_instance2 = new Command_Assignment_Inst(inst2);
        inst_instance2->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("y") == -10.5);
        test_passed = test_passed && (register_set.get_variable("z") == 0.0);
        delete(inst_instance2);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << "Inst 2 done" << std::endl;

    std::string inst3("z = 9**x");
    try {
        Abst_Command_Instruction* inst_instance3 = new Command_Assignment_Inst(inst3);
        inst_instance3->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("x") == 2.0);
        test_passed = test_passed && (register_set.get_variable("z") == 81.0);
        delete(inst_instance3);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << "Inst 3 done" << std::endl;

    std::string inst4("x = 5 / b5");
    try {
        Abst_Command_Instruction* inst_instance4 = new Command_Assignment_Inst(inst4);
        inst_instance4->execute(register_set);
        test_passed = false;
        delete(inst_instance4);

    }catch(const char* error){

    }

    std::cout << "Inst 4 done" << std::endl;

    std::string inst5("a * ");
    try {
        Abst_Command_Instruction* inst_instance5 = new Command_Assignment_Inst(inst5);
        inst_instance5->execute(register_set);
        test_passed = false;
        delete(inst_instance5);

    }catch(const char* error){

    }

    std::cout << "Inst 5 done" << std::endl;

    std::string inst6("y = z");
    try {
        Abst_Command_Instruction* inst_instance6 = new Command_Assignment_Inst(inst6);
        inst_instance6->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("y") == 81.0);
        test_passed = test_passed && (register_set.get_variable("z") == 81.0);
        delete(inst_instance6);

    }catch(const char* error) {
        test_passed = false;
    }

    std::cout << "Inst 6 done" << std::endl;

    std::string inst7("z = 78.0 / x");
    try {
        Abst_Command_Instruction* inst_instance7 = new Command_Assignment_Inst(inst7);
        inst_instance7->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("x") == 2.0);
        test_passed = test_passed && (register_set.get_variable("z") == 39.0);
        delete(inst_instance7);

    }catch(const char* error) {
        test_passed = false;
    }

    return test_passed;

}

bool Test_Suite::test_conditional_instruction() {
    bool test_passed = true;
    std::vector<std::string> var_names;

    var_names.push_back(std::string("x"));
    var_names.push_back(std::string("y"));
    var_names.push_back(std::string("w"));
    var_names.push_back(std::string("z"));

    Register_Set register_set(var_names);

    std::string inst1("x ? 2");
    try {
        Abst_Command_Instruction* inst_instance1 = new Command_Conditional_Inst(inst1);
        inst_instance1->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("x") == 0.0);
        test_passed = test_passed && (register_set.get_variable("ip") == 0.0);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << inst1 << " done" << std::endl;

    register_set.set_variable("y", 2.0);
    std::string inst2("y ? 20");
    try {
        Abst_Command_Instruction* inst_instance2 = new Command_Conditional_Inst(inst2);
        inst_instance2->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("y") == 2.0);
        test_passed = test_passed && (register_set.get_variable("ip") == 18.0);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << inst2 << " done" << std::endl;

    std::string inst3("y ? go 10");
    try {
        Abst_Command_Instruction* inst_instance3 = new Command_Conditional_Inst(inst3);
        inst_instance3->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("y") == 2.0);
        test_passed = test_passed && (register_set.get_variable("ip") == 8.0);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << inst3 << " done" << std::endl;

    std::string inst4("x?20");
    try {
        Abst_Command_Instruction* inst_instance4 = new Command_Conditional_Inst(inst4);
        inst_instance4->execute(register_set);
        test_passed = test_passed && (register_set.get_variable("x") == 0.0);
        test_passed = test_passed && (register_set.get_variable("ip") == 8.0);

    }catch(const char* error){
        test_passed = false;
    }

    std::cout << inst4 << " done" << std::endl;


    std::string inst5("a ?20");
    try {
        Abst_Command_Instruction* inst_instance5 = new Command_Conditional_Inst(inst5);
        if(inst_instance5->execute(register_set) == 0.0)
            test_passed = false;

    }catch(const char* error){
        std::cout << inst5 << " done" << std::endl;
    }


    std::string inst6(" ? b");
    try {
        Abst_Command_Instruction* inst_instance6 = new Command_Conditional_Inst(inst6);
        if(inst_instance6->execute(register_set) == 0.0)
            test_passed = false;

    }catch(const char* error){
        std::cout << inst6 << " done" << std::endl;
    }


    return test_passed;

}

bool Test_Suite::test_programmable_calculator() {

    bool test_passed = true;
    std::vector<std::string> variables = {"x", "y", "z", "w"};
    Programmable_Calculator PC(variables);
    std::ifstream input_file;

    input_file.open("../Test/input_test.txt");

    try{
        PC.parse(input_file);
        PC.execute_instructions();

        std::map<std::string, float>* variables_updated = PC.get_variables();

        test_passed = test_passed && (variables_updated->at("x") == 5.0);
        test_passed = test_passed && (variables_updated->at("y") == 0.0);
        test_passed = test_passed && (variables_updated->at("w") == 3.5);
        test_passed = test_passed && (variables_updated->at("z") == 2.5);

        delete(variables_updated);

        test_passed = test_passed && (PC.get_program_counter() == 6);
    }
    catch (const char* error){
        test_passed = false;
    }
    input_file.close();

    input_file.open("../Test/input_test_wrong.txt");

    try{
        PC.parse(input_file);

        test_passed = false;
    }
    catch (const char* error){

        std::map<std::string, float>* variables_updated = PC.get_variables();

        test_passed = test_passed && (variables_updated->at("x") == 0.0);
        test_passed = test_passed && (variables_updated->at("y") == 0.0);
        test_passed = test_passed && (variables_updated->at("w") == 0.0);
        test_passed = test_passed && (variables_updated->at("z") == 0.0);

        delete(variables_updated);

        test_passed = test_passed && (PC.get_program_counter() == 0);

    }

    input_file.close();

    return test_passed;
}