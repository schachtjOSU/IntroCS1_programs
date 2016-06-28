#ifndef BOARD_HPP
#define BOARD_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/18/2015
** Description: This program will be using classes to play a 
**     Tic Tac Toe game.  The users will choose whether X or 
**     O player will go first.  Users will make selections 
**     on the board until there is 3 of their marks in a row 
**     or there is no more spaces available.  The board will 
**     be printed each time.
***********************************************************/
#include <iostream>

using namespace std;

class Board
{
private:
	char board[3][3];		// Two dimensional array

public:
	Board();								// Default Constructor
	bool makeMove(int, int, char);			// Method for taking and validating coordinates
	enum state
	{
		PlayerX,
		PlayerO,
		Draw,
		Continue
	};										
	state gameState();				// Method for identifying the state of the game
	void print();							// Method to print the board array for the users
};


#endif