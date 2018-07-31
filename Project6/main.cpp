/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/22/18
** Description: main.cpp is the file that runs the student information system.
************************************************************************************************/

#include "University.hpp"

#include <ctime>

int main() {

    srand(time(NULL));

    //	Adding student jack and instructor bob to person array
    Person people[] = {Student("Jack", 21, 3.9), Instructor("Bob", 32, 4.8)};

    //	Adding bates hall and burt hall to building array
    Building buildings[] = {Building("Bates Hall", 16134, "110 SW 26th Street, Corvallis, OR 97331")
    , Building("Burt Hall", 75332, "2651 SW Orchard Ave, Corvallis, OR 97331")};

	//	passing people array and building array to university constructor
    University OSU("Oregon State University", people, buildings);

    //  Display the menu
    OSU.menu();

    return 0;
}