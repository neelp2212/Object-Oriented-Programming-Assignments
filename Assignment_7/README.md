# Object-Oriented-Programming-Assignments

In this exercise we use STL iterators, algorithms and function objects.
Excercise A 
Constructor takes two parameters that determine the range of numbers that the generator
produces.

Write a program that generates numbers for three different games:
1. Lotto: 7 numbers 1 – 40
2. Viking lotto: 6 numbers 1 – 48
3. Eurojackpot: 5 numbers 1 – 50

Use either generate or generate_n algorithm to generate the three sets of numbers.
Print each set of numbers using a suitable algorithm and output stream iterator.
Then find numbers that appear in all three sets and print them. Use set_intersection
algorithm to find the numbers that appear in all three sets:
• Find matching numbers from two sets and print them using for_each algorithm
• Find matching number from the third set and print them using for_each algorithm
To print the numbers with index numbering you need to use a function object (can also be
implemented with a lambda) to remember the index between calls.

Example:
Lotto: 1 12 24 36 11 15 32
Viking lotto: 24 7 11 18 35 1
Matching numbers:
#1: 1
#2: 11
#3: 24
Eurojackport: 47 1 40 24 4
Matching numbers in three sets:
#1: 1
#2: 24

After finding the matching numbers ask user if he/she wants to continue. If the answer is
yes then generate another three sets of lotto numbers