#pragma once
#include<iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "Player.h"


using namespace std;

class BinaryMinHeap
{
public:
	vector<Player>heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyup(int index);
	void heapifydown(int index);

	void Insert(Player element);
	void DeleteMin();
	Player ExtractMin();
	void showHeap();//just dumps out whats in the array
	int Size();
};

