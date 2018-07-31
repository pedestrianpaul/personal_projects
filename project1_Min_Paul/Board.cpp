/**********************************************************************************************
** Author: Paul Min
** Date: 06/28/18
** Description: Board.cpp is the Board class function implementation file. 
************************************************************************************************/

#include "Board.hpp"
#include <iostream>

/************************************************************************************************
										Board::Board()
			This function makes the board and initializes all the spaces to white										
**************************************************************************************************/
Board::Board(int row, int col) {
	//	dynamically allocate memory space for the array
	//	I am referencing stack overflow as mentioned in the lab specifications
	rowCount = row;
	colCount = col;

	//	make board
	gameBoard = new char*[rowCount];
	for(int i = 0; i < rowCount; ++i){
		gameBoard[i] = new char[colCount];
	}

	//	initialize board all white spaces
	for(int i = 0; i < rowCount; i++){
		for(int j = 0; j < colCount; j++){
			gameBoard[i][j] = ' ';
		}
	}
}



/************************************************************************************************
										Board::printBoard()
									This function prints the board										
**************************************************************************************************/
void Board::printBoard() {
	for(int i = 0; i < rowCount; i++){
		for(int j = 0; j < colCount; j++){
			std::cout << gameBoard[i][j];
		}
		std::cout << std::endl;
	}
}



/************************************************************************************************
										Board::setBoard()
							This function sets a piece on the board										
**************************************************************************************************/
void Board::setBoard(int row, int col, char symbol){
	gameBoard[row][col] = symbol;
}



/************************************************************************************************
										Board::getBoard()
							This function gets a piece on the board
**************************************************************************************************/
char Board::getBoard(int row, int col){
	return gameBoard[row][col];
}


/************************************************************************************************
										Board::getBoardRow()
							This function get the rowCount
**************************************************************************************************/
int Board::getBoardRow(){
	return rowCount;
}



/************************************************************************************************
										Board::getBoardCol()
							This function gets the colCount
**************************************************************************************************/
int Board::getBoardCol(){
	return colCount;
}


/************************************************************************************************
										Board::~Board()
							This function deallocates the memory										
**************************************************************************************************/
Board::~Board(){
	for(int i = 0; i < rowCount; i++){
		delete [] gameBoard[i];
	}
	delete [] gameBoard;
}