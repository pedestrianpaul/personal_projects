/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Penguin.cpp is the Penguin class implementation file. 
************************************************************************************************/
#include "Penguin.hpp"

/*************************************************************************************************
										Penguin::Penguin()
								This is the default constructor									
**************************************************************************************************/
Penguin::Penguin()
{
	this->setAge(5000);		//	setting age to 5000 to help with debugging
	this->setCost(1000);	
	this->setBabies(5);
	this->setPayoff(100);	//	10% of initial cost
}



/*************************************************************************************************
										Penguin::Penguin(int)
						Constructor accepts one int argument for age							
**************************************************************************************************/
Penguin::Penguin(int m_age)
{
	this->setAge(m_age);		//	setting age to 5000 to help with debugging
	this->setCost(1000);
	this->setBabies(5);
	this->setPayoff(100);		//	10% of initial cost
}