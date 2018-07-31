/**********************************************************************************************
** Author: Paul Min
** Date: 06/29/18
** Description: Interface.hpp is the Interface class specification file. 
************************************************************************************************/
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Ant.hpp"	//	Ant.hpp includes Board.hpp

class Interface{
	
public:
	void displayStartingMenu();	//	Prompt user to 1) play or 2) quit
	int validateStartingMenuChoice();	//	only allow integer '1' or integer '2'
	void promptNumRows();	//	Prompt user for number of rows for the board
	int validateNumRows();	//	check to see if rows is between '2' and '100'
	void promptNumCols();	//	Prompt user for number of columns for the board
	int validateNumCols();	//	check to see if cols is between '2' and '100'
	void promptSteps();		//	Prompt user for number of steps simulation will run for
	int validateSteps();	//	check to see if steps is between '1' and '11,000'
	void promptAntRow();	//	prompt user for the row number to place the ant
	int validateAntRow(int userRow);	//	check to see if row is 2 through whatever row user selected for board
	void promptAntCol();	//	prompt user for the col number to place the ant
	int validateAntCol(int userCol);	//	check to see if col is 2 through whatever col user selected for board
	void getInfo(int& row, int& col, int& antRow, int& antCol, int& steps);	// packages prompt & validate functions
	void getInfoForRand(int &row, int &col, int &steps); //  packages prompt & validate functions for board row/col, and steps
	void getStartingChoice(int startingChoice); //	decides what to do based off starting choice (play or quit)
	void displayEndingMenu();	//	Prompt user if they want to play again
	bool validateEndingMenu();	// returns true if "Y" or "y" or 'Y' or 'y', else returns false
    void promptRandomPlacement();   //  prompt user if they want to randomly place the ant
    bool validateRandomPlacement(); // returns true if "Y" or "y" or 'Y' or 'y', else returns false
    int randomAntRow(int userRow);  // returns random row that is within the minimum row and user selected row
    int randomAntCol(int userCol);  // returns random col that is within the minimum col and the user selected col
    
};

#endif