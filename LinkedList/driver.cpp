

#include "LinkedList.h"
#include "LinkedListAlgo.h"
#include <iostream>

int main(void)
{
	LinkedList<int> sample1{};
	for(int i = 0; i<=10; i++)
	{
		sample1.insertNode(i);
	}
	
	sample1.printLinkedList();

	LinkedListAlgo<int> temp{};

	// test mthElement from the end search algo
	const int mthElement = 5;
	Node<int>* cursorNode = temp.findMthToLastElemLineary(sample1, mthElement);
	std::cout<<cursorNode->getNodeValue();
	std::cout<<" is the "<<mthElement<<" mth element from the end"<<std::endl;

	 //test the is linkedlist cyclic checker
	bool tempTestResult = false;
	tempTestResult = temp.isListCyclic(sample1);
	std::cout<<"the list is cyclic: "<<tempTestResult;
	Node<int>* tempCursorNode = sample1.findLastNode();
	tempCursorNode->setNextNode(cursorNode);
	tempTestResult = temp.isListCyclic(sample1);
	std::cout<<"the list is cyclic: "<<temp.isListCyclic(sample1);
}
