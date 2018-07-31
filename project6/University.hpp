/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/13/18
** Description: University.hpp is the University class specification file.
************************************************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

#include <iostream>
#include <string>


class University {
protected:
    std::string universityName;
    Building* buildingPtr;
    Person* peoplePtr;

public:
    University(std::string m_name, Person* people, Building* buildings);
    void printBldgInfo() const;   //  prints information on all the buildings
    void printPeopleInfo() const; //  prints information on all the people
    int validate(int min, int max);  //  validates input between min and max
    void menu();    //  displays menu with 4 options
    void doWorkMenu();  //  display do_work menu
};

#endif
