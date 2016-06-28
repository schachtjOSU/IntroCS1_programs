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
#include "TicTacToe.hpp"
#include <string>
#include <cstring>

/***********************************************************
**  Description: Constructor for Tic Tac Toe
**  Parameters: character
************************************************************/
TicTacToe::TicTacToe(char playTurn)
{
	turn = playTurn;
}

/***********************************************************
**  Description: Starts the game and loops until a player wins or it is a draw.
**  Parameters: Takes in a Board object
************************************************************/
void TicTacToe::play(Board curBoard)
{
	// Variables
	char playerTurn;
	string playIn;
	char play[4];
	char rowCoord,
		columnCoord;
	int rowCoordInt,
		columnCoordInt;
	bool status;
	Board::state result;

	// Loop while state is still continue playing
	do
	{
		// Assign turn of the player
		playerTurn = turn;
		// Print the playing board
		curBoard.print();
		// Ask for coordinates from player, store as chars
		cout << "\n\nPlayer " << playerTurn << " select coordinates: ";
		getline(cin, playIn);
		//strncpy_s(play, playIn.c_str(), sizeof(play));
		rowCoord = playIn.at(0);
		columnCoord = playIn.at(2);
		rowCoordInt = rowCoord - 48;
		columnCoordInt = columnCoord - 48;
		// Go through make move method with coordinates
		status = curBoard.makeMove(rowCoordInt, columnCoordInt, playerTurn);
		// Announce coordinates are occupied if return is false
		if (!status)
		{
			cout << "\nThese coordinates are occupied.  Try again." << endl;
			continue;
		}
		else
		{
			// Any change in the status of the game?
			result = curBoard.gameState();
			// Change player turn
			if (playerTurn == 'x')
			{
				turn = 'o';
			}
			else
			{
				turn = 'x';
			}
		}
	} while (result == Board::Continue);
	// Print final board
	curBoard.print();
	// Conditional to output status of game
	if (result == Board::Draw)
		cout << "\n\nThis game is a draw!\n";
	else if (result == Board::PlayerX)
		cout << "\n\nPlayer X wins this round!\n";
	else if (result == Board::PlayerO)
	{
		cout << "\n\nPlayer O wins this round!\n";
	}
}

/***********************************************************
**  Description: Main function to start the program
**  Parameters: None
************************************************************/
int main()
{
	// Variables
	char userIn;
	Board board;
	string playerSelect;

	// Brief Program Title
	cout << "Welcome to the Tic Tac Toe Program!";

	// Ask which player to begin, x or o.  Store answer
	cout << "\n\nEnter x or o for which player to go first: ";
	getline(cin, playerSelect);
	userIn = playerSelect.at(0);
	userIn = tolower(userIn);

	// Create Tic Tac Toe object, pass char as argument
	TicTacToe game(userIn);

	// Start the game
	game.play(board);

	// Exit the program
	return 0;
}