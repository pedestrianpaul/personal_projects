/**********************************************************************************************
** Author: Paul Min
** Date: 06/28/18
** Description: Interface.cpp is the Interface class implementation file.
************************************************************************************************/
#include "Interface.hpp"
#include "Ant.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>


/************************************************************************************************
									Interface::displayStartingMenuChoice()
			This function displays the starting menu and presents the user with 2 choices.									
**************************************************************************************************/
void Interface::displayStartingMenu() {
	std::cout << "\n\n		Menu\n\n";
	std::cout << "1)  Start Langton's Ant simulation\n";
	std::cout << "2)  Quit\n";
	std::cout << "Enter your choice: " << std::endl;
}



/************************************************************************************************
									Interface::validateStartingMenuChoice()
			This function checks to see if the user input is an integer '1' or integer '2'. 									
**************************************************************************************************/
int Interface::validateStartingMenuChoice() {
	int choice;
	bool isValid = false;
	do {
		std::cin >> choice;

		if(!std::cin.fail() && (choice == 1 || choice == 2)){
			isValid = true;
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
									Interface::promptNumRows()
			This function prompts user for the number of rows for the board. 									
**************************************************************************************************/
void Interface::promptNumRows() {
	std::cout << "Enter an integer for the number of rows the board should have: " << std::endl;
}



/************************************************************************************************
									Interface::validateNumRows()
			This function checks to see if the user input is an integer between '2' and '100', and
			returns the number of rows if it passes input validation 									
**************************************************************************************************/
int Interface::validateNumRows() {
    const int MAX_ROWS = 400;
    const int MIN_ROWS = 2;

	int userInputRows;
    bool isValid = false;
	do {
		std::cin >> userInputRows;

		if(!std::cin.fail() && (userInputRows <= MAX_ROWS) && (userInputRows >= MIN_ROWS)){
			isValid = true;
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overfow
			std::cout << "Invalid input. Please enter an integer between '2' and '400': " << std::endl;
		}
	} while(!isValid);

	return userInputRows;
}



/************************************************************************************************
									Interface::promptNumCols()
			This function prompts user for the number of Cols for the board. 									
**************************************************************************************************/
void Interface::promptNumCols() {
	std::cout << "Enter an integer for the number of columns the board should have: " << std::endl;
}



/************************************************************************************************
									Interface::validateNumCols()
			This function checks to see if the user input is an integer between '2' and '100', and
			returns the number of cols if it passes input validation 										
**************************************************************************************************/
int Interface::validateNumCols() {
    const int MAX_COLS = 400;
    const int MIN_COLS = 2;

	int userInputCols;
    bool isValid = false;
	do {
		std::cin >> userInputCols;

		if(!std::cin.fail() && (userInputCols <= MAX_COLS) && (userInputCols >= MIN_COLS)){
			isValid = true;
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overfow
			std::cout << "Invalid input. Please enter an integer between '2' and '400': " << std::endl;
		}
	} while(!isValid);

	return userInputCols;
}



/************************************************************************************************
									Interface::promptSteps()
			This function prompts user for the number of steps for the simulation. 									
**************************************************************************************************/
void Interface::promptSteps() {
	std::cout << "How many steps should the simulation run for: " << std::endl;
}



/************************************************************************************************
									Interface::validateSteps()
			This function checks to see if the user input is an integer between '1' and '11000', and
			returns the number of steps if it passes input validation  									
**************************************************************************************************/
int Interface::validateSteps() {
    const int MIN_STEPS = 1;
    const int MAX_STEPS = 100000;

	int userInputSteps;
    bool isValid = false;
	do {
		std::cin >> userInputSteps;
		if(!std::cin.fail() && (userInputSteps <= MAX_STEPS) && (userInputSteps >= MIN_STEPS)){
			isValid = true;
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overfow
			std::cout << "Invalid input. Please enter an integer between '1' and '100,000': " << std::endl;
		}
	} while(!isValid);

	return userInputSteps;
}



/************************************************************************************************							
									Interface::promptAntRow()
			This function prompts user for the row number to place the ant 									
**************************************************************************************************/
void Interface::promptAntRow() {
	std::cout << "Which row should the ant be placed in: " << std::endl;
}



/************************************************************************************************
									Interface::validateAntRow()
			This function checks to see if the ant is placed in a valid row. Valid rows are
			2 through whatever row the user selected for the size of the board.								
**************************************************************************************************/
int Interface::validateAntRow(int userRow) {
	
	int antRow;
    bool isValid = false;
	do {
		std::cin >> antRow;

		if(!std::cin.fail() && (antRow <= userRow) && (antRow >= 1)){
			isValid = true;
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overflow
			std::cout << "Invalid input. Please enter an integer between '2' and '400': " << std::endl;
		}
	} while(!isValid);

	return antRow;
}



/************************************************************************************************
									Interface::promptAntCol()
			This function prompts user for the column number to place the ant 									
**************************************************************************************************/
void Interface::promptAntCol() {
	std::cout << "Which col should the ant be placed in: " << std::endl;
}



/************************************************************************************************
									Interface::validateAntCol()
			This function checks to see if the ant is placed in a valid column. Valid columns are
			2 through whatever column the user selected for the size of the board.								
**************************************************************************************************/
int Interface::validateAntCol(int userCol) {

	int antCol;
    bool isValid = false;
	do {
		std::cin >> antCol;

		if(!std::cin.fail() && (antCol <= userCol) && (antCol >= 1)){
			isValid = true;
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overflow
			std::cout << "Invalid input. Please enter an integer between '2' and '400': " << std::endl;
		}
	} while(!isValid);

	return antCol;
}



/************************************************************************************************
									Interface::getInfo()
			This function packages the previous prompt and validate functions together							
**************************************************************************************************/
void Interface::getInfo(int &boardRows, int &boardCols, int &antRow, int &antCol, int &gameSteps){
    Interface *computer = new Interface;
	//	prompt num rows for the board
	computer->promptNumRows();
	//	validate input and store it in boardRows
	boardRows = computer->validateNumRows();
	std::cout << "The number of rows is: " << boardRows << std::endl;

	//	prompt num cols for the board
	computer->promptNumCols();
	//	validate input and store it in boardCols
	boardCols = computer->validateNumCols();
	std::cout << "The number of cols is: " << boardCols << std::endl;

	//	prompt user for row they want to place the ant
	computer->promptAntRow();
	//	validate input and store in the antRow
	antRow = computer->validateAntRow(boardRows);
	std::cout << "The ant will be placed in row: " << antRow << std::endl; 

	//	prompt user for col they want to place the ant
	computer->promptAntCol();
	//	validate input and store in the antCol
	antCol = computer->validateAntCol(boardCols);
	std::cout << "The ant will be placed in column: " << antRow << std::endl; 

	//	prompt user for how many steps they want the game to run
	computer->promptSteps();
	//	validate input and store in gameSteps
	gameSteps = computer->validateSteps();
	std::cout << "The number of steps is: " << gameSteps <<std::endl;
    delete computer;
}



/************************************************************************************************
									Interface::getInfoForRand()
			This function packages the previous prompt and validate functions together							
**************************************************************************************************/
void Interface::getInfoForRand(int &boardRows, int &boardCols, int &gameSteps){
	Interface *computer = new Interface;
	//	Prompt num rows for the board
	computer->promptNumRows();
	//	validate input and store it in boardRows
	boardRows = computer->validateNumRows();
	std::cout << "The number of rows is: " << boardRows << std::endl;

	//	prompt num cols for the board
	computer->promptNumCols();
	//	validate input and store it in boardCols
	boardCols = computer->validateNumCols();
	std::cout << "The number of cols is: " << boardCols << std::endl;

	//	prompt user for how many steps they want the game to run
	computer->promptSteps();
	//	validate input and store in gameSteps
	gameSteps = computer->validateSteps();
	std::cout << "The number of steps is: " << gameSteps <<std::endl;
    delete computer;
}



/************************************************************************************************
									Interface::getStartingChoice()
			This function will call getInfo() if the user wants to play, else it will say goodbye 									
**************************************************************************************************/
void Interface::getStartingChoice(int startingChoice) {
	switch(startingChoice){
		case 1:
		{
			bool playAgain = false;
			do {
				Interface *computer = new Interface;
            	computer->promptRandomPlacement();	//	Ask user if they want to randomly place ant
            	//	store response as true or false in answerToRandomPlacement variable
            	bool answerToRandomPlacement = computer->validateRandomPlacement();	

            	if (answerToRandomPlacement){
            		int userInputBoardRow, userInputBoardCol, userGameSteps, randAntRow, randAntCol;
            		computer->getInfoForRand(userInputBoardRow, userInputBoardCol, userGameSteps);	//	pass variables by reference and get userinput
            		//	assign random ant placement row and col values. Values cannot exceed the input provided by user
            		//	for board row and column dimensions.
            		randAntRow = computer->randomAntRow(userInputBoardRow);
            		randAntCol = computer->randomAntCol(userInputBoardCol);

	            	Ant *antMan = new Ant;							// allocate memory
					antMan->setup(userInputBoardRow, userInputBoardCol);				// pass in user input to create board & print
					antMan->setAnt(randAntRow, randAntCol);					// pass in user input to set ant & print
					antMan->play(userGameSteps);					// pass in user input to set steps and start simulation	
					delete antMan;									//	deallocate memory
					computer->displayEndingMenu();					//	ask user if they want to play again
					playAgain = computer->validateEndingMenu();		//	true if 'a' or 'A' , false if 'b' or 'B'							
            	}
	            else {
	            	int boardRow, boardCol, antRow, antCol, gameSteps;	//	variables to hold user input
	            	computer->getInfo(boardRow, boardCol, antRow, antCol, gameSteps); // pass variables by reference and get userinput
					Ant *antMan = new Ant;							// allocate memory
					antMan->setup(boardRow, boardCol);				// pass in user input to create board & print
					antMan->setAnt(antRow, antCol);					// pass in user input to set ant & print
					antMan->play(gameSteps);						// pass in user input to set steps and start simulation	
					delete antMan;									//	dellocate memory			
					computer->displayEndingMenu();					//	ask user if they want to play again
					playAgain = computer->validateEndingMenu();		//	true if 'a' or 'A' , false if 'b' or 'B'								
	            }
				delete computer;									//	deallocate memory
			} while(playAgain);										// 	if user selects 'a' or 'A' plays again.
            std::cout << "goodbye!" << std::endl;
			break;
		}
			
		case 2:
			std::cout << "The End." << std::endl; 
			break;
	}

}



/************************************************************************************************
									Interface::promptEndingMenu()
			This function asks the user to enter 'a' or 'A' to play again or 'b' or 'B'
			to quit. 									
**************************************************************************************************/
void Interface::displayEndingMenu() {
	std::cout << "\n\n		Ending Menu\n\n";
	std::cout << "a)  Play again\n";
	std::cout << "b)  Quit\n";
	std::cout << "Enter the char 'a' to play again or enter the char 'b' to quit: " << std::endl;
}



/************************************************************************************************
									Interface::validateEndingMenu()
			This function checks to see if the user input is a character 'a' or 'A' or 'b' or 'B'
			and returns the character   									
**************************************************************************************************/
bool Interface::validateEndingMenu() {

	char endChoice;
    bool isValid = false;
	bool isTrue = false;
	do {
		std::cin >> endChoice;
		if(!std::cin.fail() && ((endChoice == 'a' || endChoice == 'A') || (endChoice == 'b' || endChoice == 'B'))){
			isValid = true;
			if(endChoice == 'a' || endChoice == 'A'){
				isTrue = true;
			}
			else if(endChoice == 'b' || endChoice == 'B'){
				isTrue = false;
			}
		}
		else{
			std::cin.clear();	//	clear buffer
			std::cin.ignore(256, '\n');	// referenced Stack Overflow
			std::cout << "Invalid input. Please enter a char 'a' or a char 'b': " << std::endl;
		}
	} while(!isValid);

	return isTrue;
}



/************************************************************************************************
									Interface::promptRandomPlacement()
			This function asks the user if they would like to randomly place the ant
**************************************************************************************************/
void Interface::promptRandomPlacement() {
    std::cout << "Would you like to randomly place the ant? Enter the char 'Y' for yes or 'N' for no: " << std::endl;
}



/************************************************************************************************
									Interface::validateRandomPlacement()
			This function checks to see if the user input is 'y' or 'Y' or 'n' or 'N'. If the
			user chooses 'y' or 'Y', it returns true, else it returns false
**************************************************************************************************/
bool Interface::validateRandomPlacement(){ 

    char randChoice;
    bool isValid = false;
    bool isTrue = false;
    do {
        std::cin >> randChoice;
        if(!std::cin.fail() && ((randChoice == 'y' || randChoice == 'Y') || (randChoice == 'n' || randChoice == 'N'))){
            isValid = true;
            if(randChoice == 'y' || randChoice == 'Y'){
                isTrue = true;
            }
            else if(randChoice == 'n' || randChoice == 'N'){
                isTrue = false;
            }
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overflow
            std::cout << "Invalid input. Please enter a char 'Y' or a char 'N': " << std::endl;
        }
    } while(!isValid);

    return isTrue;
}



/************************************************************************************************
									Interface::randomAntRow()
			This function takes the number of rows the board should have as an argument. It
			then generates a random row. The random row will be in a range from 1 to the row number
			passed as the argument.
**************************************************************************************************/
int Interface::randomAntRow(int userRow) {
    // I referenced 3.10 in the textbook to write this code
    unsigned seed;  //  Random generator seed
    seed = time(0);
    srand(seed);

    int randomRow;
    randomRow = rand() % (userRow-1) + 1;   // limits range to 1 through user chosen row for the board

    return randomRow;
}



/************************************************************************************************
									Interface::randomAntCol()
			This function takes the number of columns the board should have as an argument. It
			then generates a random column. The random column will be in a range from 1 the column
			number passed as the argument.
**************************************************************************************************/
int Interface::randomAntCol(int userCol) {
    // I referenced 3.10 in the textbook to write this code
    unsigned seed;  //  Random generator seed
    seed = time(0);
    srand(seed);

    int randomColumn;
    randomColumn = rand() % (userCol-1) + 1;    // limits range to 1 through user chosen column for the board

    return randomColumn;
}
