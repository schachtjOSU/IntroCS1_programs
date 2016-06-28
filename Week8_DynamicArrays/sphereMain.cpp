/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/25/2015
** Description: This program will be using classes to create
**     a Sphere object.  The user will input the radius of
**     the sphere and from there, the program will caluclate
**     the volume of the sphere and output the result for display.
***********************************************************/
#include <iostream>
#include "Sphere.hpp"

using namespace std;

/***********************************************************
**  Description: Calls the getVolume method and prints the radius and volume of the sphere.
**  Parameters: Takes the sphere object address
************************************************************/
void printSphereInfo(Sphere &sphere)
{
	// Set Variables
	double volume;
	double radius;

	// Call the getVolume method
	volume = sphere.getVolume();
	radius = sphere.getRadius();

	// Print the radius and volume of the sphere
	cout << "\n\nRadius of the sphere is: " << radius;
	cout << "\nVolume of the sphere is: " << volume;

	// End of void function
	cout << endl;
}


/***********************************************************
**  Description: Main function to get radius from user
**  Parameters: None
************************************************************/
int main()
{
	// Set variables
	double userRad;
	Sphere sphere;
	Sphere *pSphere;

	// Assign address
	pSphere = &sphere;

	// Brief Title
	cout << "Welcome to the Sphere Program!" << endl << endl;

	// Ask for the radius from the user
	cout << "Enter the radius here: ";
	cin >> userRad;

	// Assign the radius to access the member
	pSphere->setRadius(userRad);
		
	// Call the printSphereInfo function and send the Sphere objects address from pointer
	printSphereInfo(*pSphere);

	// Exit the program

	return 0;
}