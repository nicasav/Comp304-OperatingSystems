# COMP 304 - Operating Systems: Assignment 1 Solutions

## Purpose
The purpose of these programs is to demonstrate various concepts related to Operating Systems, such as forks, pipes, and shared memory.

## How to Build and Run
For each program, navigate to its corresponding subdirectory and follow the instructions provided in the README file. The instructions include how to compile and run the program, as well as any necessary command-line arguments and input formats.

## Instructions for Each Program

### Problem 1: Forks

#### Part (a): A program to demonstrate the creation of processes using fork() system call:

- Navigate to the "problem1a_forks" directory.
- Compile the program using the "make" command.
- Run the program using the following command: "./fork_demo <n>", where "n" is the number of processes to create.

#### Part (b): A program to create a zombie process that remains in the system for at least 5 seconds:

- Navigate to the "problem1b_zombie" directory.
- Compile the program using the "make" command.
- Run the program using the following command: "./zombie_demo &". Make sure to include the "&" symbol to run the program in the background.
- Check if the child process has become a zombie by running the "ps -l" command.

### Problem 2: Pipes

A program to benchmark the execution times of child processes:

- Navigate to the "problem2_pipes" directory.
- Compile the program using the "make" command.
- Run the program using the following command: "./benchmark <n> <command>", where "n" is the number of child processes to create and "command" is the command to be executed by the child processes.

### Problem 3: Shared Memory

A program to search for a given number in a sequence using multiple processes:

- Navigate to the "problem3_shared_mem" directory.
- Compile the program using the "make" command.
- Run the program using the following command: "./search <x> <n>", where "x" is the number to search for and "n" is the number of child processes to create. The sequence of numbers to search through should be entered through the standard input stream (stdin).
