#pragma once
#include "Node.h"
#include <ostream>
#include <iostream>

const int DEFAULT_LIST_SIZE = 0;

template <class T>
class LinkedList
{
public:
	//todo copy constructor, list constructor, move and output stream constructor
	LinkedList():listSize(DEFAULT_LIST_SIZE), head(nullptr){}
	Node<T>* getHeadNode();
	void insertNode( Node<T>* newNode);
	void insertNode( T newNodeValue);
	Node<T>* findLastNode();
	Node<T>& findNode(T& searchValue);
	bool removeSpecificNode(const T& searchValue);
	void insertNodeAtFront(const T& newNodeValue);
	void printLinkedList() const;
	void insertNodeAtFront(const Node<T>& newNode);
	void deleteList();
	~LinkedList();

private:
	int listSize;
	Node<T>* head;
};

/*
*Impl' of a basic linked list.
*/

template <typename T>
Node<T>* LinkedList<T>::getHeadNode()
{
	return this->head;
}

template <typename T>
void LinkedList<T>::insertNode(Node<T>* newNode)
{
	if(head != nullptr)
	{
		//std::cout<<"adding new node with value "<<newNode->getNodeValue()<<std::endl;
		Node<T>* targetNode = findLastNode();
		targetNode->setNextNode(newNode);
	}
	else
	{
		head = newNode;
	}

	listSize++;
}

template<typename T>
void LinkedList<T>::insertNode(T newNodeValue)
{
	insertNode(new Node<T>(newNodeValue));

}

template <typename T>
Node<T>& LinkedList<T>::findNode(T& searchValue)
{
	Node<T> cursorNode = head;
	while(cursorNode.getNext()!=nullptr && cursorNode.getValue()!=searchValue)
	{
		cursorNode = cursorNode.getNext();
	}
	return cursorNode;
}

template <typename T>
bool LinkedList<T>::removeSpecificNode(const T& deleteTarget)
{
	Node<T> cursorNode = this.head;

	if(head!=nullptr)
	{
		if(head->getValue()==deleteTarget)
		{
			head = cursorNode.getNext();
			listSize--;
			return true;
		}
	}
	else
	{
		while(cursorNode.getNext()!=nullptr)
		{
			if(cursorNode.getNext().getValue()==deleteTarget)
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

template <typename T>
 Node<T>* LinkedList<T>::findLastNode()
{
	if(!(this->head))
	{
		return nullptr;
	}
	Node<T>* cursorNode = this->head;
	while(cursorNode->getNextNode() != nullptr)
	{
		cursorNode = cursorNode->getNextNode();
	}
	return cursorNode;
}

template <typename T>
void LinkedList<T>::insertNodeAtFront(const Node<T>& newNode)
{
	if(head!=nullptr)
	{
		newNode.setNext(this->head);
	}

	head = newNode;

	listSize++;
}

template <typename T>
void LinkedList<T>::deleteList()
{
	Node<T>* tempNode = nullptr;
	while(head!=nullptr)
	{
		tempNode = head->getNextNode();
		delete head;
		head = tempNode;
	}
	delete tempNode;
	head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	deleteList();
}

template <typename T>
void LinkedList<T>::insertNodeAtFront(const T& newNodeValue)
{
	insertNodeAtFront(new Node<T>(newNodeValue));
}

template <typename T>
void LinkedList<T>::printLinkedList() const 
{
	Node<T>* cursorNode = this->head;
	while(cursorNode != nullptr)
	{
		std::cout<<cursorNode->getNodeValue()<<"<<--";
		cursorNode = cursorNode->getNextNode();
	}
	std::cout<<std::endl;

}
