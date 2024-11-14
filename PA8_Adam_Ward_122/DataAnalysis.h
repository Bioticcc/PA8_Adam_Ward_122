#pragma once
#include "BST.h"
#include "Header.h"

class DataAnalysis
{
private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream inputCsv;
public:

	DataAnalysis(std::ifstream&& myCsvStream) : inputCsv(std::move(myCsvStream)) {}

	void readCsv() {
		
	}
};

