/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/13/18
** Description: Student.hpp is the Student class specification file.
************************************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"
#include <string>

class Student : public Person{
private:
    float gpa;
public:
    Student(std::string m_name);
    Student(std::string m_name, int m_age, float m_gpa);
    virtual double getPersonNumber() const override;
    virtual void do_work() const override;
};


#endif
