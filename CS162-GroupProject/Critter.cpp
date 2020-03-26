/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Critter.cpp
** Author:  Michael Copland
** Date:    2019-04-24
** -------------------------------------------------------------------
** This is the Critter abstract class function implementation file.
** Both types of Critter have values for their position, their specific
** breed ages, and how long until they can breed. These are set in the
** constructor. 
*********************************************************************/

#include "Critter.hpp" 

// Default Constructor

Critter::Critter()
{
	row = 0;
	col = 0;
	breedAge = 0;
	stepsToBreed = 0;
	readyToBreed = false;
	movedAlready = false;
}

/*
** Constructor for Critter class.
**
** @param int  Row position
** @param int  Column position
** @param int  Age for when the Critter breeds
*/
Critter::Critter(int row, int col, int breedAge) {
    this->row = row;
    this->col = col;
    this->breedAge = breedAge;
    this->stepsToBreed = 0;
    this->readyToBreed = false;
	this->movedAlready = false;
}

/*
** Increments stepsToBreed and checks against breedAge.
*/
void Critter::incrementStepsToBreed() {
    stepsToBreed++; 
    
    if(stepsToBreed == breedAge) {
        readyToBreed = true; 
    }
}

/*
** Called after breeding. Resets breed status.
*/
void Critter::resetBreedClock() {
    stepsToBreed = 0;
    readyToBreed = false; 
}


/*
** Getters and setters for Critter class.
*/
int Critter::getRow() {
    return row; 
}

int Critter::getCol() {
    return col;
}

bool Critter::getMovedAlready()
{
	return movedAlready;
}

int Critter::getStepsToBreed()
{
	return stepsToBreed;
}

void Critter::setRow(int userRow)
{
	row = userRow;
}

void Critter::setCol(int userCol)
{
	col = userCol;
}

void Critter::setMaxRow(int userMax)
{
	maxRow = userMax;
}

void Critter::setMaxCol(int userMaxC)
{
	maxCol = userMaxC;
}

void Critter::setMovedAlready(bool userMove)
{
	movedAlready = userMove;
}

void Critter::setOccupyUp(bool userUp)
{
	occupyUp = userUp;
}

void Critter::setOccupyDown(bool userDown)
{
	occupyDown = userDown;
}

void Critter::setOccupyLeft(bool userLeft)
{
	occupyLeft = userLeft;
}

void Critter::setOccupyRight(bool userRight)
{
	occupyRight = userRight;
}


// Setters for booleans for ant position
void Critter::setAntUp(bool userUp)
{
	antUp = userUp;
}

void Critter::setAntDown(bool userDown)
{
	antDown = userDown;
}

void Critter::setAntLeft(bool userLeft)
{
	antLeft = userLeft;
}

void Critter::setAntRight(bool userRight)
{
	antRight = userRight;
}







