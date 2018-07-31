/**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: Die.hpp is the Die class specification file. 
************************************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die{
protected:
	int sides;		//	number of sides on die
	int lastRoll;	//	most recent number rolled
	unsigned seed;	//	random number generator
public:
	Die();					//  constructor
	void setSides(int sides);	//	sets number of sides on die
	int roll();					// generate random number between 1 and number of sides
};

#endif