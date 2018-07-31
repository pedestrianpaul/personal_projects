/**********************************************************************************************
** Author: Paul Min
** Date: 06/28/18
** Description: Ant.cpp is the Ant class function implementation file. 
************************************************************************************************/

#include "Ant.hpp"
#include <iostream>

/***********************************************************************************************
										Ant::Ant()
This is the default constructor. This function initalizes the direction of the ant to "North" and
sets the antSymbol to '*'
************************************************************************************************/
Ant::Ant() {
	antDirection = North;	// Ant will face north initially
}



/***********************************************************************************************
										Ant::turnLeft()
					This function turns the ant left. It only changes the direction.
					I watched a youtube video on LA and it gave me the idea to 
					create separate functions to change just the orientation of the ant
************************************************************************************************/
void Ant::turnLeft() {
	antDirection--;
	if(0 > antDirection){
		antDirection = West;
	}
}



/***********************************************************************************************
										Ant::turnRight()
					This function turns the ant right. It only changes the direction.
					I watched a youtube video on LA and it gave me the idea the 
					create separate functions to change just the orientation of the ant
************************************************************************************************/
void Ant::turnRight() {
	antDirection++;
	if(antDirection > West){
		antDirection = North;
	}
}



/***********************************************************************************************
										Ant::moveForward()
			This function moves the ant forward one piece based off its direction.
			I watched a youtube video on LA and it gave me the idea to create a function 
			to move the ant forward based off it's direction. It also helped me understand 
			how to deal with the edges.
************************************************************************************************/
void Ant::moveForward() {
	// moves ant based off direction
	switch(antDirection){
		case North:
			antRow--;
			break;
		case East:
			antCol++;
			break;
		case South:
			antRow++;
			break;
		case West:
			antCol--;
			break;
	}
	// handles the edges
	if(antCol > antBoard->getBoardCol() -1){
		antCol = 0;
	}
	else if(antCol < 0){
		antCol = antBoard->getBoardCol()-1;
	}
	else if(antRow > antBoard->getBoardRow()-1){
		antRow = 0;
	}
	else if(antRow < 0){
		antRow = antBoard->getBoardRow()-1;
	}
}



/************************************************************************************************
									Ant::setup()
						This function sets up the board
*************************************************************************************************/
void Ant::setup(int boardRow, int boardCol) { 
	antBoard = new Board(boardRow, boardCol);
	//antBoard->Board(boardRow, boardCol);		// initializes board to white based off user input
	antBoard->printBoard();
}



/************************************************************************************************
									Ant::setAnt()
This function initially places the ant on the board according to user input
*************************************************************************************************/
void Ant::setAnt(int setAntRow, int setAntCol){
	antRow = setAntRow - 1;
	antCol = setAntCol - 1;
	antBoard->setBoard(antRow, antCol, '*');	//	place ant on board
	antBoard->printBoard();	//	print board
	antBoard->setBoard(antRow, antCol, ' ');	//	set color back to white
}


/************************************************************************************************
									Ant::play()
This function uses turnLeft, turnRight, and moveForward based off the rules of Langton's Ant 
*************************************************************************************************/
void Ant::play(int steps) {
	for(int i = 1; i <= steps; i++){
		//	If piece is white
		if(antBoard->getBoard(antRow, antCol) == ' '){
			turnRight();
			//	change color from white to black
			antBoard->setBoard(antRow, antCol, '#');
			moveForward();
			//	if the piece that the ant is moving into is white
			if (antBoard->getBoard(antRow, antCol) == ' '){
				//	place ant on board
				antBoard->setBoard(antRow, antCol, '*');
				//	display step #
				std::cout << "Step #: " << i << std::endl;
				//	print board
				antBoard->printBoard();
				//	set piece back to white color
				antBoard->setBoard(antRow, antCol, ' ');
			}
			//	if the piece that the ant is moving into is black
			else if(antBoard->getBoard(antRow, antCol) =='#'){
				//	place ant on board
				antBoard->setBoard(antRow, antCol, '*');
				//	display step #
				std::cout << "Step #: " << i << std::endl;
				//	print board
				antBoard->printBoard();
				//	set piece back to white color
				antBoard->setBoard(antRow, antCol, '#');
			}	
		}	//	If piece is black
		else if(antBoard->getBoard(antRow, antCol) == '#'){
			turnLeft();
			//	change color from black to white
			antBoard->setBoard(antRow, antCol, ' ');
			moveForward();
			//	if the piece that the ant is moving into is white
			if (antBoard->getBoard(antRow, antCol) == ' '){
				//	place ant on board
				antBoard->setBoard(antRow, antCol, '*');
				//	display step #
				std::cout << "Step #: " << i << std::endl;
				//	print board
				antBoard->printBoard();
				//	set piece back to white color
				antBoard->setBoard(antRow, antCol, ' ');
			}
			//	if the piece that the ant is moving into is black
			else if(antBoard->getBoard(antRow, antCol) =='#'){
				//	place ant on board
				antBoard->setBoard(antRow, antCol, '*');
				//	display step #
				std::cout << "Step #: " << i << std::endl;
				//	print board
				antBoard->printBoard();
				//	set piece back to white color
				antBoard->setBoard(antRow, antCol, '#');
			}
		}
	}
}



/************************************************************************************************
										Ant::~Ant()
							This function deallocates the memory										
**************************************************************************************************/
Ant::~Ant() {
	delete antBoard;
}


