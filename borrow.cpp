// ------------------------------------------------ borrow.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will focus on borrow command, it includes constructors for the three types
// of genre that this movie store handles, getter-setter methods, and display function to show what movies was
// borrowed from each customer
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: Constructor for 'F' (Comedy) 
// --------------------------------------------------------------------------------------------------- 
Borrow::Borrow(char commandType, int customerID, char mediaType, char movieType, string title, int year) : Command(commandType, customerID, mediaType, movieType, title, year) {
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
// Description: Constructor for 'D' (Drama)
// --------------------------------------------------------------------------------------------------- 
Borrow::Borrow(char commandType, int customerID, char mediaType, char movieType, string director, string title) : Command(customerID, customerID, mediaType, movieType, director, title) {
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
// Description: Constructor for 'C' (Classic)
// --------------------------------------------------------------------------------------------------- 
Borrow::Borrow(char commandType, int customerID, char mediaType, char movieType, int month, int year, string actor) : Command(commandType, customerID, mediaType, movieType, month, year, actor) {
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
void Borrow::setCommandType(char commandType) {
	this->commandType = commandType;
}

// ------------------------------------ setCustomerID() -----------------------------------------------
// Description: Setter method for customer ID
// --------------------------------------------------------------------------------------------------- 
void Borrow::setCustomerID(int customerID) {
	this->customerID = customerID;
}

// ------------------------------------ setMediaType() -----------------------------------------------
// Description: Setter method for media type
// --------------------------------------------------------------------------------------------------- 
void Borrow::setMediaType(char mediaType) {
	this->mediaType = mediaType;
}

// ------------------------------------ setMovieType() -----------------------------------------------
// Description: Setter method for movie type
// --------------------------------------------------------------------------------------------------- 
void Borrow::setMovieType(char movieType) {
	this->movieType = movieType;
}

// ------------------------------------ setDirector() -----------------------------------------------
// Description: Setter method for director
// --------------------------------------------------------------------------------------------------- 
void Borrow::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setTitle() -----------------------------------------------
// Description: Setter method for title
// --------------------------------------------------------------------------------------------------- 
void Borrow::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setActor() -----------------------------------------------
// Description: Setter method for actor
// --------------------------------------------------------------------------------------------------- 
void Borrow::setActor(string actor) {
	this->actor = actor;
}

// ------------------------------------ setMonth() -----------------------------------------------
// Description: Setter method for month
// --------------------------------------------------------------------------------------------------- 
void Borrow::setMonth(int month) {
	this->month = month;
}

// ------------------------------------ setYear() -----------------------------------------------
// Description: Setter method for year
// --------------------------------------------------------------------------------------------------- 
void Borrow::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getCommandType() -----------------------------------------------
// Description: Getter method for command type
// --------------------------------------------------------------------------------------------------- 
char Borrow::getCommandType() {
	return commandType;
}

// ------------------------------------ getCustomerID() -----------------------------------------------
// Description: Getter method for customer ID
// --------------------------------------------------------------------------------------------------- 
int Borrow::getCustomerID() {
	return customerID;
}

// ------------------------------------ getMediaType() -----------------------------------------------
// Description: Getter method for media type
// --------------------------------------------------------------------------------------------------- 
char Borrow::getMediaType() {
	return mediaType;
}

// ------------------------------------ getMovieType() -----------------------------------------------
// Description: Getter method for movie type
// --------------------------------------------------------------------------------------------------- 
char Borrow::getMovieType() {
	return movieType;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for director
// --------------------------------------------------------------------------------------------------- 
string Borrow::getDirector() {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// --------------------------------------------------------------------------------------------------- 
string Borrow::getTitle() {
	return title;
}

// ------------------------------------ getActor() -----------------------------------------------
// Description: Getter method for actor
// --------------------------------------------------------------------------------------------------- 
string Borrow::getActor() {
	return actor;
}

// ------------------------------------ getMonth() -----------------------------------------------
// Description: Getter method for month
// --------------------------------------------------------------------------------------------------- 
int Borrow::getMonth() {
	return month;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// --------------------------------------------------------------------------------------------------- 
int Borrow::getYear() {
	return year;
}

// ------------------------------------ display() -----------------------------------------------
// Description: Displays the movies that was borrowed from each customer
// --------------------------------------------------------------------------------------------------- 
void Borrow::display() {
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