#pragma once
#include "Header.h"
#include "TranNode.h"

class BST
{
public:

	BST() : root(nullptr) {}

	Node* getRoot() { return root; }
	void setRoot(Node* ptr) { root = ptr; }

	Node* insert(string data, int n) {
		return insert(root, data, n);

	}

	void  inOrderTraversal() {
		printTree(root);
	}

	~BST() {
		cout << "\nDestroying Tree...\n";
		destroyTree(root);
	}

private:
	Node* root;
	//using dynamic_cast to access information inside TranRoot:
	
	Node* insert(Node*& root, string data, int n) {

		if (root == nullptr) {
			cout << "inserting node containing: " << data << ", " << n << std::endl;
			TranNode* newNode = new TranNode(data, n);
			return newNode;
		}

		//using dynamic_cast to access information inside TranRoot:
		Node* Lchi = root->getLchi();
		Node* Rchi = root->getRchi();
		TranNode* nodeT = dynamic_cast<TranNode*>(root);
		TranNode* LchiT = dynamic_cast<TranNode*>(Lchi);
		TranNode* RchiT = dynamic_cast<TranNode*>(Rchi);

		/*
		if (root->getData() < root->getLchi()->getData()) {  
 			root->setLchi(insert(root->getLchi(), data, n));
		}
		if (root->getData() > root->getRchi()->getData()) {
			root->setRchi(insert(root->getRchi(), data, n));
		}
		*/
		if (n < LchiT->getUnits()) {
			root->setLchi(insert(root->getLchi(), data, n));
		}
		if (n > RchiT->getUnits()) {
			root->setRchi(insert(root->getRchi(), data, n));
		}
		return root;
	}

	void printTree(Node*& root) {
		if (!root)return;
		printTree(root->getLchi());
		TranNode* nodeT = dynamic_cast<TranNode*>(root);
		nodeT->printData();
		printTree(root->getRchi());
	}

	void destroyTree(Node* root) {
		if (!root) { return; }
		destroyTree(root->getLchi());
		destroyTree(root->getRchi());
		delete root;
	}





};

