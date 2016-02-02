

#include "LinkedList.h"
#include "LinkedListAlgo.h"
#include <iostream>

int main(void)
{
	LinkedList<int> sample1{};
	for(int i = 0; i<=50; i++)
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
}
