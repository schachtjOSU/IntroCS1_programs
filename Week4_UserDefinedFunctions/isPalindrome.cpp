/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/28/2015
** Description: This program will read a string, take the 
**     string as a parameter to a function, then decide 
**     whether the string is a palindrome.
***********************************************************/

#include <iostream>
#include <string>

using namespace std;

// Boolean function decide if string is palindrome.
/* Reference: The function below has code taken from 
**     "Easiest way to check if a string is pallindrome"
**     www.http://stackoverflow.com/questions/8444710/easiest-way-to-check-if-a-string-is-palindrome
**     Date found: 01/28/2015 */
/* Reference: "std::string::at"
**     http://www.cplusplus.com/reference/string/string/at/
**     Date found: 01/28/2015 */
bool isPalindrome(string word)
{
	// Set variables
	int num;		// total length of word

	// Find length of word
	num = word.length();

	// Loop through characters in word and find any mismatches forward and backward
	for (int i = 0; i < (num / 2) + 1; ++i)
	{
		// Condition if there is a mismatch
		if (word.at(i) != word.at(num - i - 1))
			return false;
	}
	return true;
}

// Main function
int main()
{
	// Set variables
	string word;		// User entered word

	// Briefly describe program
	cout << "Welcome to the Pallindrome Program!\n";
	cout << "\nPlease enter a word you think is a pallindrome"
		<< "\nand the program will decide if it is or not.\n";

	// Take in a word
	cout << "Please enter your word: ";
	getline(cin, word);

	// Boolean function to decide if word is Pallindrome
	bool answer = isPalindrome(word);

	// Output result
	if (answer)
	{
		cout << "\nYour word " << word << " is a pallindrome.\n";
	}
	else
		cout << "\nYour word " << word << " is NOT a pallindrome.\n";

	// Exit program
	return 0;
}