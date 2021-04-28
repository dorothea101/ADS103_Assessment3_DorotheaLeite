#pragma once
#include <queue>
#include "Node.h"




//ADDAED THIS!!!!!!!

//HELPER CLASS FOR OUTPUT
class LevelNode {
public:
	Node* number;
	int level;

	//constructor
	LevelNode(Node* number, int level)
	{
		this->number = number;
		this->level = level;
	}




};
//BST- is a Binary Search Tree
//Root node sort of acting as center
// EVERYTHING SMALLER THAN ROOT, IS SORTED TO THE LEFT BRANCH SOMEWHERE
//EVERYTHING ELSE TO THE RIGHT
class BST
{
public:
	Node* root = NULL;
	virtual void insert(Node* newNumber); //hover over insert to openBST.CPP
	Node* search(int ID, bool showSearchPath = false);

	void inOrderTraversal(Node* current);
	void preOrderTraversal(Node* current);
	void postOrderTraversal(Node* current);
	//hover over search


	//ADDED THIS AS WELL!!!!!
	//show
	void show(Node* p);
};

//Recursive Traversal functions
/*void inOrderTraversal(StudentNode* current);
void preOrderTraversal(StudentNode* current);
void postOrderTraversal(StudentNode* current);*/