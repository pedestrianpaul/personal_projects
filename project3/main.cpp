/**********************************************************************************************
** Author: Paul Min
** Date: 06/25/18
** Description: The main function
************************************************************************************************/
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

int main (){

	int matrixSize;
	//	Prompt user for what kind of matrix they would like to build
	std::cout << "What type of matrix would you like to build: " << std::endl;
	std::cout << "Enter 2 to build a 2x2 matrix." << std::endl;
	std::cout << "Enter 3 to build a 3x3 matrix." << std::endl;

	//	Receive input
	std::cin >> matrixSize;

	//	Input validation
	while(matrixSize != 2 && matrixSize != 3){
		std::cout << "Invalid input. Please enter the integer 2 to build a 2x2 matrix or the integer 3 to build a 3x3 matrix." << std::endl;
		std::cin >> matrixSize;
		if(matrixSize != 2 && matrixSize !=3){
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	}

	//	Dynamically allocate the memory space for the array
	//	I am referencing stackoverflow as mentioned in the lab specifications
	
	int colCount = matrixSize;
	int rowCount = matrixSize;

	int** matrix = new int*[rowCount];
	for(int i = 0; i < rowCount; ++i){
		matrix[i] = new int[colCount];
	}


	//	ask user to enter 4 or 9 integers
	readMatrix(matrix, matrixSize);

	//	calculate determinant
	int matrixDeterminant = determinant(matrix, matrixSize);

	//	Display matrix
	std::cout << "This is the matrix: " << std::endl;
	std::cout << "The determinant is: " << matrixDeterminant << std::endl;

	//	Print matrix
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < matrixSize; j++){
			std::cout << matrix[i][j] << "	";
		}
		std::cout << std::endl; //	new line for each row
	}

	//	clean up
	for(int i = 0; i < matrixSize; i++){
		delete [] matrix[i];
	}
	delete [] matrix;

	return 0;
}