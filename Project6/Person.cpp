/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/22/18
** Description: Person.cpp is the Person class implementation file.
************************************************************************************************/

#include "Person.hpp"
#include <iostream>
#include <string>

/************************************************************************************************
                              std::string Person::getPersonName() const
                            This function returns the name of the person
*************************************************************************************************/
std::string Person::getPersonName() const {
    return personName;
}



/************************************************************************************************
                              std::string Person::getPersonAge() const
                            This function returns the age of the person
*************************************************************************************************/
int Person::getPersonAge() const {
    return personAge;
}



/************************************************************************************************
                              double Person::getPersonNumber() const
                            This function returns the age of the person
*************************************************************************************************/
double Person::getPersonNumber() const {
    return personNumber;
}



/************************************************************************************************
                              virtual void Person::do_work() const
    This function will be overridden either by the student or instructor class.
*************************************************************************************************/
void Person::do_work() const {
    std::cout << "If you're seeing this something went wrong." << std::endl;
}



/************************************************************************************************
                              virtual Person::~Person();
                                Virtual Destructor
*************************************************************************************************/
Person::~Person(){
    
}