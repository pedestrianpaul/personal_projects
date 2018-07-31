/**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: LoadedDie.cpp is the LoadedDie class implementation file.
************************************************************************************************/
#include "LoadedDie.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int LoadedDie::roll(){
	lastRoll = Die::roll();

	int remainder = sides - lastRoll;

	//	biased rolling depending on how big remainder is	
	if(remainder >= 1 && remainder <= 5){
		lastRoll++;		
	}
	else if(remainder >= 6 && remainder <=10){
		lastRoll += 5;
	}
	else if(remainder >= 11 && remainder <= 15){
		lastRoll += 10;
	}
	else if(remainder >= 16 && remainder <= 20){
		lastRoll += 15;	
	}
	else if(remainder >= 21 && remainder <= 30){
		lastRoll += 20;
	}
	else if(remainder >= 31 && remainder <= 40){
		lastRoll += 30;
	}
	else if(remainder >= 41 && remainder <= 50){
		lastRoll += 40;
	}
	else if(remainder >= 51 && remainder <= 60){
		lastRoll += 50;
	}
	else if(remainder >= 61 && remainder <= 70){
		lastRoll += 60;
	}

	return lastRoll;
}