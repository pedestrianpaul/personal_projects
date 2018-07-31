/**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: Game.hpp is the Game class specification file. 
************************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"	
#include "LoadedDie.hpp"
#include <string>

class Die;
class LoadedDie;

class Game{
private:
	int p1RollValue;
	int p2RollValue;
	Die p1NormalDie;
	Die p2NormalDie;
	LoadedDie p1LoadedDie;
	LoadedDie p2LoadedDie;
	
public:
	void displayStartingMenu();			//	Prompt user to 1) Play Game or 2) Exit Game
	int validateStartingMenuChoice();	//	only allow integer '1' or integer '2'
	void promptNumRounds();				//	Prompt user for number of rounds for the game
	int validateNumRounds();				//	check to see if rounds is between '1' and '100'
	void promptDiePlayer1();			//	Prompt type of die for player 1
	void promptDiePlayer2();			//	Prompt type of die for player 2
	char validateDieType();				//	check to see if input is 'L' || 'l' || 'N' || 'n'
	void promptSidesPlayer1();			//	Prompt number of sides on die for player 1
	void promptSidesPlayer2();			//	Prompt number of sides on die for player 2
	int validateNumSides();				//	check to see if number of sides is between '1' and '20'
	void getStartingChoice(int);			//	decides what to do based off starting choice (play or quit)
	void getInfo(int& rounds, char& p1DieType, char& p2DieType, int& p1NumSides, int& p2NumSides);	// packages prompt & validate functions
	void setup(char p1DieType, int nSidesP1, char p2DieType, int nSidesP2, std::string& p1DieName, std::string& p2DieName);	//	This function sets up the game with the input received
	void play(int rounds, char p1DieType, char p2DieType, int nSidesP1, int nSidesP2, std::string p1Name, std::string p2Name, int& p1Wins, int& p2Wins, int& ties); // This function plays the game
	void roundResult(std::string p1Name, std::string p2Name, int p1RollValue, int p2RollValue, int nSidesP1, int nSidesP2, int& p1Wins, int& p2Wins, int& ties, int rounds);	// This function displays detailed round results
};

#endif