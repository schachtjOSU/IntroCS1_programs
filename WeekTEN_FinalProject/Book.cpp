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
**  Description: Default Constructor for Book.
**  Parameters: None
************************************************************/
Book::Book()
{
	idCode = "Unkown ID Code";
	title = "Untitled";
	author = "Unkown Author";
	setLocation(ON_SHELF);
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	setDateCheckedOut(0);		// This may have to change
}

/***********************************************************
**  Description: Constructor, sets fields for a Book object
**  Parameters: 3 strings for Book: Id Code; Title, and Author
************************************************************/
Book::Book(string idc, string t, string a)
{
	setIdCode(idc);
	setTitle(t);
	setAuthor(a);
	setLocation(ON_SHELF);
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	setDateCheckedOut(0);		// This may have to change
}

/***********************************************************
**  Description: Sets the Author field in Book object
**  Parameters:	1 string for author field.
************************************************************/
void Book::setAuthor(string a)
{
	author = a;
}

/***********************************************************
**  Description: Sets the current Patron, who checked out book
**  Parameters:	1 Patron object
************************************************************/
void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

/***********************************************************
**  Description: Sets the date checked out to the field
**  Parameters: 1 integer variable as the date
************************************************************/
void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}

/***********************************************************
**  Description: Sets the ID Code field for the book
**  Parameters: 1 string variable
************************************************************/
void Book::setIdCode(string idc)
{
	idCode = idc;
}

/***********************************************************
**  Description: Sets the location field for the book
**  Parameters: 1 Locale object
************************************************************/
void Book::setLocation(Locale lo)
{
	location = lo;
}

/***********************************************************
**  Description: Sets the Patron to the request for the book
**  Parameters: 1 Patron object
************************************************************/
void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

/***********************************************************
**  Description: Sets the title of the Book object
**  Parameters: 1 string variable
************************************************************/
void Book::setTitle(string t)
{
	title = t;
}

/***********************************************************
**  Description: Return the ID Code field from Book object
**  Parameters: None
************************************************************/
string Book::getIdCode()
{
	return idCode;
}

/***********************************************************
**  Description: Return the Title field from Book object
**  Parameters: None
************************************************************/
string Book::getTitle()
{
	return title;
}

/***********************************************************
**  Description: Return the Author field from Book object
**  Parameters: None
************************************************************/
string Book::getAuthor()
{
	return author;
}

/***********************************************************
**  Description: Return the location from Book object
**  Parameters: None
************************************************************/
Locale Book::getLocation()
{
	return location;
}

/***********************************************************
**  Description: Return the checked out by field from the Book object
**  Parameters: None
************************************************************/
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

/***********************************************************
**  Description: Return the requested by field from the book object
**  Parameters: None
************************************************************/
Patron* Book::getRequestedBy()
{
	return requestedBy;
}

/***********************************************************
**  Description: Return the date checked out field from the book object
**  Parameters: None
************************************************************/
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}