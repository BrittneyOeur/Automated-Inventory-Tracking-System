// ------------------------------------------------ return.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file is the child class of Command, this will handle the return command.
// Which will return the specific movies stated from the customer. In addition, it will print out what movies
// was returned to the movie rental store.
// --------------------------------------------------------------------------------------------------------------------

#include "return.h"

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: Constructor for 'F' (Comedy) 
// --------------------------------------------------------------------------------------------------- 
Return::Return(char commandType, int customerID, char mediaType, char movieType, string title, int year) : Command(commandType, customerID, mediaType, movieType, title, year) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = mediaType;
	this->movieType = movieType;
	this->director = "none";
	this->title = title;
	this->actor = "none";
	this->month = 0;
	this->year = year;
}

// ------------------------------------ Parameterized constructor -----------------------------------------------
// // Constructor for 'D' (Drama)
// --------------------------------------------------------------------------------------------------- 
Return::Return(char commandType, int customerID, char mediaType, char movieType, string director, string title) : Command(commandType, customerID, mediaType, movieType, director, title) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = mediaType;
	this->movieType = movieType;
	this->director = director;
	this->title = title;
	this->actor = "none";
	this->month = 0;
	this->year = 0;
}

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Constructor for 'C' (Classic)
// --------------------------------------------------------------------------------------------------- 
Return::Return(char commandType, int customerID, char mediaType, char movieType, int month, int year, string actor) : Command(commandType, customerID, mediaType, movieType, month, year, actor) {
	this->commandType = commandType;
	this->customerID = customerID;
	this->mediaType = mediaType;
	this->movieType = movieType;
	this->director = "none";
	this->title = "none";
	this->actor = actor;
	this->month = month;
	this->year = year;
}

// ------------------------------------ setCommandType() -----------------------------------------------
// Description: Setter method for command type
// --------------------------------------------------------------------------------------------------- 
void Return::setCommandType(char commandType) {
	this->commandType = commandType;
}

// ------------------------------------ setCustomerID() -----------------------------------------------
// Description: Setter method for customer ID
// --------------------------------------------------------------------------------------------------- 
void Return::setCustomerID(int customerID) {
	this->customerID = customerID;
}

// ------------------------------------ setMediaType() -----------------------------------------------
// Description: Setter method for media type
// --------------------------------------------------------------------------------------------------- 
void Return::setMediaType(char mediaType) {
	this->mediaType = mediaType;
}

// ------------------------------------ setMovieType() -----------------------------------------------
// Description: Setter method for movie type
// --------------------------------------------------------------------------------------------------- 
void Return::setMovieType(char movieType) {
	this->movieType = movieType;
}

// ------------------------------------ setDirector() -----------------------------------------------
// Description: Setter method for director
// --------------------------------------------------------------------------------------------------- 
void Return::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setTitle() -----------------------------------------------
// Description: Setter method for movie title
// --------------------------------------------------------------------------------------------------- 
void Return::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setActor() -----------------------------------------------
// Description: Setter method for actor
// --------------------------------------------------------------------------------------------------- 
void Return::setActor(string actor) {
	this->actor = actor;
}

// ------------------------------------ setMonth() -----------------------------------------------
// Description: Setter method for month
// --------------------------------------------------------------------------------------------------- 
void Return::setMonth(int month) {
	this->month = month;
}

// ------------------------------------ setYear() -----------------------------------------------
// Description: Setter method for year
// --------------------------------------------------------------------------------------------------- 
void Return::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getCommandType() -----------------------------------------------
// Description: Getter method for command type
// --------------------------------------------------------------------------------------------------- 
char Return::getCommandType() {
	return commandType;
}

// ------------------------------------ getCustomerID() -----------------------------------------------
// Description: Getter method for customer ID
// --------------------------------------------------------------------------------------------------- 
int Return::getCustomerID() {
	return customerID;
}

// ------------------------------------ getMediaType() -----------------------------------------------
// Description: Getter method for media type
// --------------------------------------------------------------------------------------------------- 
char Return::getMediaType() {
	return mediaType;
}

// ------------------------------------ getMovieType() -----------------------------------------------
// Description: Getter method for movie type
// --------------------------------------------------------------------------------------------------- 
char Return::getMovieType() {
	return movieType;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for director
// --------------------------------------------------------------------------------------------------- 
string Return::getDirector() {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// --------------------------------------------------------------------------------------------------- 
string Return::getTitle() {
	return title;
}

// ------------------------------------ getActor() -----------------------------------------------
// Description: Getter method for actor
// --------------------------------------------------------------------------------------------------- 
string Return::getActor() {
	return actor;
}

// ------------------------------------ getMonth() -----------------------------------------------
// Description: Getter method for month
// --------------------------------------------------------------------------------------------------- 
int Return::getMonth() {
	return month;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// --------------------------------------------------------------------------------------------------- 
int Return::getYear() {
	return year;
}

// ------------------------------------ display() -----------------------------------------------
// Description: This will print out the three diferent movie types (comedy, drama, and classic)
// --------------------------------------------------------------------------------------------------- 
void Return::display() {
	// If the movie type is comedy
	if (this->getMovieType() == 'F') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getTitle() << " " << this->getYear() << endl;
	}

	// If the movie type is drama
	else if (this->getMovieType() == 'D') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getDirector() << " " << this->getTitle() << endl;
	}

	// If the movie type is classic
	else if (this->getMovieType() == 'C') {
		cout << this->getCommandType() << " " << this->getCustomerID() << " " << this->getMediaType() << " " << this->getMovieType() << " " << this->getMonth() << " " << this->getYear() << " " << this->getActor() << endl;
	}
}