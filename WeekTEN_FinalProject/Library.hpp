#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

using namespace std;

class Patron;  // forward declarations
class Book;

class Library
{
private:
	std::vector<Book> holdings;		// a list of Books the Library has
	std::vector<Patron> members;	// a list of Patrons the Libary has
	int currentDate;				// stores the current date represented as an integer number of "days" since the Library object was created
public:
	Library();						// initialize the current date to zero
	void addBook();					// prompts the user for book info (including the ID, which can be any arbitrary string) and uses it to create a Book, which is added to holdings
	void addMember();				// prompts the user for patron info (including the ID, which can be any arbitrary string) and uses it to create a Patron, which is added to members
	void checkOutBook(string, string);		
	void returnBook(std::string bookID);
	void requestBook(string, string);
	void incrementCurrentDate();
	void payFine(string, double);
	void viewPatronInfo(string);
	void viewBookInfo(string);
	int getCurrentDate();
};

#endif