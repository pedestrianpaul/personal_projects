/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Turtle.cpp is the Turtle class implementation file. 
************************************************************************************************/
#include "Turtle.hpp"

/*************************************************************************************************
										Turtle::Turtle()
								This is the default constructor									
**************************************************************************************************/
Turtle::Turtle()
{
	this->setAge(5000);		//	setting age to 5000 to help with debugging
	this->setCost(100);	
	this->setBabies(10);
	this->setPayoff(5);		//	5% of initial cost
}



/*************************************************************************************************
										Turtle::Turtle(int)
								This is the default constructor									
**************************************************************************************************/
Turtle::Turtle(int m_age)
{
	this->setAge(m_age);		//	setting age to 5000 to help with debugging
	this->setCost(100);	
	this->setBabies(10);
	this->setPayoff(5);		//	5% of initial cost
}