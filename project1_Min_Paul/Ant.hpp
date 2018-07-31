/**********************************************************************************************
** Author: Paul Min
** Date: 06/28/18
** Description: Ant.hpp is the Ant class function specification file. 
************************************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

class Ant {
private:
    enum Direction {North, East, South, West}; // ant's orientation 0 = up, 1 = right, 2 = down, 3 = left
	int antRow;
	int antCol;
	int antDirection;
	Board *antBoard;
public:
	Ant();					//	constructor initializes direction of ant to up and sets the symbol of ant to '*'
	void turnLeft();		//	change orientation of the ant
	void turnRight();		//	change orientation of the ant
	void moveForward();		//	move the ant forward one space based off orientation
	void setup(int boardRow, int boardCol);			//	setups the simulation
	void setAnt(int row, int col);			//	places the ant on the board
	void play(int steps);	//  uses turnLeft, turnRight, and moveForward functions in combination. 
	~Ant();					//	Destructor
};

#endif