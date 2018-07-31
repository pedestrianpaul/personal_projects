/**********************************************************************************************
** Author: Paul Min
** Date: 06/28/18
** Description: main.cpp for Langton's Ant project gameplay. 
************************************************************************************************/
#include "Interface.hpp"
#include <iostream>

int main () {
	//	Announce Extra Credit
	std::cout << "**** Extra Credit: Random Ant Position Implemented ****" << std::endl;

	Interface IO;	// instantiate an object of the Interface class
    //  Ask user if they want to play or quit
	IO.displayStartingMenu();
	
    //  validate input and store it in startingChoice
    int startingChoice = IO.validateStartingMenuChoice();

    //  decide what to do based off starting choice
    IO.getStartingChoice(startingChoice);
    
	return 0;
}
