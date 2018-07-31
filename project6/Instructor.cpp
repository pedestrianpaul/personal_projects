/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/22/18
** Description: Instructor.cpp is the Instructor class implementation file.
************************************************************************************************/

#include "Instructor.hpp"
#include <iostream>
#include <ctime>



/************************************************************************************************
					Instructor::Instructor()
	This is a constructor that accepts no arguments.
*************************************************************************************************/
Instructor::Instructor(std::string m_name){
    personName = m_name;
}


/************************************************************************************************
					Instructor::Instructor(std::string m_name, int m_age)
	This is the constructor. It accepts a string and an int as arguments. The string is for
	the name of the instructor. The int is for the age of the instructor.
*************************************************************************************************/
Instructor::Instructor(std::string m_name, int m_age, float m_rating){
	personName = m_name;
	personAge = m_age;
    rating = m_rating;

    //  Generate random number for rating
    personNumber = rating;

}



/************************************************************************************************
					    double Instructor::getPersonNumber() const;
	                This function returns the personNumber data member
*************************************************************************************************/
double Instructor::getPersonNumber() const {
    return personNumber;
}



/************************************************************************************************
					    void Instructor::do_work() const;
	                This function output the following message:

“PERSON_NAME graded papers for X hours.” Where PERSON_NAME is the person’s name, and X is
 the randomly generated number.
*************************************************************************************************/
void Instructor::do_work() const {
    int randomNum = (rand() % 7) + 2;
    std::cout << this->getPersonName() << " graded papers for " << randomNum
              << " hours." << std::endl;
}