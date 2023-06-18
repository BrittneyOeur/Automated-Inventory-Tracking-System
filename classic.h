#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "movie.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Child class of the parent class Movie
class Classic : public Movie {
	public:
		// Constructor
		Classic(char movieType, int stock, string director, string title, string actor, int month, int year); 

		//Getters-Setters
		virtual void setStock(int stock);
		virtual void setDirector(string director);
		virtual void setTitle(string title);
		virtual void setActor(string actor);
		virtual void setMonth(int month);
		virtual void setYear(int year);

		virtual int getStock() const;
		string getDirector() const;
		string getTitle() const;
		string getActor() const;
		int getMonth() const;
		int getYear() const;

		// Overload operators
		virtual bool operator>(const Movie& classic) const;
		virtual bool operator<(const Movie& classic) const;
		virtual bool operator==(const Movie& classic) const;
		virtual bool operator!=(const Movie& classic) const;

		virtual void display();

	private:
		char movieType;
		int stock;
		string director;
		string title;
		string actor;
		int month;
		int year;
};
#endif

