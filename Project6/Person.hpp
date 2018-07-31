/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/13/18
** Description: Person.hpp is the Person class specification file.
************************************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>


class Person {
protected:
    std::string personName;
    int personAge;
    float personNumber; //  stores either gpa or instructor rating
public:
    std::string getPersonName() const;
    int getPersonAge() const;
    virtual double getPersonNumber() const;
    virtual void do_work() const;
    virtual ~Person();
};


#endif
