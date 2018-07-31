/**********************************************************************************************
** Program Name: Zoo
** Author: Paul Min
** Date: 07/13/18
** Description: Zoo.cpp is the Zoo class implementation file. 
************************************************************************************************/
#include "Zoo.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

/*************************************************************************************************
										Zoo::Zoo()
				This is the default constructor for the Zoo class
**************************************************************************************************/
Zoo::Zoo(){

    //  for random numbers
    seed = time(0);
    srand(seed);

	//	game starts with $100k
	money = 100000;

    //  bonus set to 0
    bonus = 0;

    //  day is set to 1
    day = 1;

	//	since no animals have been purchased yet
	numTigers = 0;
	numPenguins = 0;
	numTurtles = 0;
    numCheetahs = 0;

	//	starting capacity for animal arrays should be 10
	tigerCapacity = 10;
	penguinCapacity = 10;
	turtleCapacity = 10;
    cheetahCapacity = 10;

	tigerPopulation = nullptr;
    penguinPopulation = nullptr;
    turtlePopulation = nullptr;
    cheetahPopulation = nullptr;

	//	dynamic array for tigers has a size of 10 to start
	tigerPopulation = new Tiger[tigerCapacity];

	//	dynamic array for penguins has a size of 10 to start
	penguinPopulation = new Penguin[penguinCapacity];

	//	dynamic array for turtles has a size of 10 to start
	turtlePopulation = new Turtle[turtleCapacity];

    //  dynamic array for cheetahs has a size of 10 to start
    cheetahPopulation = new Cheetah[cheetahCapacity];

}



/*************************************************************************************************
										Zoo::getNumTigers()
						This function returns the numTigers data member
**************************************************************************************************/
int Zoo::getNumTigers(){
	return numTigers;
}



/*************************************************************************************************
										Zoo::getNumPenguins()
						This function returns the numPenguins data member
**************************************************************************************************/
int Zoo::getNumPenguins(){
	return numPenguins;
}



/*************************************************************************************************
										Zoo::getNumTurtles()
						This function returns the numTurtles data member
**************************************************************************************************/
int Zoo::getNumTurtles(){
	return numTurtles;
}



/*************************************************************************************************
										Zoo::getNumCheetahs()
						This function returns the numCheetahs data member
**************************************************************************************************/
int Zoo::getNumCheetahs(){
    return numCheetahs;
}



/*************************************************************************************************
										Zoo::getMoney()
						This function returns the money data member
**************************************************************************************************/
int Zoo::getMoney(){
    return money;
}



/*************************************************************************************************
										Zoo::getDay()
						This function returns the day data member
**************************************************************************************************/
int Zoo::getDay(){
    return day;
}



/*************************************************************************************************
										Zoo::addTiger(int)
	This function adds one tiger to the dynamic array. The age of the added tiger is set to the 
	argument that is passed to the function.

	referenced: https://www.cs.fsu.edu/~myers/c++/notes/dma.html
**************************************************************************************************/
void Zoo::addTiger(int m_age){
	numTigers++;
	//	Check to see if array needs to be resized
	if(numTigers > tigerCapacity){

		tigerCapacity *= 2;	//	double the size of tigerCapacity

		//	Create new array of the appropriate type and of the new size
		Tiger* temp = new Tiger[tigerCapacity];

		//	Copy the data from the old array into the new array
		for(int i = 0; i < tigerCapacity/2; i++){
			temp[i] = tigerPopulation[i];
		}

		//	Delete the old array
		delete [] tigerPopulation;

		//	Change the pointer
		tigerPopulation = temp;
	}

	tigerPopulation[numTigers-1] = Tiger(m_age);
}



/*************************************************************************************************
										Zoo::addPenguin(int)
	This function adds one penguin to the dynamic array. The age of the added penguin is set to the
	argument that is passed to the function.

	referenced: https://www.cs.fsu.edu/~myers/c++/notes/dma.html
**************************************************************************************************/
void Zoo::addPenguin(int m_age){
	numPenguins++;

	//	Check to see if array needs to be resized
	if(numPenguins > penguinCapacity){

		penguinCapacity *= 2;	//	double the size of tigerCapacity

		//	Create new array of the appropriate type and of the new size
		Penguin* temp = new Penguin[penguinCapacity];

		//	Copy the data from the old array into the new array
		for(int i = 0; i < penguinCapacity/2; i++){
			temp[i] = penguinPopulation[i];
		}

		//	Delete the old array
		delete [] penguinPopulation;

		//	Change the pointer
		penguinPopulation = temp;
	}

	penguinPopulation[numPenguins-1] = Penguin(m_age);
}



/*************************************************************************************************
										Zoo::addTurtle(int)
	This function adds one turtle to the dynamic array. The age of the added turtle is set to the
	argument that is passed to the function.

	referenced: https://www.cs.fsu.edu/~myers/c++/notes/dma.html
**************************************************************************************************/
void Zoo::addTurtle(int m_age){
	numTurtles++;

	//	Check to see if array needs to be resized
	if(numTurtles > turtleCapacity){

		turtleCapacity *= 2;	//	double the size of tigerCapacity

		//	Create new array of the appropriate type and of the new size
		Turtle* temp = new Turtle[turtleCapacity];

		//	Copy the data from the old array into the new array
		for(int i = 0; i < turtleCapacity/2; i++){
			temp[i] = turtlePopulation[i];
		}

		//	Delete the old array
		delete [] turtlePopulation;

		//	Change the pointer
		turtlePopulation = temp;
	}

	turtlePopulation[numTurtles-1] = Turtle(m_age);
}



/*************************************************************************************************
										Zoo::addCheetah(int)
	This function adds one cheetah to the dynamic array. The age of the added cheetah is set to the
	argument that is passed to the function.

	referenced: https://www.cs.fsu.edu/~myers/c++/notes/dma.html
**************************************************************************************************/
void Zoo::addCheetah(int m_age){
    numCheetahs++;

    //	Check to see if array needs to be resized
    if(numCheetahs > cheetahCapacity){

        cheetahCapacity *= 2;	//	double the size of tigerCapacity

        //	Create new array of the appropriate type and of the new size
        Cheetah* temp = new Cheetah[cheetahCapacity];

        //	Copy the data from the old array into the new array
        for(int i = 0; i < cheetahCapacity/2; i++){
            temp[i] = cheetahPopulation[i];
        }

        //	Delete the old array
        delete [] cheetahPopulation;

        //	Change the pointer
        cheetahPopulation = temp;
    }

    cheetahPopulation[numCheetahs-1] = Cheetah(m_age);
}



/*************************************************************************************************
									Zoo::removeTiger()
	    This function removes one tiger. It decrements the numTigers by 1.
**************************************************************************************************/
void Zoo::removeTiger(){
    numTigers--;
}



/*************************************************************************************************
									Zoo::removePenguin()
	    This function removes one penguin. It decrements the numPenguins by 1.
**************************************************************************************************/
void Zoo::removePenguin(){
    numPenguins--;
}



/*************************************************************************************************
									Zoo::removeTurtle()
	    This function removes one turtle. It decrements the numTurtles by 1.
**************************************************************************************************/
void Zoo::removeTurtle(){
    numTurtles--;
}



/*************************************************************************************************
									Zoo::removeCheetah()
	    This function removes one cheetah. It decrements the numCheetahs by 1.
**************************************************************************************************/
void Zoo::removeCheetah(){
    numCheetahs--;
}



/*************************************************************************************************
									Zoo::displayMoney()
					This function displays Money available: $ ...
**************************************************************************************************/
void Zoo::displayMoney(){
    std::cout << "Money available: $" << this->getMoney() << std::endl;
}



/*************************************************************************************************
									Zoo::displayDay()
						This function displays the day number
**************************************************************************************************/
void Zoo::displayDay(){
	std::cout << "****************************" << std::endl;
    std::cout << "Day " << this->getDay() << ": " << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << std::endl; // empty line
}



/*************************************************************************************************
									Zoo::promptFirstTiger()
	This function prompts the user to purchase at least 1 tiger. It uses oneOrTwo() to validate
	input and stores user input in the numFirstTigers data member. Once input is received, it calls
	addTiger() to add tigers to the zoo and deducts the tiger cost * numFirstTigers
**************************************************************************************************/
void Zoo::promptFirstTiger(){
    this->displayMoney();
    std::cout << "You must purchase at least 1 Tiger." << std::endl;
    std::cout << "Tigers cost $10,000 each." << std::endl;
    std::cout << "You can choose to purchase either 1 or 2 Tigers." << std::endl;
    std::cout << "How many Tigers would you like to purchase:" << std::endl;

    //  Only accepts int 1 or int 2 and stores it in numFirstTigers
    numFirstTigers = this->oneOrTwo();

    std::cout << "You chose to purchase " << numFirstTigers << " Tiger(s)" << std::endl;
    std::cout << std::endl;	// new line
    std::cout << "********************************************" << std::endl; // separator

    switch(numFirstTigers){
        case 1:
            money -= 10000;
            this->addTiger(1);
            break;
        case 2:
            money -= 20000;
            this->addTiger(1);
            this->addTiger(1);
            break;
    }
}



/*************************************************************************************************
									Zoo::promptFirstPenguin()
	This function prompts the user to purchase at least 1 penguin. It uses oneOrTwo() to validate
	input and stores user input in the numFirstPenguins data member. Once input is received, it calls
	addPenguin() to add penguins to the zoo and deducts the penguin cost * numFirstPenguins
**************************************************************************************************/
void Zoo::promptFirstPenguin(){
    this->displayMoney();
    std::cout << "You must purchase at least 1 Penguin." << std::endl;
    std::cout << "Penguins cost $1,000 each." << std::endl;
    std::cout << "You can choose to purchase either 1 or 2 Penguins." << std::endl;
    std::cout << "How many Penguins would you like to purchase:" << std::endl;

    //  Only accepts int 1 or int 2 and stores it in numFirstPenguins
    numFirstPenguins = this->oneOrTwo();

    std::cout << "You chose to purchase " << numFirstPenguins << " Penguin(s)" << std::endl;
    std::cout << std::endl;	// new line
    std::cout << "********************************************" << std::endl; // separator

    switch(numFirstPenguins){
        case 1:
            money -= 1000;
            this->addPenguin(1);
            break;
        case 2:
            money -= 2000;
            this->addPenguin(1);
            this->addPenguin(1);
            break;
    }
}



/*************************************************************************************************
									Zoo::promptFirstTurtle()
	This function prompts the user to purchase at least 1 turtle. It uses oneOrTwo() to validate
	input and stores user input in the numFirstTurtles data member. Once input is received, it calls
	addTurtle() to add turtles to the zoo and deducts the turtle cost * numFirstTurtles								
**************************************************************************************************/
void Zoo::promptFirstTurtle(){
    this->displayMoney();
    std::cout << "You must purchase at least 1 Turtle." << std::endl;
    std::cout << "Turtles cost $100 each." << std::endl;
    std::cout << "You can choose to purchase either 1 or 2 Turtles." << std::endl;
    std::cout << "How many Turtles would you like to purchase:" << std::endl;

    //  Only accepts int 1 or int 2 and stores it in numFirstTurtles
    numFirstTurtles = this->oneOrTwo();

    std::cout << "You chose to purchase " << numFirstTurtles << " Turtle(s)" << std::endl;
    std::cout << std::endl;	// new line
    std::cout << "********************************************" << std::endl; // separator

    switch(numFirstTurtles){
        case 1:
            money -= 100;
            this->addTurtle(1);
            break;
        case 2:
            money -= 200;
            this->addTurtle(1);
            this->addTurtle(1);
            break;
    }
}


/*************************************************************************************************
									Zoo::promptCheetahInfo()
    This function asks the user to enter the cost, the amount of babies, the feed cost, and the
    payoff associated with a cheetah.
**************************************************************************************************/
void Zoo::promptCheetahInfo() {
    std::cout << "Before you purchase a Cheetah please provide the following information:" << std::endl;
    //  Cheetah cost
    std::cout << "How much should a cheetah cost: " << std::endl;
    cheetahCost = this->cheetahCostValidation();    //  validates input between 1 - 20000
    std::cout << "Cheetahs cost $" << cheetahCost << "." << std::endl;
    //  Cheetah babies
    std::cout << "How many babies should a cheetah have: " << std::endl;
    cheetahBabies = this->cheetahBabyValidation();
    std::cout << "Cheetahs have " << cheetahBabies << " babies." << std::endl;
    //  Cheetah food cost
    std::cout << "How much should the food cost for a cheetah: " << std::endl;
    cheetahFeedCost = this->cheetahFoodCostValidation();
    std::cout << "Cheetah food cost $" << cheetahFeedCost << " per cheetah." << std::endl;
    //  Cheetah payoff
    std::cout << "How much profit should a cheetah generate for the zoo: " << std::endl;
    cheetahPayoff = this->cheetahPayoffValidation();
    std::cout << "Cheetahs generate $" << cheetahPayoff << " per cheetah." << std::endl;
}


/*************************************************************************************************
									Zoo::promptFirstCheetah()
	This function prompts the user to purchase at least 1 cheetah. It uses oneOrTwo() to validate
	input and stores user input in the numFirstCheetahs data member. Once input is received, it calls
	addCheetah() to add cheetahs to the zoo and deducts the cheetah cost * numFirstCheetahs		
**************************************************************************************************/
void Zoo::promptFirstCheetah(){
    this->displayMoney();
    std::cout << "You must purchase at least 1 Cheetah." << std::endl;
    this->promptCheetahInfo();
    std::cout << "Cheetahs cost $" << cheetahCost << " each." << std::endl;
    std::cout << "You can choose to purchase either 1 or 2 Cheetahs." << std::endl;
    std::cout << "How many Cheetahs would you like to purchase:" << std::endl;

    //  Only accepts int 1 or int 2 and stores it in numFirstCheetahs
    numFirstCheetahs = this->oneOrTwo();

    std::cout << "You chose to purchase " << numFirstCheetahs << " Cheetah(s)" << std::endl;
    std::cout << std::endl;	// new line

    switch(numFirstCheetahs){
        case 1:
            money -= cheetahCost;
            this->addCheetah(1);
            break;
        case 2:
            money -= cheetahCost*2;
            this->addCheetah(1);
            this->addCheetah(1);
            break;
    }
}


/************************************************************************************************
							        Zoo::oneOrTwo()
	This function checks to see if the user input is an integer '1' or integer '2'. If it
 is 1 or 2 it returns the value.
**************************************************************************************************/
int Zoo::oneOrTwo() {
    int choice;
    bool isValid = false;
    do {
        std::cin >> choice;

        if(!std::cin.fail() && (choice == 1 || choice == 2)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
            std::cout << "Invalid input. Please choose between the integer '1' or the integer '2': " << std::endl;
        }
    } while(!isValid);

    return choice;
}



/************************************************************************************************
							        Zoo::oneTwoThreeFour()
	This function checks to see if the user input is an integer '1' or integer '2' or integer '3'
    or integer '4'.
**************************************************************************************************/
int Zoo::oneTwoThreeFour() {
    int choice;
    bool isValid = false;
    do {
        std::cin >> choice;

        if(!std::cin.fail() && (choice == 1 || choice == 2 || choice == 3 || choice == 4)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced stack overflow and TA james
            std::cout << "Invalid input. Please choose between the integer '1', the integer '2',"
                      << " the integer '3', or the integer '4': " << std::endl;
        }
    } while(!isValid);

    return choice;
}



/*************************************************************************************************
									Zoo::cheetahCostValidation()
    This function validates user input to see that it is an integer between 1 - 20000. If it
    passes validation it returns the integer.
**************************************************************************************************/
int Zoo::cheetahCostValidation() {
    const int MAX_COST = 20000;
    const int MIN_COST = 1;

    int userInput;
    bool isValid = false;
    do {
        std::cin >> userInput;

        if(!std::cin.fail() && (userInput <= MAX_COST) && (userInput >= MIN_COST)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overflow
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overfow
            std::cout << "Invalid input. Please enter an integer between '1' and '20000': " << std::endl;
        }
    } while(!isValid);

    return userInput;
}



/*************************************************************************************************
									Zoo::cheetahBabyValidation()
    This function validates user input to see that it is an integer between 1 - 10. If it
    passes validation it returns the integer.
**************************************************************************************************/
int Zoo::cheetahBabyValidation() {
    const int MAX_COST = 10;
    const int MIN_COST = 1;

    int userInput;
    bool isValid = false;
    do {
        std::cin >> userInput;

        if(!std::cin.fail() && (userInput <= MAX_COST) && (userInput >= MIN_COST)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overflow
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overfow
            std::cout << "Invalid input. Please enter an integer between '1' and '10': " << std::endl;
        }
    } while(!isValid);

    return userInput;
}



/*************************************************************************************************
									Zoo::cheetahFoodCostValidation()
    This function validates user input to see that it is an even integer between 2 - 200. If it
    passes validation it returns the integer.
**************************************************************************************************/
int Zoo::cheetahFoodCostValidation() {
    const int MAX_COST = 200;
    const int MIN_COST = 2;

    int userInput;
    bool isValid = false;
    do {
        std::cin >> userInput;

        if(!std::cin.fail() && (userInput <= MAX_COST) && (userInput >= MIN_COST) && (userInput % 2 == 0)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overflow
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overfow
            std::cout << "Invalid input. Please enter an even integer between '2' and '200': " << std::endl;
        }
    } while(!isValid);

    return userInput;
}



/*************************************************************************************************
									Zoo::cheetahPayoffValidation()
    This function validates user input to see that it is an even integer between 1 - 5000. If it
    passes validation it returns the integer.
**************************************************************************************************/
int Zoo::cheetahPayoffValidation() {
    const int MAX_COST = 5000;
    const int MIN_COST = 1;

    int userInput;
    bool isValid = false;
    do {
        std::cin >> userInput;

        if(!std::cin.fail() && (userInput <= MAX_COST) && (userInput >= MIN_COST)){
            isValid = true;
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overflow
        }
        else{
            std::cin.clear();	//	clear buffer
            std::cin.ignore(256, '\n');	// referenced Stack Overfow
            std::cout << "Invalid input. Please enter an integer between '1' and '5000': " << std::endl;
        }
    } while(!isValid);

    return userInput;
}

/*************************************************************************************************
									Zoo::incrementAnimalsAge()
	                    This function increases all animals age by 1
**************************************************************************************************/
void Zoo::incrementAnimalsAge(){
    std::cout << "All animals are now one day older!" << std::endl;

    //  increment all tigers age by 1
    for(int i = 0; i < numTigers; i++){
        tigerPopulation[i].setAge(tigerPopulation[i].getAge()+1);
    }

    //  increment all penguins age by 1
    for(int j = 0; j < numPenguins; j++){
        penguinPopulation[j].setAge(penguinPopulation[j].getAge()+1);
    }

    //  increment all turtles age by 1
    for(int k = 0; k < numTurtles; k++){
        turtlePopulation[k].setAge(turtlePopulation[k].getAge()+1);
    }

    //  increment all cheetahs age by 1
    for(int c = 0; c < numCheetahs; c++){
        cheetahPopulation[c].setAge(cheetahPopulation[c].getAge()+1);
    }
}



/*************************************************************************************************
									Zoo::calculateFeedingCost()
This function calculates the feeding cost for all animals. Once total feeding cost is calculated
it is deducted from the total amount of money. Afterwards, money available is displayed to user.

**************************************************************************************************/
void Zoo::calculateFeedingCost() {
    int tigerFeedCost = this->getNumTigers() * Animal::getBaseFoodCost() * 5;
    int penguinFeedCost = numPenguins * Animal::getBaseFoodCost();
    int turtleFeedCost = numTurtles * (Animal::getBaseFoodCost()/2);
    int cheetahFeedingCost = numCheetahs * cheetahFeedCost;

    int totalFeedCost = tigerFeedCost + penguinFeedCost + turtleFeedCost + cheetahFeedingCost;

    std::cout << "The feed cost for " << this->getNumTigers() << " tigers is $" << tigerFeedCost << std::endl;
    std::cout << "The feed cost for " << this->getNumPenguins() << " penguins is $" << penguinFeedCost << std::endl;
    std::cout << "The feed cost for " << this->getNumTurtles() << " turtles is $" << turtleFeedCost << std::endl;
    std::cout << "The feed cost for " << this->getNumCheetahs() << " cheetahs is $" << cheetahFeedingCost << std::endl;
    std::cout << "The total feed cost for day " << day << " is $" << totalFeedCost << "." << std::endl;

    money -= totalFeedCost;
    this->displayMoney();
}



/*************************************************************************************************
									Zoo::textRandAnimalDies()
            This function reads a message from randAnimalDies.txt to display a status message
**************************************************************************************************/
void Zoo::textRandAnimalDies() {
    //  will hold the line read from input file
    std::string paragraph;
    std::ifstream inputFile;

    inputFile.open("randAnimalDies.txt");
    getline(inputFile, paragraph);
    std::cout << paragraph << std::endl;
    inputFile.close();
}



/*************************************************************************************************
									Zoo::textAttendanceBoom()
            This function reads a message from attendanceBoom.txt to display a status message
**************************************************************************************************/
void Zoo::textAttendanceBoom(){
    //  will hold the line read from input file
    std::string paragraph;
    std::ifstream inputFile;

    inputFile.open("attendanceBoom.txt");
    getline(inputFile, paragraph);
    std::cout << paragraph << std::endl;
    inputFile.close();
}



/*************************************************************************************************
									Zoo::textBabyAnimal()
            This function reads a message from babyAnimal.txt to display a status message
**************************************************************************************************/
void Zoo::textBabyAnimal(){
    //  will hold the line read from input file
    std::string paragraph;
    std::ifstream inputFile;

    inputFile.open("babyAnimal.txt");
    getline(inputFile, paragraph);
    std::cout << paragraph << std::endl;
    inputFile.close();
}



/*************************************************************************************************
									Zoo::textNothing()
            This function reads a message from nothing.txt to display a status message
**************************************************************************************************/
void Zoo::textNothing(){
    //  will hold the line read from input file
    std::string paragraph;
    std::ifstream inputFile;

    inputFile.open("nothing.txt");
    getline(inputFile, paragraph);
    std::cout << paragraph << std::endl;
    inputFile.close();
}


/*************************************************************************************************
									Zoo::randAnimalDies()
                        This function chooses a random animal to die
    It does this by generating a random number between 1 - 4. Each number corresponds to an animal
    that will be chosen to die if the quantity of that type of animal is greater than 0 in the zoo.
    If there are no animals of that type in the zoo, it checks to see if other animals are
    available. If no animals are in the zoo, then it couts a statement explaining that 
    an animal was supposed to die, but no animals are in the zoo.
**************************************************************************************************/
void Zoo::randAnimalDies() {

    //  generate random number between 1 - 4
    int randAnimal = (rand() % 4) + 1;

    switch(randAnimal){
        //  Tiger dies
        case 1:
            //  If there are any tigers in the zoo
            if(numTigers > 0){
                // One tiger dies
                std::cout << "A tiger randomly died from sickness." << std::endl;
                this->removeTiger();
            }else if(numPenguins > 0){
                // One penguin dies
                std::cout << "A penguin randomly died from sickness." << std::endl;
                this->removePenguin();
            }else if(numTurtles > 0){
                // One turtle dies
                std::cout << "A turtle randomly died from sickness." << std::endl;
                this->removeTurtle();
            }else if(numCheetahs>0){
                //  One cheetah dies
                std::cout << "A cheetah randomly died from sickness." << std::endl;
                this->removeCheetah();
            }else{
                std::cout << "A random animal was supposed to die, but you have no animals in your zoo." << std::endl;
            }
            break;
        //  Penguin dies
        case 2:
            if(numPenguins > 0){
                // One penguin dies
                std::cout << "A penguin randomly died from sickness." << std::endl;
                this->removePenguin();
            }else if(numTigers > 0){
                //  One tiger dies
                std::cout << "A tiger randomly died from sickness." << std::endl;
                this->removeTiger();
            }else if(numTurtles > 0){
                // One turtle dies
                std::cout << "A turtle randomly died from sickness." << std::endl;
                this->removeTurtle();
            }else if(numCheetahs > 0){
                //  One Cheetah dies
                std::cout << "A cheetah randomly died from sickness." << std::endl;
                this->removeCheetah();
            }else{
                std::cout << "A random animal was supposed to die, but you have no animals in your zoo." << std::endl;
            }
            break;
        //  Turtle dies
        case 3:
            if(numTurtles > 0){
                //  One turtle dies
                std::cout << "A turtle randomly died from sickness." << std::endl;
                this->removeTurtle();
            }else if(numPenguins > 0){
                // One penguin dies
                std::cout << "A penguin randomly died from sickness." << std::endl;
                this->removePenguin();
            }else if(numTigers > 0){
                //  One tiger dies
                std::cout << "A tiger randomly died from sickness." << std::endl;
                this->removeTiger();
            }else if(numCheetahs > 0){
                //  One Cheetah dies
                std::cout << "A cheetah randomly died from sickness." << std::endl;
                this->removeCheetah();
            }else{
                std::cout << "A random animal was supposed to die, but you have no animals in your zoo." << std::endl;
            }
            break;
        //  Cheetah dies
        case 4:
            if(numCheetahs > 0){
                //  One Cheetah dies
                std::cout << "A cheetah randomly died from sickness." << std::endl;
                this->removeCheetah();
            }else if(numTurtles > 0){
                //  One turtle dies
                std::cout << "A turtle randomly died from sickness." << std::endl;
                this->removeTurtle();
            }else if(numPenguins > 0){
                // One penguin dies
                std::cout << "A penguin randomly died from sickness." << std::endl;
                this->removePenguin();
            }else if(numTigers > 0){
                //  One tiger dies
                std::cout << "A tiger randomly died from sickness." << std::endl;
                this->removeTiger();
            }else{
                std::cout << "A random animal was supposed to die, but you have no animals in your zoo." << std::endl;
            }
            break;
    }
}



/*************************************************************************************************
									Zoo::attendanceBoom()
    This function generates a random bonus for the day between 250-500 dollars for each tiger in
    the zoo.
**************************************************************************************************/
void Zoo::attendanceBoom() {
    //  generate random number between 1 and 251
    int randomNumberBonus = (rand() % 251) + 1;
    randomNumberBonus += 249;

    bonus = this->getNumTigers() * randomNumberBonus;
    std::cout << this->getNumTigers() << " tigers generated $" << randomNumberBonus << " each for a total of $"
              << bonus << " as a reward!" << std::endl;
}



/*************************************************************************************************
									Zoo::randAnimalBirth()
    This function chooses a random animal to give birth. If the chosen animal type has no adults,
    it will choose a different animal. If the different animal has no adults, it will choose yet
    another animal. If no animals in the zoo are adults it will display output stating so.
**************************************************************************************************/
void Zoo::randAnimalBirth() {
    //  generate random number between 1 - 3
    int randAnimal = (rand() % 4) + 1;

    //  check to see if there is an adult tiger in the zoo
    bool tigerAdult = false;
    for(int i = 0; i < numTigers; i++){
        if(tigerPopulation[i].getAge() >= 3){
            tigerAdult = true;
            break;
        }
    }
    //  check to see if there is an adult penguin in the zoo
    bool penguinAdult = false;
    for(int j = 0; j < numPenguins; j++){
        if(penguinPopulation[j].getAge() >= 3){
            penguinAdult = true;
            break;
        }
    }
    //  check to see if there is an adult turtle in the zoo
    bool turtleAdult = false;
    for(int k = 0; k < numTurtles; k++){
        if(turtlePopulation[k].getAge() >= 3){
            turtleAdult = true;
            break;
        }
    }

    //  check to see if there is an adult cheetah in the zoo
    bool cheetahAdult = false;
    for(int s = 0; s < numTurtles; s++){
        if(cheetahPopulation[s].getAge() >= 3){
            cheetahAdult = true;
            break;
        }
    }

    //	Check to see if 
    if(tigerAdult == true || penguinAdult == true || turtleAdult == true || cheetahAdult == true){
    	//	read text from input file and display that a baby animal is born.
    	this->textBabyAnimal();
    }else{
    	std::cout << "Status message for animal birth not displayed "
    			  << "since there are no adult animals in the zoo" << std::endl; 
    }

    switch(randAnimal){
        //  Check tiger first
        case 1:
            //  If there is an adult tiger
            if(tigerAdult){
                //  add one tiger age 0 to zoo
                std::cout << "A baby tiger was born!" << std::endl;
                this->addTiger(0);
            //  If there is an adult penguin
            }else if(penguinAdult){
                //  add five penguins age 0 to zoo
                std::cout << "Five baby penguins were born!" << std::endl;
                for(int i = 0; i < 5; i++){
                    this->addPenguin(0);
                }
            //  If there is an adult turtle
            }else if(turtleAdult){
                //  add ten turtles age 0 to zoo
                std::cout << "Ten baby turtles were born!" << std::endl;
                for(int i = 0; i < 10; i++){
                    this->addTurtle(0);
                }
            }else if(cheetahAdult){
                //  add cheetah babies age 0 to zoo
                std::cout << cheetahBabies << " baby cheetahs were born!" << std::endl;
                for(int i = 0; i < cheetahBabies; i++){
                    this->addCheetah(0);
                }
            } else{
                std::cout << "There are no adult animals in your zoo. No animals are able to give birth." << std::endl;
            }
            break;
        //  Check penguin first
        case 2:
            //  If there is an adult penguin
            if(penguinAdult){
                //  add five penguins age 0 to zoo
                std::cout << "Five baby penguins were born!" << std::endl;
                for(int i = 0; i < 5; i++){
                    this->addPenguin(0);
                }
            //  If there is an adult turtle
            }else if(turtleAdult){
                //  add ten turtles age 0 to zoo
                std::cout << "Ten baby turtles were born!" << std::endl;
                for(int i = 0; i < 10; i++){
                    this->addTurtle(0);
                }
            //  If there is an adult tiger
            }else if(tigerAdult){
                //  add one tiger age 0 to zoo
                std::cout << "A baby tiger was born!" << std::endl;
                this->addTiger(0);
            }else if(cheetahAdult){
                //  add cheetah babies age 0 to zoo
                std::cout << cheetahBabies << " baby cheetah(s) were born!" << std::endl;
                for(int i = 0; i < cheetahBabies; i++){
                    this->addCheetah(0);
                }
            }else{
                std::cout << "There are no adult animals in your zoo. No animals are able to give birth." << std::endl;
            }
            break;
        //  Check turtle first
        case 3:
            //  If there is an adult turtle
            if(turtleAdult){
                //  add ten turtles age 0 to zoo
                std::cout << "Ten baby turtles were born!" << std::endl;
                for(int i = 0; i < 10; i++){
                    this->addTurtle(0);
                }
            //  If there is an adult tiger
            }else if(tigerAdult){
                //  add one tiger age 0 to zoo
                std::cout << "A baby tiger was born!" << std::endl;
                this->addTiger(0);
            }else if(penguinAdult){
                //  add five penguins age 0 to zoo
                std::cout << "Five baby penguins were born!" << std::endl;
                for(int i = 0; i < 5; i++){
                    this->addPenguin(0);
                }
            //  If there is an adult cheetah
            }else if(cheetahAdult){
                //  add cheetah babies age 0 to zoo
                std::cout << cheetahBabies << " baby cheetahs were born!" << std::endl;
                for(int i = 0; i < cheetahBabies; i++){
                    this->addCheetah(0);
                }
            }else{
                std::cout << "There are no adult animals in your zoo. No animals are able to give birth." << std::endl;
            }
            break;
        case 4:
            //  If there is an adult cheetah
            if(cheetahAdult){
                //  add cheetah babies age 0 to zoo
                std::cout << cheetahBabies << " baby cheetahs were born!" << std::endl;
                for(int i = 0; i < cheetahBabies; i++){
                    this->addCheetah(0);
                }
            //  If there is an adult turtle
            }else if(turtleAdult){
                //  add ten turtles age 0 to zoo
                std::cout << "Ten baby turtles were born!" << std::endl;
                for(int i = 0; i < 10; i++){
                    this->addTurtle(0);
                }
            //  If there is an adult tiger
            }else if(tigerAdult){
                //  add one tiger age 0 to zoo
                std::cout << "A baby tiger was born!" << std::endl;
                this->addTiger(0);
            //  If there is an adult penguin
            }else if(penguinAdult){
                //  add five penguins age 0 to zoo
                std::cout << "Five baby penguins were born!" << std::endl;
                for(int i = 0; i < 5; i++){
                    this->addPenguin(0);
                }
            }else{
                std::cout << "There are no adult animals in your zoo. No animals are able to give birth." << std::endl;
            }
            break;
    }
}

/*************************************************************************************************
									Zoo::randomEvent()
                        This function generates a random number 1-4.
                        1) A sickness occurs to an animal
                        2) A boom in zoo attendance occurs
                        3) A baby animal is born
                        4) Nothing happens
**************************************************************************************************/
void Zoo::randomEvent(){
    int randomEventNum = (rand() % 4) + 1;

    switch(randomEventNum){
        case 1:
            // call function to read text from input file
            this->textRandAnimalDies();
            this->randAnimalDies();
            break;
        case 2:
            //  call function to read text from input file
            this->textAttendanceBoom();
            this->attendanceBoom();
            break;
        case 3:
            //  call function to read text from input file
            this->randAnimalBirth();
            break;
        case 4:
            //  call function to read text from input file
            this->textNothing();
            break;
    }
}



/************************************************************************************************
							        Zoo::calculatePayoff()
	This function calculates the profit for the day based on the number of each animal and their
 payoff.
**************************************************************************************************/
void Zoo::calculatePayoff() {
    int tigerPayoff = this->getNumTigers() * 2000;
    int penguinPayoff = this->getNumPenguins() * 100;
    int turtlePayoff = this->getNumTurtles() * 5;
    int cheetahProfit = this->getNumCheetahs() * cheetahPayoff;

    int animalPayoff = tigerPayoff + penguinPayoff + turtlePayoff + cheetahProfit;

    int profit = animalPayoff + bonus;

    std::cout << "****************************" << std::endl;
    std::cout << "Profit for Day " << day << std::endl;
    std::cout << "****************************" << std::endl;

    std::cout << "You earned $" << tigerPayoff << " from " << numTigers << " tiger(s)." << std::endl;
    std::cout << "You earned $" << penguinPayoff << " from " << numPenguins << " penguin(s)." << std::endl;
    std::cout << "You earned $" << turtlePayoff << " from " << numTurtles << " turtle(s)." << std::endl;
    std::cout << "You earned $" << cheetahProfit << " from " << numCheetahs << " cheetah(s)." << std::endl;
    std::cout << "The bonus for day " << day << " is: $" << bonus << "." << std::endl;
    std::cout << "The total profit for day " << day << " is: $" << profit << "." << std::endl;

    //  add profit to bank
    money += profit;

    //  reset bonus to 0
    bonus = 0;

    this->displayMoney();
}

/************************************************************************************************
							        Zoo::promptAdultAnimal()
	This function prompts the user if they would like to buy an adult animal (1) yes (2) no
 If yes, the function asks the user to enter a number between 1 - 4 to decide which adult animal
 to buy.
**************************************************************************************************/
void Zoo::promptAdultAnimal() {
    std::cout << "Would you like to buy an adult animal? Enter '1' for yes or '2' for no: " << std::endl;

    int yesOrNo = this->oneOrTwo();
    int animalChoice;

    switch(yesOrNo){
        // choice is yes
        case 1:
            std::cout << "Enter '1' to buy an adult tiger." << std::endl;
            std::cout << "Enter '2' to buy an adult penguin." << std::endl;
            std::cout << "Enter '3' to buy an adult turtle." << std::endl;
            std::cout << "Enter '4' to buy an adult cheetah." << std::endl;

            animalChoice = this->oneTwoThreeFour();

            switch(animalChoice){
                //  Buy an adult tiger
                case 1:
                    std::cout << "You purchased one adult tiger." << std::endl;
                    this->addTiger(3);
                    money -= 10000;
                    this->displayMoney();
                    break;
                //  Buy an adult penguin
                case 2:
                    std::cout << "You purchased one adult penguin." << std::endl;
                    this->addPenguin(3);
                    money -= 1000;
                    this->displayMoney();
                    break;
                //  Buy an adult turtle
                case 3:
                    std::cout << "You purchased one adult turtle." << std::endl;
                    this->addTurtle(3);
                    money -= 100;
                    this->displayMoney();
                    break;
                //	Buy an adult cheetah
                case 4:
                    std::cout << "Your purchased one adult cheetah." << std::endl;
                    this->addCheetah(3);
                    money -= cheetahCost;
                    this->displayMoney();
                    break;
            }
            break;
        //  choice is no
        case 2:
            std::cout << "You decided not to buy an adult animal." << std::endl;
            this->displayMoney();
            break;
    }
}



/************************************************************************************************
							        Zoo::promptKeepPlaying()
	This function asks the user if they would like to keep playing. 1) keep playing or 2) quit
	If 1) is selected, cout "You chose to keep playing" and increment day data member.
	If 2) is selected set money to -100000 which will break out of the game loop and end the day.
**************************************************************************************************/
void Zoo::promptKeepPlaying() {
    std::cout << "\n\n	Keep playing or quit?\n\n";
    std::cout << "1)  Keep playing\n";
    std::cout << "2)  End game\n";
    std::cout << "Enter your choice: " << std::endl;

    int keepPlaying = this->oneOrTwo();

    switch(keepPlaying){
        case 1:
            std::cout << "You chose to keep playing!" << std::endl;
            day++;
            break;
        case 2:
            money = -100000;
            break;
    }
}



/************************************************************************************************
							        Zoo::checkMoney()
			This function checks to see if the user has more than 0 dollars. If user doesn't,
			display "Game over The End!"" to the user
**************************************************************************************************/
void Zoo::checkMoney() {
    if(money <= 0){
        std::cout << "Game over! The end!" << std::endl;
    }
}

/************************************************************************************************
							        Zoo::gameLoop()
	This function runs while money > 0. This function handles the game loop.
**************************************************************************************************/
void Zoo::gameLoop(){
    //  Loop while user has money
    while(money > 0){
        //  Display day
        this->displayDay();

        //  Display money
        this->displayMoney();

        //  Increase age of all animals by 1 day
        this->incrementAnimalsAge();

        //  Calculate feeding cost and subtract from bank
        this->calculateFeedingCost();

        //  Random Event
        this->randomEvent();

        //  Calculate payoff and add bonus if available
        this->calculatePayoff();

        //  prompt buy one adult animal
        this->promptAdultAnimal();

        //  prompt keep playing or end game
        this->promptKeepPlaying();

        //  check if user has no money
        this->checkMoney();
    }
}



/************************************************************************************************
							        Zoo::play()
	            This function starts the game and includes the game loop.
**************************************************************************************************/
void Zoo::play(){
    //  Prompt first animals

    std::cout << "************* Implemented extra animal and status message extra credit *************" << std::endl;

    this->promptFirstTiger();
    this->promptFirstPenguin();
    this->promptFirstTurtle();
    this->promptFirstCheetah();

    //  Start game loop
    this->gameLoop();
}



/*************************************************************************************************
										Zoo::~Zoo()
							This is the destructor for the Zoo class
**************************************************************************************************/
Zoo::~Zoo(){
	
	delete [] tigerPopulation;
	delete [] penguinPopulation;
	delete [] turtlePopulation;
    delete [] cheetahPopulation;
}
