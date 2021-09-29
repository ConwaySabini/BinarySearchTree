#include "bintree.h"

BinTree::BinTree() { // default constructor
	root = new Node();
}

BinTree::BinTree(const BinTree& tree) { // copy constructor creates deep copy
	*this = tree;
}

BinTree::~BinTree() { // destructor
	empty(root);
}

//------------------------- isEmpty ---------------------------------
// Declares if the tree is empty or not. 
// Returns true if the tree is empty and false otherwise.
// Preconditions: Tree object created.
// Postconditions: None.
bool BinTree::isEmpty() const { // HOW TO CHECK FOR Deletion
	if (root == nullptr || root->data == nullptr) {
		return true;
	}
	return false;
}

//------------------------- makeEmpty ---------------------------------
// Empties the tree by deleting each node and data.
// Calls private helper method.
// Preconditions: Tree object created.
// Postconditions: All nodes and nodeData objects are deleted from the tree.
void BinTree::makeEmpty() {
	empty(this->root);
	this->root = nullptr;
}

//------------------------- insert ---------------------------------
// Inserts the NodeData argument at the correct spot in the binary search tree.
// Calls private helper method to traverse the tree recursively. 
// If there is duplicate or null data return false. If the node is inserted
// return true.
// Preconditions: Tree object created and data is not nullptr or a 
// duplicate value.
// Postconditions: The new Node is inserted with NodeData.
bool BinTree::insert(NodeData* data) {
	if (data == nullptr) {
		return false;
	}
	try {
		root = insert(data, root);
	}
	catch (exception e) { // if the data was a duplicate return false
		return false;
	}
	return true;
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//------------------------- retrieve ---------------------------------
// Calls the helper function to traverse the tree.
// Returns true if toFind is found and false otherwise.
// Preconditions: Create tree with parameter toFind data.
// Postconditions: found is changed to point to the data equal to toFind in
// the tree.
bool BinTree::retrieve(const NodeData& toFind, NodeData*& found) const {
	return retrieve(toFind, found, root);
}

//------------------------- retrieve ---------------------------------
// Traverses the tree to find the NodeData argument. If the data is found then
// the pointer to the data is stored in the found argument.
// Returns true if toFind is found and false otherwise.
// Preconditions: Call public retrieve method.
// Postconditions: found is changed to point to the data equal to toFind in
// the tree.
bool BinTree::retrieve(const NodeData& toFind, NodeData*& found,
	const Node* subtree) const {
	if (subtree == nullptr || subtree->data == nullptr) { // null case
		return false;
	}
	else if ((*subtree->data) == toFind) { // base case equal
		found = subtree->data;
		return true;
	}
	else if (toFind < *(subtree->data)) { // traverse left side
		if (subtree->left != nullptr) {
			return retrieve(toFind, found, subtree->left);
		}
	}
	else if (toFind > * (subtree->data)) { // traverse right side
		if (subtree->right != nullptr) {
			return retrieve(toFind, found, subtree->right);
		}
	}
	return false; // unable to find data
}

//------------------------- getHeight ---------------------------------
// Calls height helper method.
// Returns the height of the node if it is found and 0 otherwise. 
// Height is 1 for leaf nodes.
// Preconditions: Create tree with data equal to findLevel.
// Postconditions: None
int BinTree::getHeight(const NodeData& findLevel) const {
	if (this->isEmpty()) {
		return 0;
	}
	if (*(root->data) == findLevel) {
		return 1;
	}
	return height(findLevel, root);
}

//------------------------- bstreeToArray ---------------------------------
// Converts tree to array and empties the tree.
// Calls inorderHelper function to turn the tree into an array.
// Preconditions: Insert a node in the tree.
// Postconditions: Tree is emptied and all nodes are deleted.
// Array is filled with values from tree
void BinTree::bstreeToArray(NodeData* treeArr[]) {
	if (this->isEmpty()) {
		this->makeEmpty();
		return;
	}
	int index = 0;
	inorderHelper(treeArr, root, index);
	this->makeEmpty();
}

//------------------------- bstreeToArray ---------------------------------
// Calls arrayToTreeHelper function to set the root.
// Converts array to binary search tree and replaces values in array with null.
// balances the tree so that subtrees have no height difference greater than 1.
// Preconditions: Call bstreeToArray method to fill array with node data.
// Postconditions: tree is filled with values from the array and 
// array is filled with null.
void BinTree::arrayToBSTree(NodeData* treeArr[]) {
	if (!this->isEmpty()) {
		this->makeEmpty();
	}
	bool end = false;
	int size = 0;
	while (end == false) { // traverse array to determine size
		if (treeArr[size] == nullptr) {
			end = true;
		}
		else {
			size++;
		}
	}
	arrayToTreeHelper(treeArr, 0, size); // insert the nodes in BSTree
	while (size >= 0) { // traverse array to set values as nullptr
		treeArr[size] = nullptr;
		size--;
	}
}

//------------------------- operator= ---------------------------------
// Assigns argument tree to calling tree and creates a deep copy.
// Returns the calling tree.
// Preconditions: Assign a tree to another tree.
// Postconditions: Calling tree is filled with equal nodes from parameter tree.
BinTree& BinTree::operator=(const BinTree& rhs) {
	if (this == &rhs) { // self assignment
		return *this;
	}
	else if (rhs.isEmpty()) {
		this->makeEmpty();
		return *this;
	}
	else {
		this->makeEmpty();
		this->assign(rhs.root);
		return *this;
	}
}

//------------------------- operator== ---------------------------------
// Compares two tree objects for equality.
// Returns true if the trees are equal and false otherwise.
// Calls isEqual helper function.
// Preconditions: Compare two tree objects.
// Postconditions: None.
bool BinTree::operator==(const BinTree& rhs) const {
	if (this == &rhs) {
		return true;
	}
	if (this->isEmpty() && rhs.isEmpty()) {
		return true;
	}
	if (this->isEmpty() || rhs.isEmpty()) {
		return false;
	}
	return isEqual(root, rhs.root);
}

//------------------------- operator== ---------------------------------
// Compares two tree objects for equality.
// Returns false if the trees are equal and true otherwise.
// Calls isEqual helper function.
// Preconditions: Compare two tree objects.
// Postconditions: None.
bool BinTree::operator!=(const BinTree& rhs) const {
	if (*this == rhs) {
		return false;
	}
	if (this->isEmpty() && rhs.isEmpty()) {
		return false;
	}
	if (this->isEmpty() || rhs.isEmpty()) {
		return true;
	}
	return !isEqual(root, rhs.root);
}

//------------------------- arrayToTreeHelper ---------------------------------
// Inserts each NodeData from the treeArr array in the binary search tree.
// Preconditions: Call arrayToBSTree method with nodes in array.
// Postconditions: Every node from the array was inserted into the binary
// search tree.
void BinTree::arrayToTreeHelper(NodeData* treeArr[], int low, int high) {
	if (low > high) {
		return;
	}
	int mid = (low + high) / 2;
	insert(treeArr[mid]); // set the root as middle array value
	arrayToTreeHelper(treeArr, low, mid - 1);
	// traverse left side recursively with left half of array
	arrayToTreeHelper(treeArr, mid + 1, high);
	// traverse right side recursively with right half of array
	return;
}

//------------------------- empty ---------------------------------
// Empties the tree by deleting all nodes.
// Preconditions: Call makeEmpty method or destructor.
// Postconditions: All nodes and NodeData objects are deleted 
// and set to nullptr.
void BinTree::empty(Node* subtree) {
	if (subtree == nullptr) {
		return;
	}
	empty(subtree->left);
	empty(subtree->right);
	delete subtree->data;
	subtree->data = nullptr;
	delete subtree;
	subtree = nullptr;
}

//------------------------- assign ---------------------------------
// Assigns the argument tree to the calling tree by inserting each node.
// Preconditions: Call the assignment operator on two tree objects.
// Postconditions: Creates a deep copy of argument tree by inserting nodes.
void BinTree::assign(const Node* source) {
	NodeData* copy = new NodeData();
	*copy = *source->data;
	this->insert(copy);
	if (source->left != nullptr) { // traverse left side if possible
		assign(source->left);
	}
	if (source->right != nullptr) { // traverse right side if possible
		assign(source->right);
	}
}

//------------------------- isEqual ---------------------------------
// Compares two tree objects for equality.
// Returns true if the trees are equal and false otherwise.
// Preconditions: Compare two tree objects.
// Postconditions: None.
bool BinTree::isEqual(const Node* lhs, const Node* rhs) const {
	if (lhs == nullptr && rhs == nullptr) { // null case
		return true;
	}
	else if (lhs == nullptr || rhs == nullptr) { // null case
		return false;
	}
	else if (*lhs->data == *rhs->data && isEqual(lhs->left, rhs->left) && 
		(isEqual(lhs->right, rhs->right))) { 
		// Checks left and right subtrees for equality
		return true;
	}
	return false;
}

//------------------------- height ---------------------------------
// Calls heightHelper method.
// Traverses the tree to find the findLevel argument. If the data is found then
// it calls helper function to determine the height of the node.
// Returns the height of the node if it is found and 0 otherwise. 
// Height is 1 for leaf nodes.
// Preconditions: Call getHeight method.
// Postconditions: None
int BinTree::height(const NodeData& findLevel, const Node* subtree) const {
	if ((*subtree->data) == findLevel) { // found
		return heightHelper(subtree);
	}
	if (*subtree->data > findLevel) { // traverse left
		if (subtree->left != nullptr) {
			return height(findLevel, subtree->left);
		}
	}
	else if (*subtree->data < findLevel) { // traverse right
		if (subtree->right != nullptr) {
			return height(findLevel, subtree->right);
		}
	}
	return 0;
}

//------------------------- height ---------------------------------
// Traverses the subtree to find the height of the node. 
// Returns the height of the node.
// Preconditions: Call getHeight method and found node to determine height.
// Postconditions: None
int BinTree::heightHelper(const Node* subtree) const {
	if (subtree == nullptr) {
		return 0;
	}
	int rHeight = heightHelper(subtree->right); // traverse right side
	int lHeight = heightHelper(subtree->left); // traverse left side
	// return the larger of the two heights
	if (lHeight < rHeight) {
		return rHeight + 1;
	}
	return lHeight + 1;
}

//------------------------- inorderHelper ---------------------------------
// Recursivly calls itslef to to and inorder traversal of the tree to copy
// NodeData object to the array.
// Preconditions: Call bstreeToArray method.
// Postconditions: treeArr is filled with values from the tree. 
// Index is incremented.
void BinTree::inorderHelper(NodeData* treeArr[], const Node* subtree, 
	int& index) {
	if (subtree->left != nullptr) { // Traverse left if possible
		inorderHelper(treeArr, subtree->left, index);
	}
	NodeData* copy = new NodeData(*subtree->data);
	treeArr[index] = copy;
	index++;
	if (subtree->right != nullptr) { // Traverse right if possible
		inorderHelper(treeArr, subtree->right, index);
	}
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}



