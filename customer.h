#ifndef CUSTOMER_HEADER_
#define CUSTOMER_HEADER_

#include "command.h"
#include "borrow.h"
#include "return.h"

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Customer {
	public:
		// Constructor
		Customer(int customer_id, string first_name, string last_name);

		// Destructor
		~Customer();

		// Getters-Setters
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setCustomerID(int customerID);

		string getFirstName();
		string getLastName();
		int getCustomerID();

		void addComedyCommand(char commandType, int customerID, char mediaType, char movieType, string title, int year); 
		void addDramaCommand(char commandType, int customerID, char mediaType, char movieType, string director, string title);
		void addClassicCommand(char commandType, int customerID, char mediaType, char movieType, int month, int year, string actor);
		
		//Show the history of the customer
		void display();

	private:
		string firstName;
		string lastName;
		int customerID;

		queue<Command*> commands;
		
		// Track the number of commands
		int size = 0; 
};

#endif