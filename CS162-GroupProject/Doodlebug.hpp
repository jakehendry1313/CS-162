/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Doodlebug.hpp
** Author:  Robert King
** Date:    2019-05-03
**------------------------------------------------------------------
** This is the header file for the Doodlebug class.  This class
** has functions to move and breed the bug, as well as to check
** to see if it has starved.
********************************************************************/


#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug: public Critter
{
private:
	int movesSinceLastMeal;

public:

	Doodlebug(int startingX, int startingY);

	// Override functions from Critter
	Critter* breed();
	bool getBreedStatus();
	bool move();
	bool starve();
	bool starvationCheck();
	int getType();

	~Doodlebug() {};

};


#endif
