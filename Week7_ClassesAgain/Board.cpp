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
#include "Board.hpp"

using namespace std;

/***********************************************************
**  Description:  Default Constructor
**  Parameters: None
************************************************************/
Board::Board()
{
	for (int rows = 0; rows < 3; rows++)
	{
		for (int columns = 0; columns < 3; columns++)
		{
			board[rows][columns] = { '.' };
		}
	}
}

/***********************************************************
**  Description:  With the coordinates, checks to see if element is empty.  places player mark if so.
**  Parameters: Takes integers for coordinates of rows and columns.  Also, who is playing.
************************************************************/
bool Board::makeMove(int rows, int columns, char player)
{
	// Variables
	bool placedMove;

	// Check if coordinates are empty, return true if so
	if (board[rows][columns] == '.')
	{
		board[rows][columns] = player;
		placedMove = true;
	}
	// if not empty, return false
	else
	{
		placedMove = false;
	}

	// return the placed move
	return placedMove;
}

/***********************************************************
**  Description: Goes through the array to see if either player has won.  Returns state of the game
**  Parameters: None
************************************************************/
Board::state Board::gameState()
{
	// Variables
	int rows = 0;
	int columns = 0;
	char playerSpot;
	int secElement = 1;
	int thirdElement = 2;
	int counter = 0;
	bool winSelect = false;

	// Loop through each row
	for (rows = 0; rows < 3; rows++)
	{
		// If the space is NOT empty
		if (board[rows][columns] != '.')
		{
			// Assign player spot
			playerSpot = board[rows][columns];
			// Does the player spot also inlcude in the second and third column of row?
			if ((board[rows][secElement] == playerSpot) && (board[rows][thirdElement] == playerSpot))
			{
				// Return Winner
				if (playerSpot == 'x')
				{
					return PlayerX;
					winSelect = true;
				}
				else
				{
					return PlayerO;
					winSelect = true;
				}
			}
		}
	}
	// Clean up rows
	rows = 0;

	// Loop through each column
	for (columns = 0; columns < 3; columns++)
	{
		// If the space is NOT empty
		if (board[rows][columns] != '.')
		{
			// Assign player spot
			playerSpot = board[rows][columns];
			// Does the player spot also include in the second and third row of the column?
			if ((board[secElement][columns] == playerSpot) && (board[thirdElement][columns] == playerSpot))
			{
				// Return Winner
				if (playerSpot == 'x')
				{
					return PlayerX;
					winSelect = true;
				}
				else
				{
					return PlayerO;
					winSelect = true;
				}
			}
		}
	}

	// Check diagnal
	if (board[1][1] != '.')
	{
		// Assign middle spot
		playerSpot = board[1][1];
		// Does the player spot in middle exist in two other diagnol spots?
		if ((board[0][0] == playerSpot) && (board[2][2] == playerSpot))
		{
			// Return Winner
			if (playerSpot == 'x')
			{
				return PlayerX;
				winSelect = true;
			}
			else
			{
				return PlayerO;
				winSelect = true;
			}
		}
		// Does the player spot in middle exist in the other two diagnol spots?
		else if ((board[2][0] == playerSpot) && (board[0][2] == playerSpot))
		{
			// Return Winner
			if (playerSpot == 'x')
			{
				return PlayerX;
				winSelect = true;
			}
			else
			{
				return PlayerO;
				winSelect = true;
			}
		}
	}
	if (winSelect == false)
	{
		// Loop through array for empty spots
		for (rows = 0; rows < 3; rows++)
		{
			for (columns = 0; columns < 3; columns++)
			{
				if (board[rows][columns] != '.')
				{
					counter++;
				}
			}
		}
		if (counter == 9)
		{
			return Draw;
		}
		else
		{
			return Continue;
		}
	}
}

/***********************************************************
**  Description: This prints the board to display
**  Parameters: None
************************************************************/
void Board::print()
{
	// Variables
	int rows;
	int columns;
	board[rows][columns];
	// Print columns
	cout << "\n\n   0  1  2";

	//Loop through each row to print
	for (rows = 0; rows < 3; rows++)
	{
		cout << "\n" << rows;
		for (columns = 0; columns < 3; columns++)
		{
			cout << "  " << board[rows][columns];
		}
	}
}