/**********************************************************************************************
** Author: Paul Min
** Date: 06/28/18
** Description: Board.hpp is the Board class function specification file. 
************************************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
private:
	int rowCount;
	int colCount;
	char **gameBoard;

public:
	Board(int row, int col);	// creates board and initializes all elements to hold an empty space (white)
	void printBoard();			//	prints the board
	void setBoard(int row, int col, char symbol);	// sets the board with a symbol of your choosing
	char getBoard(int row, int col);	// gets character from the board
	int getBoardRow();			// returns board row
	int getBoardCol();			// returns board col
	~Board();					//	destructor 
};

#endif