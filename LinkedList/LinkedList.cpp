#include "LinkedList.h"


/*
*Impl' of a basic linked list.
*/

template <typename N>
Node<N>& LinkedList<N>::getHeadNode()
{
	return this.head;
}

template <typename N>
void LinkedList<N>::insertNode(const Node<N>& newNode)
{
	if (head != nullptr)
	{
		Node<N>& targetNode = findLastNode();
		targetNode.setNextNode(newNode);
	}
	else
	{
		head = newNode;
	}

	listSize++;
}

template <typename N>
void LinkedList<N>::insertNode(N& newNodeValue)
{
	insertNode(new Node<N>(newNodeValue));
}

template <typename N>
Node<N>& LinkedList<N>::findNode(N& searchValue)
{
	Node<N>& cursorNode = head;
	while (cursorNode->getNextNode() != nullptr && cursorNode->getNodeValue() != searchValue)
	{
		cursorNode = cursorNode->getNextNode();
	}
	return cursorNode;
}

template <typename N>
void LinkedList<N>::removeSpecificNode(N& searchValue)
{
	Node<N>& targetNode = findLastNode(searchValue);
	//TODO: complete this

	listSize--;
}

template <typename N>
Node<N>& LinkedList<N>::findLastNode()
{
	Node<N>* cursorNode = head;
	while (cursorNode->next != nullptr)
	{
		cursorNode = cursorNode->getNextNode();
	}
	delete cursorNode;
	return cursorNode;
}

template <typename N>
void LinkedList<N>::insertNodeAtFront(const Node<N>& newNode)
{
	if (head != nullptr)
	{
		newNode.setNextNode(this->head);
	}

	head = newNode;

	listSize++;
}

template <typename N>
void LinkedList<N>::insertNodeAtFront(const N& newNodeValue)
{
	insertNodeAtFront(new Node<N>(newNodeValue));
}

