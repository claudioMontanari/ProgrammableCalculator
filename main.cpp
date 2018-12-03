#include <iostream>

#include "Test/Test_Suite.h"
#include "Programmable_Calculator.h"

#include "CLI/Abstract_CLI_Command.h"
#include "CLI/Debug_CLI_Command.h"
#include "CLI/Run_CLI_Command.h"
#include "CLI/Continue_CLI_Command.h"
#include "CLI/Input_File_CLI_Command.h"
#include "CLI/Print_CLI_Command.h"
#include "CLI/Input_Terminal_CLI_Command.h"

#include <functional>
#include <map>

int main() {

    char input = 'i';
    std::map<char, std::function<Abstract_CLI_Command*()>> commands_builder;
    Abstract_CLI_Command* current_command;
    std::vector<std::string> variables = {"x", "y", "w", "z"};
    Programmable_Calculator programmable_calculator(variables);

    auto input_file_cmd = [] () { return new Input_File_CLI_Command(); };
    auto input_terminal_cmd = [] () { return new Input_Terminal_CLI_Command(); };
    auto debug_cmd = [] () { return new Debug_CLI_Command(); };
    auto run_cmd = [] () { return new Run_CLI_Command(); };
    auto continue_cmd = [] () { return new Continue_CLI_Command(); };
    auto print_cdm = [] () { return new Print_CLI_Command(); };

    commands_builder.insert(std::pair<char, std::function<Abstract_CLI_Command*()>>('i', input_file_cmd));
    commands_builder.insert(std::pair<char, std::function<Abstract_CLI_Command*()>>('t', input_terminal_cmd));
    commands_builder.insert(std::pair<char, std::function<Abstract_CLI_Command*()>>('d', debug_cmd));
    commands_builder.insert(std::pair<char, std::function<Abstract_CLI_Command*()>>('r', run_cmd));
    commands_builder.insert(std::pair<char, std::function<Abstract_CLI_Command*()>>('c', continue_cmd));
    commands_builder.insert(std::pair<char, std::function<Abstract_CLI_Command*()>>('p', print_cdm));


    while( input != 'q') {
        std::cout << " ______________________________________________________________________ " << std::endl;
        std::cout << "|                                                                      |" << std::endl;
        std::cout << "|    Welcome to the Programmable Calculator Command Line Interface!    |" << std::endl;
        std::cout << "|                                                                      |" << std::endl;
        std::cout << "|     - i : to specify an input file of commands                       |" << std::endl;
        std::cout << "|     - t : to insert instructions from terminal                       |" << std::endl;
        std::cout << "|     - d : to run the instructions in debug mode                      |" << std::endl;
        std::cout << "|     - r : to run up to 100 instructions                              |" << std::endl;
        std::cout << "|     - c : to run other 100 instructions                              |" << std::endl;
        std::cout << "|     - p : to print the instructions sequence                         |" << std::endl;
        std::cout << "|     - q : to quit from the program                                   |" << std::endl;
        std::cout << "|______________________________________________________________________|" << std::endl;

        std::cin >> input;
        if( input != 'q') {
            auto it = commands_builder.find(input);
            if (it != commands_builder.end()) {
                current_command = it->second();
                current_command->execute(programmable_calculator, std::cin, std::cout);

            } else
                std::cout << "The given input is not a valid command, retry" << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;

    return 0;
}