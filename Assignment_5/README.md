# Object-Oriented-Programming-Assignments

Excercise A - Implement operators

Improve class you wrote in exercise 4 by adding overloaded operators. The operators to
add are:
1. Output operator ( << ) that outputs the time in two character fields with leading
zeros and separates the fields with a colon.
2. Comparison operator less than ( < ) that compares two times
3. Addition operator ( + ) that adds two times
4. Subtract operator ( - ) that subtracts two times.
5. Pre and post increment operators ( ++ ). Both operators increment the time by one
minute

Your class should work with the test program below. Note that your class must have a
default constructor that initializes time to 0:00.

Addition must make times to roll over to “next day” but doesn’t have to keep track of
days. For example, adding 14:30 and 13:45 should result in 4:15 or adding 18:30 and 5:37
should yield 0:07.