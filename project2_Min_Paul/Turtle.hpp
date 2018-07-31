/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Turtle.hpp is the Turtle class specification file. 
************************************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal{

public:	
	Turtle();	//	Default constructor
	Turtle(int);
};

#endif