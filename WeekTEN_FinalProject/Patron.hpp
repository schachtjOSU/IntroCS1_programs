#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>

using namespace std;

class Book;  // forward declaration

class Patron
{
private:
	string idNum;			// a unique identifier for a Patron
	string name;			// cannot be assumed to be unique
	vector<Book*> checkedOutBooks;		// a list of Books that Patron currently has checkedOut
	double fineAmount;			// how much the Patron owes the Library in late fines
public:
	Patron();
	Patron(string, string);		// Takes in idNum and name
	void setIdNum(string);
	void setName(string);
	string getIdNum();						
	string getName();
	vector<Book*> getCheckedOutBooks();
	void addBook(Book* );				// adds the specified Book to checkedOutBooks
	void removeBook(Book* );			// removes the specified Book from checkedOutBooks
	double getFineAmount();
	void amendFine(double);		// a positive argument increases the fineAmount, a negative one decreases it.
};

#endif