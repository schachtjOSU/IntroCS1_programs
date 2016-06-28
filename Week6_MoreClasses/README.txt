Intro to Computer Science 1
Week 6: More programming with classes
Author: Jeffrey Schachtsick

** Files **
Car.hpp
Car.cpp
LineSegment.hpp
LineSegment.cpp
Point.hpp
Point.cpp
Supplies.hpp
Supplies.cpp
makefile

** Compiling **
Each of the files included in this file have been compiled using Visual Studio 2013.  You could also compile the files using gcc.  It should be noted, the files should not be compiled together, but as seperate programs.  To compile them all at once, I was provided with a makefile from the course which is included.

** Car Program **
This program will be using classes to ask the user for the year and make of the car.  The user will then be able to accelerate or put on the brakes until he/she decides to quit.  Each time the user decides to accelerate or brake the display will print the speed.  The car can only go between 0 and 80 speed.

** LineSegment Program **
This program will be using classes to input x and y coordinate points, calculate the length of the line segment, and calculate the slope of the line between two points.  Also uses Point.cpp and Point.hpp files for implementation.

** Supplies Program **
This program will be using classes to track inventory changes of the thingamajigs, watchamacalits,  and framistats.  The program will allow the user to produce more inventory, print a parts order or quit the program.

