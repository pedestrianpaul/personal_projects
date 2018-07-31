/**********************************************************************************************
** Author: Paul Min
** Date: 07/02/18
** Description: output_letters function takes an output file stream variable, and a pointer to 
** an array of integers that contains frequencies of letters. The function first asks user for 
** the filename the user would like to output to, then outputs the frequencies of letters to 
** the output file in the format specified above.
************************************************************************************************/
#include <iostream>
#include <fstream>
void output_letters(std::ofstream &osFile, int* array) {
	//	will store output file name 
	std::string outputFileName;	
	//	Prompt user for output file name
	std::cout << "What is the name of the file you would like to output to: " << std::endl;
	std::getline(std::cin, outputFileName);

	osFile.open(outputFileName);

	const int max = 26;
	for(int i = 0; i < max; i++){
		char letter = static_cast<char>(i+97);
		osFile << letter <<": " << array[i] << "\n" << std::endl;
	}
	osFile.close();
}