#include <iostream>
#include <string>
#include "BST.h"   //1
#include "AVL.h"

using namespace std;

void main() {
	//ok lets build a search tree
	BST bst1;  //2
	/*StudentNode* sNodePtr = new StudentNode(123, "asasd");//4 this will dynamicallybuild a student for me in RAM
	//give back my memory address and point to that
	bst1.insert(sNodePtr);   //now i want to insert student, but it takes a student pointer,//3 //5
		//now there are 2 ways i can go about this*/
	bst1.insert(new Node(3433, "Jeff"));
	bst1.insert(new Node(2222, "Bill"));
	bst1.insert(new Node(1221, "Trevor"));
	bst1.insert(new Node(4533, "Uncle"));
	bst1.insert(new Node(3333, "Adam"));
	bst1.insert(new Node(6666, "Bridge"));
	bst1.insert(new Node(7777, "Bam"));
	bst1.insert(new Node(4343, "Bucket"));





	cout << "Try finding student matching id 1221..." << endl;
	Node* sPtr = bst1.search(1221, true);// i put true, because I want a search path

	if (sPtr == NULL) //THIS IS IF IT DOESNT FIND IT OR MY TREE IS EMPTY
		cout << "Cannot find a student matching id 1221" << endl;
	else
		cout << "Found " << sPtr->name << " with id 1221" << endl;



	//now lastly go to BST.cpp

	cout << "Students inorder Traversal" << endl;
	cout << " ========================== " << endl;
	bst1.inOrderTraversal(bst1.root);


	cout << "Students preorder Traversal" << endl;
	cout << " ========================== " << endl;
	bst1.preOrderTraversal(bst1.root);


	cout << "Students postorder Traversal" << endl;
	cout << " ========================== " << endl;
	bst1.postOrderTraversal(bst1.root);


	cout << endl << endl;
	cout << "AVL" << endl;
	cout << "===" << endl;

	AVL avl1;
	avl1.displayRotations = true;
	avl1.insert(new Node(2333, "Jeff"));
	avl1.insert(new Node(2222, "Bill"));
	avl1.insert(new Node(1221, "Trevor"));
	cout << "Tree height thus far: " << avl1.height(avl1.root) << endl;
	avl1.insert(new Node(4533, "Uncle"));
	avl1.insert(new Node(3333, "Adam"));
	avl1.insert(new Node(6666, "Bridge"));
	avl1.insert(new Node(7777, "Bam"));
	avl1.insert(new Node(4343, "Bucket"));
	cout << "AVL ROOT: " << avl1.root->name << "  " << avl1.root->ID << endl;
	cout << "Students AVL inorder transversal" << endl;
	cout << "================================" << endl;
	avl1.inOrderTraversal(avl1.root);




	cout << "try to find student matching id 4343..." << endl;
	Node* sPtr2 = avl1.search(4343, true);
	if (sPtr != NULL)
		cout << "Found" << sPtr2->name << " with id 4343" << endl;
	else
		cout << "Cannot find id 4343 in avl1 tree" << endl;




	system("pause");
}