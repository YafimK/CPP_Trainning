#pragma once

template <class T>
class Node
{
public:

	Node(const T& value);

	Node<T>* getNextNode() const;
	void setNextNode(Node<T>* nextNode);
	void setNodeValue(const T& newValue);
	const T& getNodeValue() const;

	~Node() {}

private:
	Node<T>* next;	
	T nodeValue;
};


template <typename T>
Node<T>::Node(const T&  value) : next(nullptr), nodeValue(value) { }

template <typename T>
Node<T>* Node<T>::getNextNode() const
{
	return this->next;
}

template <typename T>
void Node<T>::setNextNode(Node<T>* nextNode)
{
	this->next = nextNode;
}

template <typename T>
void Node<T>::setNodeValue(const T& newValue)
{
	this.nodeValue = newValue;
}

template <typename T>
const T& Node<T>::getNodeValue() const
{
	return this->nodeValue;
}



