#pragma once
#include "Header.h"

class Node
{
public:

	Node(string str) : data(str), Rchi(nullptr), Lchi(nullptr) {}

	string getData() { return data; }
	Node*& getLchi()  { return Lchi; }
	Node*& getRchi()  { return Rchi; }
	void setData(string str) { data = str; }
	void setLchi(Node* ptr) { Lchi = ptr; }
	void setRchi(Node* ptr) { Rchi = ptr; }
	virtual void printData() = 0;
	virtual ~Node() { 
		//cout << "deconstructing Node\n"; 
		}

protected:
	string data;
	Node* Lchi;
	Node* Rchi;
};

