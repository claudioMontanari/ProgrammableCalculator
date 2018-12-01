## Object Oriented Languages and Environment - CS474 
### Claudio Montanari - Programmable Calculator Project

#### Installation

To install the project import it in a C++ editor (CLion for instance) and set the compiler to c++11.

#### Features

The Programmable Calculator prompts the user a menu with the following commands:

- i : Ask the user to insert a path to a file of commands 
- d : Execute the program in debug mode - one instruction  at a time
- r : Run the program up to 100 instructions
- c : Continue to run the program for other 100 instructions
- p : Prints the instructions of the program and the value of the variables
- q : Quit from the system

#### Notes

The __execute family__ of commands (Run, Debug and Continue) require that the user previously loaded a file of commands.

The __insert__ functionality require a valid path to a file of commands placed in the main directory. 
The grammar of the language is the following (EBNF grammar):

```
<input_file> = (<instruction>.)+
<instruction> = <assignment> | <conditional>
<assignment> = <id> '=' <operator> [<operation> <operator>]
<conditional> = <id> ? (0-9)+ 
<operator> = <id> | <number>
<operation> = + | - | / | * | **
<id> = x | y | w | z
<number> = (0-9)+[.(0-9)+]
```
For what concern the semantic of the instructions basically we have:

- __assignment__ : assign the result of an expression to a variable
 
- __expression__ : a single variable/number or a binary operation (+, -, *, / have a standard meaning, while ** is for the power operation)

- __conditional__ : jump to a given address if the target variable is different from 0

Below there is an example of a valid input file that computes the factorial of a number placed in x (what follows the // is just a comment and shouldn't be placed into the input file): 

```
x = 5.                  //Assign 5 to x
w = 1.                  //Assign 1 to w
z = x.                  //Assign x to z
w = w * z.              //Assign w * z to w
z = z - 1.              //Decrement z by one
z ? 4.                  //Jump to instruction 4 if z is different from 0
```
