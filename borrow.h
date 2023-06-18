#ifndef BORROW_HEADER_
#define BORROW_HEADER_

#include "command.h"

#include <iostream>
#include <string>

using namespace std;

// Child class of the parent class Command
class Borrow : public Command {
	public:
		// Constructor for 'F' (Comedy) 
		Borrow(char commandType, int customerID, char mediaType, char movieType, string title, int year); 

		// Constructor for 'D' (Drama)
		Borrow(char commandType, int customerID, char mediaType, char movieType, string director, string title); 

		// Constructor for 'C' (Classic)
		Borrow(char commandType, int customerID, char mediaType, char movieType, int month, int year, string actor); 

		// Getters-Setters
		virtual void setCommandType(char commandType);
		virtual void setCustomerID(int customerID);
		virtual void setMediaType(char mediaType);
		virtual void setMovieType(char movieType);
		virtual void setDirector(string director);
		virtual void setTitle(string title);
		virtual void setActor(string actor);
		virtual void setMonth(int month);
		virtual void setYear(int year);

		virtual char getCommandType();
		virtual int getCustomerID();
		virtual char getMediaType();
		virtual char getMovieType();
		virtual string getDirector();
		virtual string getTitle();
		virtual string getActor();
		virtual int getMonth();
		virtual int getYear();

		// Displays the movies that is borrowed
		virtual void display();

	private:
		char commandType;
		int customerID;
		char mediaType;
		char movieType;
		string director;
		string title;
		string actor;
		int month;
		int year;
};

#endif