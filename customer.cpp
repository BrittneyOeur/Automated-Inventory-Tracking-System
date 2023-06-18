// ------------------------------------------------ customer.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will focus on customers, such as including commands to each specific
// customers, based on what they have called for each movie genre. In addition, it will print the history of each 
// customer, that includes what movies that have borrowed and returned.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"

// ------------------------------------ Default constructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
Customer::Customer(int customerID, string firstName, string lastName) {
	this->customerID = customerID;
	this->firstName = firstName;
	this->lastName = lastName;
}

// ------------------------------------ Destructor -----------------------------------------------
// Description: This a default destructor
// --------------------------------------------------------------------------------------------------- 
Customer::~Customer() {

}

// ------------------------------------ addComedyCommand() -----------------------------------------------
// Description: This will add the command to the given movie genre, in this case, it is the comedy
// --------------------------------------------------------------------------------------------------- 
void Customer::addComedyCommand(char commandType, int customerID, char mediaType, char movieType, string title, int year) {
	if (commandType == 'R') {
		Command* comedyCommand = new Return(commandType, customerID, mediaType, movieType, title, year);
		commands.push(comedyCommand);
		size+=1;
	}

	else if (commandType == 'B') {
		Command* comedyCommand = new Borrow(commandType, customerID, mediaType, movieType, title, year);
		commands.push(comedyCommand);
		size+=1;
	}
}

// ------------------------------------ addDramaCommand() -----------------------------------------------
// Description: This will add the command to the given movie genre, in this case, it is the drama
// --------------------------------------------------------------------------------------------------- 
void Customer::addDramaCommand(char commandType, int customerID, char mediaType, char movieType, string director, string title) {
	if (commandType == 'R') {
		Command* dramaCommand = new Return(commandType, customerID, mediaType, movieType, director, title);
		commands.push(dramaCommand);
		size+=1;
	}
	else if (commandType == 'B') {
		Command* dramaCommand = new Borrow(commandType, customerID, mediaType, movieType, director, title);
		commands.push(dramaCommand);
		size+=1;
	}
}

// ------------------------------------ addClassicCommand() -----------------------------------------------
// Description: This will add the command to the given movie genre, in this case, it is the classic
// --------------------------------------------------------------------------------------------------- 
void Customer::addClassicCommand(char commandType, int customerID, char mediaType, char movieType, int month, int year, string actor) {
	if (commandType == 'R') {
		Command* classicCommand = new Return(commandType, customerID, mediaType, movieType, month, year, actor);
		commands.push(classicCommand);
		size+=1;
	}
	else if (commandType == 'B') {
		Command* classicCommand = new Borrow(commandType, customerID, mediaType, movieType, month, year, actor);
		commands.push(classicCommand);
		size+=1;
	}
}

// ------------------------------------ setFirstName() -----------------------------------------------
// Description: Setter method for first name
// --------------------------------------------------------------------------------------------------- 
void Customer::setFirstName(string firstName) {
	this->firstName = firstName;
}

// ------------------------------------ setLastName() -----------------------------------------------
// Description: Setter method for last name
// --------------------------------------------------------------------------------------------------- 
void Customer::setLastName(string lastName) {
	this->lastName = lastName;
}

// ------------------------------------ setCustomerID() -----------------------------------------------
// Description: Setter method for customer ID
// --------------------------------------------------------------------------------------------------- 
void Customer::setCustomerID(int customerID) {
	this->customerID = customerID;
}

// ------------------------------------ getFirstName() -----------------------------------------------
// Description: Getter method for first name
// --------------------------------------------------------------------------------------------------- 
string Customer::getFirstName() {
	return firstName;
}

// ------------------------------------ getLastName() -----------------------------------------------
// Description: Getter method for last name
// --------------------------------------------------------------------------------------------------- 
string Customer::getLastName() {
	return lastName;
}

// ------------------------------------ getCustomerID() -----------------------------------------------
// Description: Getter method for customer ID
// --------------------------------------------------------------------------------------------------- 
int Customer::getCustomerID() {
	return customerID;
}

// ------------------------------------ display() -----------------------------------------------
// Description: Displays the customers that is stored inside the movie rental store
// --------------------------------------------------------------------------------------------------- 
void Customer::display() {
	Command* commandQueue;

	cout << endl;
	cout << ".:HISTORY OF CUSTOMER:." << endl << endl;

	cout << this->getFirstName() << " " << this->getLastName() << " ID: " << this->getCustomerID() << endl;

	// If the queue is empty
	if (commands.empty() == true) {
		cout << "ERROR: Customer's history is empty." << endl;
		return;
	}

	// Loop to go through queue
	for (int i = 1; i < size + 1; i++) {
		commandQueue = commands.front();
		commandQueue->display();
		commands.push(commandQueue);
		commands.pop();
	}
	cout << endl;
}