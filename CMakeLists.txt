cmake_minimum_required(VERSION 3.12)
project(ProgrammableCalculatorProject)

set(CMAKE_CXX_STANDARD 11)

include_directories(Programmable_calculator)
include_directories(Test)

add_executable(ProgrammableCalculatorProject
        Programmable_calculator/Abst_Command_Instruction.h
        Programmable_calculator/Command_Assignment_Inst.cpp
        Programmable_calculator/Command_Assignment_Inst.h
        Programmable_calculator/Command_Conditional_Inst.cpp
        Programmable_calculator/Command_Conditional_Inst.h
        Programmable_calculator/Command_Expression_Inst.cpp
        Programmable_calculator/Command_Expression_Inst.h
        Programmable_calculator/Register_Set.cpp
        Programmable_calculator/Register_Set.h
        Test/Test_Suite.cpp
        Test/Test_Suite.h
        main.cpp Programmable_calculator/Programmable_Calculator.h Programmable_calculator/Programmable_Calculator.cpp CLI/Abstract_CLI_Command.h CLI/Input_File_CLI_Command.h CLI/Print_CLI_Command.h CLI/Debug_CLI_Command.h CLI/Run_CLI_Command.h CLI/Continue_CLI_Command.h CLI/Continue_CLI_Command.cpp CLI/Debug_CLI_Command.cpp CLI/Input_File_CLI_Command.cpp CLI/Print_CLI_Command.cpp CLI/Run_CLI_Command.cpp)
