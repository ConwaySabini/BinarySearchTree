// ----------------------------- bintree.h ------------------------------------

// @author Sabini Ethan 343

// @date January 20, 2020

// @modified January 31, 2020

// ----------------------------------------------------------------------------

// This class represents a binary search tree. Each node in the tree contains a
// pointer to the NodeData object that contains the string value. 

// ----------------------------------------------------------------------------

// Binary search trees first store a value in the root. Then the tree stores 
// smaller values to the left and larger values to the right. There are no 
// duplicates stored in the binary search tree.

// ----------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
using namespace std;

class BinTree {
public:
	BinTree();
	// default constructor creates root and initializes data to empty string
	BinTree(const BinTree& tree); // copy constructor creates a deep copy
	~BinTree(); // destructor, calls makeEmpty

	bool isEmpty() const;		// true if tree is empty, otherwise false
	void makeEmpty();			// make the tree empty so isEmpty returns true
	bool insert(NodeData* data); 
	// inserts node and returns true or false if the data is duplicate.
	void displaySideways() const; // provided below, displays the tree sideways
	bool retrieve(const NodeData& toFind, NodeData*& found) const;
	// returns true if toFind is found and stores the pointer in found
	// returns false if not found
	int getHeight(const NodeData& findLevel) const;
	// returns the height of the parameter findLevel, 1 if a leaf node
	void bstreeToArray(NodeData* treeArr[]);
	// stores the contents of the tree in the array and empties the tree
	void arrayToBSTree(NodeData* treeArr[]);
	// stores the contents of the array in the tree and empties the array

	BinTree& operator=(const BinTree& rhs); // creates a deep copy
	bool operator==(const BinTree& rhs) const;
	// compares the contents of the tree
	bool operator!=(const BinTree& rhs) const;
	// compares the contents of the tree
	friend ostream& operator<<(ostream& output, const BinTree& rhs) {
		output << rhs.root; // private helper operator overload
		output << endl;
		return output;
	}
	// ouputs the contents of the tree to cout
private:
	struct Node {
		NodeData* data = nullptr;			// pointer to data object
		Node* left = nullptr;				// pointer to left subtree
		Node* right = nullptr;				// pointer to right subtree
	};
	Node* root = nullptr;								// root of the tree

	// utility functions
	friend ostream& operator<<(ostream& output, const Node* subtree) {
		if (subtree == nullptr) {
			return output;
		}
		// in-order traversal of tree
		output << subtree->left;
		output << (*subtree->data) << " "; // prints string
		output << subtree->right;
		return output;
	}
	// Traverses the tree in order to print contents
	Node* insert(NodeData* data, Node* subtree) throw (exception) {
		// base case when subtree is empty inserts node
		if (subtree == nullptr || subtree->data == nullptr) {
			subtree = new Node();
			subtree->data = data; 
		}
		else if (*data <= *subtree->data) { // traverse left side
			if (*data == *subtree->data) { // if duplicate throw exception
				throw exception();
			}
			subtree->left = insert(data, subtree->left);
		}
		else if (*data > *subtree->data) { // traverse right side
			subtree->right = insert(data, subtree->right);
		}
		return subtree;
	}
	// inserts the node in the correct place if there is no duplicate
	void arrayToTreeHelper(NodeData* treeArr[], int low, int high);
	// converts the array into a binary search tree
	void empty(Node* subtree); // deletes all nodes in the tree
	void assign(const Node* source); // creates a deep copy of tree contents
	bool retrieve(const NodeData& toFind, NodeData*& found, 
		const Node* subtree) const; 
	// traverses tree to find the NodeData parameter and store it in found
	bool isEqual(const Node* lhs, const Node* rhs) const;
	// compares contents of the tree, returns true if equal, otherwise false
	int height(const NodeData& findLevel, const Node* subtree) const;
	// recursivly searches each half of tree for findLevel
	int heightHelper(const Node* subtree) const;
	// finds the height of the node, 1 if leaf
	void inorderHelper(NodeData* treeArr[], const Node* subtree, int& index);
	// converts the tree to an array
	void sideways(Node* current, int level) const; 
	// provided in the bintree.cpp, helper for displaySideways()
};

#endif
