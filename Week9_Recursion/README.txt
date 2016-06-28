Intro to Computer Science 1
Week 9: Working on Recursion Functions
Author: Jeffrey Schachtsick

** Files **
convert.cpp
hailstone2.cpp
recSum.cpp
revPrint.cpp
makefile

** Compiling **
Each of the files included in this file have been compiled using Visual Studio 2013.  You could also compile the files using gcc.  It should be noted, the files should not be compiled together, but as seperate programs.  To compile them all at once, I was provided with a makefile from the course which is included.

** convert Program **
This program will ask the user to decide whether they would like to convert a binary number to decimal format or a decimal into binary.  This program will use recursive function to display the number in the format choice of the user.
Known Issues: not appropriately allocating memory.

** hailstone2 Program **
This program will read an integer from the user, then start the hailstone sequence.  The hailstone sequence goes through conditional steps until the number is wittled down to the number 1.  The conditional 
steps include if that integer is even, then you divide it by two to get the next integer in the sequence, but if it is odd, then you multiply it by three and add one to get the next integer in the sequence.  For each conditional step, the number of sequences is counted and that sequence will be displayed for the user.

** recSum Program **
This program will ask the user how many numbers of double type to be entered, ask the user for those numbers, and then add them up in a recursive function.

** revPrint Program **
This program will ask the user how many integers to be entered, ask the user for those integers, and then prints out the integers in reverse order.

