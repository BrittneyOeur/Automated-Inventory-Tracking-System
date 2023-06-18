#ifndef RETURN_HEADER_
#define RETURN_HEADER_

#include "command.h"

#include <iostream>
#include <string>

using namespace std;

// Child class of the parent class, Command
class Return : public Command {
	public:
		// Constructor for 'F' (Comedy) 
		Return(char command_type, int customer_id, char media_type, char movie_type, string title, int year); 

		// Constructor for 'D' (Drama)
		Return(char command_type, int customer_id, char media_type, char movie_type, string director, string title); 

		// Constructor for 'C' (Classic)
		Return(char command_type, int customer_id, char media_type, char movie_type, int month, int year, string actor); 

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

		// Display inventory
		virtual void display();

	private:
		char commandType;
		int customerID;
		char mediaType = 'D';
		char movieType;
		string director;
		string title;
		string actor;
		int month;
		int year;
};

#endif