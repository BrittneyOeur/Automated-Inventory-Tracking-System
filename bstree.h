#ifndef BSTREE_HEADER_
#define BSTREE_HEADER_

#include "movie.h"

#include <iostream>

using namespace std;

class BSTree {
    public:
        // Constructor
        BSTree();

        // Destructor
        ~BSTree();

        // Checks if the binary search tree is empty:
        bool isEmpty() const;

        // Deletes every node in the binary search tree:
        void makeEmpty();

        // Inserts the given node:
        BSTree* insert(Movie* movie);

        bool operator==(const BSTree& tree) const;
        bool operator!=(const BSTree& tree) const;

        // Report whether the object is found (true or false):
        bool retrieveComedy(Movie*& movie, string title, int year);
        bool retrieveDrama(Movie*& movie, string director, string title);
        bool retrieveClassic(Movie*& movie, int month, int year, string actor);

        // Displays the BSTree
        void display();

    private:
        struct Node {
            // Stores movie
            Movie* movie;
            Node* left;
            Node* right;
        };

        Node* root = nullptr;

        // Helper function for 'insert'
        BSTree* insertRecursive(Node*& current, Movie* movieInsert);

        // Helper function for '=='
        bool equalHelper(Node* firstTree, Node* secondTree) const;

        // Deletes a node
        void deleteNode(Node* node);

        // Display helper function for 'display'
        void displayHelper(Node* node);
};

#endif