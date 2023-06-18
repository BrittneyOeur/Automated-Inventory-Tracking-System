// ------------------------------------------------ command.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will focus on the commmands, it handles the borrow and return commands.
// Borrow will take movies from the store and returning will give back (add) the movies to the store. It also includes
// displaying the history of the customers, such as the action type and what movies was borrowed and returned.
// --------------------------------------------------------------------------------------------------------------------

#include "command.h"

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for 'I' (Inventory)
// --------------------------------------------------------------------------------------------------- 
Command::Command(char commandType) {
	this->commandType = commandType;
	this->customerID = 0;
	this->mediaType = ' ';
	this->movieType = ' ';
	this->director;
	this->title = " ";
	this->actor = " ";
	this->month = 0;
	this->year = 0;
}

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for 'H' (History)
// --------------------------------------------------------------------------------------------------- 
Command::Command(char commandType, int customerID) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = ' ';
	this->movieType = ' ';
	this->director;
	this->title = " ";
	this->actor = " ";
	this->month = 0;
	this->year = 0;
}

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for 'B' or 'R' and 'F' (Comedy movies)
// --------------------------------------------------------------------------------------------------- 
Command::Command(char commandType, int customerID, char mediaType, char movieType, string title, int year) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = mediaType;
	this->movieType = movieType;
	this->title = title;
	this->director = " ";
	this->actor = " ";
	this->month = 0;
	this->year = year;
}

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for 'B' or 'R' and 'D' (Drama movies)
// --------------------------------------------------------------------------------------------------- 
Command::Command(char commandType, int customerID, char mediaType, char movieType, string director, string title) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = mediaType;
	this->movieType = movieType;
	this->director = director;
	this->title = title;
	this->actor = " ";
	this->month = 0;
	this->year = 0;
}

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for 'B' or 'R' and 'C' (Classic movies)
// --------------------------------------------------------------------------------------------------- 
Command::Command(char commandType, int customerID, char mediaType, char movieType, int month, int year, string actor) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = mediaType;
	this->movieType = movieType;
	this->director = " ";
	this->title = " ";
	this->actor = actor;
	this->month = month;
	this->year = year;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for command type
// --------------------------------------------------------------------------------------------------- 
void Command::setCommandType(char commandType) {
	this->commandType = commandType;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for customer ID
// --------------------------------------------------------------------------------------------------- 
void Command::setCustomerID(int customerID) {
	this->customerID = customerID;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for media type
// --------------------------------------------------------------------------------------------------- 
void Command::setMediaType(char mediaType) {
	this->mediaType = mediaType;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for movie type
// --------------------------------------------------------------------------------------------------- 
void Command::setMovieType(char movieType) {
	this->movieType = movieType;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for director
// --------------------------------------------------------------------------------------------------- 
void Command::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for title
// --------------------------------------------------------------------------------------------------- 
void Command::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for actor
// --------------------------------------------------------------------------------------------------- 
void Command::setActor(string actor) {
	this->actor = actor;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for month
// --------------------------------------------------------------------------------------------------- 
void Command::setMonth(int month) {
	this->month = month;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for year
// --------------------------------------------------------------------------------------------------- 
void Command::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getCommandType() -----------------------------------------------
// Description: Getter method for command type
// --------------------------------------------------------------------------------------------------- 
char Command::getCommandType() {
	return commandType;
}

// ------------------------------------ getCustomerID() -----------------------------------------------
// Description: Getter method for customer ID
// --------------------------------------------------------------------------------------------------- 
int Command::getCustomerID() {
	return customerID;
}

// ------------------------------------ getMediaType() -----------------------------------------------
// Description: Getter method for media type
// --------------------------------------------------------------------------------------------------- 
char Command::getMediaType() {
	return mediaType;
}

// ------------------------------------ getMovieType() -----------------------------------------------
// Description: Getter method for movie type
// --------------------------------------------------------------------------------------------------- 
char Command::getMovieType() {
	return movieType;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for director
// --------------------------------------------------------------------------------------------------- 
string Command::getDirector() {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// --------------------------------------------------------------------------------------------------- 
string Command::getTitle() {
	return title;
}

// ------------------------------------ getActor() -----------------------------------------------
// Description: Getter method for actor
// --------------------------------------------------------------------------------------------------- 
string Command::getActor() {
	return actor;
}

// ------------------------------------ getMonth() -----------------------------------------------
// Description: Getter method for month
// --------------------------------------------------------------------------------------------------- 
int Command::getMonth() {
	return month;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// --------------------------------------------------------------------------------------------------- 
int Command::getYear() {
	return year;
}

// ------------------------------------ display() -----------------------------------------------
// Description: This will display the command type for each customers, including the types of
// movies they have borrowed or returned
// --------------------------------------------------------------------------------------------------- 
void Command::display() {
	// If the movie type is a comedy
	if (this->getMovieType() == 'F') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getTitle() << " " << this->getYear() << endl;
	}

	// If the movie type is a drama
	else if (this->getMovieType() == 'D') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getDirector() << " " << this->getTitle() << endl;
	}
	
	// If the movie type is classic
	else if (this->getMovieType() == 'C') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getMonth() << " " << this->getYear() << " " << this->getActor() << endl;
	}
}
