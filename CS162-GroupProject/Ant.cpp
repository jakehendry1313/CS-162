/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Ant.hpp
** Author:  Casey Levy
** Date:    2019-04-26
**------------------------------------------------------------------
** This is the header file for the Ant class.  This class
** has functions to move and breed the bug. It is derived from
** Critter.
********************************************************************/

#include "Ant.hpp"

#include <iostream>

/*
** Parameters: two integers that represent board position
** Constructor that initializes the ant's position, steps to breed, and age
*/
Ant::Ant(int startingX, int startingY)
{
	row = startingX;
	col = startingY;
	stepsToBreed = 0;
	breedAge = 3;
}

/*
** Return type: Critter * that represents the new Ant created via breeding
** Function for Ant breeding. Creates new ant in adjacent space that is empty randomly.
** If space is occupied, picks new space until empty one is found. If no spaces are empty, no breeding occurs.
*/

Critter * Ant::breed()
{
	Critter* babyAnt = nullptr;

	bool emptySpace = false;
	int breedSpace = rand() % 4;
	int breedCounter = 0;

	while (!emptySpace && breedCounter < 20)
	{ 
		switch (breedSpace)
		{
		case 0:
			if (row > 0 && !occupyUp)
			{
				babyAnt = new Ant(row - 1, col);
				emptySpace = true;
			}
			break;
		case 1:
			if ((row < (maxRow - 1)) && !occupyDown)
			{
				babyAnt = new Ant(row + 1, col);
				emptySpace = true;
			}
			break;
		case 2: 
			if (col > 0 && !occupyLeft)
			{
				babyAnt = new Ant(row, col - 1);
				emptySpace = true;
			}
			break;
		case 3:
			if ((col < (maxCol - 1)) && !occupyRight)
			{
				babyAnt = new Ant(row, col + 1);
				emptySpace = true;
			}
			break;
		}

		breedCounter++;
	}

	return babyAnt;
}

/*
** Return type: Bool - returns true if steps to breed is greater or equal to breed age.
*/
bool Ant::getBreedStatus()
{
	if (stepsToBreed > breedAge)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
** Return type: Bool - Returns true if the movement is possible, returns false if not. 
** Function for Ant movement. Picks a random number to begin moving towards, moves there if spot is empty. 
*/
bool Ant::move()
{
	bool validMove = false;
	int direction = rand() % 4;

	switch (direction)
	{
	case 0:                                                            // Movement upwards
		if (row > 0 && !occupyUp)
		{
			setRow(row - 1);
		}
		validMove = true;
		break;
	case 1:                                                            // Movement Down
		if ((row < (maxRow-1)) && !occupyDown) 
		{
			setRow(row + 1);
		}
		validMove = true;
		break;
	case 2:                                                             // Movement left
		if (col > 0 && !occupyLeft)
		{
			setCol(col - 1);
		}
		validMove = true;
		break;
	case 3:                                                             // Movement right
		if ((col < (maxCol-1)) && !occupyRight) 
		{
			setCol(col + 1);
		}
		validMove = true;
		break;
	}

	movedAlready = true; // marker for if the ant attempted to move already.
	return validMove;;
}

/*
** Return type: Bool - returns starvation status
** Inherited virtual function from Critter. Since Ants do not starve, this returns false.
*/

bool Ant::starve()
{
	return false;
}

/*
** Return type: Integer - identifies the critter type based on enum
** In the enum, ANT is 1, therefore - returns 1.
*/
int Ant::getType()
{
	return 1;
}
