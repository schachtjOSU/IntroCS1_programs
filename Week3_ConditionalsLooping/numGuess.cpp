/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/18/2015
** Description: This program will generate a number at 
**     random between 1 and 100 (inclusive).  The user will 
**     be asked to guess the number till he/she gets it 
**     right with hints on how close along the way.  Upon 
**     guessing the right number, the program will the user 
**     how many guesses it took to get the right number.  
***********************************************************/

#include <iostream>
#include <cstdlib>		// Header file used for rand

using namespace std;

int main()
{
	// Variables
	int number,					// Randomly generated number
		userGuess = 0,			// The user's guess
		guessCount = 0;			// Counter for how many guesses, count starts at zero

	// Brief Description of the program
	cout << "Welcome to the Number Guess Program!" << endl;
	cout << "This program will generate an integer between 1 and 100.\n"
		<< "Your job is to guess the correct integer and when you guess correctly, \n"
		<< " the program will let you know how many guesses it took.\n";

	// Generate a random number between 1 and 100 and store it.
	number = rand() % 100 + 1;

	// Start a loop until user makes the correct guess
	while (userGuess != number)
	{
		// Ask the user which number to guess and store it
		cout << "\nWhat is the integer you would like to guess: ";
		cin >> userGuess;

		// Conditionals to compare user's guess with the number.
		// Output if the guess was to high or to low.  Count for each condition
		if (userGuess > number)
		{
			cout << "\nToo high.  Try again.";
			guessCount += 1;
		}
		else if (userGuess < number)
		{
			cout << "\nToo low.  Try again";
			guessCount += 1;
		}
		else
		{
			cout << "\nYou guessed correct!";
			guessCount += 1;
		}
	}
	
	// Output user made the correct guess and how many tries it took.
	cout << "\nYour total count of guesses is: " << guessCount;

	// Exit program
	return 0;
}
