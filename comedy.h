#ifndef COMEDY_HEADER_
#define COMEDY_HEADER_

#include "movie.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Child class of the parent class Movie
class Comedy : public Movie {
	public:
		//Constructor
		Comedy(char movieType, int stock, string director, string title, int year);

		// Getters-Setters
		virtual void setStock(int stock);
		virtual void setDirector(string director);
		virtual void setTitle(string title);
		virtual void setYear(int year);

		virtual int getStock() const;
		string getDirector() const;
		string getTitle() const;
		int getYear() const;

		// Overload operators
		virtual bool operator>(const Movie& comedy) const;
		virtual bool operator<(const Movie& comedy) const;
		virtual bool operator==(const Movie& comedy) const;
		virtual bool operator!=(const Movie& comedy) const;

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

