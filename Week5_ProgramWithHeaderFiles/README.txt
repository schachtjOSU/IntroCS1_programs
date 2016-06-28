Intro to Computer Science 1
Week 5: Programming with Header files and Classes
Author: Jeffrey Schachtsick

** Files **
Box.h
Box.cpp
Date.h
Date.cpp
DiceCup.h
DiceCup.cpp
Hero.h
Hero.cpp
makefile

** Compiling **
Each of the files included in this file have been compiled using Visual Studio 2013.  You could also compile the files using gcc.  It should be noted, the files should not be compiled together, but as seperate programs.  To compile them all at once, I was provided with a makefile from the course which is included.

** Box Program **
This program will be using classes to ask the user for the height, width, and length of a box.  Input validation will result for numbers less than 0.  The program will output total volume and surface area of the box.

** Date Program **
This program will be using classes to ask the user the month, day and year.  The user will be able to select which format within a loop until she/he decides to quit the program.

** DiceCup Program **
This program will be using classes to ask the user for the number of dice and the number of faces on each dice.  Then the program will ask the number of rolls of the dice cup and will output each total value of all dice for each roll of the dice.

** Hero Program **
This program will be using classes to ask the user attributes of their Hero.  Fields of the Hero will contain strength, hit points, speed, and money.  The program will then ask the user how much damage the Hero has sustained until and keep going until the hero runs out of hit points.  Output will display all attributes after each damage taken by the hero.

