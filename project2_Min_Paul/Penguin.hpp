/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Penguin.hpp is the Penguin class specification file. 
************************************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal{

public:	
	Penguin();	//	Default constructor
	Penguin(int);
};

#endif