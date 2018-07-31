/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Tiger.cpp is the Tiger class implementation file. 
************************************************************************************************/
#include "Tiger.hpp"

/*************************************************************************************************
										Tiger::Tiger()
								This is the default constructor									
**************************************************************************************************/
Tiger::Tiger()
{
	this->setAge(5000);		//	setting age to 5000 to help with debugging
	this->setCost(10000);
	this->setBabies(1);
	this->setPayoff(2000);	//	20% of initial cost
}



/*************************************************************************************************
										Tiger::Tiger(int)
						Constructor accepts one int argument for age							
**************************************************************************************************/
Tiger::Tiger(int m_age)
{
	this->setAge(m_age);		//	setting age to 5000 to help with debugging
	this->setCost(10000);
	this->setBabies(1);
	this->setPayoff(2000);		//	20% of initial cost
}