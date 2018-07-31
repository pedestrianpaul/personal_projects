/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/13/18
** Description: Student.cpp is the Student class implementation file.
************************************************************************************************/

#include "Student.hpp"
#include <iostream>
#include <ctime>


/************************************************************************************************
					                    Student::Student()
	                    This is a default constructor with no arguments
*************************************************************************************************/
Student::Student(std::string m_name){
    personName = m_name;
}



/************************************************************************************************
					Student::Student(std::string m_name, int m_age)
	This is the constructor. It accepts a string and an int as arguments. The string is for
	the name of the student. The int is for the age of the student.
*************************************************************************************************/
Student::Student(std::string m_name, int m_age, float m_gpa){
    personName = m_name;
    personAge = m_age;
    gpa = m_gpa;

    //  Generate random number for rating
    personNumber = gpa;

}



/************************************************************************************************
					    double Student::getPersonNumber() const;
	                This function returns the personNumber data member
*************************************************************************************************/
double Student::getPersonNumber() const {
    return personNumber;
}



/************************************************************************************************
					    void Student::do_work() const;
	                This function output the following message:

“PERSON_NAME did X hours of homework.” Where PERSON_NAME is the person’s name, and X is
 the randomly generated number.
*************************************************************************************************/
void Student::do_work() const {
    int randomNum = (rand() % 7) + 2;
    std::cout << this->getPersonName() << " did " << randomNum
              << " hours of homework." << std::endl;
}