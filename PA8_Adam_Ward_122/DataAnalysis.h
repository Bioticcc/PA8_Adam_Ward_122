#pragma once
#include "BST.h"
#include "Header.h"
class DataAnalysis
{
private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream myCsvStream;

	void openCsv() {
		myCsvStream.open("data.csv", std::ios::in);
		if (!myCsvStream.is_open()) {
			cout << "\n FILE FAILED TO OPEN \n";
		}
		else cout << "\n File succesfully opened!\n";
	}

	void split(const string& units, const string& item, const string& transactionType) {
		if (transactionType == "Purchased") {
			mTreePurchased.insert(item, stoi(units));
			return;
		}
		else if (transactionType == "Sold") {
			mTreeSold.insert(item, stoi(units));
			return;
		}
	}

	void parse() {
		string units, item, transactionType;
		getline(myCsvStream, units, ',');
		getline(myCsvStream, item, ',');
		getline(myCsvStream, transactionType, '\n');
		split(units, item, transactionType);
	}

	void readCsv() {
		openCsv();
		while (!myCsvStream.eof()) {
			parse();
		}
		cout << "\n|---Purchased-->\n";
		cout << "|Item|Unit\n";
		mTreePurchased.inOrderTraversal();
		cout << "\n|-----Sold----->\n";
		cout << "|Item|Unit\n";
		mTreeSold.inOrderTraversal();
	}

	void printTrends() {
		cout << "\n\n|----Trends---->\n";
		cout << "Least Purchased Item: " << mTreePurchased.findSmallest().getData() << "|" << mTreePurchased.findSmallest().getUnits() << endl;
		cout << "Most Purchased Item: " << mTreePurchased.findLargest().getData() << "|" << mTreePurchased.findLargest().getUnits() << endl;
		cout << "Least Sold Item: " << mTreeSold.findSmallest().getData() << "|" << mTreeSold.findSmallest().getUnits() << endl;
		cout << "Most Sold Item: " << mTreeSold.findLargest().getData() << "|" << mTreeSold.findLargest().getUnits() << endl;
	}


public:

	DataAnalysis() {}
	
	void runAnalysis() {
		readCsv();
		printTrends();
	}
};

