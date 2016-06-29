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
#include <string>
#include <iomanip>
#include "Book.hpp"
#include "Library.hpp"
#include "Patron.hpp"

using namespace std;

/***********************************************************
**  Description: Default Constructor for Library.
**  Parameters: None
************************************************************/
Library::Library()
{
	vector<Book> holdings;
	vector<Patron> members;
	int currentDate = 1;
}


/***********************************************************
**  Description: Prompts the user for book info to create a book.
**      Book will be added to holdings
**  Parameters: None
************************************************************/
void Library::addBook()
{
	// Set variables
	string idCode,			// Items to add into new book object
		author,
		title;
	int holdSize;			// For debugging, size of holdings
	string stuff;			// for the extra stuff

	// Prompt user for ID code (string)
	getline(cin, stuff);
	cout << "\nPlease enter the Book's ID Code: ";
	getline(cin, idCode);

	// Prompt user for Book's title (string)
	cout << "\nPlease enter the Book's title: ";
	getline(cin, title);

	// Prompt user for Book's Author (string)
	cout << "\nPlease enter the Book's author: ";
	getline(cin, author);

	// Create the Book object
	Book nuBook(idCode, title, author);

	// Add the Book to the Library.
	holdings.push_back(nuBook);

	// Debugging Print out what is in the Library!!!!!!!!!!!!!!
	holdSize = holdings.size();
	cout << "\nNumber of books in holdings is: " << holdSize;

	// Done with this function
}

/***********************************************************
**  Description: Get the current date
**  Parameters: None
************************************************************/
int Library::getCurrentDate()
{
	return currentDate;
}

/***********************************************************
**  Description: Prompts the user for patron info, which include
**     ID and name.  Then uses the info to create a Patron and 
**     adds to members
**  Parameters: None
************************************************************/
void Library::addMember()
{
	// Set variables
	string id,			// user input
		name,
		extraStrm;		// Extra in stream
	int memSize;		// Debugging number of members

	// Clear out any extra instream
	getline(cin, extraStrm);

	// Prompt user for new ID number
	cout << "\nPlease enter the new member's ID: ";
	getline(cin, id);

	// Prompt user for name of member
	cout << "\nPlease enter the new member's name: ";
	getline(cin, name);

	// Create the new Patron
	Patron p(id, name);

	// Add member to the Library
	members.push_back(p);

	// Debugging, print out number of members in library!!!!!!!!!!!!!!!!!
	memSize = members.size();
	cout << "\nNumber of Members in Library now at: " << memSize;

	// Done with function
}

/***********************************************************
**  Description: Does a couple checks before checking book out
**      to patron.  Sets the status field of the book, change to 
**      Library status of the book, and field changes with the Patron.
**  Parameters: Takes two string parameters, patronID and bookID
************************************************************/
void Library::checkOutBook(string patronID, string bookID)
{
	// Set variables
	int sizePatron,			// Get the size of the vectors
		sizeBooks;
	string pID,
		bID;
	bool pMatch = false,	// Used to match patron and books
		bMatch = false;
	Locale loc;				// Location of book
	Locale local = CHECKED_OUT;
	Patron personID;			// Person who has it requested.
	Patron person;
	Book book;
	int date;				// current date
	Library lib;
	string title;			// Book title
	string name;			// Patron's name

	// Get the current date
	date = lib.getCurrentDate();

	// Go through Patrons to see if there is a match with patronID
	// Get the size of the vector and loop through each vector
	sizePatron = members.size();
	for (int i = 0; i < sizePatron; i++)
	{
		// Get the patron Id from memory
		pID = members[i].getIdNum();

		// Match what's in memory with user entry
		if (pID == patronID)
		{
			// There is a match. Get the person's ID
			pMatch = true;
			name = members[i].getName();
			person = members[i];
		}
	}
	if (pMatch == false)
	{
		cout << "\nThere is no Patron by that ID.  Please Try Again." << endl;
		return;
	}

	// Go through Books to see if there is a match with bookID
	// Get the size of the vector and loop through each vector in Books
	sizeBooks = holdings.size();
	for (int k = 0; k < sizeBooks; k++)
	{
		// Get the Book ID from memory
		bID = holdings[k].getIdCode();

		// Match what's in memory with user entry
		if (bID == bookID)
		{
			// It's a match!  Get location of book, personID, and bookID, title
			bMatch = true;
			loc = holdings[k].getLocation();
			book = holdings[k];
			title = book.getTitle();
		}
	}
	if (bMatch == false)
	{
		cout << "\nThere is no Book by that ID.  Please Try Again." << endl;
		return;
	}

	// If this Book is already checked out, print out that message and return to the menu
	if (loc == CHECKED_OUT)
	{
		cout << "\nThis Book is already Checked Out!  Try to Request this Book." << endl;
		return;
	}

	// If this Book is already on hold by another Patron, print out that message and return to the menu
	else if ((loc == ON_HOLD_SHELF) && (patronID != pID))
	{
		cout << "\nThis Book is already on Hold by a Patron." << endl;
		return;
	}

	// Otherwise update the Book's checkedOutBy, dateCheckedOut and Location
	else
	{
		// If the Book was on hold for this Patron, update requestedBy and update the Patron's list
		if (loc == ON_HOLD_SHELF)
		{
			personID = *book.getRequestedBy();
			book.setRequestedBy(NULL);
			// Set the Patron's List?????????????????????????
		}
		
		// Set Checked Out By with patron ID

		book.setCheckedOutBy(& person);
		// Set the location of the book to checkedout
		book.setLocation(local);
		// Set the date checked out
		date = lib.getCurrentDate();
		book.setDateCheckedOut(date);
		// Add to Patron's list
		person.addBook(&book);
	}

	// Display the Book title has been checked out by the Patron name.
	cout << "\n" << title << " has been checked out by " << name << "." << endl << endl;

	// End of function
}


/***********************************************************
**  Description: Does a couple checks before returning to the 
**      library.  Sets the status field of the book, change to
**      Library status of the book, and field changes with the Patron.
**  Parameters: Takes one string as parameter with BookID.
************************************************************/
void Library::returnBook(string bookID)
{
	// Set variables
	int sizeBooks;			// Get the size of the holdings in library
	string bID;				// Books ID
	bool bMatch = false;	// Make sure there is a match with the ID and in memory
	Locale loc;				// Get the Location of the book
	Locale local;
	Book book;				// Get the book object
	string title;			// Get the title of the book
	Patron person;			// Person who checked out book

	// Go through Books to see if there is a match with bookID
	// Get the size of the vector and loop through each vector in Books
	sizeBooks = holdings.size();
	for (int k = 0; k < sizeBooks; k++)
	{
		// Get the Book ID from memory
		bID = holdings[k].getIdCode();

		// Match what's in memory with user entry
		if (bID == bookID)
		{
			// It's a match!  Get location of book, personID, and bookID, title
			bMatch = true;
			loc = holdings[k].getLocation();
			book = holdings[k];
			title = book.getTitle();
			person = *book.getCheckedOutBy();
			
		}
	}
	if (bMatch == false)
	{
		cout << "\nThere is no Book by that ID.  Please Try Again." << endl;
		return;
	}

	// If this Book is NOT already checked out, print out that message and return to the menu
	if (loc != CHECKED_OUT)
	{
		cout << "\nThis Book is NOT Checked Out!  Please Try Again." << endl;
		return;
	}
	else
	{
		// Update the Book's location, depending on whether another Patron has requested it
		if (book.getRequestedBy() != NULL)
		{
			local = ON_HOLD_SHELF;
			book.setLocation(local);
		}
		else
		{
			local = ON_SHELF;
			book.setLocation(local);
		}

		// Update the Book's checkedOutBy
		book.setCheckedOutBy(NULL);
		book.setDateCheckedOut(0);

		// Update the Patron's list, remove book.
		person.removeBook(&book);

		// Display title has been returned
		cout << "\n" << title << " has been returned to the library." << endl << endl;
	}
}

/***********************************************************
**  Description: Does a couple checks before requesting a 
**     book.  Updates the Book's requestedBy, updates the 
**     location of the book, and prints a final message to 
**     the user.
**  Parameters: Takes 2 string parameters with BookID and PatronID.
************************************************************/
void Library::requestBook(string patronID, string bookID)
{
	// Set variables
	int sizePatron;			// Number of Patrons in Library
	string pID;				// patron ID
	bool pMatch = false;	// See if there is a match with Patron
	string name;			// Patron's name
	Patron person;			// Patron object
	int sizeBooks;			// Number of Books
	string bID;				// book ID
	bool bMatch = false;	// See if there is a match with Book
	Locale loc;				// Location of book
	Book book;				// Book object
	string title;			// Book title
	Patron request;			// Requesting Patron
	string reID;			// Requester name
	Patron check;			// Checked out Patron

	// if the Book or Patron are no in Library, print message and return to the menu
	// Go through Patrons to see if there is a match with patronID
	// Get the size of the vector and loop through each vector
	sizePatron = members.size();
	for (int i = 0; i < sizePatron; i++)
	{
		// Get the patron Id from memory
		pID = members[i].getIdNum();

		// Match what's in memory with user entry
		if (pID == patronID)
		{
			// There is a match. Get the person's ID
			pMatch = true;
			name = members[i].getName();
			person = members[i];
		}
	}
	if (pMatch == false)
	{
		cout << "\nThere is no Patron by that ID.  Please Try Again." << endl;
		return;
	}

	// Go through Books to see if there is a match with bookID
	// Get the size of the vector and loop through each vector in Books
	sizeBooks = holdings.size();
	for (int k = 0; k < sizeBooks; k++)
	{
		// Get the Book ID from memory
		bID = holdings[k].getIdCode();

		// Match what's in memory with user entry
		if (bID == bookID)
		{
			// It's a match!  Get location of book, personID, and bookID, title
			bMatch = true;
			loc = holdings[k].getLocation();
			book = holdings[k];
			title = book.getTitle();
		}
	}
	if (bMatch == false)
	{
		cout << "\nThere is no Book by that ID.  Please Try Again." << endl;
		return;
	}
	// If the Book is already requested by another Patron, print message and return to the menu
	// Find out who requested Book, compare with this person
	request = *book.getRequestedBy();
	reID = request.getIdNum();
	if (reID == patronID)
	{
		cout << "\nPatron has already requested Book.  Returning to Menu." << endl << endl;
		return;
	}

	// If the Book is currently checked out by the same Patron, print message and return to the menu
	check = *book.getCheckedOutBy();
	reID = check.getIdNum();
	if (reID == patronID)
	{
		cout << "\nPatron has already checked this book out.  Returning to Menu." << endl << endl;
		return;
	}

	// Otherwise, update Book's requestedBy, update location of Book, and print message to user
	book.setRequestedBy(&person);
	if (loc == ON_SHELF)
	{
		loc = ON_HOLD_SHELF;
		book.setLocation(loc);
	}
	cout << "\n" << title << "has been requested by " << name << "." << endl << endl;
}

/***********************************************************
**  Description: Checks whethere the Patron exists, amends the 
**     fine to the Patron's fine field, and prints summary of
**     Patron's fine field to display.
**  Parameters: Takes a string paramenter of the Patron ID and
**     a double parameter of the pay fine amount.
************************************************************/
void Library::payFine(string patronID, double payment)
{
	// Set Variables
	int sizePatron;			// Number of Patrons in Library
	string pID;				// patron ID
	bool pMatch = false;	// See if there is a match with Patron
	string name;			// Patron's name
	Patron person;			// Patron object
	double totalFines;		// Patron's total Fines

	// Validate Patron ID exists, return if not.
	// Get the size of the vector and loop through each vector
	sizePatron = members.size();
	for (int i = 0; i < sizePatron; i++)
	{
		// Get the patron Id from memory
		pID = members[i].getIdNum();

		// Match what's in memory with user entry
		if (pID == patronID)
		{
			// There is a match. Get the person's ID
			pMatch = true;
			name = members[i].getName();
			person = members[i];
		}
	}
	if (pMatch == false)
	{
		cout << "\nThere is no Patron by that ID.  Please Try Again." << endl;
		return;
	}

	// Use amendFine to update the Patron's fine
	person.amendFine(payment);

	// Print Patron name and Patron's fineAmount
	totalFines = person.getFineAmount();
	cout << "\n" << name << "'s total fine amount is $" << fixed << setprecision(2)
		<< totalFines;
}

/***********************************************************
**  Description: Increment the day, amend fines for any overdue books.
**  Parameters: None
************************************************************/
void Library::incrementCurrentDate()
{
	// Set variables
	int sizePatron;			// Number of Patrons in Library
	vector <Book*> checkOutBooks;	// Books checked out by 
	int sizeCOBooks;		// Number of checked out books
	Book book;
	int coDate;				// Original check out date
	int dateDiff;			// Difference in book checkout and current date
	double payment = -0.10;			// Pay the fine

	// Incriment the date
	currentDate += 1;

	// Get the size of the Patrons
	sizePatron = members.size();
	// Loop through each Patron
	for (int i = 0; i < sizePatron; i++)
	{
		// Get the patron's checked Out books
		checkOutBooks = members[i].getCheckedOutBooks();
		sizeCOBooks = checkOutBooks.size();
		// Loop through each checked out book
		for (int k = 0; k < sizeCOBooks; k++)
		{
			// Get the Check out date
			book = *checkOutBooks[k];
			coDate = book.getDateCheckedOut();
			dateDiff = currentDate - coDate;
			// Compare date with CO length
			if (dateDiff > book.CHECK_OUT_LENGTH)
			{
				// Amend the fine!!!
				members[i].amendFine(payment);
			}
		}
	}
	// End of function
}

/***********************************************************
**  Description: Check Patron is member, print Patron fields
**  Parameters: 1 string parameber patronID
************************************************************/
void Library::viewPatronInfo(string patronID)
{
	//Set variables
	int sizePatron;			// Number of Patrons in Library
	string pID;				// patron ID
	bool pMatch = false;	// See if there is a match with Patron
	string name;			// Patron's name
	Patron person;			// Patron object
	double fine;			// Patron's fines
	vector <Book*> checkOutBooks;	// Books checked out by 
	int sizeCOBooks;		// Number of checked out books
	Book book;
	string title;			// Title of book


	// Check Patron is member
	// Validate Patron ID exists, return if not.
	// Get the size of the vector and loop through each vector
	sizePatron = members.size();
	for (int i = 0; i < sizePatron; i++)
	{
		// Get the patron Id from memory
		pID = members[i].getIdNum();

		// Match what's in memory with user entry
		if (pID == patronID)
		{
			// There is a match. Get the person's ID
			pMatch = true;
			name = members[i].getName();
			person = members[i];
			fine = person.getFineAmount();
			checkOutBooks = person.getCheckedOutBooks();
		}
	}
	if (pMatch == false)
	{
		cout << "\nThere is no Patron by that ID.  Please Try Again." << endl;
		return;
	}
	// Print out Patron fields
	else
	{
		cout << "\nPatron ID: " << patronID << endl;
		cout << "Patron's Name: " << name << endl;
		cout << "Checked out books include:" << endl;
		sizeCOBooks = checkOutBooks.size();
		for (int i = 0; i < sizeCOBooks; i++)
		{
			book = *checkOutBooks[i];
			title = book.getTitle();
			cout << title << endl;
		}
		cout << "Total Fines: $" << fixed << setprecision(2) << fine << endl;
	}
	cout << endl << endl;
	// Exit function
}


/***********************************************************
**  Description: Check Book is in holdings, Print Book fields
**  Parameters: 1 string parameter, for BookID
************************************************************/
void Library::viewBookInfo(string bookID)
{
	// Set variables
	int sizeBooks;			// Number of Books
	string bID;				// book ID
	bool bMatch = false;	// See if there is a match with Book
	Locale loc;				// Location of book
	Book book;				// Book object
	string title;			// Book title
	Patron request;			// Requesting Patron
	string author;			// Book author
	string reqName;
	string coName;
	Patron person;
	int curDate;			// Find difference in days left
	int bookDate;
	int diffDate;
	int daysDue;

	// Go through Books to see if there is a match with bookID
	// Get the size of the vector and loop through each vector in Books
	sizeBooks = holdings.size();
	for (int k = 0; k < sizeBooks; k++)
	{
		// Get the Book ID from memory
		bID = holdings[k].getIdCode();

		// Match what's in memory with user entry
		if (bID == bookID)
		{
			// It's a match!  Get location of book, personID, and bookID, title
			bMatch = true;
			loc = holdings[k].getLocation();
			book = holdings[k];
			title = book.getTitle();
			author = book.getAuthor();
			loc = book.getLocation();		
		}
	}
	if (bMatch == false)
	{
		cout << "\nThere is no Book by that ID.  Please Try Again." << endl;
		return;
	}
	// Print Book fields
	else
	{
		cout << "\nBook ID: " << bookID << endl;
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		if (loc == CHECKED_OUT)
			cout << "Book Location: Checked Out" <<  endl;
		else if (loc == ON_HOLD_SHELF)
			cout << "Book Location: On Hold Shelf" << endl;
		else
			cout << "Book Location: On Shelf" << endl;
		if (loc == CHECKED_OUT || loc == ON_HOLD_SHELF)
		{
			request = *book.getRequestedBy();
			reqName = request.getName();
			if (reqName != "")
			{
				cout << "Book on Hold for Patron: " << reqName << endl;
			}
		}
		if (loc == CHECKED_OUT)
		{
			person = *book.getCheckedOutBy();
			coName = person.getName();
			if (coName != "")
				cout << "Book is Checked Out to: " << coName << endl;
		}
		
		// Find how many days left till due, or if overdue
		curDate = currentDate;
		bookDate = book.getDateCheckedOut();
		if (bookDate != 0)
		{
			diffDate = curDate - bookDate;
			if (diffDate > book.CHECK_OUT_LENGTH)
				cout << "Book is Overdue!" << endl;
			else
			{
				daysDue = book.CHECK_OUT_LENGTH - diffDate;
				cout << "Book is due in: " << daysDue << " days." << endl;
			}
		}
	}
}