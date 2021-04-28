#include "AVL.h"



//using recursion, we keep exploring down. and pass final height values up
int AVL::height(Node* node)
{
    int h = 0;


    //Helps break recursion cycle, when we get to 
    //nulls at the bottom of branches
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);


        //max gets biggest of the 2 and discards the smaller
        int maxH = max(leftH, rightH);
        h = maxH + 1;

    }
    return h;


}

int AVL::difference(Node* node)
{
    // if empty tree, well its balanced, its 0
    if (node == NULL)
        return 0;
    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

Node* AVL::RRrotation(Node* parent)//A
{
    Node* temp = parent->rightChild;//B
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;//SETTING IT TO OLD PARENT
    if (displayRotations)
        cout << "RR rotation on " << parent->name << endl;

    return temp;

}

Node* AVL::LLrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotations)
        cout << "LL rotation on " << parent->name << endl;

    return temp;


}


//NB needs 2 rotations
//first rotation rotates  bottom 2 nodes
//which turns the whole structure into a RR rotation
//2 nd rotation uses RRrotation
Node* AVL::LRrotation(Node* parent)
{
    Node* temp = parent->leftChild;//B
    parent->leftChild = RRrotation(temp);
    if (displayRotations)
        cout << "LR rotation on " << parent->name << endl;
    return LLrotation(parent);


}

Node* AVL::RLrotation(Node* parent)
{
    Node* temp = parent->rightChild;//B
    parent->rightChild = LLrotation(temp);
    if (displayRotations)
        cout << "RL rotation on " << parent->name << endl;
    return RRrotation(parent);

}

Node* AVL::balance(Node* parent)
{
    //GET balance factor
    int balanceFactor = difference(parent);
    //IF balancefactor not within -1, 0, 1 , then lets work out what rotations to do
    if (balanceFactor > 1)
    {

        //left branch is heavy, now work out is left or right child heavy
        if (difference(parent->leftChild) > 0)
        {

            //left child unbalanced
            parent = LLrotation(parent);


        }
        else
        {
            //Right child unbalanced
            parent = LRrotation(parent);
        }



    }
    else if (balanceFactor < -1)
    {

        //Right branch is heavy, but which child
        if (difference(parent->rightChild) > 0)
        {
            //Left child heavy
            parent = RLrotation(parent);
        }
        else
        {
            //right child heavy
            parent = RRrotation(parent);

        }




    }
    return parent;

}

Node* AVL::insertAVL(Node* parent, Node* newNumber)//where to put new node
{
    //if sub tree empty this becomes the parent
    if (parent == NULL)
    {
        parent = newNumber;

        return parent;
    }

    //PARENT NOT NULL, so we havn't found an empty space to stick new student yet
    //So we need to go down either right or left path
    if (newNumber->ID < parent->ID)
    {
        parent->leftChild = insertAVL(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else //assume id>= parent's id
    {
        parent->rightChild = insertAVL(parent->rightChild, newNumber);
        parent = balance(parent);

    }
}

void AVL::insert(Node* newNumber)
{
    cout << "Inserting  " << newNumber->name << newNumber->ID << endl;
    root = insertAVL(root, newNumber);
    cout << endl;
}
