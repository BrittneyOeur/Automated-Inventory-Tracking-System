// ------------------------------------------------ bstree.cpp -------------------------------------------------------
// Brittney Oeur, CSS 343 A
// Creation Date: 5/22/23
// Date of Last Modification: 6/2/23
// --------------------------------------------------------------------------------------------------------------------
// Description: This implementation file will focus on binary search tree, includes methods such as insertion, retrieving 
// the nodes  (based on the type of genre of movies), delete nodes, and display the binary search tree
// (printed in an in-order way)
// --------------------------------------------------------------------------------------------------------------------

#include "bstree.h"

// ------------------------------------ Default constructor -----------------------------------------------
// Description: This a default constructor
// --------------------------------------------------------------------------------------------------- 
BSTree::BSTree() {
    root = nullptr;
}

// ------------------------------------ Destructor -----------------------------------------------
// Description: This a default Destructor
// --------------------------------------------------------------------------------------------------- 
BSTree::~BSTree() {
    makeEmpty();
}

// ------------------------------------ insert() -----------------------------------------------
// Description: This will insert the movie into the binary search tree
// --------------------------------------------------------------------------------------------------- 
BSTree* BSTree::insert(Movie* movie) {
    return insertRecursive(this->root, movie);
}

// ------------------------------------ insertRecursive() -----------------------------------------------
// Description: Insert helper function
// --------------------------------------------------------------------------------------------------- 
BSTree* BSTree::insertRecursive(Node*& current, Movie* movieInsert) {
    if (current == nullptr) {
        current = new Node;
        current->movie = movieInsert;
        current->left = nullptr;
        current->right = nullptr;
    }

    else if (*movieInsert < *(current->movie)) {
        insertRecursive(current->left, movieInsert);
    }

    else if (*movieInsert > *(current->movie)) {
        insertRecursive(current->right, movieInsert);
    }

    return this;
}

// ------------------------------------ deleteNode() -----------------------------------------------
// Description: Deletes the nodes in the binary search tree
// --------------------------------------------------------------------------------------------------- 
void BSTree::deleteNode(Node* node) {
    // Checks if the node is not null:
    if (node != nullptr) {
        // Traverse to the left subtree:
        deleteNode(node->left);

        // Traverse to the right subtree:
        deleteNode(node->right);

        if (node->movie != nullptr) {
            delete node->movie;
            node->movie = nullptr;
        }

        // Deletes the node:
        delete node;
        node = nullptr;
    }
}

// ------------------------------------ isEmpty() -----------------------------------------------
// Description: Checks if the binary search tree is empty
// --------------------------------------------------------------------------------------------------- 
bool BSTree::isEmpty() const {
    if (root == nullptr) {
        return true;
    }

    return false;
}

// ------------------------------------ makeEmpty() -----------------------------------------------
// Description: This empties the binary search tree
// --------------------------------------------------------------------------------------------------- 
void BSTree::makeEmpty() {
    deleteNode(root);
    root = nullptr;
}

// ------------------------------------ operator== -----------------------------------------------
// Description: Overload operator checks to see if the trees are the same
// --------------------------------------------------------------------------------------------------- 
bool BSTree::operator==(const BSTree& tree) const {
    // If the root is null ANd the other tree is null
    if (root == nullptr && tree.root == nullptr) {
        return true;
    }

    else {
        return equalHelper(root, tree.root);
    }
}

// ------------------------------------ equalHelper() -----------------------------------------------
// Description: Overload operator== helper function
// --------------------------------------------------------------------------------------------------- 
bool BSTree::equalHelper(Node* firstTree, Node* secondTree) const {
    // If firstTree AND secondTree are null:
    if (firstTree == nullptr && secondTree == nullptr) {
        // Are the same
        return true;
    }

    // If firstTree OR secondTree are null:
    if (firstTree == nullptr || secondTree == nullptr) {
        // Are not the same
        return false;
    }

    // If the current data for the firstTree does not equal the secondTree:
    if ((*firstTree->movie == *secondTree->movie) && (firstTree->left == nullptr) && (secondTree->left == nullptr) && (firstTree->right == nullptr) && (secondTree->right == nullptr)) {
        // If nodes have the same data and no children:
        return true;
    }

    // Both nodes have the same NodeData, keep on traversing both trees:
    return ((*firstTree->movie == *secondTree->movie) && (equalHelper(firstTree->left, secondTree->left) && equalHelper(firstTree->right, secondTree->right)));
}

// ------------------------------------ operator!= -----------------------------------------------
// Description: Overload operator checks to see if the trees are not the same
// --------------------------------------------------------------------------------------------------- 
bool BSTree::operator!=(const BSTree& tree) const {
    return !(*this == tree);
}

// ------------------------------------ retrieveComedy() -----------------------------------------------
// Description: This retrieves a specific comedy movie from the Comedy movie binary search tree
// --------------------------------------------------------------------------------------------------- 
bool BSTree::retrieveComedy(Movie*& movie, string title, int year) {
    Node* current = root;
    bool found = false;

    // Loops as long current is not nullptr AND found is false
    while ((current != nullptr) && (!found)) {
        // If not empty AND able to get the movie title AND movie year
        if ((!isEmpty()) && (current->movie->getTitle() == title) && (current->movie->getYear() == year)) {
            movie = current->movie;
            found = true;
            return true;
        }

        // If the current movie title is greater than the other
        else if ((current->movie->getTitle() > title)) {
            current = current->left;
        }

        // If they are the same movie AND the current movie year is greater than the other
        else if ((current->movie->getTitle() == title) && (current->movie->getYear() > year)) {
            current = current->left;
        }

        // If the current movie title is less than the other
        else if ((current->movie->getTitle() < title)) {
            current = current->right;
        }

        // If they are the same AND the current movie year is less than the other
        else if ((current->movie->getTitle() == title) && (current->movie->getYear() < year)) {
            current = current->right;
        }
    }
    return false;
}

// ------------------------------------ retrieveDrama() -----------------------------------------------
// Description: This retrieves a specific drama movie from the Drama movie binary search tree
// --------------------------------------------------------------------------------------------------- 
bool BSTree::retrieveDrama(Movie*& movie, string director, string title) {
    Node* current = root;
    bool found = false;

    // Loops as long current is not nullptr AND found is false
    while ((current != nullptr) && (!found)) {
        // If not empty AND able to get the movie title AND movie director
        if ((!isEmpty()) && (current->movie->getTitle() == title) && (current->movie->getDirector() == director)) {
            movie = current->movie;
            found = true;
            return true;
        }

        // If current movie director is greater than the other
        else if ((current->movie->getDirector() > director)) {
            current = current->left;
        }

        // If they have the same director AND current movie title is greater than the other
        else if ((current->movie->getDirector() == director) && (current->movie->getTitle() > title)) {
            current = current->left;
        }

        // If the current director is less than the other
        else if ((current->movie->getDirector() < director)) {
            current = current->right;
        }

        // If they have the same director AND the current movie title is less than the other
        else if ((current->movie->getDirector() == director) && (current->movie->getTitle() < title)) {
            current = current->right;
        }
    }
    return false;
}

// ------------------------------------ retrieveClassic() -----------------------------------------------
// Description: This retrieves a specific classic movie from the Classic movie binary search tree
// --------------------------------------------------------------------------------------------------- 
bool BSTree::retrieveClassic(Movie*& movie, int month, int year, string actor) {
    Node* current = root;
    bool found = false;

    // // Loops as long current is not nullptr AND found is false
    while ((current != nullptr) && (!found)) {
        // If not empty AND able to get the movie release date AND actor
        if ((!isEmpty()) && (current->movie->getMonth() == month) && (current->movie->getYear() == year) && (current->movie->getActor() == actor)) {
            movie = current->movie;
            found = true;
            return true;
        }

        // If the current movie year is greater than the other
        else if ((current->movie->getYear() > year)) {
            current = current->left;
        }

        // If they are released on the same year AND the month date of the current movie is greater than the other
        else if ((current->movie->getYear() == year) && (current->movie->getMonth() > month)) {
            current = current->left;
        }

        // If they are released on the same year AND month AND the current movie actor is greater tan the other
        else if ((current->movie->getYear() == year) && (current->movie->getMonth() == month) && (current->movie->getActor() > actor)) {
            current = current->left;
        }

        // If the current movie year is less than the other
        else if ((current->movie->getYear() < year)) {
            current = current->right;
        }

        // If they were released on the same year AND the month date of the current movie is less than the other
        else if ((current->movie->getYear() == year) && (current->movie->getMonth() < month)) {
            current = current->right;
        }

        // If they were released on the same year AND month AND the current movie actor is less than the other
        else if ((current->movie->getYear() == year) && (current->movie->getMonth() == month) && (current->movie->getActor() < actor)) {
            current = current->right;
        }
    }
    return false;
}

// ------------------------------------ display() -----------------------------------------------
// Description: Displays the binary search tree
// --------------------------------------------------------------------------------------------------- 
void BSTree::display() {
    // If the binary search tree is empty
    if (isEmpty() == true) {
        return;
    }

    displayHelper(root);
}

// ------------------------------------ displayHelper() -----------------------------------------------
// Description: Display helper function
// --------------------------------------------------------------------------------------------------- 
void BSTree::displayHelper(Node* node) {
    if (node != nullptr) {
        displayHelper(node->left);
        node->movie->display();
        displayHelper(node->right);
    }
}