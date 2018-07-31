/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/22/18
** Description: Instructor.hpp is the Instructor class specification file.
************************************************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"
#include <string>

class Instructor : public Person{
private:
    double rating;
public:
    Instructor(std::string m_name);
    Instructor(std::string m_name, int m_age, float m_rating);
    virtual double getPersonNumber() const override;
    virtual void do_work() const override;
};


#endif
