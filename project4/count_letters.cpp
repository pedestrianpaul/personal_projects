/**********************************************************************************************
** Author: Paul Min
** Date: 07/02/18
** Description: The count_letters function takes an input file stream variable, and a pointer 
** to an array of integers. The function first reads the paragraph string from the input file 
** stream, then counts the letter frequencies of that paragraph, and store the frequencies in
** the array. Disregards upper/lower case letters.
************************************************************************************************/
#include "count_letters.hpp"
#include "output_letters.hpp"
#include <iostream>
#include <cstring>

void count_letters(std::ifstream &isFile, int* array){
    std::cout << "successfully called count_letters" << std::endl;
    const int max = 25;	// array[max] represents z
    const int min = 0;	//	array [min] represents a
    std::string paragraph;

    std::getline(isFile, paragraph);	//	read one line of file up to the "\n"

    while(!isFile.fail()){
        if(paragraph == ""){
            std::ofstream outputFile;		//	File stream output object
            output_letters(outputFile, array);

            //	reset the array and set all values to 0
            for (int j = 0; j < 26; j++){
                array[j] = 0;
            }
            std::getline(isFile, paragraph);	//	read one line of file up to the "\n"
        }
        else {
            //	iterate through the paragraph
            int paragraphLengthMinusOne = paragraph.length()-1;
            for(int i = 0; i <= paragraphLengthMinusOne; i++){
                int num = tolower(paragraph[i]);	//	convert char to int
                if((num - 97 >= min) && (num -97 <= max)){			// check to see if num-97 would = a-z
                    int element = num - 97;
                    array[element]++;							//	increment array element to keep track of letters
                }
            }
            std::ofstream outputFile;		//	File stream object output
            output_letters(outputFile, array);

            //	reset the array and set all values to 0
            for (int j = 0; j < 26; j++){
                array[j] = 0;
            }
            std::getline(isFile, paragraph);	//	read one line of file up to the "\n"
        }
    }
    isFile.close();

}