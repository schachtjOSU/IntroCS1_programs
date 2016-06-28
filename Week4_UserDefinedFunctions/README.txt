Intro to Computer Science 1
Week 4: User Defined Functions
Author: Jeffrey Schachtsick

** Files **
smallSort.cpp
isPrime.cpp
isPalindrome.cpp
hailstone.cpp
fallDistance.cpp
Makefile

** Compiling **
Each of the files included in this file have been compiled using Visual Studio 2013.  You could also compile the files using gcc.  It should be noted, the files should not be compiled together, but as seperate programs.  To compile them all at once, I was provided with a Makefile from the course which is included.

** smallSort Program **
This program will read in three integers from the user, print out the original order, sort the order from lowest to highest with a void function, then finally printing out the new order.

** isPrime Program **
This program will read a positive integer from the user, passed as a parameter to a boolean function, then the function will return true or false to whether the number was a prime number.

** isPalindrome Program **
This program will read a string, take the string as a parameter to a function, then decide whether the string is a palindrome.

** hailstone Program **
This program will read an integer from the user, then start the hailstone sequence.  The hailstone sequence goes through to conditional steps until the number is wittled down to the number 1.  The conditional steps include if that integer is even, then you divide it by two to get the next integer in the sequence, but if it is odd, then you multiply it by three and add one to get the next integer in the sequence.  For each conditional step, the number of sequences is counted and that sequence will be displayed for the user.

** fallDistance Program **
This program will read a number as the falling time for an object.  The number will be calculated to determine the object's distance to fall and the distance will be output to display.

