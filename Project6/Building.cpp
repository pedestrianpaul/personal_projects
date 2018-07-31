/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/22/18
** Description: Building.cpp is the Building class implementation file.
************************************************************************************************/

#include "Building.hpp"
#include <string>


/************************************************************************************************
                   Building::Building(std::string name, int size, std::string address)
   This function is the building constructor. It has three parameters. It accepts 3 arguments.
   A string for the building name, and int for the building size, and a string for the address
*************************************************************************************************/
Building::Building(std::string m_name, int m_size, std::string m_address){
    this->bldgName = m_name;
    this->bldgSize = m_size;
    this->bldgAddress = m_address;
}



/************************************************************************************************
                              std::string Building::getBldgName() const
                            This function returns the name of the building
*************************************************************************************************/
std::string Building::getBldgName() const {
    return bldgName;
}



/************************************************************************************************
                              int Building::getBldgSize() const
                            This function returns the size of the building
*************************************************************************************************/
int Building::getBldgSize() const {
    return bldgSize;
}



/************************************************************************************************
                              std::string Building::getBldgAddress() const
                            This function returns the address of the building
*************************************************************************************************/
std::string Building::getBldgAddress() const {
    return bldgAddress;
}