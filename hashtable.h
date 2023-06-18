#ifndef HASHTABLE_HEADER_
#define HASHTABLE_HEADER_

#include "customer.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

const int CAPACITY_ = 100;

class HashNode {
	public:
		// Hash table key
		int ID; 

		// Value of our hash table 
		Customer* customer; 

		// Constructor
		HashNode(int key, Customer* value) {
			ID = key;
			customer = value;
		}
};

	class HashTable {
		public:
			// Constructor
			HashTable(); 

			// Based on key, calculate where the HashNode is located in the array
			int HashFunc(int key); 

			// Based on given the key and the value, insert the HashNode
			void Insert(int key, Customer*& value); 

			// Based on the customer ID, searh the hash table for the customer
			bool Search(int key, Customer*& value); 

		private:
			// HashTable array
			HashNode** array;
};

#endif