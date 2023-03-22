This program searches for a given number in a sequence of integers by dividing the sequence into multiple disjoint portions and searching each of these portions using multiple child processes in parallel.

Purpose

The purpose of this program is to demonstrate how to parallelize a search algorithm for improved performance by taking advantage of multiple CPU cores.

Building

To build the program, navigate to the program directory and run the following command:
gcc -o program program.c

Usage

The program is executed as follows:
./program <number> <n>

where <number> is the number to search for, and <n> is the number of child processes to use for the search.
The input sequence of integers to search through is read from the standard input stream. The sequence should be entered as space-separated integers in a single line, followed by the end-of-file character.

Testing

To test the program, run it with different input sequences and values of n, and verify that it correctly finds the given number in the sequence (if it exists). Here are a few examples:
// Test with a small input sequence and 3 child processes
$ echo "1 2 3 4 5 6 7 8 9 10" | ./program 8 3

// Test with a large input sequence and 10 child processes
$ seq 1 100000 | ./program 777 10
