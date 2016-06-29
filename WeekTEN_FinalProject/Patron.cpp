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
#include <vector>
#include "Book.hpp"
#include "Library.hpp"
#include "Patron.hpp"

using namespace std;

/***********************************************************
**  Description: Default Constructor for Patron.
**  Parameters: None
************************************************************/
Patron::Patron()
{
	setIdNum("Unknown ID");
	setName("Unknown Name");
	vector <Book*> checkedOutBooks(0);
	fineAmount = 0.0;
}

/***********************************************************
**  Description: Constructor for Patron.
**  Parameters: Takes two string parameters
************************************************************/
Patron::Patron(string id, string n)
{
	setIdNum(id);
	setName(n);
	vector <Book*> checkedOutBooks(0);
	fineAmount = 0.0;
}

/***********************************************************
**  Description: Sets the idNum field in Patron object
**  Parameters: Takes a string parameter
************************************************************/
void Patron::setIdNum(string id)
{
	idNum = id;
}

/***********************************************************
**  Description: Sets the name field in Patron object
**  Parameters: Takes a string parameter
************************************************************/
void Patron::setName(string n)
{
	name = n;
}

/***********************************************************
**  Description: Returns the idNum field of the Patron object
**  Parameters: None
************************************************************/
string Patron::getIdNum()
{
	return idNum;
}

/***********************************************************
**  Description: Returns the name field of the Patron object
**  Parameters: None
************************************************************/
string Patron::getName()
{
	return name;
}

/***********************************************************
**  Description: Adds a book to the Patron's vector
**  Parameters: Book ojbect, passed by reference
************************************************************/
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

/***********************************************************
**  Description: Removes a book to the Patron's vector
**  Parameters: Book Object, passed by reference
************************************************************/
void Patron::removeBook(Book* b)
{
	// Set variables
	int sizeCO;
	
	// Find book in checked out books
	sizeCO = checkedOutBooks.size();
	for (int i = 0; i < sizeCO; i++)
	{
		if (checkedOutBooks[i] == b)
			checkedOutBooks.erase(checkedOutBooks.begin() + i, checkedOutBooks.end() + i);
	}
}

/***********************************************************
**  Description: Amends the Patron's total fines
**  Parameters: Takes 1 double type parameter of payment
************************************************************/
void Patron::amendFine(double payment)
{
	// Subtract payment from the fineAmount
	fineAmount -= payment;
}


/***********************************************************
**  Description: Returns the fineAmount
**  Parameters: None
************************************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}

/***********************************************************
**  Description:  Return volume of Patron's books checked out
**  Parameters: None
************************************************************/
vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}