Intro to Computer Science 1
Week 7: More programming with classes
Author: Jeffrey Schachtsick

** Files **
Board.hpp
Board.cpp
caesar.cpp
Item.hpp
Item.cpp
ShopCart.hpp
ShopCart.cpp
TicTacToe.hpp
TicTacToe.cpp
makefile

** Compiling **
Each of the files included in this file have been compiled using Visual Studio 2013.  You could also compile the files using gcc.  It should be noted, the files should not be compiled together, but as seperate programs.  To compile them all at once, I was provided with a makefile from the course which is included.

** TicTacToe Program **
This program will be using classes to play a Tic Tac Toe game.  The users will choose whether X or O player will go first.  Users will make selections on the board until there is 3 of their marks in a row   or there is no more spaces available.  The board will be printed each time.  Also uses the Board.cpp and Board.hpp files for implementation.

** caesar Program **
This program will be take a users string and an integer offset to create a Ceaser cipher.

** ShopCart Program **
This program will be using classes to store items into an Item class vector.  The user will be able to add items, list contents, calculate total price in the shopping cart, or quit the program.  Also uses the Item.cpp and Item.hpp files for implementation.

