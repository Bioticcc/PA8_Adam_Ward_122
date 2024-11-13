#include "Header.h"
#include "BST.h"
#include "TranNode.h"
#include "Node.h"


int main() {

	/*
	- 2 BSTS, one representing products sold, one representing products purchased
	- Okay, so when we begin you need to search for a few things:
		- Abstraction in nodes?
		- Inheritance in C++ classes?
		- Public inheritance?
		- Protected class data?
		- virtual contstructors?
		- pure virtual member functions?
	- Abstract class Node
	- Class TransactionNode witch inherits Node
	- 
	*/

	BST T;
	T.insert("one", 1);
	T.insert("two", 2);
	T.insert("three", 3);
	T.insert("four", 4);
	T.insert("five", 5);
	T.inOrderTraversal();

}
