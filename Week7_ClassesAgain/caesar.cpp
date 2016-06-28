/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/20/2015
** Description: This program will be take a users string 
**     and an integer offset to create a Ceaser cipher.
** References: Encrypting using Caesar Cipher C++, found 02/20/2015
**     Source - http://stackoverflow.com/questions/23281142/encrypting-using-caesar-cipher-c
     Help in making a Caesar Cipher maker, found 02/20/2015
	 Source - http://www.cplusplus.com/forum/general/42633/
***********************************************************/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/***********************************************************
**  Description: Codes the original string to a Caeser Cipher with specified offset
**  Parameters: char array and integer offset
************************************************************/
void encipher(char * cipherArray, int offset)
{
	// Variables
	int length = 0;

	// Find the length of the array
	while (cipherArray[length] != 0)
	{
		length = length++;
	}

	// Loop through array
	for ( int i = 0; i < length; i++)
	{
		if (isupper(cipherArray[i]))
		{
			cipherArray[i] = (((cipherArray[i]) - 'A' + offset) % 26 + 'A');
			if ((!isalpha(cipherArray[i])) || (islower(cipherArray[i])))
			{
				cipherArray[i] - 26;
			}
		}
		else if ((ispunct(cipherArray[i])) || (cipherArray[i] == ' '))
		{
			continue;
		}
		else
		{
			cipherArray[i] = (((cipherArray[i]) - 'a' + offset) % 26 + 'a');
			if (!isalpha(cipherArray[i]))
			{
				cipherArray[i] - 26;
			}
		}		
	}

	// Print array
	cout << "\nYour cipher is: ";
	for (int j = 0; j < length; j++)
	{
		cout << cipherArray[j];
	}
        cout << endl;
}


/***********************************************************
**  Description: Main function to get string, send string to char array, and get offset number
**  Parameters: None
************************************************************/
int main()
{
	// Variables
	string userIn;
	char ciphArray[100];
	int offset;
	int length;

	// Brief Program Title
	cout << "Welcome to the Caesar Cipher Program!" << endl << endl;

	// Ask user for the sting
	cout << "Enter your string here: ";
	cin.getline(ciphArray, 100, '\n');
	cout << endl << endl;

	// Ask for the offset
	cout << "Enter your offset: ";
	cin >> offset;

	// Start the Caesar cipher function
	encipher(ciphArray, offset);

	// Exit program
	return 0;
}
