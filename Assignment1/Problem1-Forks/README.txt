Fork and Process Hierarchy

This set of programs demonstrates the use of the fork() system call to create child processes and build a process hierarchy.
Program 1: p1a.c

The p1a.c program creates a process hierarchy with n child processes (specified on the command line as a single argument). When the program is run, it prints information about each process in the hierarchy, including its process ID, its parent process ID, and the depth of the process in the hierarchy.
To compile and run the program, open a terminal window and navigate to the directory containing the p1a.c file. Then, type the following commands and press Enter:
gcc p1a.c -o p1a
./p1a n

where n is the number of child processes to create.
Program 2: p1b.c

The p1b.c program creates a child process and prints a message indicating whether the parent or child process was created. If the child process was successfully created, it immediately exits. If the parent process was created, it waits for 5 seconds before exiting.
To compile and run the program, open a terminal window and navigate to the directory containing the p1b.c file. Then, type the following command and press Enter:
gcc p1b.c -o p1b
./p1b

Example Output

When you run the programs, you should see output similar to the following:
p1a.c

Main ProcessID: 1234, level: 0
Process ID: 1235, Parent ID: 1234, level: 1
Process ID: 1236, Parent ID: 1235, level: 2
Process ID: 1237, Parent ID: 1235, level: 2
Process ID: 1238, Parent ID: 1234, level: 1
Process ID: 1239, Parent ID: 1238, level: 2
Process ID: 1240, Parent ID: 1238, level: 2

p1b.c

Child process created.
Parent process created.

In the p1b.c output, the order of the printed messages may vary depending on the timing of the program execution.
