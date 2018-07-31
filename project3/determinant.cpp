/**********************************************************************************************
** Author: Paul Min
** Date: 06/25/18
** Description: The function takes in the 2D array, which contains the value inside the 
** matrix, and calculate the determinant. Afterwards, the function should return the determinant. 
************************************************************************************************/
#include "determinant.hpp"

int determinant(int **array, int matrixSize){
	// Initialize determinantValue
	int determinantValue;

	switch(matrixSize){
		case 2:
			determinantValue = (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
			break;
		case 3:
			determinantValue = (array[0][0] * (array[1][1] * array[2][2] - array[1][2] * array[2][1])) -
							   (array[0][1] * (array[1][0] * array[2][2] - array[1][2] * array[2][0])) +
							   (array[0][2] * (array[1][0] * array[2][1] - array[1][1] * array[2][0]));
			break;
	}
	return determinantValue;
}
