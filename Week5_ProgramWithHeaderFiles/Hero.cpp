/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 02/07/2015
** Description: This program will be using classes to ask
**     the user attributes of their Hero.  Fields of the
**     Hero will contain strength, hit points, speed, and
**     money.  The program will then ask the user how much
**     damage the Hero has sustained until and keep going
**     until the hero runs out of hit points.  Output will
**     display all attributes after each damage taken by the
**     hero.
***********************************************************/


#include <iostream>
#include "Hero.hpp"

using namespace std;

// Default constructor
Hero::Hero()
{
	setStrength(1);
	setHitPoints(1);
	setSpeed(1);
	setMoney(1);
}

// Constructor with 4 arguments
Hero::Hero(int heroStrength, int heroHitPoints, int heroSpeed, int heroMoney)
{
	setStrength(heroStrength);
	setHitPoints(heroHitPoints);
	setSpeed(heroSpeed);
	setMoney(heroMoney);
}

// Functions for setting the Hero's attributes
void Hero::setStrength(int heroStrength)
{
	strength = heroStrength;
}

void Hero::setHitPoints(int heroHitPoints)
{
	hitPoints = heroHitPoints;
}

void Hero::setSpeed(int heroSpeed)
{
	speed = heroSpeed;
}

void Hero::setMoney(int heroMoney)
{
	money = heroMoney;
}

// Functions for returning Hero attributes
int Hero::getStrength()
{
	return strength;
}

int Hero::getHitPoints()
{
	return hitPoints;
}

int Hero::getSpeed()
{
	return speed;
}

int Hero::getMoney()
{
	return money;
}

// Function for returning Hero dead/alive status
bool Hero::takeDamage(int damage)
{
	hitPoints = hitPoints - damage;
	if (hitPoints > 0)
		return true;
	else
		return false;
}

// Main Function
int main()
{
	// Variables
	int heroStrength,		// Hero strength
		heroHitPoints,		// Hero Hit Points
		heroSpeed,			// Hero's speed
		heroMoney;			// Hero's Money

	int damage;				// User enter damage

	bool heroAlive = true;	// Set to Hero is Alive

	// Brief Program Description
	cout << "Welcome to the Hero Program." << endl;
	cout << "\nThis program will allow you to customize your Hero attibutes."
		<< "\nThen will ask you how much damage your Hero has taken until"
		<< "\nyour Hero has suffered enough.";

	// Default Constructor
	//Hero hero();

	// Ask the user for Hero attributes
	cout << "\nEnter the integer of your Hero's strength: ";
	cin >> heroStrength;
	cout << "\nEnter the integer of your Hero's Hit Points: ";
	cin >> heroHitPoints;
	cout << "\nEnter the integer of your Hero's Speed: ";
	cin >> heroSpeed;
	cout << "\nEnter the integer of your Hero's Money: ";
	cin >> heroMoney;

	// Constructor with user Hero attributes
	Hero hero(heroStrength, heroHitPoints, heroSpeed, heroMoney);

	// Start Damage loop until hit points is less than or equal to 0
	// Ask the user how much damage hero sustained
	if (heroHitPoints > 0)
	{
		while (heroAlive)
		{
			cout << "\nHow much damage is your hero going to take: ";
			cin >> damage;
			heroAlive = hero.takeDamage(damage);
			heroStrength = hero.getStrength();
			heroHitPoints = hero.getHitPoints();
			heroSpeed = hero.getSpeed();
			heroMoney = hero.getMoney();
			cout << "\nYour current Hero stats are: "
				<< "\nStrength: " << heroStrength
				<< "\nHit Points: " << heroHitPoints
				<< "\nSpeed: " << heroSpeed
				<< "\nMoney: " << heroMoney;
		}
	}
	// End Program
	cout << "\nYour Hero has met an untimely demise!" << endl;
     system("pause");
	// Exit Program
	return 0;
}