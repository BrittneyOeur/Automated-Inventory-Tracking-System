#ifndef MOVIE_HEADER_
#define MOVIE_HEADER_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Movie {
	friend ostream& operator<<(ostream& out, const Movie& movie); 

	public:
		// Constructor, for 'F' and 'D' (Comedy and Drama)
		Movie(char movie_type, int stock, string director, string title, int year);

		// Constructor, or 'C' (Classic)
		Movie(char movie_type, int stock, string director, string title, string actor, int month, int year);

		//Getters and Setters
		virtual void setStock(int stock);
		void setMovieType(char movieType);
		void setDirector(string director);
		void setTitle(string title);
		void setActor(string actor);
		void setMonth(int month);
		void setYear(int year);

		virtual int getStock() const;
		char getMovieType() const;
		string getDirector() const;
		string getTitle() const;
		string getActor() const;
		int getMonth() const;
		int getYear() const;

		// Display movies
		virtual void display();

		// Overload operators
		virtual bool operator>(const Movie& movie) const;
		virtual bool operator<(const Movie& movie) const;
		virtual bool operator==(const Movie& movie) const;
		virtual bool operator!=(const Movie& movie) const;	

	private:
		int stock;
		char movieType;
		string director;
		string title;
		string actor;
		int month;
		int year;
};
#endif

