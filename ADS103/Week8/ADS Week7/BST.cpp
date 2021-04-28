#include "BST.h"

void BST::insert(Node* newNumber)
{
	//If the root is NULL(tree is empty),then make this student the root;;
	if (root == NULL)
	{
		root = newNumber;
		return; //exit function early, we are done here
	}
	//So if we are not done
	//we need some pointers to help us navigate the tree to find where to put the new student
	//We have studentNode pointer
	Node* current = root; //current to the current one it points at, current one pointing at
	//USE CURRENT TO CHOOSE TO MOVE DOWN TO THE LEFT OR THE RIGHT, DEPENDING ON the data inside things
	Node* parent = NULL; //Parent of current node, KEEP TRACK OF PARENT

	while (true)//this is an infinite loop, WE WILL BREAK OUT A DIFFRENT WAY
	{
		//Lets keep track of where we were before moving down further
		parent = current;
		//now go left or  right ??!which way do we go down
		//IF NEW STUDENTS studentID IS LESS THAN THE STUDENT AT THE CURRENT NODE, then go DOWN LEFT
		if (newNumber->ID < current->ID) //comparing newstudent against current student(((LESS THAN))))
		{
			//< means we go down deeper into tree on left side
			current = current->leftChild;
			//if current is NULL, we just found an empty space to insert our new student
			if (current == NULL)
			{
				//DONE, STICK STUDENT HERE, and my structure knows about it, we have parent pointing to newStudent, where we put them in
				parent->leftChild = newNumber;
				return;//done,bail out



			}

		}

		//Now what if current student is (((((GREATER THAN OR EQUAL))))))
		else
		{
			//go down RIGHT PATH AND THEREFORE CURRENT IS EQUAL TO 
			current = current->rightChild;
			//if current is NULL, insert there
			if (current == NULL)
			{
				parent->rightChild = newNumber;
				return;
			}

		}
	}
}



//now what does search do, search checks at the root, if the root is null, it will return null, nothing to find
//OTHERWISE IF IT FOUND IT AT ROOT, IF IT DIDNT, JUST KEEP GOING DOWN LEFT AND RIGHT, TILL YOU FIND IT 
//OR YOU RUN OUT OF NODES TO CHECK,AND THEN YOU HAVE TO REPORT IT AS NOT FOUND AS WELL
Node* BST::search(int ID, bool showSearchPath)
{
	/*return nullptr;*/
	//if tree empty, cant find student matching studentID
	if (root == NULL)//does it ==NULL, DO SOMETHING WITH IT
	{
		return NULL;

	}
	//REMEMBER WHEN WE ARE Inserting we have to keep track of parent, and current,
	// but when searching for stuff, we only have to keep track of current
	//So lets go steal this line of code( StudentNode* current = root; )
	Node* current = root;// now this is the line of code we stole

	while (current->ID != ID)
		//while current studentid is not equal to my studentid keep looping
		//until i find a match(30:35/46:09)
		//now lets check this thing out
	{
		//If current is equal to null, search was unsuccessful, searchID could not be found
		//then just, return NULL


		if (showSearchPath)//IS TRUE,THEN COUT ,only if this is to true, that you will see this line
			cout << current->ID << " " << current->ID << endl;

		//havn't found it yet,lefts explore left or right down the tree
		//So do we go left or right?
		if (ID < current->ID)
		{
			//go left, everything is smaller 
			current = current->leftChild; //hey buddy youre pointing at some sort of node in the tree
			//i want you to point at  whatever that nodes left, child pointer thiny is pointing at
			//thats how we can move it down(34:46/46:09)just updating
		}
		else  //we havnt found it yet, so we are either going to go left or right
		{
			//go right
			current = current->rightChild;
			//it will keep looping till it finds a match
			//so once it finds a match, it will break out of the loop and return
		}
		if (current == NULL)
		{
			return NULL;
		}
	}

	return current;//should be pointing at the match in tree :D
	//now lets test this stuff out, go to source.cpp
}

//got this one node and it explores down the left, then it outputs itself //9 then explores down right//7
//outputs tree in ascending order
void BST::inOrderTraversal(Node* current)
{
	//the if statement here helps us to break out of the infinite loop cycle
	//current == null is the end of the branch path, this 'if' stops from infinite looping
	if (current != NULL)
	{
		//smallest to largest
		inOrderTraversal(current->leftChild);  //line a
		cout << current->ID << " " << endl;//9
		inOrderTraversal(current->rightChild); //7//and line b

	}
}//to make this function go biggest to smallest,reverse line a and b

//go to source.cpp


void BST::preOrderTraversal(Node* current)//OUTPUT ME, THEN GO LEFT, THEN GO RIGHT
{
	if (current != NULL)
	{

		cout << current->ID << " " << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}
}

void BST::postOrderTraversal(Node* current)
{
	if (current != NULL)
	{
		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->ID << " "  << endl;
	}

}//now go back to source.cpp

/*void preOrderTraversal(StudentNode* current)
{
}

void postOrderTraversal(StudentNode* current)
{
}*/
