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
		targetNode.setNext(newNode);
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
	Node<N> cursorNode = head;
	while (cursorNode.getNext() != nullptr && cursorNode.getValue() != searchValue)
	{
		cursorNode = cursorNode.getNext();
	}
	return cursorNode;
}

template <typename N>
bool LinkedList<N>::removeSpecificNode(const N& deleteTarget)
{
	Node<N> cursorNode = this.head;

	if(head != nullptr)
	{
		if(head->getValue() == deleteTarget)
		{
			head = cursorNode.getNext();
			listSize--;
			return true;
		}
	}
	else
	{
		while(cursorNode.getNext() != nullptr)
		{
			if(cursorNode.getNext().getValue() == deleteTarget)
			{
				cursorNode.setNext(cursorNode.getNext());
				delete cursorNode.getNext();
				listSize--;
				return true;
			}
			cursorNode = cursorNode.getNext();
		}
	}


	return false;
}

template <typename N>
Node<N>& LinkedList<N>::findLastNode()
{
	Node<N>* cursorNode = head;
	while (cursorNode->next != nullptr)
	{
		cursorNode = cursorNode->getNext();
	}
	delete cursorNode;
	return cursorNode;
}

template <typename N>
void LinkedList<N>::insertNodeAtFront(const Node<N>& newNode)
{
	if (head != nullptr)
	{
		newNode.setNext(this->head);
	}

	head = newNode;

	listSize++;
}

template <typename N>
void LinkedList<N>::deleteList()
{
	Node<N>* tempNode = nullptr;
	while(head != nullptr)
	{
		*tempNode = head->getNext();
		delete head;
		head = tempNode;
	}
	delete tempNode;
	head = nullptr;
}

template <typename N>
LinkedList<N>::~LinkedList()
{
	deleteList();
}

template <typename N>
void LinkedList<N>::insertNodeAtFront(const N& newNodeValue)
{
	insertNodeAtFront(new Node<N>(newNodeValue));
}

