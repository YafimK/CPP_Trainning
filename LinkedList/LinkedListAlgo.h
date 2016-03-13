#pragma once
/*
*Diffrent Linked List algoritms impl'
*/
#include "LinkedList.h"
template <typename T>
class LinkedListAlgo
{	public:
	LinkedListAlgo(){};
	/*
	* Find the M'th item from the end of the list.
	* (In case it's a single linked list without size variable.)
	* we will find it linearly with two pointers (one that's m steps away
	* from the start)
	*/
	static Node<T>* findMthToLastElemLineary(LinkedList<T>& targetList, int mthItemNumber);
	/*
	* it will be a turtle rabbit algo impl' in order to check if the list is cyclic
	* This will take O(3N/2)->>O(N) at most
	*/
	static bool isListCyclic(LinkedList<T>& targetList);
	
};

template <typename T>
Node<T>* LinkedListAlgo<T>::findMthToLastElemLineary(LinkedList<T>& targetList, int mthItemNumber) {
	if(targetList.getHeadNode() == nullptr)
	{
		throw new std::exception("empty list or list's head is nullptr");

	}
	if( mthItemNumber < 0)
	{
		throw new std::exception("m'th item number should be positive");
	}

	Node<T>* mthNodePointer = targetList.getHeadNode();
	Node<T>* cursorNode = targetList.getHeadNode();
	int cursorNodeIndex = 0;
	int mthNodePointerIndex = 0;

	while(cursorNode->getNextNode() != nullptr)
	{
		if(mthItemNumber <= (cursorNodeIndex-mthNodePointerIndex))
		{
			mthNodePointer = mthNodePointer->getNextNode();
			mthNodePointerIndex++;
		}
		cursorNodeIndex++;
		cursorNode = cursorNode->getNextNode();
	}

	if((cursorNodeIndex-mthNodePointerIndex)!=mthItemNumber)
	{
		throw new std::exception("the list is shorter than the provided item number");
	}
	return mthNodePointer;

}

template <typename T>
bool LinkedListAlgo<T>::isListCyclic(LinkedList<T>& targetList)
{
	if(targetList.getHeadNode()->getNextNode() == nullptr)
	{
		return false;
	}
	
	Node<T>* turtuNode = targetList.getHeadNode();
	Node<T>* rabbitNode = turtuNode->getNextNode();

	while(rabbitNode != nullptr && rabbitNode->getNextNode() != nullptr)
	{
		if(turtuNode == rabbitNode)
		{
			return true;
		}
		turtuNode = turtuNode->getNextNode();
		rabbitNode = rabbitNode->getNextNode()->getNextNode();
	}

	return false;
}
