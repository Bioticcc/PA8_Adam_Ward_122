#pragma once
#include "Node.h"

class TranNode : public Node
{
public:

	TranNode(string str, int n) : Node(str), units(n) {}

	int getUnits() { return units; }
	void setUnits(int n) { units = n; }
	void printData() { 
		//cout << "\nTESTING TESTING\n";
		cout << "Data: " << getData() << "|Units: " << units << std::endl; 
	}

	~TranNode() {
		//cout << "deconstructing TranNode\n";
		}
private:
	int units;
};

