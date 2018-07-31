/**********************************************************************************************
** Author: Paul Min
** Date: 07/09/18
** Description: Game.cpp is the Game class implementation file.
************************************************************************************************/
#include "Game.hpp"
#include <iostream>
#include <string>


/************************************************************************************************
							Game::displayStartingMenuChoice()
	This function displays the starting menu and presents the user with 2 choices.
	1) Play game
	2) Exit game								
**************************************************************************************************/
void Game::displayStartingMenu() {
	std::cout << "\n\n	Dice Menu\n\n";
	std::cout << "1)  Play game\n";
	std::cout << "2)  Exit game\n";
	std::cout << "Enter your choice: " << std::endl;
}



/************************************************************************************************
							Game::validateStartingMenuChoice()
	This function checks to see if the user input is an integer '1' or integer '2'. If the input
	is a '1' or '2' it returns it.									
**************************************************************************************************/
int Game::validateStartingMenuChoice() {
	int choice;
	bool isValid = false;
	do {
		std::cin >> choice;

		if(!std::cin.fail() && (choice == 1 || choice == 2)){
			isValid = true;
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
			std::cout << "Invalid input. Please choose between the integer '1' or the integer '2': " << std::endl;
		}
	} while(!isValid);

	return choice;
}



/************************************************************************************************
								Game::promptRounds()
		This function prompts user for the number of rows for the board. 									
**************************************************************************************************/
void Game::promptNumRounds() {
	std::cout << "Enter an integer for the number of rounds the game should have: " << std::endl;
}



/************************************************************************************************
									Game::validateRounds()
	This function checks to see if the user input is an integer between '1' and '100', and
	returns the number of rounds if it passes input validation 									
**************************************************************************************************/
int Game::validateNumRounds() {
    const int MAX_ROUNDS = 100;
    const int MIN_ROUNDS = 1;

	int userInputRounds;
    bool isValid = false;
	do {
		std::cin >> userInputRounds;

		if(!std::cin.fail() && (userInputRounds <= MAX_ROUNDS) && (userInputRounds >= MIN_ROUNDS)){
			isValid = true;
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overfow
			std::cout << "Invalid input. Please enter an integer between '1' and '100': " << std::endl;
		}
	} while(!isValid);

	return userInputRounds;
}



/************************************************************************************************
								Game::promptDiePlayer1()
				This function asks Player1 what type of die they would like
**************************************************************************************************/
void Game::promptDiePlayer1() {
    std::cout << "Player 1, what type of die would you like? Enter the char 'L' for Loaded or 'N' for Normal: " << std::endl;
}



/************************************************************************************************
								Game::promptDiePlayer2()
				This function asks Player2 what type of die they would like
**************************************************************************************************/
void Game::promptDiePlayer2() {
    std::cout << "Player 2, what type of die would you like? Enter the char 'L' for Loaded or 'N' for Normal: " << std::endl;
}



/************************************************************************************************
									Game::validateDieType()
			This function checks to see if the user input is 'l' or 'L' or 'n' or 'N'. If the
			user chooses 'l' or 'L' or 'n' or 'N', the function returns the input.
**************************************************************************************************/
char Game::validateDieType(){ 

    char dieTypeChoice;
    bool isValid = false;
    do {
        std::cin >> dieTypeChoice;
        if(!std::cin.fail() && ((dieTypeChoice == 'l' || dieTypeChoice == 'L') || (dieTypeChoice == 'n' || dieTypeChoice == 'N'))){
            isValid = true;
            std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
            if(dieTypeChoice == 'l' || dieTypeChoice == 'L'){
                dieTypeChoice = 'L';
            }
            else if(dieTypeChoice == 'n' || dieTypeChoice == 'N'){
                dieTypeChoice = 'N';
            }
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overflow
            std::cout << "Invalid input. Please enter a char 'L' or a char 'N': " << std::endl;
        }
    } while(!isValid);

    return dieTypeChoice;
}



/************************************************************************************************
								Game::promptSidesPlayer1()
		This function asks Player1 how many sides their die should have
**************************************************************************************************/
void Game::promptSidesPlayer1() {
    std::cout << "Player 1, please enter an integer number of sides your die will have: " << std::endl;
}



/************************************************************************************************
								Game::promptSidesPlayer2()
			This function asks Player1 how many sides their die should have
**************************************************************************************************/
void Game::promptSidesPlayer2() {
    std::cout << "Player 2, please enter an integer number of sides your die will have: " << std::endl;
}



/************************************************************************************************
								Game::validateNumSides()
	This function checks to see if the user input is an integer between '1' and '100', and
	returns the number of sides if it passes input validation 									
**************************************************************************************************/
int Game::validateNumSides() {
    const int MAX_SIDES = 100;
    const int MIN_SIDES = 1;

	int userInputSides;
    bool isValid = false;
	do {
		std::cin >> userInputSides;

		if(!std::cin.fail() && (userInputSides <= MAX_SIDES) && (userInputSides >= MIN_SIDES)){
			isValid = true;
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overfow
			std::cout << "Invalid input. Please enter an integer between '1' and '100': " << std::endl;
		}
	} while(!isValid);

	return userInputSides;
}



/************************************************************************************************
									Game::getStartingChoice()
	This function will will play the game or exit the game depending on whether startingchoice
	is a 1 or a 2. It accepts an argument startingChoice which is determined from the
 	validateStartingMenuChoice method
**************************************************************************************************/
void Game::getStartingChoice(int startingChoice) {
	switch(startingChoice){
		case 1:
		{
			//	declare variables that you will pass into getInfo
			int nRounds, nSidesP1, nSidesP2;	
			char p1DieType, p2DieType;

			//	prompt user for rounds, die type for p1/p2, and sides for p1/p2			
			this->getInfo(nRounds, p1DieType, p2DieType, nSidesP1, nSidesP2);
			//	setup Die based off user input
			std::string p1DieName, p2DieName;
			this->setup(p1DieType, nSidesP1, p2DieType, nSidesP2, p1DieName, p2DieName);

			//	play game
			int p1Wins = 0;
			int p2Wins = 0;
			int ties = 0;
			this->play(nRounds, p1DieType, p2DieType, nSidesP1, nSidesP2, p1DieName, p2DieName, p1Wins, p2Wins, ties);
			std::cout << "Goodbye!" << std::endl;
			break;
    	}
			
		case 2:
			std::cout << "The End." << std::endl; 
			break;
	}

}



/************************************************************************************************
									Game::getInfo()
			This function packages the previous prompt and validate functions together. It accepts
	an int, char, char, int, and int arguments. These arguments are passed by reference. 							
**************************************************************************************************/
void Game::getInfo(int &nRounds, char &p1DieType, char &p2DieType, int &nSidesP1, int &nSidesP2){
	//	how many rounds the game should last
	this->promptNumRounds();	
	nRounds = this->validateNumRounds();	//	if user selects 1 - 100 store it in nRounds
	std::cout << "The number of rounds is: " << nRounds << std::endl;
	std::cout << std::endl;	// empty line

	//	Ask player 1 what type of die
    this->promptDiePlayer1();	
    p1DieType = this->validateDieType();	//	if user selects 'L' or 'l' or 'N' or 'n' store it in p1DieType
    std::cout << "Player 1 die type is: " << p1DieType << std::endl;
	std::cout << std::endl;	// empty line

    //	Ask player 2 what type of die
    this->promptDiePlayer2();	
    p2DieType = this->validateDieType();	//	if user selects 'L' or 'l' or 'N' or 'n' store it in p2DieType
    std::cout << "Player 2 die type is: " << p2DieType << std::endl;
	std::cout << std::endl;	// empty line

    //	number of sides for player 1
    this->promptSidesPlayer1();
    nSidesP1 = this->validateNumSides();
    std::cout << "Player 1's die has " << nSidesP1 << " sides." << std::endl;
    std::cout << std::endl;	// empty line

    //	number of sides for player 2
    this->promptSidesPlayer2();
    nSidesP2 = this->validateNumSides();
    std::cout << "Player 2's die has " << nSidesP2 << " sides." << std::endl;
	std::cout << std::endl;	// empty line
}



/************************************************************************************************
									Game::setup()
	This function implements user input received from get info. It accepts 6 parameters.
	Some of the arguments are received from getInfo. It sets the sides and name of the die/loadeddie
	based off user input received from getInfo.  							
**************************************************************************************************/
void Game::setup(char p1DieType, int nSidesP1, char p2DieType, int nSidesP2, std::string& p1DieName, std::string& p2DieName){
	//	Set sides on normal or loaded Die for P1
	switch(p1DieType){
		case 'N':
			p1NormalDie.setSides(nSidesP1);
			p1DieName = "normal";
			break;
		case 'L':
			p1LoadedDie.setSides(nSidesP1);
			p1DieName = "loaded";
			break;
	}

	//	Set sides on normal or loaded Die for P2
	switch(p2DieType){
		case 'N':
			p2NormalDie.setSides(nSidesP2);
			p2DieName = "normal";
			break;
		case 'L':
			p2LoadedDie.setSides(nSidesP2);
			p2DieName = "loaded";
			break;
	}
}



/************************************************************************************************
									Game::play()
	This function plays War with 2 die for the specified number of rounds. It also displays 
	the round results after each round. At the end, the final results are displayed.						
**************************************************************************************************/
void Game::play(int rounds, char p1DieType, char p2DieType, int nSidesP1, int nSidesP2, std::string p1Name, std::string p2Name, int& p1Wins, int& p2Wins, int& ties){
	for(int i = 1; i <= rounds; i++){
		//	Roll die for player 1
		switch(p1DieType){
			case 'N':
				p1RollValue = p1NormalDie.roll();
				break;
			case 'L':
				p1RollValue = p1LoadedDie.roll();
				break;
		}

		//	Roll die for player 2
		switch(p2DieType){
			case 'N':
				p2RollValue = p2NormalDie.roll();
				break;
			case 'L':
				p2RollValue = p2LoadedDie.roll();
				break;
		}
		std::cout << "********************* Round " << i << " results **********************************" << std::endl;
		this->roundResult(p1Name, p2Name, p1RollValue, p2RollValue, nSidesP1, nSidesP2, p1Wins, p2Wins, ties, i);
		
	}

	//	Final score count
	std::cout << "************************ Final Results *******************************" << std::endl;
	std::cout << "Player 1 won " << p1Wins << " rounds." << std::endl;
	std::cout << "Player 2 won " << p2Wins << " rounds." << std::endl;
	std::cout << "There were " << ties << " rounds that ended in a tie." << std::endl;

	if(p1Wins > p2Wins){
		std::cout << "Player 1 wins the game!" << std::endl;
	}
	else if (p2Wins > p1Wins){
		std::cout << "Player 2 wins the game!" << std::endl;
	}
	else if (p2Wins == p1Wins){
		std::cout << "Player 1 and Player 2 tie the game!" << std::endl;
	}
}



/************************************************************************************************
									Game::roundResult()
	This function display round results. It accepts 10 arguments. It increments p1wins, p2wins,
	or ties based off the values of p1RollValue & p2RollValue.					
**************************************************************************************************/
void Game::roundResult(std::string p1Name, std::string p2Name, int p1RollValue, int p2RollValue, int nSidesP1, int nSidesP2, int& p1Wins, int& p2Wins, int& ties, int rounds){
	//	Display round report
	std::cout << "Player 1 used a " << p1Name << " die with " << nSidesP1 << " sides." << std::endl;
	std::cout << "Player 2 used a " << p2Name << " die with " << nSidesP2 << " sides." << std::endl;
	std::cout << "Player 1 rolled a " << p1RollValue << "." << std::endl;
	std::cout << "Player 2 rolled a " << p2RollValue << "." << std::endl;

	if(p1RollValue > p2RollValue){
		p1Wins++;
		std::cout << "Player 1 wins round " << rounds << "!" << std::endl;
	}
	else if(p2RollValue > p1RollValue){
		p2Wins++;
		std::cout << "Player 2 wins round " << rounds << "!" << std::endl;
	} 
	else if(p2RollValue == p1RollValue){
		ties++;
		std::cout << "Round " << rounds << " is a tie!" << std::endl;
	}
}
