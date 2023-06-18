#ifndef COMMAND_HEADER_
#define COMMAND_HEADER_

#include <iostream>
#include <string>

using namespace std;

// Parent class of Borrow and Return
class Command {
	public:
		// Constructors:
		
		// For 'I' (Inventory)
		// Action types I: no more fields
		Command(char commandType); 

		// For 'H' (History)
		// Action type H: one more field customer ID. Fields are separated by a space
		Command(char commandType, int customerID);

		// Action types B and R: customer ID followed by type of media (currently only �D� for
		// DVD) then movie type and movie data(with values of the two sorting attributes, using
		// comma or space to separate them as in the movie data file).Fields are separated by a
		// space.

		// For 'B' or 'R' and 'F' (Comedy movies)
		Command(char commandType, int customerID, char mediaType, char movieType, string title, int year);

		// For 'B' or 'R' and 'D' (Drama movies)
		Command(char commandType, int customerID, char mediaType, char movieType, string director, string title);

		// For 'B' or 'R' and 'C' (Classic movies)
		Command(char command_type, int customerID, char mediaType, char movieType, int month, int year, string actor);

		// Getters-Setters
		void setCommandType(char commandType);
		void setCustomerID(int customerID);
		void setMediaType(char mediaType);
		void setMovieType(char movieType);
		void setDirector(string director);
		void setTitle(string title);
		void setActor(string actor);
		void setMonth(int month);
		void setYear(int year);

		char getCommandType();
		int getCustomerID();
		char getMediaType();
		char getMovieType();
		string getDirector();
		string getTitle();
		string getActor();
		int getMonth();
		int getYear();

		// Displays the inventory
		virtual void display();

	private:
		char commandType; 
		int customerID; 
		char mediaType; 
		char movieType; 
		string director;
		string title;
		int month;
		int year;
		string actor;
};

#endif