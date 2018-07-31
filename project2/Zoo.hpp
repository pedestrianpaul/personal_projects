/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Zoo.hpp is the Zoo class specification file. 
************************************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Cheetah.hpp"

class Zoo{
private:
	Tiger* tigerPopulation;
	Penguin* penguinPopulation;
	Turtle* turtlePopulation;
	Cheetah* cheetahPopulation;

	//	animal numbers
	int numTigers;
	int numPenguins;
	int numTurtles;
	int tigerCapacity;	//	starting capacity is 10 animals
	int penguinCapacity;
	int turtleCapacity;

	//	First Animal Purchase Choices
	int numFirstTigers;	//	Either 1 or 2 depending on user input.
	int numFirstPenguins;
	int numFirstTurtles;
	int numFirstCheetahs;

	//	Money and Day
	int day;
	int money;
	int bonus;	//	bonus from attendance boom

	//	random seed
	unsigned seed;

	//	cheetah data
	int numCheetahs;
	int cheetahCapacity;
	int cheetahCost;
	int cheetahBabies;
	int cheetahFeedCost;
	int cheetahPayoff;

public:	
	Zoo();	//	Default constructor

	//	Getters
	int getNumTigers();
	int getNumPenguins();
	int getNumTurtles();
	int getNumCheetahs();
	int getMoney();
	int getDay();

	//	Add animals
	void addTiger(int m_age);
	void addPenguin(int m_age);
	void addTurtle(int m_age);
	void addCheetah(int m_age);

	//	Remove animals
	void removeTiger();
	void removePenguin();
	void removeTurtle();
	void removeCheetah();

	//	Display Functions
	void displayMoney();
	void displayDay();

	//	Starting Questions
	void promptFirstTiger();
	void promptFirstPenguin();
	void promptFirstTurtle();
	void promptCheetahInfo();
	void promptFirstCheetah();

	//	Input Validation
	int oneOrTwo();
	int oneTwoThreeFour();
	int cheetahCostValidation();
	int cheetahBabyValidation();
	int cheetahFoodCostValidation();
	int cheetahPayoffValidation();

	//	Random Events
	void randAnimalDies();
	void attendanceBoom();
	void randAnimalBirth();

	//	I/O text file functions for Random Events
	void textRandAnimalDies();
	void textAttendanceBoom();
	void textBabyAnimal();
	void textNothing();

	//	Game Loop Functions
	void gameLoop();
	void incrementAnimalsAge();
	void calculateFeedingCost();
	void randomEvent();
	void calculatePayoff();
	void promptAdultAnimal();
	void promptKeepPlaying();
	void checkMoney();

	//	Play the game
	void play();

	//	Destructor
	~Zoo();	
};

#endif