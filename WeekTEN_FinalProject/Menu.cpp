/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 03/08/2015
** Description: This program will be using classes to create 
**     a Library object.  The user will be able to make 
**     adjustments to the Library through a Menu until 
**     exiting the program.
***********************************************************/
// Include Header Files here
#include <iostream>
#include "Book.hpp"
#include "Library.hpp"
#include "Patron.hpp"

using namespace std;

/***********************************************************
**  Description: Main will display a menu and based on user's
**     choice, pass to the correct function.
**  Parameters: none
************************************************************/
int main()
{
	// Set variables
	bool exitProgram = false;		// Flag to exit program loop
	char chooseLetter;
	string extraStream;				// For in case of extra in Stream garbage
	string patronID;				// variables for user entering data
	string bookID;
	double pay;						// For the payFine

	// Brief Title
	cout << "***************************************" << endl;
	cout << "**                                   **" << endl;
	cout << "** Welcome to the Library Simulator! **" << endl;
	cout << "**                                   **" << endl;
	cout << "***************************************" << endl << endl;
	
	// Create the Library object
	Library library;

	// Loop through Menu, until exit
	do
	{
		// Display the Menu
		cout << "***  Library Simulator Menu ***" << endl << endl;
		cout << "B) Add a Book to the Library." << endl;
		cout << "P) Add a Patron to the Library." << endl;
		cout << "C) Check out a Book." << endl;
		cout << "R) Return a Book." << endl;
		cout << "U) Request a Book." << endl;
		cout << "F) Pay Patron Fine." << endl;
		cout << "D) Increment the Current Date." << endl;
		cout << "V) View Patron Info." << endl;
		cout << "I) View Book Info." << endl;
		cout << "Q) Exit the Library Simulator." << endl;

		// Ask for a choice from user and store value
		cout << "From the menu, choose a number above: ";
		cin >> chooseLetter;
		chooseLetter = toupper(chooseLetter);

		// Switch for each option
		switch (chooseLetter)
		{
		case 'B':
		{
			cout << "\n** Add a Book to the Library **" << endl;
			library.addBook();
			cout << endl << endl;
			break;
		}
		case 'P':
		{
			cout << "\n** Add a Patron to the Library **" << endl;
			library.addMember();
			cout << endl << endl;
			break;
		}
		case 'C':
		{
			cout << "\n** Check out a Book **" << endl;
			getline(cin, extraStream);
			cout << "\nPlease enter the Patron ID: ";
			getline(cin, patronID);
			cout << "\nPlease enter the Book's ID: ";
			getline(cin, bookID);
			library.checkOutBook(patronID, bookID);
			break;
		}
		case 'R':
		{
			cout << "\n** Return a Book **" << endl;
			getline(cin, extraStream);
			cout << "\nPlease enter the Book's ID: ";
			getline(cin, bookID);
			library.returnBook(bookID);
			break;
		}
		case 'U':
		{
			cout << "\n** Request a Book **" << endl;
			getline(cin, extraStream);
			cout << "\nPlease enter the Patron ID: ";
			getline(cin, patronID);
			cout << "\nPlease enter the Book's ID: ";
			getline(cin, bookID);
			library.requestBook(patronID, bookID);
			break;
		}
		case 'F':
		{
			cout << "\n** Pay Patron Fine **" << endl;
			getline(cin, extraStream);
			cout << "\nPlease enter the Patron ID: ";
			getline(cin, patronID);
			cout << "\nPlease enter the amount to pay: ";
			cin >> pay;
			library.payFine(patronID, pay);
			break;
		}
		case 'D':
		{
			cout << "\n** Increment the Current Date **" << endl;
			library.incrementCurrentDate();
			break;
		}
		case 'V':
		{
			cout << "\n** View Patron Info **" << endl;
			getline(cin, extraStream);
			cout << "\nPlease enter the Patron ID: ";
			getline(cin, patronID);
			library.viewPatronInfo(patronID);
			break;
		}
		case 'I':
		{
			cout << "\n** View Book Info **" << endl;
			getline(cin, extraStream);
			cout << "\nPlease enter the Book's ID: ";
			getline(cin, bookID);
			library.viewBookInfo(bookID);
			break;
		}
		case 'Q':
		{
			cout << "\nThank you for using the Library Simulator!" << endl;
			exitProgram = true;
			break;
		}
		default:
		{
			cout << "\nSorry, I did not understand your entry.  Try Again!" << endl;
			break;
		}
		}


	} while (!exitProgram);

	// Exit the program
	cout << endl;
     system("pause");
	return 0;
}