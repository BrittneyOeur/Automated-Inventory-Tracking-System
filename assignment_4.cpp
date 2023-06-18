// ------------------------------------------------ assignment_4.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will call the MovieStore class, to read text files, which includes
// the customers, the types of movies, commands, and will initiate the given commands
// --------------------------------------------------------------------------------------------------------------------

#pragma

#include "movie.h"
//#include "movie.cpp"
#include "moviestore.h"
//#include "moviestore.cpp"
#include "inventory.h"
// #include "inventory.cpp"
#include "comedy.h"
// #include "comedy.cpp"
#include "drama.h"
// #include "drama.cpp"
#include "classic.h"
// #include "classic.cpp"
#include "customer.h"
// #include "customer.cpp"
#include "hashtable.h"
// #include "hashtable.cpp"
#include "command.h"
// #include "command.cpp"
#include "bstree.h"
// #include "bstree.cpp"
#include "return.h"
// #include "return.cpp"
#include "borrow.h"
// #include "borrow.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	MovieStore store;

	store.readCustomer("data4customers.txt");
	store.readMovies("data4movies.txt");
	store.readCommands("data4commands.txt");
	store.executeCommands();

	return 0;
}