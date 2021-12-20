# Object-Oriented-Programming-Assignments

Excercise 1 (Basic input and output, arrays and pointers)

Write a program that first asks from the user how many numbers he needs. After that the
program allocates memory space to store those numbers (integer array). Next the program
fills the array with random numbers between 0 - 99, and the program displays all numbers
from the array. After that the program calculates the mean of the generated number
calling a separate function, int mean(int *array, int n). Finally the program must
free the memory space it allocated.

There is rand() function for generating random numbers. Limiting the range to [0,99] is
done with rand() % 100. In order to use rand() function you must include cstdlib header.