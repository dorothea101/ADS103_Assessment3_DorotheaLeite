#include "BinaryMinHeap.h"

int BinaryMinHeap::leftChildIndex(int parent)
{
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}

int BinaryMinHeap::rightChildIndex(int parent)
{
    
}

int BinaryMinHeap::parentIndex(int child)
{
    
}

void BinaryMinHeap::heapifyup(int index)
{
}

void BinaryMinHeap::heapifydown(int index)
{
}

void BinaryMinHeap::Insert(Player element)
{
}

void BinaryMinHeap::DeleteMin()
{
}

Player BinaryMinHeap::ExtractMin()
{
    
}

void BinaryMinHeap::showHeap()
{
}

int BinaryMinHeap::Size()
{
    
}
