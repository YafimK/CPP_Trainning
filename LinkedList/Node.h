#pragma once

template <typename T>
class Node
{
public:

	Node(const T& value);

	Node* getNextNode() const;
	void setNextNode(Node<T>& nextNode);
	void setNodeValue(const T& newValue);
	const T& getNodeValue() const;

	~Node() {}

private:
	Node& next;
	T nodeValue;
};

