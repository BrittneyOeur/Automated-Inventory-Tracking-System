// ------------------------------------------------ movie.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file handles all the movies in the rental store, such as, comedy, drama, and classic
// movies. It include getter-setter methods to store the variables accordingly based on the movie that is stored
// inside the movie store. In addition, it will print out all the movies that exist in the store.
// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"

// ------------------------------------ Parameterized Constructor -----------------------------------------------
// Description: Constructor fucntion for 'F' and 'D' (Comedy and Drama)
// --------------------------------------------------------------------------------------------------- 
Movie::Movie(char movieType, int stock, string director, string title, int year) {
	this->movieType = movieType;
	this->stock = stock;
	this->director = director;
	this->title = title;
	string actor = " "; 
	this->year = year;
	int month = 13;
}

// ------------------------------------ Parameterized Constructor -----------------------------------------------
// Description: Construction function for 'C' (Classic)
// --------------------------------------------------------------------------------------------------- 
Movie::Movie(char movieType, int stock, string director, string title, string actor, int month, int year) {
	this->movieType = movieType;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->actor = actor;
	this->month = month;
	this->year = year;
}

// ------------------------------------ setStock() -----------------------------------------------
// Description: Setter method for stock
// --------------------------------------------------------------------------------------------------- 
void Movie::setStock(int stock) {
	this->stock = stock;
}

// ------------------------------------ setMovieType() -----------------------------------------------
// Description: Setter method for movie type
// --------------------------------------------------------------------------------------------------- 
void Movie::setMovieType(char movieType) {
	this->movieType = movieType;
}

// ------------------------------------ setDirector() -----------------------------------------------
// Description: Setter method for director 
// --------------------------------------------------------------------------------------------------- 
void Movie::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setTitle() -----------------------------------------------
// Description: Setter method for title
// --------------------------------------------------------------------------------------------------- 
void Movie::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setActor() -----------------------------------------------
// Description: Setter method for actor
// --------------------------------------------------------------------------------------------------- 
void Movie::setActor(string actor) {
	this->actor = actor;
}

// ------------------------------------ setMonth() -----------------------------------------------
// Description: Setter method for month
// --------------------------------------------------------------------------------------------------- 
void Movie::setMonth(int month) {
	this->month = month;
}

// ------------------------------------ setYear() -----------------------------------------------
// Description: Setter method for year
// --------------------------------------------------------------------------------------------------- 
void Movie::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getStock() -----------------------------------------------
// Description: Getter method for stock
// --------------------------------------------------------------------------------------------------- 
int Movie::getStock() const {
	return stock;
}

// ------------------------------------ getMovieType() -----------------------------------------------
// Description: Getter method for movie type
// --------------------------------------------------------------------------------------------------- 
char Movie::getMovieType() const {
	return movieType;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for director
// --------------------------------------------------------------------------------------------------- 
string Movie::getDirector() const {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// --------------------------------------------------------------------------------------------------- 
string Movie::getTitle() const {
	return title;
}

// ------------------------------------ getActor() -----------------------------------------------
// Description: Getter method for actor
// --------------------------------------------------------------------------------------------------- 
string Movie::getActor() const {
	return actor;
}

// ------------------------------------ getMonth() -----------------------------------------------
// Description: Getter method for month
// --------------------------------------------------------------------------------------------------- 
int Movie::getMonth() const {
	return month;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// --------------------------------------------------------------------------------------------------- 
int Movie::getYear() const {
	return year;
}

// ------------------------------------ operator<< -----------------------------------------------
// Description: Prints out the movies that is in the movie rental store's inventory
// --------------------------------------------------------------------------------------------------- 
ostream& operator<<(ostream& out, const Movie& movie) {
	if (movie.getMovieType() != 'F' || movie.getMovieType() != 'D' || movie.getMovieType() != 'C') {
		out << "ERROR: Movie type does not exist." << endl;
		return out;
	}

	// If movie type is 'F' or 'D'
	else if (movie.getMovieType() == 'F' || movie.getMovieType() == 'D') {
		out << movie.getMovieType() << ", " << movie.getStock() << ", " << movie.getDirector() << ", " << movie.getTitle() << ", " << movie.getYear() << endl;
	}

	// If movie type is 'C'
	else if (movie.getMovieType() == 'C') {
		out << movie.getMovieType() << ", " << movie.getStock() << ", " << movie.getDirector() << ", " << movie.getTitle() << ", " << movie.getActor() << " " << movie.getMonth() << " " << movie.getYear() << endl;
	}

	return out;
}

// ------------------------------------ operator> -----------------------------------------------
// Description: Checks if the current movie is greater than the other movie
// Based on the year of the movies
// --------------------------------------------------------------------------------------------------- 
bool Movie::operator>(const Movie& movie) const {
	if (this->getYear() > movie.getYear()) {
		return true;
	}

	else {
		return false;
	}

	return false;
}

// ------------------------------------ operator< -----------------------------------------------
// Description: Checks if the current movie is less than the other movie
// Based on the year of the movies
// --------------------------------------------------------------------------------------------------- 
bool Movie::operator<(const Movie& movie) const {
	if (this->getYear() < movie.getYear()) {
		return true;
	}

	else {
		return false;
	}

	return false;
}

// ------------------------------------ operator== -----------------------------------------------
// Description: Checks if the movies are the same. Based off the title and year
// --------------------------------------------------------------------------------------------------- 
bool Movie::operator==(const Movie& movie) const {
	if ((this->getTitle() == movie.getTitle()) && (this->getYear() == movie.getYear())) {
		return true;
	}

	else {
		return false;
	}
}

// ------------------------------------ operator!= -----------------------------------------------
// Description: Check if the movies are not the same. Based off the movie objects 
// --------------------------------------------------------------------------------------------------- 
bool Movie::operator!=(const Movie& movie) const {
	if (*this == movie) {
		return false;
	}
	else {
		return true;
	}
}

// ------------------------------------ display() -----------------------------------------------
// Description: Displays the movies in the movie rental store
// --------------------------------------------------------------------------------------------------- 
void Movie::display() {
	// If the movie type is 'F' or 'D'
	if (this->getMovieType() == 'F' || this->getMovieType() == 'D') {
		cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear() << endl;
	}

	// If the movie type is 'C'
	else if (this->getMovieType() == 'C') {
		cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getActor() << " " << this->getMonth() << " " << this->getYear() << endl;
	}

	cout << endl;
}