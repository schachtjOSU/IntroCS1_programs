/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/07/2015
** Description: This program will be using classes to ask
**     the user for the height, width, and length of a box.
**     Input validation will result for numbers less than 0.
**     The program will output total volume and surface
**     area of the box.
***********************************************************/

#include <iostream>
#include "Box.hpp"

using namespace std;

// Default Constructor
Box::Box()
{
	setHeight(1);
	setWidth(1);
	setLength(1);
}

// Constructor for taking 3 parameters
Box::Box(double boxHeight, double boxWidth, double boxLength)
{
	setHeight(boxHeight);
	setWidth(boxWidth);
	setLength(boxLength);
}


// Functions for setting the height, width, and length when constructor given parameters
void Box::setHeight(double boxHeight)
{
	height = boxHeight;
}

void Box::setWidth(double boxWidth)
{
	width = boxWidth;
}

void Box::setLength(double boxLength)
{
	length = boxLength;
}


// Function for finding the Volume
double Box::getVolume()
{
	double volume;		// Total volume for box

	volume = height*length*width;
	return volume;
}

// Function for finding box's total surface area
double Box::getSurfaceArea()
{
	double surfArea;	// Total surface area of box
	double hwArea,		// Area of height and width
		hlArea,			// Area of height and length
		wlArea;			// Area of width and length

	// Find areas
	hwArea = height * width;
	hlArea = height * length;
	wlArea = width * length;
	surfArea = (2 * hwArea) + (2 * hlArea) + (2 * wlArea);
	return surfArea;
}


// Main function
int main()
{
	// Variables
	double boxHeight,	// User input for box height
		boxWidth,		// User input for box width
		boxLength;		// User input for box length

	double volume;
	double surfArea;

	// Brief Description
	cout << "Welcome to the Box Program" << endl;
	cout << "\nThis program will take your height, width, and length of a box"
		"\nand output the volume and surface area of that box." << endl;

	// Ask the user for height, width, and length
	cout << "\nEnter the box height: ";
	cin >> boxHeight;
	cout << "\nEnter the box width: ";
	cin >> boxWidth;
	cout << "\nEnter the box length: ";
	cin >> boxLength;

	// Conditionals for input validation
	if (boxHeight < 0)
	{
		cout << "\nError: height entered was less than 0"
			<< "\nSetting height to 0";
		boxHeight = 0;
	}
	if (boxWidth < 0)
	{
		cout << "\nError: width entered was less than 0"
			<< "\nSetting width to 0";
		boxWidth = 0;
	}
	if (boxLength < 0)
	{
		cout << "\nError: length entered was less than 0"
			<< "\nSetting length to 0";
		boxLength = 0;
	}

	// Conditional for constructors????
	Box box(boxHeight, boxWidth, boxLength);
	volume = box.getVolume();
	surfArea = box.getSurfaceArea();

	// Output results for volume and surface area
	cout << "\nThe box's volume is: " << volume;
	cout << "\nThe box's surface area is: " << surfArea
		<< endl;

     system("pause");
	// Exit the program
	return 0;
}