/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Animal.hpp is the Animal class specification file. 
************************************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal{
protected:
	int age;
	int cost;
	int numberOfBabies;
	static const int baseFoodCost = 10;
	int payoff;
public:	
	Animal();									//	Default constructor
	int getAge();								//	getter function for age data member
	int getCost();								//	getter function for cost data member
	int getBabies();							//	getter function for numberOfBabies data member
	int getPayoff();							//	getter function for payoff data member
	static int getBaseFoodCost();				//	getter function for baseFoodCost data member
	void setAge(int m_age);						//	setter function for age data member
	void setCost(int m_cost);					//	setter function for cost data member
	void setBabies(int m_numberOfBabies);		//	setter function for numberOfBabies data member
	void setPayoff(int m_payoff);				//	setter function for payoff data member
};

#endif