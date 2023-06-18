// ------------------------------------------------ moviestore.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file is the movie rental store. It handles reading textfiles, which consists of
// the movies, custmers, commands, and it will execute the commands. This file handles binary seach tree, queues,
// and a hash table.
// --------------------------------------------------------------------------------------------------------------------

#include "moviestore.h"

// ------------------------------------ Default constructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
MovieStore::MovieStore() {

}

// ------------------------------------ Destructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
MovieStore::~MovieStore(){

}

// ------------------------------------ readMovies() -----------------------------------------------
// Description: This will read the movie text files, which will print out the movies accordingly
// --------------------------------------------------------------------------------------------------- 
void MovieStore::readMovies(string textFile) {
	ifstream file;
	file.open(textFile);

	// Any variables that are not a string, will be saved as string:
	string stringMovieType, stringStock, stringYear;
	char movieType; 
	int stock;
	string title, director, firstName, lastName, fullName;
	int month, year;
	string line;

	getline(file, line);

	// Loops till it reaches at the end of the file:
	while (!file.eof()) {
		stringstream ss(line);

		getline(ss, stringMovieType, ',');
		movieType = stringMovieType[0];

		getline(ss, stringStock, ',');
		stock = stoi(stringStock);

		getline(ss, director, ',');

		getline(ss, title, ',');
		
		// If the movie type is 'F' or 'D'
		if ((movieType == 'F') || (movieType == 'D')) {
			getline(ss, stringStock, ',');
			year = stoi(stringStock);
		}

		// If the movie type is 'C'
		else if ((movieType == 'C')) {
			ss >> firstName >> lastName;
			fullName = firstName + " " + lastName;
			ss >> month >> year;
		}

		// If it is any other movie type
		else {
			cout << "ERROR: movie type " << movieType << " does not exist." << endl;
		}

		// If movie type is 'F' or 'D'
		if ((movieType == 'F') || (movieType == 'D')) {
			movieInventory.addMovie(movieType, stock, director, title, "", 0, year);
		}

		// If move type is 'C'
		else if (movieType == 'C') {
			movieInventory.addMovie(movieType, stock, director, title, fullName, month, year);
		}

		getline(file, line); 
	}
	file.close();
}

// ------------------------------------ readCommands() -----------------------------------------------
// Description: This will read the commands from a text files, and each command will be pushed
// into a queue, so that when it is called, the first command that was pushed, will be executed
// --------------------------------------------------------------------------------------------------- 
void MovieStore::readCommands(string textFile) {
	ifstream file;
	file.open(textFile);
	char actionType, mediaType, movieType;
	int customerID;
	string director, title, firstName, lastName, fullName;
	int month, year;
	string line;

	getline(file, line); 

	while (!file.eof()) {
		stringstream ss(line);
		ss >> actionType >> customerID >> mediaType >> movieType;

		// Inventory
		if (actionType == 'I') {
			Command* inventoryCommand = new Command(actionType);
			movieInventory.displayMovies();
			commandsList.push(inventoryCommand);
		}

		// History
		else if (actionType == 'H') {
			Command* historyCommand = new Command(actionType, customerID);
			commandsList.push(historyCommand);
		}

		// If movie type is 'F' (Comedy)
		if (movieType == 'F') {
			getline(ss, title, ',');
			ss >> year;

			// If action type is to borrow or return
			if ((actionType == 'B') || (actionType == 'R')) {
				Command* newCommand = new Borrow(actionType, customerID, mediaType, movieType, title, year);
				commandsList.push(newCommand);
			}
		}

		// If movie type is 'D' (Drama)
		else if (movieType == 'D') {
			getline(ss, director, ',');
			getline(ss, title, ',');

			// If action type is to borrow or return
			if ((actionType == 'B') || (actionType == 'R')) {
				Command* newCommand = new Borrow(actionType, customerID, mediaType, movieType, director, title);
				commandsList.push(newCommand);
			}
		}

		// If movie type is 'C' (Classic)
		else if (movieType == 'C') {
			ss >> month >> year >> firstName >> lastName;

			// Stores the full name of the actor
			fullName = firstName + " " + lastName;

			// If action type is to borrow or return
			if ((actionType == 'B') || (actionType == 'R')) {
				Command* newCommand = new Borrow(actionType, customerID, mediaType, movieType, month, year, fullName);
				commandsList.push(newCommand);
			}
		}
		getline(file, line); 
	}
	file.close();
}

// ------------------------------------ readCustomer() -----------------------------------------------
// Description: This will read the customers from a text files, and for each (new) customers,
// they will be added into the movie store's system
// --------------------------------------------------------------------------------------------------- 
void MovieStore::readCustomer(string textFile) {
	ifstream file;
	file.open(textFile);

	int customerID;
	string firstName, lastName;
	string line;

	getline(file, line);

	// Loops until it reaches end of text file
	while (!file.eof()) {
		stringstream ss(line);

		// Retrieve the customer ID and full name from the text file
		ss >> customerID >> lastName >> firstName;

		// Insert them into a new Customer object
		Customer* addCustomer = new Customer(customerID, firstName, lastName);

		// Inserts the customer into an Hash Table
		customersList.Insert(customerID, addCustomer);

		getline(file, line); 
	}
	file.close();
}

// ------------------------------------ executeCommands() -----------------------------------------------
// Description: This will execute the commands that was called from the given text file. 
// The commands are stored into a queue, so that it will print the commands in order.
// --------------------------------------------------------------------------------------------------- 
void MovieStore::executeCommands() {
	int customerID;
	Customer* retrieveCustomer;

	// Loops as long the queue for commands is not empty
	while (!commandsList.empty()) {

		// If command type is 'I' (Inventory)
		if (commandsList.front()->getCommandType() == 'I') {
			// Displays the movies that is in the store's inventory
			movieInventory.displayMovies();
		}

		// If command type is 'H' (History)
		else if (commandsList.front()->getCommandType() == 'H') {
			// Retrieves the first-most customer from the queue
			customerID = commandsList.front()->getCustomerID();

			// Search for that customer from the hash table
			customersList.Search(customerID, retrieveCustomer);

			retrieveCustomer->display();
		}

		// If command type is 'R' (Return)
		else if (commandsList.front()->getCommandType() == 'R') {

			// If movie type is 'F' (Comedy)
			if (commandsList.front()->getMovieType() == 'F') {
				// Retrieves the first-most customer from the queue
				int customerID = commandsList.front()->getCustomerID();

				// Search for that customer from the hash table
				customersList.Search(customerID, retrieveCustomer);

				// Retrieve the title and year of the given comedy movie
				string title = commandsList.front()->getTitle();
				int year = commandsList.front()->getYear();

				movieInventory.returnComedy(title, year);
				retrieveCustomer->addComedyCommand('R', customerID, commandsList.front()->getMediaType(), 'F', title, year);
			}

			// If movie type is 'D' (Drama)
			else if (commandsList.front()->getMovieType() == 'D') {
				// Retrieves the first-most customer from the queue
				int customerID = commandsList.front()->getCustomerID();

				// Search for that customer from the hash table
				customersList.Search(customerID, retrieveCustomer);

				// Retrieve the director and title of the given drama movie
				string director = commandsList.front()->getDirector();
				string title = commandsList.front()->getTitle();

				movieInventory.returnDrama(director, title);
				retrieveCustomer->addDramaCommand('R', customerID, commandsList.front()->getMediaType(), 'D', director, title);
			}

			// If movie type is 'C' (Classic)
			else if (commandsList.front()->getMovieType() == 'C') {
				// Retrieves the first-most customer from the queue
				int customerID = commandsList.front()->getCustomerID();

				// Search for that customer from the hash table
				customersList.Search(customerID, retrieveCustomer);

				// Retrieve the released data and actor of the given classic movie
				int month = commandsList.front()->getMonth();
				int year = commandsList.front()->getYear();
				string actor = commandsList.front()->getActor();

				movieInventory.returnClassic(month, year, actor);
				retrieveCustomer->addClassicCommand('R', customerID, commandsList.front()->getMediaType(), 'C', month, year, actor);
			}
		}

		// If command type is 'B' (Borrow)
		else if (commandsList.front()->getCommandType() == 'B') {

			// If movie type is 'F' (Comedy)
			if (commandsList.front()->getMovieType() == 'F') {
				// Retrieves the first-most customer from the queue
				int customerID = commandsList.front()->getCustomerID();

				// Search for that customer from the hash table
				customersList.Search(customerID, retrieveCustomer);

				// Retrieve the title and year of the given comedy movie
				string title = commandsList.front()->getTitle();
				int year = commandsList.front()->getYear();

				movieInventory.borrowComedy(title, year);
				retrieveCustomer->addComedyCommand('B', customerID, commandsList.front()->getMediaType(), 'F', title, year);
			}

			// If movie type is 'D' (Drama)
			else if (commandsList.front()->getMovieType() == 'D') {
				// Retrieves the first-most customer from the queue
				int customerID = commandsList.front()->getCustomerID();

				// Search for that customer from the hash table
				customersList.Search(customerID, retrieveCustomer);

				// Retrieve the director and title of the given drama movie
				string director = commandsList.front()->getDirector();
				string title = commandsList.front()->getTitle();

				movieInventory.borrowDrama(director, title);
				retrieveCustomer->addDramaCommand('B', customerID, commandsList.front()->getMediaType(), 'D', director, title);
			}

			// If movie type is 'C' (Classic)
			else if (commandsList.front()->getMovieType() == 'C') {
				// Retrieves the first-most customer from the queue
				int customerID = commandsList.front()->getCustomerID();

				// Search for that customer from the hash table
				customersList.Search(customerID, retrieveCustomer);

				// Retrieve the released data and actor of the given classic movie
				int month = commandsList.front()->getMonth();
				int year = commandsList.front()->getYear();
				string actor = commandsList.front()->getActor();

				movieInventory.borrowClassic(month, year, actor);
				retrieveCustomer->addClassicCommand('B', customerID, commandsList.front()->getMediaType(), 'C', month, year, actor);
			}
		}
		// Pops the commands, so that the commands will be executed in order
		commandsList.pop();
	}
}