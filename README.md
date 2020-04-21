# Push_Swap

### Summary:
Push_swap is an algorithm project: the goal is to sort data on a stack,
with a limited set of instructions, using the lowest possible number of actions.

### Project description:
In Push_swap, data needs to be sorted.
To do so, you have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.

The goal of the project is to write two programs in C
• The first, named **_checker_** which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays **OK** if integers
are sorted. Otherwise, it will display **KO**.
• The second one called **_push_swap_** which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer arguments received.

### Game rules
The game is composed of 2 stacks named **a** and **b**.
To start with:
   ◦ a contains a random number of either positive or negative numbers without any duplicates.
   ◦ b is empty
The goal is to sort in ascending order numbers into stack a.

To do this you have the following operations at your disposal:
**sa** : _swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements)_.
**sb** : _swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements)_.
**ss** : _sa and sb at the same time_.
**pa** : _push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty._
**pb** : _push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty._
**ra** : _rotate a - shift up all elements of stack a by 1. The first element becomes
the last one._
**rb** : _rotate b - shift up all elements of stack b by 1. The first element becomes
the last one._
**rr** : _ra and rb at the same time._
**rra** : _reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one._
**rrb** : _reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one._
**rrr** : _rra and rrb at the same time._

### The Checker program
• `checker` will get as an argument the stack **a** formatted as a list of integers.
The first argument should be at the top of the stack. If no argument is given `checker` stops and
displays nothing.
• `checker` will then wait and read instructions on the standard input, each instruction
will be followed by ’\n’. Once all the instructions have been read, `checker` will
execute them on the stack received as an argument.
• If after executing those instructions, stack a is actually sorted and **b** is empty, then
checker must display **OK** followed by a `\n` on the standard output. In every
other case, checker must display **KO** followed by a `\n` on the standard output.

### The Push_Swap program
• `push_swap` will receive as an argument the stack **a** formatted as a list of integers. The first argument should be at the top
of the stack.
• The program must display the smallest list of instructions possible to sort the stack
**a**, the smallest number being at the top.
• Instructions must be separaed by a `\n` and nothing else.
• The goal is to sort the stack with the minimum possible number of operations.

### Usage
`make` then use as follow
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG
pb
ra
pb
rr
pa
pa
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
$>
```
Obtained mark for this project : 112/100
