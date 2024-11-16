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

	TranNode& findSmallest() {
		if (!root) {
			throw std::runtime_error("Tree empty!");
		}
		Node* curr = root;
		while (curr->getLchi()) {
			curr = curr->getLchi();
		}
		TranNode* nodeT = dynamic_cast<TranNode*>(curr);
		if (!nodeT)throw std::runtime_error("Node is not TranNode");
		return *nodeT;
	}

	TranNode& findLargest() {
		if (!root) {
			throw std::runtime_error("Tree empty!");
		}
		Node* curr = root;
		while (curr->getRchi()) {
			curr = curr->getRchi();
		}
		TranNode* nodeT = dynamic_cast<TranNode*>(curr);
		if (!nodeT)throw std::runtime_error("Node is not TranNode");
		return *nodeT;
	}



	~BST() {
		cout << "\nDestroying Tree...\n";
		destroyTree(root);
	}



private:
	Node* root;
	//using dynamic_cast to access information inside TranRoot:
	
	Node* insert(Node*& root, const string& data, int n) {

		if (root == nullptr) {
			//cout << "inserting node containing: " << data << ", " << n << std::endl;
			root = new TranNode(data, n);
			return root;
		}

		//using dynamic_cast to access information inside TranRoot:
		TranNode* nodeT = dynamic_cast<TranNode*>(root);

		if (n < nodeT->getUnits()) {
			root->setLchi(insert(root->getLchi(), data, n));
		} else {
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

