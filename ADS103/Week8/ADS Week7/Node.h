#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int ID;
	string name;
	Node* leftChild;
	Node* rightChild;

	Node(int ID, string name);
};

