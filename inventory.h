#ifndef INVENTORY_HEADER_
#define INVENTORY_HEADER_

#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "bstree.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Inventory {
	public:
		// Constructor
		Inventory();

		// Destructor
		~Inventory();

		// Add movies into the store's inventory
		void addMovie(char movieType, int stock, string director, string title, string actor, int month, int year); 

		// Borrow and return methods, that will handle the three types of movies
		bool borrowComedy(string title, int year); 
		bool borrowDrama(string director, string title); 
		bool borrowClassic(int month, int year, string actor); 
		bool returnComedy(string title, int year);
		bool returnDrama(string director, string title);
		bool returnClassic(int month, int year, string actor);

		// Displays the movies
		void displayMovies(); 

	private:
		BSTree comedyTree;
		BSTree dramaTree; 
		BSTree classicTree; 

};

#endif

