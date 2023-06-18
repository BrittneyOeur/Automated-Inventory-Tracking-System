// ------------------------------------------------ comedy.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will focus on comedy genre of movies, it includes a constructor to 
// store the information of the comedy movie, getter-setter methods, overload operators to compare the different
// comedy movies that is stored, and a display function to display all the comedy movies that is in the store.
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for the comedy movie genre
// --------------------------------------------------------------------------------------------------- 
Comedy::Comedy(char movieType, int stock, string director, string title, int year) : Movie(movieType, stock, director, title, year) {
	this->movieType = movieType;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;
}

// ------------------------------------ setStock() -----------------------------------------------
// Description: Setter method for stock
// --------------------------------------------------------------------------------------------------- 
void Comedy::setStock(int stock) {
	this->stock = stock;
}

// ------------------------------------ setDirector() -----------------------------------------------
// Description: Setter method for director
// --------------------------------------------------------------------------------------------------- 
void Comedy::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setTitle() -----------------------------------------------
// Description: Setter method for title
// --------------------------------------------------------------------------------------------------- 
void Comedy::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setYear()-----------------------------------------------
// Description: Setter method for year
// --------------------------------------------------------------------------------------------------- 
void Comedy::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getStock() -----------------------------------------------
// Description: Getter method for stock
// --------------------------------------------------------------------------------------------------- 
int Comedy::getStock() const {
	return stock;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for director
// --------------------------------------------------------------------------------------------------- 
string Comedy::getDirector() const {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// --------------------------------------------------------------------------------------------------- 
string Comedy::getTitle() const {
	return title;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// --------------------------------------------------------------------------------------------------- 
int Comedy::getYear() const {
	return year;
}

// ------------------------------------ operator> -----------------------------------------------
// Description: Overload operator check to see if the current movie is greater than the other
// --------------------------------------------------------------------------------------------------- 
bool Comedy::operator>(const Movie& comedy) const {
	// If current movie title is less than the other
	if (this->getTitle() < comedy.getTitle()) {
		return false;
	}

	else if (this->getTitle() > comedy.getTitle()) {
		return true;
	}

	// If they have the same title
	else if (this->getTitle() == comedy.getTitle()) {
		if (this->getYear() < comedy.getYear()) {
			return false;
		}

		// If the current year is greater than the other movie
		else if (this->getYear() > comedy.getYear()) {
			return true;
		}

		else if (this->getYear() == comedy.getYear()) {
			return false; 
		}
	}
	return false;
}

// ------------------------------------ operator< -----------------------------------------------
// Description: Overload operator check to see if the current movie is less than the other
// --------------------------------------------------------------------------------------------------- 
bool Comedy::operator<(const Movie& comedy) const {
	// If the current movie title is greater than the other
	if (this->getTitle() > comedy.getTitle()) {
		return false;
	}

	else if (this->getTitle() < comedy.getTitle()) {
		return true;
	}

	// If they have the same movie title
	else if (this->getTitle() == comedy.getTitle()) {
		if (this->getYear() > comedy.getYear()) {
			return false;
		}
		
		// If the current year is less than the other movie
		else if (this->getYear() < comedy.getYear()) {
			return true;
		}

		else if (this->getYear() == comedy.getYear()) {
			return false; 
		}
	}
	return false;
}

// ------------------------------------ operator== -----------------------------------------------
// Description: Overload operator check to see if the movies are the same
// --------------------------------------------------------------------------------------------------- 
bool Comedy::operator==(const Movie& comedy) const {
	// If they are the same movies
	if (this->getMovieType() == comedy.getMovieType() && this->getDirector() == comedy.getDirector() && this->getTitle() == comedy.getTitle() && this->getYear() == comedy.getYear()) {
		return true;
	}

	// If they are not the same
	else {
		return false;
	}
}

// ------------------------------------ operator!= -----------------------------------------------
// Description: Overload operator check to see if the movies are not the same
// --------------------------------------------------------------------------------------------------- 
bool Comedy::operator!=(const Movie& comedy) const {
	// If they are the same movies
	if (this->getMovieType() == comedy.getMovieType() && this->getDirector() == comedy.getDirector() && this->getTitle() == comedy.getTitle() && this->getYear() == comedy.getYear()) {
		return false;
	}

	// If they are not the same
	else {
		return true;
	}

}

// ------------------------------------ display() -----------------------------------------------
// Description: Display only the comedy movies
// --------------------------------------------------------------------------------------------------- 
void Comedy::display() {
	cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getYear() << endl;
}