This program executes a specified command in multiple child processes and measures the execution time of each child process. The program then calculates the maximum, minimum, and average execution times and prints the results to the console.
To run the program, compile the p2.c file using a C compiler such as gcc, and then run the resulting executable with command-line arguments:

./p2 <num_children> <command> <arg1> <arg2> ... <argn>

where:

<num_children> is the number of child processes to create.

<command> is the command to be executed by each child process.

<arg1>, <arg2>, …, <argn> are the arguments to be passed to the command.


For example, to create 3 child processes and execute the command ./my_program with arguments arg1 and arg2, run the following command:
./p2 3 ./my_program arg1 arg2

The program will then execute the command in each child process, and measure the execution time of each child process. Finally, the program will calculate the maximum, minimum, and average execution times and display them on the console.
The output of the program should look similar to the following:
Child 1 Executed in 5036.57 millis
Child 2 Executed in 5043.02 millis
Child 3 Executed in 5037.52 millis
Max: 5043.02 millis
Min: 5036.57 millis
Average: 5039.70 millis

This output shows the execution time of each child process and the calculated maximum, minimum, and average execution times.