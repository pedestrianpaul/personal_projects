/**********************************************************************************************
** Author: Paul Min
** Date: 07/02/18
** Description: main.cpp for File I/o
************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "count_letters.hpp"
#include "output_letters.hpp"

int main () {
	const int size = 26;			//	26 letters in the alphabet
	int array[size] = { };			//	initializes each element of the array to 0
	std::ifstream inputFile;		//	File stream object input
	std::string fileName;			//	Holds the input file name



	//	Prompt the user to enter the input file name
	std::cout << "What is the name of the file you would like to read: " << std::endl;
	//	Get the name of the input file and store it in fileName variable
	std::getline(std::cin, fileName);
	//	Open the input file
	inputFile.open(fileName);

	//	Check to see if file opened, if not say goodbye
	if (!inputFile) {
		std::cout << "File open error! Goodbye." << std::endl;
		return 0;
	}
	//	call count letters function
	count_letters(inputFile, array);

    //  inputFile.close();

	return 0;
}