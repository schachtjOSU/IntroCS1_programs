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

using namespace std;

class Hero
{
private:
	int strength,	// Hero's strength
		hitPoints,	// Hero's avaialable hit points
		speed,		// Hero's speed
		money;		// Hero's avaialable money

public:
	
	// Default constructor
	Hero();

	// Constructor taking 4 int parameters
	Hero(int, int, int, int);

	// Methods for setting Hero attributes
	void setStrength(int);
	void setHitPoints(int);
	void setSpeed(int);
	void setMoney(int);

	// Methods for returning Hero attributes
	int getStrength();
	int getHitPoints();
	int getSpeed();
	int getMoney();

	// Method for returning boolean, if Hero is still alive
	bool takeDamage(int);

};