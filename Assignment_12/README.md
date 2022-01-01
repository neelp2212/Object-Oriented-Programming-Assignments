# Object-Oriented-Programming-Assignments

-Constructor takes two parameters that determine the range of numbers that the generator
produces. The parameters are: upper and lower limit of the range. Both values are
included in the range. For example: lower = 2, upper = 6 can produce following random
numbers: 2, 3, 4, 5, 6.
The example generator used in the slides gets stuck in an infinite loop if all numbers in the
range have already been used. Improve the generator so that it throws runtime_error if all
numbers in the range have already been used.
Write a test program to test your random number generator. Function test_generator tries
to generate requested number of unique random numbers. Function catches exceptions
and prints a message if an exception occurs. Finally the program prints the generated
random numbers.
void test_generator(UniqueRng ur, int count)
int main(void) {
 UniqueRng randGen(5, 13);
 test_generator(randGen, 6);
 test_generator(randGen, 9);
 test_generator(randGen, 13);
 UniqueRng randGen2(1, 35);
 test_generator(randGen2, 7);
 test_generator(randGen2, 7);
 test_generator(randGen2, 7);
 test_generator(randGen2, 70);
}
