/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/11/2015
** Description: This program will be using classes to ask
**     the user for the year and make of the car.  The user
**     will then be able to accelerate or put on the brakes
**     until he/she decides to quit.  Each time the user
**     decides to accelerate or brake the display will print
**     the speed.  The car can only go between 0 and 80 speed.
***********************************************************/

#include <iostream>
#include <string>
#include "Car.hpp"

using namespace std;


// Default Constructor
Car::Car()
{
	setYear(0);
	setMake("");
	setSpeed(0);
}

// Constructor for Car object taking 3 arguments
Car::Car(int carYear, string carMake, int carSpeed)
{
	setYear(carYear);
	setMake(carMake);
	setSpeed(carSpeed);
}

// set the year of the car in object
void Car::setYear(int carYear)
{
	year = carYear;
}

// set the car make in the object
void Car::setMake(string carMake)
{
	make = carMake;
}

// set the speed of the car
void Car::setSpeed(int carSpeed)
{
	speed = carSpeed;
}

// get the speed of the car
int Car::getSpeed()
{
	return speed;
}

// Method for accelerating the car
void Car::accelerate()
{
	// variables
	int currentSpeed;
	
	// Get the current speed of the car
	currentSpeed = getSpeed();

	// Conditional check if car is at maximum, add 10 if less than 80
	if (currentSpeed < 80)
	{
		currentSpeed += 10;
		// set the speed of the car
		setSpeed(currentSpeed);
	}
	// Else car can go no faster than 80
	else
	{
		cout << "\nYour car can go no faster than a speed of 80.";
	}
	// Done
}


// Method for braking the car
void Car::brake()
{
	// variables
	int currentSpeed;

	// Get the current speed of the car
	currentSpeed = getSpeed();

	// Conditional check if car is at maximum, add 10 if less than 80
	if (currentSpeed > 0)
	{
		currentSpeed -= 10;
		// set the speed of the car
		setSpeed(currentSpeed);
	}
	// Else car can no slower than 0
	else
	{
		cout << "\nYour car is already stopped.";
	}
	// Done
}

int main()
{
	// Variables
	int carYear;	// Car's year
	string carMake;	// Car's make
	char answer;	// User car menu selection
	bool looping = true;	// To continue the looping in user menu
	int carSpeed;

	// Brief description of Program
	cout << "Welcome to the Car Program!" << endl;
	cout << "\nThis program will allow you to create a car with"
		<< "\nthe car's year and make.  Then you will be able to"
		<< "\naccelerate or brake your car." << endl;

	// Ask the user for the car's year and make
	cout << "\nEnter the year of your car: ";
	cin >> carYear;
	cin.ignore();
	cout << "\nEnter in the make of your car: ";
	getline(cin, carMake);
	//cin >> carMake;

	// Create Car object
	Car car(carYear, carMake, 0);

	// Do while loop until the user selects to quit
	do
	{
		// User menu
		cout << "\nWhat would you like to do with your car?"
			<< endl << "(A) to accelerate the car."
			<< endl << "(B) to brake the car."
			<< endl << "(Q) to quit the program."
			<< endl << "Enter the letter here: ";
		cin >> answer;
		answer = toupper(answer);
		
		// Conditionals to which user selection
		switch (answer)
		{
		case 'A':
		{
			car.accelerate();
			carSpeed = car.getSpeed();
			cout << "\nYour car speed is now at " << carSpeed << endl;
			break;
		}
		case 'B':
		{
			car.brake();
			carSpeed = car.getSpeed();
			cout << "\nYour car speed is now at " << carSpeed << endl;
			break;
		}
		case 'Q':
		{
			looping = false;
			break;
		}
		default:
		{
			cout << "\nYou did not enter A, B, or Q!";
			break;
		}
		}

	} while (looping == true);

     system("pause");
	// Exit program
	return 0;
}