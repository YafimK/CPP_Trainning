

#include "LinkedList.h"
#include "LinkedListAlgo.h"
#include "DoubleLinkedListXor.h"
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
	std::cout<<"the list is cyclic: "<<tempTestResult<<std::endl;
	Node<int>* tempCursorNode = sample1.findLastNode();
	tempCursorNode->setNextNode(cursorNode);
	tempTestResult = temp.isListCyclic(sample1);
	std::cout<<"the list is cyclic: "<<temp.isListCyclic(sample1) << std::endl;

	//test the xor linked list
	/* Create following Doubly Linked List
	head-->40<-->30<-->20<-->10   */
	Node<int> *head = NULL;
	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);
	insertNode(&head, 40);

	// print the created list
	printXorLinkedList(head);


	return 0;

}
