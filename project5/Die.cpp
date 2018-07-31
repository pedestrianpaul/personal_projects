/**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: Die.cpp is the Die class implementation file.
************************************************************************************************/
#include "Die.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/************************************************************************************************************
												Die::Die()
								This is the constructor for the Die Class
*************************************************************************************************************/
Die::Die(){
	lastRoll = 0;
	seed = time(0);
	srand(seed);
}



/************************************************************************************************************
												Die::setSides()
								This function sets the Die's sides
*************************************************************************************************************/
void Die::setSides(int nSides){
	sides = nSides;
}



/************************************************************************************************************
												Die::roll()
	This function rolls the dice. It generates a random number between 1 and the number of sides on the
	die. 
*************************************************************************************************************/
int Die::roll(){
	lastRoll = 0;

	//	generate random number between 1 and number of sides
	lastRoll = (std::rand() % sides) + 1;

	return lastRoll;
}