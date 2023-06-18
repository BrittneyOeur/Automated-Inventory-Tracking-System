#ifndef DRAMA_HEADER_
#define DRAMA_HEADER_

#include "movie.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Child class of the parent class Movie
// dramas (‘D’) are sorted by Director, then Title

class Drama : public Movie {
	public:
		//Constructor
		Drama(char movieType, int stock, string director, string title, int year);

		//Getters and Setters
		virtual void setStock(int stock);
		virtual void setDirector(string director);
		virtual void setTitle(string title);
		virtual void setYear(int year);

		virtual int getStock() const;
		string getDirector() const;
		string getTitle() const;
		int getYear() const;

		// Operator Overloads
		virtual bool operator>(const Movie& drama) const;  
		virtual bool operator<(const Movie& drama) const; 
		virtual bool operator==(const Movie& drama) const; 
		virtual bool operator!=(const Movie& drama) const; 

		//Actions
		virtual void display();

	private:
		char movieType; 
		int stock; 
		string director; 
		string title; 
		int year; 
};
#endif

