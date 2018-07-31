/**********************************************************************************************
** Author: Paul Min
** Date: 06/25/18
** Description: The function prompts the user for all the numbers within the matrix, that means 
for 2x2 matrix, it should ask the user for 4 numbers, and 9 numbers for a 3x3 matrix. 
Because the function takes a pointer to the 2D array, it should not return anything. 
************************************************************************************************/

#include "readMatrix.hpp"

void readMatrix(int **array, int matrixSize) {

	//	Prompt user to enter a certain number of values depending on the matrixSize
	switch(matrixSize){
		case 2:
			std::cout << "Enter 4 integers to populate the 2x2 matrix: " << std::endl;
			break;
		case 3:
			std::cout << "Enter 9 integers to populate the 3x3 matrix: " << std::endl;
			break;
		default:
			std::cout << "Invalid size" << std::endl;
	}

	//	Populate array with user input
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < matrixSize; j++){
			std::cin >> array[i][j];
			//	input validation 
			while(!std::cin.good()){
				std::cin.clear();	//	clear buffer
				std::cin.ignore(256, '\n');	//	empty buffer
				std::cout << "Invalid input. Please enter an integer: " << std::endl;
				std::cin >> array[i][j];
			}	
		}
	}
}