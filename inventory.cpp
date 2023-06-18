// ------------------------------------------------ inventory.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file handles all the movies in the rental store, such as, comedy, drama, and classic
// movies. It include getter-setter methods to store the variables accordingly based on the movie that is stored
// inside the movie store. In addition, it will print out all the movies that exist in the store.
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"


// ------------------------------------ Default constructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
Inventory::Inventory() {

}

// ------------------------------------ Destructor -----------------------------------------------
// Description: This a default destructor
// --------------------------------------------------------------------------------------------------- 
Inventory::~Inventory() {

}

// ------------------------------------ addMovie() -----------------------------------------------
// Description: This will add the movies into the movie rental store's inventory
// --------------------------------------------------------------------------------------------------- 
void Inventory::addMovie(char movieType, int stock, string director, string title, string actor, int month, int year) {
	// If movie type is 'F' (comedy)
	if (movieType == 'F') {
		Movie* comedyMovie = new Comedy(movieType, stock, director, title, year);

		// Inserts into the comedy's binary search tree
		comedyTree.insert(comedyMovie);
	}

	// If the movie type is 'D' (drama)
	else if (movieType == 'D') {
		Movie* dramaMovie = new Drama(movieType, stock, director, title, year);

		// Inserts into the drama's binary search tree
		dramaTree.insert(dramaMovie);
	}

	// If the movie type is 'C' (classic)
	else if (movieType == 'C') {
		Movie* classicMovie = new Classic(movieType, stock, director, title, actor, month, year);

		// Inserts into the classic's binary search tree
		classicTree.insert(classicMovie);
	}
}

// ------------------------------------ borrowComedy() -----------------------------------------------
// Description: This will borrow the comedy movies
// --------------------------------------------------------------------------------------------------- 
bool Inventory::borrowComedy(string title, int year) {
	Movie* borrowMovie;

	// If the movie does not exist
	if (!comedyTree.retrieveComedy(borrowMovie, title, year)) {
		cout << "ERROR: Movie cannot be found." << endl;
		return false;
	}

	else {
		// If the stock for that movie is 0 or less than 0
		if (borrowMovie->getStock() < 1) {
			cerr << "ERROR: Out of stock of this comedy movie." << endl;
			return false;
		}

		int decreaseStock = borrowMovie->getStock() - 1;
		borrowMovie->setStock(decreaseStock);
		return true;
	}
}

// ------------------------------------ returnComedy() -----------------------------------------------
// Description: This will return the given comedy movies
// --------------------------------------------------------------------------------------------------- 
bool Inventory::returnComedy(string title, int year) {
	Movie* returnMovie;

	// If the movie does not exist
	if (!comedyTree.retrieveComedy(returnMovie, title, year)) {
		cout << "ERROR: Movie cannot be found." << endl;
		return false;
	}

	else {
		// If the stock for that movie is 0 or less than 0
		if (returnMovie->getStock() < 1) {
			cout << "ERROR: stock cannot be 0 or less than 0." << endl;
			return false;
		}

		int increaseStock = returnMovie->getStock() + 1;
		returnMovie->setStock(increaseStock);
		return true;
	}
}

// ------------------------------------ borrowDrama() -----------------------------------------------
// Description: This will borrow the drama movies
// --------------------------------------------------------------------------------------------------- 
bool Inventory::borrowDrama(string director, string title) {
	Movie* borrowMovie;

	// If the movie does not exist
	if (!dramaTree.retrieveDrama(borrowMovie, director, title)) {
		cout << "ERROR: Movie cannot be found." << endl;
		return false;
	}
	else {
		// If the stock for that movie is 0 or less than 0
		if (borrowMovie->getStock() < 1) {
			cout << "ERROR: Out of stock of this drama movie." << endl;
			return false;
		}

		int decreaseStock = borrowMovie->getStock() - 1;
		borrowMovie->setStock(decreaseStock);
		return true;
	}
}

// ------------------------------------ returnDrama() -----------------------------------------------
// Description: This will return the drama movies
// --------------------------------------------------------------------------------------------------- 
bool Inventory::returnDrama(string director, string title) {
	Movie* returnMovie;

	// If the movie does not exist
	if (!dramaTree.retrieveDrama(returnMovie, director, title)) {
		cout << "ERROR: Movie cannot be found." << endl;
		return false;
	}

	else {
		// If the stock for that movie is 0 or less than 0
		if (returnMovie->getStock() < 1) {
			cout << "ERROR: stock cannot be 0 or less than 0." << endl;
			return false;
		}

		int increaseStock = returnMovie->getStock() + 1;
		returnMovie->setStock(increaseStock);
		return true;
	}
}

// ------------------------------------ borrowClassic() -----------------------------------------------
// Description: This will borrow the classic movies
// --------------------------------------------------------------------------------------------------- 
bool Inventory::borrowClassic(int month, int year, string actor) {
	Movie* borrowMovie;

	// If the movie does not exist
	if (!classicTree.retrieveClassic(borrowMovie, month, year, actor)) {
		cout << "ERROR: Movie cannot be found." << endl;
		return false;
	}

	else {
		// If the stock for that movie is 0 or less than 0
		if (borrowMovie->getStock() < 1) {
			cout << "ERROR: Out of stock of this classic movie." << endl;
			return false;
		}

		int decreaseStock = borrowMovie->getStock() - 1;
		borrowMovie->setStock(decreaseStock);
		return true;
	}
}

// ------------------------------------ returnClassic() -----------------------------------------------
// Description: This will the return classic movies
// --------------------------------------------------------------------------------------------------- 
bool Inventory::returnClassic(int month, int year, string actor) {
	Movie* returnMovie;

	// If the movie does not exist
	if (!classicTree.retrieveClassic(returnMovie, month, year, actor)) {
		cout << "ERROR: Movie cannot be found." << endl;
		return false;
	}

	else {
		// If the stock for that movie is 0 or less than 0
		if (returnMovie->getStock() < 1) {
			cout << "ERROR: stock cannot be 0 or less than 0." << endl;
			return false;
		}

		int increaseStock = returnMovie->getStock() + 1;
		returnMovie->setStock(increaseStock);
		return true;
	}
}

// ------------------------------------ displayMovies() -----------------------------------------------
// Description: This will display the movies that is currently in the store's inventory
// --------------------------------------------------------------------------------------------------- 
void Inventory::displayMovies() {
	cout << endl;
	cout << ".:INVENTORY:." << endl << endl;

	// If the comedy BSTree is empty
	cout << "Comedy Movies: " << endl;
	if (comedyTree.isEmpty() == true) {
		cout << "EMPTY: No comedy movies at the moment." << endl;
	}

	else {
		comedyTree.display();
	}

	cout << endl;

	// If the drama BSTree is empty
	cout << "Drama Movies: " << endl;
	if (dramaTree.isEmpty() == true) {
		cout << "EMPTY: No drama movies at the moment." << endl;
	}

	else {
		dramaTree.display();
	}

	cout << endl;

	// If the classic BSTree is empty
	cout << "Classic Movies: " << endl;
	if (classicTree.isEmpty() == true) {
		cout << "EMPTY: No classic movies at the moment." << endl;
	}

	else {
		classicTree.display();
	}
	cout << endl;
}