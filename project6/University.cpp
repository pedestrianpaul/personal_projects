/**********************************************************************************************
** Program Name: SIS
** Author: Paul Min
** Date: 07/13/18
** Description: University.cpp is the University class implementation file.
************************************************************************************************/

#include "University.hpp"

/************************************************************************************************
			University::University(std::string m_name, Person* m_people, Building* m_buildings)
	This is the constructor. It accepts 3 arguments. The name parameter is used to set the name
	of the university. It accepts a pointer to an array of Person objects and a pointer to an
	array of Building objects
*************************************************************************************************/
University::University(std::string m_name, Person* people, Building* buildings){
    universityName = m_name;
    buildingPtr = buildings;
    peoplePtr = people;
}

/************************************************************************************************
                            void University::printBldgInfo()
    This function prints all the information on all the buildings in its information system
    (name, address, and building's size)
 ************************************************************************************************/

void University::printBldgInfo() const{
    std::cout << "************ Building Info ************" << std::endl;
    for(int i = 1; i <= 2; i++){
        std::cout << "Building: " << i << std::endl;
        std::cout << "Name: " << buildingPtr[i-1].getBldgName() << std::endl;
        std::cout << "Size in sqft: " << buildingPtr[i-1].getBldgSize() << std::endl;
        std::cout << "Address: " << buildingPtr[i-1].getBldgAddress() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "********** End of Building Info **********" << std::endl;
}


/************************************************************************************************
                            void University::printPeopleInfo()
    This function prints the information of all the people (name, age, gpa or rating)
 ************************************************************************************************/
void University::printPeopleInfo() const{
    std::cout << "************ People Info ************" << std::endl;
        //  Student
        std::cout << "Student 1: " << std::endl;
        std::cout << "Name: " << peoplePtr[0].getPersonName() << std::endl;
        std::cout << "Age: " << peoplePtr[0].getPersonAge() << std::endl;
        std::cout << "GPA: " << peoplePtr[0].getPersonNumber() << std::endl;
        //  Instructor
        std::cout << std::endl;
        std::cout << "Instructor 1: " << std::endl;
        std::cout << "Name: " << peoplePtr[1].getPersonName() << std::endl;
        std::cout << "Age: " << peoplePtr[1].getPersonAge() << std::endl;
        std::cout << "Rating: " << peoplePtr[1].getPersonNumber() << std::endl;


    std::cout << "********** End of People Info **********" << std::endl;
}



/************************************************************************************************
							        University::validate()
	This function checks to see if the user input is an integer '1' or integer '2' or integer '3'
    or integer '4'.
**************************************************************************************************/
int University::validate(int min, int max) {
    int choice;
    bool isValid = false;
    do {
        std::cin >> choice;

        if(!std::cin.fail() && (choice >= min && choice <= max)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
            std::cout << "Invalid input. Please choose between the integer "
                      << min << " and the integer " << max << ": " << std::endl;
        }
    } while(!isValid);

    return choice;
}



/************************************************************************************************
							        University::menu()
	                This function displays a menu with 4 choices
	                1) Prints information about all the buildings
	                2) Prints information of everybody at the university
	                3) Chose a person to do work
	                4) Exit the program
**************************************************************************************************/
void University::menu(){
    int choice;
    do{
        std::cout << "\n\n		Menu\n\n";
        std::cout << "1)  Prints information about all the buildings\n";
        std::cout << "2)  Prints information of everybody at the university\n";
        std::cout << "3)  Choose a person to do work\n";
        std::cout << "4)  Exit the program\n";
        std::cout << "Enter your choice: " << std::endl;

        //  validate user input and make sure it's between 1 - 4
        choice = this->validate(1,4);

        switch(choice){
            case 1:
                //  prints building info
                this->printBldgInfo();
                break;
            case 2:
                //  prints information of everybody at the university
                this->printPeopleInfo();
                break;
            case 3:
                //  shows do work menu
                this->doWorkMenu();
                break;
            case 4:
                //  exits the program
                std::cout << "Goodbye!" << std::endl;
                break;
        }
    }while(choice != 4);
}



/************************************************************************************************
							        University::doWorkMenu()
	                This function displays a menu with all the people's names
	                and lets the user input the choice of the person the user would
	                like, to do work.
**************************************************************************************************/
void University::doWorkMenu() {
    std::cout << "\n\n      do_work menu\n\n";
    std::cout << "1)  " << peoplePtr[0].getPersonName() << std::endl;   //  student
    std::cout << "2)  " << peoplePtr[1].getPersonName() << std::endl;   //  instructor
    std::cout << "Choose between 1 or 2 to decide who should do work: " << std::endl;

    //  validate workChoice is between 1 & 2
    int workChoice = this->validate(1, 2);


    switch(workChoice){
        //  Student does work
        case 1:{
            Person* personPtr1;
            Student jack(peoplePtr[0].getPersonName());
            personPtr1 = &jack;

            personPtr1->do_work();
            personPtr1 = NULL;
            break;
        }
            //  Instructor does work
        case 2:{
            Person* personPtr2;
            Instructor bob(peoplePtr[1].getPersonName());
            personPtr2 = &bob;

            personPtr2->do_work();
            personPtr2 = NULL;
            break;
        }
    }
}