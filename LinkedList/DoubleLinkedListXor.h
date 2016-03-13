#pragma once
#include "Node.h"
/*
http://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/
*/
template <typename T>
	/*
	*	calculate the new next pointer of the node - xor between the prev and the next
	*/
	Node<T>* calculateNextNodeXorAddress(Node<T>* prev, Node<T>* next = nullptr)
	{
		Node<T>* temp = (Node<T>*)((unsigned int)(prev) ^ (unsigned int)(next));
		return temp;
	}

	template <typename T>
	//insert the node at front 
	void static insertNode(Node<T>** head, T data)
	{
		Node<T> newNode(data);

		/* calculate the address of the next node - which is the current head and Nullptr (it's tge bew gead)*/
		newNode.setNextNode(calculateNextNodeXorAddress(*head));

		/* incase the list is not null and the list is not empty - then we need to find the last node*/
		if (*head != nullptr)
		{
			Node<T>* nextNode = calculateNextNodeXorAddress((*head)->getNextNode()); // recieve the next node after the head
			(*head)->setNextNode(calculateNextNodeXorAddress(&newNode, nextNode));
		}

		*head = &newNode;
	}
	//TODO: need some fixing
	template <typename T>
	void static printXorLinkedList(Node<T>* head)
	{
		Node<T>* cursorNode = head;
		Node<T>* prevNode = nullptr;

		while (cursorNode != nullptr)
		{
			std::cout << cursorNode->getNodeValue() << "<<--";
			cursorNode = calculateNextNodeXorAddress(prevNode, cursorNode->getNextNode());
		}

		std::cout << std::endl;
	}

