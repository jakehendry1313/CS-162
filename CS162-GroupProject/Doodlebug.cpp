/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Doodlebug.cpp
** Author:  Robert King
** Date:    2019-05-03
**------------------------------------------------------------------
** This is the implementation file for the Doodlebug class.  This 
** has functions to move and breed the bug, as well as to check
** to see if it has starved.
********************************************************************/

#include "Doodlebug.hpp"

#include <cstdlib>
#include <iostream>


/*
** Parameters: two integers that represent board position
** Constructor that initializes the Doodlebug's steps to breed, breed age,
** and moves since last meal.
*/
Doodlebug::Doodlebug(int startingX, int startingY)
{
	row = startingX;
	col = startingY;
	stepsToBreed = 0;
	breedAge = 8;
	movesSinceLastMeal=0;
}


/*
** Return type: Critter * that represents the new Doodlebug created via breeding
** Function for Doodlebug breeding. Creates new Doodlebug in adjacent space that is empty randomly.
** If space is occupied, picks new space until empty one is found. If no spaces are empty, no breeding occurs.
*/

Critter * Doodlebug::breed()
{

    Critter* babyDoodlebug = nullptr;

    bool emptySpace = false;
    int breedSpace;
    int breedCounter = 0;

    while (!emptySpace && (breedCounter < 20))
    {
        breedSpace = rand() % 4;
		switch (breedSpace)
        {
        case 0:
            if (row > 0 && !occupyUp)
            {
				babyDoodlebug = new Doodlebug(row - 1, col);
                emptySpace = true;
            }
            break;
        case 1:
            if ((row < (maxRow - 1)) && !occupyDown)
            {
			    babyDoodlebug = new Doodlebug(row + 1, col);
                emptySpace = true;
            }
            break;
        case 2:
            if (col > 0 && !occupyLeft)
            {
				babyDoodlebug = new Doodlebug(row, col - 1);
                emptySpace = true;
            }
            break;
        case 3:
            if ((col < (maxCol - 1)) && !occupyRight)
            {
				babyDoodlebug = new Doodlebug(row, col + 1);
                emptySpace = true;
            }
            break;
        }
        breedCounter++;
	}
	return babyDoodlebug;
}

/*
** Return type: Bool - returns true if steps to breed is greater or equal to breed age.
*/

bool Doodlebug::getBreedStatus()
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
** Function for Doodlebug movement. First, the function checks for a random adjacent ant.
** If there is an ant, it moves to that spot. If not, it will try again to seek a random
** unoccupied spot and move there.
*/

bool Doodlebug::move()
{
    bool validMove = false;
    int direction, counter = 0;

	while (!validMove && (counter < 20))
	{
		direction = rand() % 4;
		switch(direction)
		{
    	case 0:                                                            // Movement upwards
			if (row > 0 && antUp)
        	{
		 		setRow(row - 1); 
            	validMove = true;
        	}
			break;
			
    	case 1:                                                            // Movement Down
			if ((row < (maxRow-1)) && antDown) 
       		{
			 	setRow(row + 1); 	
        		validMove = true;
       		}
			break;
			
    	case 2:                                                             // Movement left
			 if (col > 0 && antLeft)
       		 {
   			  	setCol(col - 1); 
				validMove = true;
       		 } 	
        	 break;

    	case 3:                                                             // Movement right
			 if ((col < (maxCol-1)) && antRight) 
       		 {
          	  setCol(col + 1); 
       		  validMove = true;
			 }
        	break;
			
		}
	if (validMove) movesSinceLastMeal = 0;  // if the doodlebug ate, reset the counter
	counter++;
	}

	direction = rand() % 4;

	if (!validMove) // attempt to move to a random empty space if haven't moved already.
	{
		switch (direction)
    	{
    	case 0:                                                            // Movement upwards
      		if (row > 0 && !occupyUp)
        	{
           	 setRow(row - 1); 
        	 validMove = true;
			}
        	break;
    	case 1:                                                            // Movement Down
        	if ((row < (maxRow-1)) && !occupyDown) 
       		{
          	  setRow(row + 1); 
        	  validMove = true;
        	}
			break;
    	case 2:                                                             // Movement left
       		 if (col > 0 && !occupyLeft)
       		 {
          	  setCol(col - 1); 
        	  validMove = true;
         	 }
			 break;
    	case 3:                                                             // Movement right
    	    if ((col < (maxCol-1)) && !occupyRight) 
       		{
          	  setCol(col + 1); 
        	  validMove = true;
			}
        	break;
  	    }
	
	}
    movesSinceLastMeal++;
	movedAlready = true; // marker for if the doodlebug attempted to move already.
    return validMove;
}

/*
** Return type: Bool - returns starvation status
** Inherited virtual function from Critter. Doodlebugs starve after 3 moves of
** not eating.
*/
bool Doodlebug::starve()
{
	if (movesSinceLastMeal > 3) 
		{
		return true;
		}
	else 
		{
		return false;
		}
}

/*
** Return type: Integer - identifies the critter type based on enum
** In the enum, DOODLEBUG is 2, therefore - returns 2.
*/
int Doodlebug::getType()
{
	return 2;
}
