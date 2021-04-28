#pragma once
#include "BST.h"

//AVL is self balancing search tree
//AVL- Adelson, Velski  and Landis
class AVL : public BST
{
public:
	bool displayRotations = true;


	//works out height of sub tree
	int height(Node* node);

	//difference between left and right sub trees
	int difference(Node* node);



	//ROTATIONS
	//4 different types of rotations LL,RR, LR,RL
	//Return new parent of sub tree
	//parameter::Current parent of sub tree
	//Right child, right branch
	Node* RRrotation(Node* parent);
	//Left child,left branch
	Node* LLrotation(Node* parent);
	//left branch,RIGHT CHILD
	Node* LRrotation(Node* parent);
	//right branch,left CHILD
	Node* RLrotation(Node* parent);//GO AVL cpp

	//BALANCE FUNCTION/
	//balances a tree structure where parent is the middle top node
	//returns new parent after balancing(rotations)
	Node* balance(Node* parent);



	//INSERT( THEN CHECKS)THE HEIGHT OF THE 2 SUB TREES and works out difference if it 
	//needs to balance them balance does rotations, so insert does everything
	//Recursive insert that considers parent a sub tree
	//This insert also balances itself
	//returns the new root node of the tree
	Node* insertAVL(Node* parent, Node* newNumber);

	//So build is backwards!!!!

	//OVERIDING insert from parent
	void insert(Node* newNumber);
};

