/**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: main.cpp for Dice War gameplay. 
************************************************************************************************/
#include "Game.hpp"	//	Game.hpp includes Die.hpp and LoadedDie.hpp
#include <iostream>

int main () {

	Game diceGame;	//	instantiate Game class object

	diceGame.displayStartingMenu();	//	display starting Menu

	int startingChoice = diceGame.validateStartingMenuChoice();	//	store input in starting choice

	diceGame.getStartingChoice(startingChoice);	//	if choice is 1 play game, else quit
    
	return 0;
}