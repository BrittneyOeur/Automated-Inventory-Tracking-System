#ifndef MOVIESTORE_HEADER_
#define MOVIESTORE_HEADER_

#include "movie.h"
#include "inventory.h"
#include "customer.h"
#include "hashtable.h"
#include "command.h"
#include "return.h"
#include "borrow.h"
#include "bstree.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class MovieStore {
	public:
		//Constructor
		MovieStore();

		// Destructor
		~MovieStore();

		// Read movies from text file
		void readMovies(string textFile);

		// Read customers from text file
		void readCustomer(string textFile);

		// Read commands from text file
		void readCommands(string textFile);

		// Execute commands
		void executeCommands(); 

	private:
		Inventory movieInventory;
		HashTable customersList; 
		queue<Command*> commandsList; 
};

#endif