// ------------------------------------------------ hashtable.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file focus on the Hash Table, this is used to uniquely identify the different 
// customers that is stored in the rental movie store. Based on their id, it will retrieve all the information
// that is stored in that id (the key). This way it helps differentiates from the other customers.
// --------------------------------------------------------------------------------------------------------------------

#include "hashtable.h"

// ------------------------------------ Default constructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
HashTable::HashTable() {
	// Create a new HashNode object using the CAPACITY_ value
	array = new HashNode * [CAPACITY_];

	// Sets every slot in the array to null
	for (int i = 0; i < CAPACITY_; i++) {
		array[i] = nullptr;
	}
}

// ------------------------------------ HashFunc() -----------------------------------------------
// Description: This will located where the key belongs to in the Hash Table
// --------------------------------------------------------------------------------------------------- 
int HashTable::HashFunc(int key) {
	// Finds where the key belongs
	return key % CAPACITY_;
}

// ------------------------------------ Insert() -----------------------------------------------
// Description: This will insert the different types of customers based on their
// unique id that is given to them
// --------------------------------------------------------------------------------------------------- 
void HashTable::Insert(int key, Customer*& value) {
	HashNode* hashNode = new HashNode(key, value);

	int index = HashFunc(key);

	// Loops as long the index is not null AND the array's ID does not match the key
	while ((array[index] != nullptr) && (array[index]->ID != key)) {
		index = HashFunc(index + 1);
	}

	// If the index is not null
	if (array[index] != nullptr) {
		// Delete that specific index of the array
		delete array[index];
	}

	// Set the array with the specific index into a Hash Node object
	array[index] = new HashNode(key, value);
}

// ------------------------------------ Search() -----------------------------------------------
// Description: This will search for the specific key that is called
// --------------------------------------------------------------------------------------------------- 
bool HashTable::Search(int key, Customer*& value) {
	int index = HashFunc(key);

	// Loops until the array reaches to an index that is null
	while (array[index] != nullptr) {
		// If the ID matches the key (if that customer exist in the store)
		if (array[index]->ID == key) {

			// Set that value to the specific customer
			value = array[index]->customer;

			// Able to find customer
			return true;
		}

		// If the customer is not found, increment the index
		index += 1;
	}

	// Customer does not exist or cannot be found
	return false;
}
