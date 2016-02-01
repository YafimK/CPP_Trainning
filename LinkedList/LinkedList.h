#pragma once
#include "Node.h"

const int DEFAULT_LIST_SIZE = 0;

template <typename N>
class LinkedList
{
public:

	Node<N>& getHeadNode();

	void insertNode(const Node<N>& newNode);

	void insertNode(N& newNodeValue);

	Node<N>& findLastNode();

	Node<N>& findNode(N& searchValue);

	void removeSpecificNode(N& searchValue);
	void insertNodeAtFront(const N& newNodeValue);
	void insertNodeAtFront(const Node<N>& newNode);

private:
	int listSize = DEFAULT_LIST_SIZE;
	Node<N>& head = nullptr;
};

