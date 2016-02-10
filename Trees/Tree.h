#pragma once
#pragma once
#include "leaf.h"

template <class T>
class Tree
{
public:
	Tree() = delete;

	virtual ~Tree()
	{
		delete root;
	};

	Leaf<T>* getTreeRoot() = delete;
	virtual void insert(const T& value) = delete;

private:
	Leaf<T>* root;

};

