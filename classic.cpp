// ------------------------------------------------ classic.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will focus on classic movie genre, it includes overload operators,
// to compare to other classic movies, and based on the results, will print them accordingly (in-order).
// Based on their release date and major actor
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"

// ------------------------------------ Parameterized constructor -----------------------------------------------
// Description: This a constructor for the classic movie genre
// --------------------------------------------------------------------------------------------------- 
Classic::Classic(char movieType, int stock, string director, string title, string actor, int month, int year) : Movie(movieType, stock, director, title, actor, month, year) {
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
void Classic::setStock(int stock) {
	this->stock = stock;
}

// ------------------------------------ setDirector() -----------------------------------------------
// Description: Setter method for director
// ---------------------------------------------------------------------------------------------------
void Classic::setDirector(string director) {
	this->director = director;
}

// ------------------------------------ setTitle() -----------------------------------------------
// Description: Setter method for title
// ---------------------------------------------------------------------------------------------------
void Classic::setTitle(string title) {
	this->title = title;
}

// ------------------------------------ setActor() -----------------------------------------------
// Description: Setter method for actor
// ---------------------------------------------------------------------------------------------------
void Classic::setActor(string actor) {
	this->actor = actor;
}

// ------------------------------------ setMonth() -----------------------------------------------
// Description: Setter method for month
// ---------------------------------------------------------------------------------------------------
void Classic::setMonth(int month) {
	this->month = month;
}

// ------------------------------------ setYear() -----------------------------------------------
// Description: Setter method for year
// ---------------------------------------------------------------------------------------------------
void Classic::setYear(int year) {
	this->year = year;
}

// ------------------------------------ getStock() -----------------------------------------------
// Description: Getter method for stock
// ---------------------------------------------------------------------------------------------------
int Classic::getStock() const {
	return stock;
}

// ------------------------------------ getDirector() -----------------------------------------------
// Description: Getter method for director
// ---------------------------------------------------------------------------------------------------
string Classic::getDirector() const {
	return director;
}

// ------------------------------------ getTitle() -----------------------------------------------
// Description: Getter method for title
// ---------------------------------------------------------------------------------------------------
string Classic::getTitle() const {
	return title;
}

// ------------------------------------ getActor() -----------------------------------------------
// Description: Getter method for actor
// ---------------------------------------------------------------------------------------------------
string Classic::getActor() const {
	return actor;
}

// ------------------------------------ getMonth() -----------------------------------------------
// Description: Getter method for month
// ---------------------------------------------------------------------------------------------------
int Classic::getMonth() const {
	return month;
}

// ------------------------------------ getYear() -----------------------------------------------
// Description: Getter method for year
// ---------------------------------------------------------------------------------------------------
int Classic::getYear() const {
	return year;
}

// ------------------------------------ operator> -----------------------------------------------
// Description: Overload operator to check which classic movie is greater
// ---------------------------------------------------------------------------------------------------
bool Classic::operator>(const Movie& classic) const {
	// If the current movie year is greater than the other
	if (this->getYear() < classic.getYear()) {
		return false;
	}

	else if (this->getYear() > classic.getYear()) {
		return true;
	}

	// If the years are the same
	else if (this->getYear() == classic.getYear()) {
		// If the month is less than the other
		if (this->getMonth() > classic.getMonth()) {
			return false;
		}

		else if (this->getMonth() < classic.getMonth()) {
			return true;
		}

		// If the month are same
		else if (this->getMonth() == classic.getMonth()) {
			// If the current movie actor is less than the other
			if (this->getActor() < classic.getActor()) {
				return false;
			}

			else if (this->getActor() > classic.getActor()) {
				return true;
			}

			// If the actors are the same
			else {
				return false;
			}
		}
	}
	return false;
}

// ------------------------------------ operator< -----------------------------------------------
// Description: Overload operator to check if the movie is less than the other
// ---------------------------------------------------------------------------------------------------
bool Classic::operator<(const Movie& classic) const {
	// If the year is greater than the other movie
	if (this->getYear() > classic.getYear()) {
		return false;
	}

	else if (this->getYear() < classic.getYear()) {
		return true;
	}

	// If the years are the same
	else if (this->getYear() == classic.getYear()) {
		// If the month is less than the other
		if (this->getMonth() < classic.getMonth()) {
			return true;
		}

		else if (this->getMonth() > classic.getMonth()) {
			return false;
		}

		// If the month are the same
		else if (this->getMonth() == classic.getMonth()) {
			// If the current movie actor is greater than the other
			if (this->getActor() > classic.getActor()) {
				return false;
			}

			else if (this->getActor() < classic.getActor()) {
				return true;
			}

			// If the actors are the same
			else {
				return false;
			}
		}
	}
	return false;
}

// ------------------------------------ operator== -----------------------------------------------
// Description: Overload operator to check if the movies are the same
// ---------------------------------------------------------------------------------------------------
bool Classic::operator==(const Movie& classic) const {
	// If the movies are the same
	if (this->getMovieType() == classic.getMovieType() && this->getDirector() == classic.getDirector() && this->getTitle() == classic.getTitle() && this->getYear() == classic.getYear() && this->getMonth() == classic.getMonth() && this->getActor() == classic.getActor()) {
		return true;
	}

	// If the movies are not the same
	else {
		return false;
	}
}

// ------------------------------------ operator!= -----------------------------------------------
// Description: Overload operator to check if the movies are not the same
// ---------------------------------------------------------------------------------------------------
bool Classic::operator!=(const Movie& classic) const {
	// If the movies are the same
	if (this->getMovieType() == classic.getMovieType() && this->getDirector() == classic.getDirector() && this->getTitle() == classic.getTitle() && this->getYear() == classic.getYear() && this->getMonth() == classic.getMonth() && this->getActor() == classic.getActor()) {
		return false;
	}

	// If the movies are not the same
	else {
		return true;
	}
}

// ------------------------------------ display() -----------------------------------------------
// Description: Displays only the classic movies that the store holds
// ---------------------------------------------------------------------------------------------------
void Classic::display() {
	cout << this->getMovieType() << ", " << this->getStock() << ", " << this->getDirector() << ", " << this->getTitle() << ", " << this->getActor() << " " << this->getMonth() << " " << this->getYear() << endl;
}