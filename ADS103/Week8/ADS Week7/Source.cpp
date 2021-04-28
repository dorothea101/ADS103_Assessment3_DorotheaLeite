#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"   //1
#include "AVL.h"

using namespace std;

void main() {


	//THIS JUST READ THE FIRST NUMBER!!!!!!!(this will be the first number-telling you how many NumberOfNumbers
	ifstream readFile;  //To read from a file
	readFile.open("input-q1a2.txt"); //to open the input file
	int numberOfNumbers;         // we create this int to store the numberOfNumbers  //WE HAVE CALLED THIS NUMBER OFNUMBERS, BECAUSE THIS IS THE AMOUNT OF NUMBERS WILL BE GIVEN
	readFile >> numberOfNumbers;    //here it is reading from the file

	//ok lets build a search tree
	BST bst1;  //2
	/*StudentNode* sNodePtr = new StudentNode(123, "asasd");//4 this will dynamicallybuild a student for me in RAM
	//give back my memory address and point to that
	bst1.insert(sNodePtr);   //now i want to insert student, but it takes a student pointer,//3 //5
		//now there are 2 ways i can go about this*/
	/*bst1.insert(new Node(3433));// "Jeff"));
	bst1.insert(new Node(2222)); //"Bill"));
	bst1.insert(new Node(1221)); //"Trevor"));
	bst1.insert(new Node(4533));//"Uncle"));
	bst1.insert(new Node(3333));// "Adam"));
	bst1.insert(new Node(6666));// "Bridge"));
	bst1.insert(new Node(7777));
	bst1.insert(new Node(4343));*/


	
	//HERE WE JUST BUILT A AVL TREE AND CALLED avl2 (.......1......)//WE DID THIS BY SIMPLY AVL(type) and avl2(its name)
	AVL avl2;                                




	//THIS IS INSERTING NUMBERS INTO THE TREE
	//-outside is the loop-for(inti=0;i is less than all the numbrs, meaning you can only loop as many times as is allowed
	//- inside what does it do
	//it creates a storage place first (int AnumberOfNumbers)
	//-it reads this first number, in order, one at a time
	//- then it inserts this number, into the tree, by way of new Node( and its called

	for (int i = 0; i < numberOfNumbers; i++)  //////(>>>>>THIS IS A LOOP, THAT WILL DO SOMETHING A CERTAIN AMOUNT OF TIMES= NOofNumbers>>>>>)
	{                     //we call it int because it is reading in numbers //(>>>>>>we know the amount of numbers, by numberOfNumbers>>>>>>>)
		int AnumberOfNumbers;    //here we are inserting one number, thats why i call it AnumberOfNumbers  //what do i do once Ive read the number?( i insert the number, into  the tree
		readFile >>  AnumberOfNumbers;     //So each time through the loop it reads only one number at a time

		avl2.insert(new Node(AnumberOfNumbers));                     // avl2 is our tree that we will insert a new Node into, which is called AnumberOfNumbers, 
		//because it is one, numberOfNumbers
		


	}
	//NOW WE WRITE, BUT WHERE AND WHY?
	
	bst1.show(bst1.root);



	cout << "Try finding student matching id 1221..." << endl;
	Node* sPtr = bst1.search(1221, true);// i put true, because I want a search path

	if (sPtr == NULL) //THIS IS IF IT DOESNT FIND IT OR MY TREE IS EMPTY
		cout << "Cannot find a student matching id 1221" << endl;
	else
		cout << "Found " << " with id 1221" << endl;



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
	avl1.insert(new Node(2333));
	avl1.insert(new Node(2222));
	avl1.insert(new Node(1221));
	cout << "Tree height thus far: " << avl1.height(avl1.root) << endl;
	avl1.insert(new Node(4533));
	avl1.insert(new Node(3333));
	avl1.insert(new Node(6666));
	avl1.insert(new Node(7777));
	avl1.insert(new Node(4343));
	cout << "AVL ROOT: " << "  " << avl1.root->ID << endl;
	cout << "Students AVL inorder transversal" << endl;
	cout << "================================" << endl;
	avl1.inOrderTraversal(avl1.root);




	cout << "try to find student matching id 4343..." << endl;
	Node* sPtr2 = avl1.search(4343, true);
	if (sPtr != NULL)
		cout << "Found" << " with id 4343" << endl;
	else
		cout << "Cannot find id 4343 in avl1 tree" << endl;


	bst1.show(bst1.root);

	system("pause");
}