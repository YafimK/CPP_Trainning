#pragma once
template<typename T>
class Node
{
public:

	Node<T>(T& value): nodeValue(value), next(nullptr)
	{

	}

	Node<T>& getNextNode() const
	{
		return next;
	}

	void setNextNode(Node<T>& nextNode) const
	{
		next = nextNode;
	}

	T& getNodeValue() const
	{
		return nodeValue;
	}

private:
	Node& next;
	T nodeValue;
};