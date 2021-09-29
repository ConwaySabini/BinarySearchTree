// ---------------------------- mydriver.cpp ----------------------------------

// @author Sabini Ethan 343

// @date January 25, 2020

// @modified January 31, 2020

// ----------------------------------------------------------------------------

// This driver tests all methods and operators in the BinTree class.

// ----------------------------------------------------------------------------
/*
#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;

const int ARRAYSIZE = 100;


//global function prototypes
void buildTree(BinTree&, ifstream&);      // inserts nodes into tree from file
void initArray(NodeData* []);             // initialize array to NULL


int main() {
	// open file containing data for tree
	ifstream infile("inputfile.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	NodeData ayeND("aye");
	NodeData whatND("what");
	NodeData yesND("yes");
	NodeData coolND("cool");
	NodeData okayND("okay");
	NodeData nahND("nah");
	NodeData punND("pun");
	NodeData vvvvND("vvvv");
	NodeData oND("o");
	NodeData ooND("oo");
	NodeData lND("l");
	NodeData xND("x");
	NodeData yND("y");

	BinTree T, T2, dup;
	NodeData* ndArray[ARRAYSIZE];
	initArray(ndArray);
	cout << "Initial data:" << endl << "  ";
	buildTree(T, infile);              // builds and displays initial data
	cout << endl;
	BinTree first(T);					// test copy constructor
	dup = dup = T;					// test assignment operator

	while (!infile.eof()) {
		cout << "Tree Inorder:" << endl << T;           // operator<< does endl
		T.displaySideways();

		// test retrieve 
		NodeData* p;                    // pointer of retrieved object
		bool found;                  // whether or not object was found in tree
		found = T.retrieve(ayeND, p);
		cout << "Retrieve --> aye:  " << (found ? "found" : "not found") 
			<< endl;
		found = T.retrieve(yesND, p);
		cout << "Retrieve --> yes:  " << (found ? "found" : "not found") 
			<< endl;
		found = T.retrieve(punND, p);
		cout << "Retrieve --> pun:  " << (found ? "found" : "not found") 
			<< endl;

		// test getHeight 
		cout << "Height    --> aye:  " << T.getHeight(ayeND) << endl;
		cout << "Height    --> what:  " << T.getHeight(whatND) << endl;
		cout << "Height    --> o:  " << T.getHeight(oND) << endl;
		cout << "Height    --> oo:  " << T.getHeight(ooND) << endl;
		cout << "Height    --> vvvv:  " << T.getHeight(vvvvND) << endl;
		cout << "Height    --> y:  " << T.getHeight(yND) << endl;

		// test ==, and != 
		T2 = T;
		cout << "T == T2?     " << (T == T2 ? "equal" : "not equal") << endl;
		cout << "T != first?  " << (T != first ? "not equal" : "equal") 
			<< endl;
		cout << "T == dup?    " << (T == dup ? "equal" : "not equal") << endl;
		dup = T;

		// test bstreeToArray and arrayToBSTree
		T.bstreeToArray(ndArray);
		T.arrayToBSTree(ndArray);
		T.displaySideways();

		T.makeEmpty();                  // empty out the tree
		initArray(ndArray);             // empty out the array

		cout << "-------------------------------------------------------------"
			<< endl;
		cout << "Initial data:" << endl << "  ";
		buildTree(T, infile);
		cout << endl;
	}
	
	return 0;
}


//------------------------------- buildTree ----------------------------------
// Inserts characters from file as nodes in the tree. 
// Each space in between characters will invoke another insert.
// To build a tree, read strings from a line, terminating when "$$" is
// encountered. Since there is some work to do before the actual insert that is
// specific to the client problem, it's best that building a tree is not a 
// member function. It's a global function.
// Preconditions: Create tree and pass it as argument. 
// Create file with correct formatting and open it.
// Postconditions: Tree is filled with values from the text file.


void buildTree(BinTree& T, ifstream& infile) {
	string s;

	for (;;) {
		infile >> s;
		cout << s << ' ';
		if (s == "$$") break;                // at end of one line
		if (infile.eof()) break;             // no more lines of data
		NodeData* ptr = new NodeData(s);   // NodeData constructor takes string
		// would do a setData if there were more than a string

		bool success = T.insert(ptr);
		if (!success)
			delete ptr;                       // duplicate case, not inserted 
	}
}

//------------------------------- initArray ----------------------------------
// Initialize the array of NodeData* to NULL pointers.
// Preconditions: Create array and pass it as argument.
// Postconditions: array values are null.

void initArray(NodeData* ndArray[]) {
	for (int i = 0; i < ARRAYSIZE; i++)
		ndArray[i] = NULL;
}

*/