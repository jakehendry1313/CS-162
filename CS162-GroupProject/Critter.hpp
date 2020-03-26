/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Critter.hpp
** Author:  Michael Copland
** Date:    2019-04-24
** -------------------------------------------------------------------
** This is the Critter abstract class specification (header) file. Both
** types of Critter have values for their position, their specific
** breed ages, and how long until they can breed. These are set in the
** constructor. 
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <stdlib.h> 

class Critter {
	enum cells { SPACE, ANT, DOODLEBUG };

	protected:
        int row, col, breedAge, stepsToBreed;
		int maxRow, maxCol;					// Tracks maximum board size to prevent outside movement bounds
        bool readyToBreed;                  // can the Critter breed yet
		bool movedAlready;					/* Update 4/28: factors if the ant has moved
												and prevents it from moving until next move() function call.*/
		bool occupyUp, occupyDown, occupyLeft, occupyRight;	// If true, there is neighbor in that cell and cannot move. 
		bool antUp, antDown, antLeft, antRight;		

	public:
		Critter();
        Critter(int, int, int);

        // abstract functions
        virtual Critter* breed() = 0;       /* Critter can breed if
                                               conditions are met */
        virtual bool getBreedStatus() = 0;  // checks for breeding readiness
        virtual bool move() = 0;            /* performs move actions
                                               based on Critter */
		virtual bool starve() = 0;         // check Doodlebug starvation counter
        virtual int getType() = 0;          // returns type of Critter

        // functions
        void incrementStepsToBreed();       // call after every step
        void resetBreedClock();             // call after breeding

		// getters
        int getRow();                       // returns row
        int getCol();                       // returns column
		bool getMovedAlready();				// gets movedAlready
		int getStepsToBreed();

		// setters
		void setRow(int userRow);			// sets row
		void setCol(int userCol);			// sets column
		void setMaxRow(int userMax);
		void setMaxCol(int userMaxC);
		void setMovedAlready(bool userMove);// sets movedAlready 

		// Neighbor Occupying cells
		void setOccupyUp(bool userUp);
		void setOccupyDown(bool userDown);
		void setOccupyLeft(bool userLeft);
		void setOccupyRight(bool userRight);

		// Ant Cells
		void setAntUp(bool userUp);
		void setAntDown(bool userDown);
		void setAntLeft(bool userLeft);
		void setAntRight(bool userRight);

};

#endif
