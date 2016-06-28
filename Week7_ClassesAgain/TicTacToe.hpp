#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/19/2015
** Description: This program will be using classes to play a
**     Tic Tac Toe game.  The users will choose whether X or
**     O player will go first.  Users will make selections
**     on the board until there is 3 of their marks in a row
**     or there is no more spaces available.  The board will
**     be printed each time.
***********************************************************/
#include <iostream>
#include "Board.hpp"

using namespace std;

class TicTacToe
{
private:
	Board playerTurn;				// Player's turn
	char turn;

public:
	TicTacToe(char);		// Constructor
	void play(Board);		// play method
};

#endif