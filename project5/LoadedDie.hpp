 /**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: LoadedDie.hpp is the LoadedDie class specification file. 
************************************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die{

public:
	int roll();	// generate random number between 1 and number of sides
};

#endif