/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/22/18
** Description: Building.hpp is the Building class specification file.
************************************************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
#include <string>


class Building {
protected:
    std::string bldgName;
    int bldgSize;
    std::string bldgAddress;
public:
    Building(std::string name, int size, std::string address);
    std::string getBldgName() const;
    int getBldgSize() const;
    std::string getBldgAddress() const;
};

#endif
