// ------------------------------------------------ drama.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file focuses on the drama genre of movies. It includes getter and setter methods,
// as well as, overload operators to compare with the other drama movies
// --------------------------------------------------------------------------------------------------------------------

#include "drama.h"

// ------------------------------------ Default constructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
Drama::Drama(char movieType, int stock, string director, string title, int year) : Movie(movieType, stock, director, title, year) {
	this->movieType = movieType;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
}

// ------------------------------------ setStock() -----------------------------------------------
// Description: Setter method for stock
// --------------------------------------------------------------------------------------------------- 
void Drama::setStock(int stock) {
	this->stock = stock;
}

// ------------------------------------ setStock() -----------------------------------------------
// Description: Setter method for stock
// ---------------------------------------------------------------------------------------------------
void Drama::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setStock() -----------------------------------------------
// Description: Setter method for stock
// ---------------------------------------------------------------------------------------------------
void Drama::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setStock() -----------------------------------------------
// Description: Setter method for stock
// ---------------------------------------------------------------------------------------------------
void Drama::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getStock() -----------------------------------------------
// Description: Getter method for stock
// --------------------------------------------------------------------------------------------------- 
int Drama::getStock() const {
	return stock;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for dirtector
// --------------------------------------------------------------------------------------------------- 
string Drama::getDirector() const {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// --------------------------------------------------------------------------------------------------- 
string Drama::getTitle() const {
	return title;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// --------------------------------------------------------------------------------------------------- 
int Drama::getYear() const {
	return year;
}

// ------------------------------------ operator> -----------------------------------------------
// Description: Overload operators checks to see which movies (based on director and title) is greater than the other
// --------------------------------------------------------------------------------------------------- 
bool Drama::operator>(const Movie& drama) const {
	// If the current movie's director is less than the other
	if (this->getDirector() < drama.getDirector()) {
		return false;
	}

	// If the current movie's director is greater than the other
	else if (this->getDirector() > drama.getDirector()) {
		return true;
	}

	// If they have the same director
	else if (this->getDirector() == drama.getDirector()) {
		if (this->getTitle() < drama.getTitle()) {
			return false;
		}

		// Checks to see which title is greater
		else if (this->getTitle() > drama.getTitle()) {
			return true;
		}

		else if (this->getTitle() == drama.getTitle()) {
			return false;
		}
	}
	return false;
}

// ------------------------------------ operator< -----------------------------------------------
// Description: Overload operator checks to see which movies (based on director and title) is less than the other
// --------------------------------------------------------------------------------------------------- 
bool Drama::operator<(const Movie& drama) const {
	// If the current movie's director is greater than the other
	if (this->getDirector() > drama.getDirector()) {
		return false;
	}

	// If the current movie's director is less than the other
	else if (this->getDirector() < drama.getDirector()) {
		return true;
	}

	// If they have the same director
	else if (this->getDirector() == drama.getDirector()) {
		if (this->getTitle() > drama.getTitle()) {
			return false;
		}

		// Checks to see which title is less than
		else if (this->getTitle() < drama.getTitle()) {
			return true;
		}

		else if (this->getTitle() == drama.getTitle()) {
			return false;
		}
	}
	return false;
}

// ------------------------------------ operator== -----------------------------------------------
// Description: Overload operator, checks to see if the movies are the same
// --------------------------------------------------------------------------------------------------- 
bool Drama::operator==(const Movie& drama) const {
	// If the movies are the same
	if (this->getMovieType() == drama.getMovieType() && this->getDirector() == drama.getDirector() && this->getTitle() == drama.getTitle() && this->getYear() == drama.getYear()) {
		return true;
	}

	else {
		return false;
	}
}

// ------------------------------------ operator!= -----------------------------------------------
// Description: Overload operator, checks to see if the movies are not the same
// --------------------------------------------------------------------------------------------------- 
bool Drama::operator!=(const Movie& drama) const {
	// If the movies are the same
	if (this->getMovieType() == drama.getMovieType() && this->getDirector() == drama.getDirector() && this->getTitle() == drama.getTitle() && this->getYear() == drama.getYear()) {
		return false;
	}

	else {
		return true;
	}
}

// ------------------------------------ diosplay() -----------------------------------------------
// Description: This will display the drama movies
// --------------------------------------------------------------------------------------------------- 
void Drama::display() {
	cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear() << endl;
}