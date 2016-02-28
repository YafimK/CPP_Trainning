#pragma once
#include "leaf.h"
static const int DEFAULT_TREE_SIZE = 0;

template <class T>
class Tree
{
public:
	virtual ~Tree()
	{
		delete root;
	}

	virtual Leaf<T>* getTreeRoot() const {
		return this->root;
	}
	virtual void setTreeRoot(Leaf<T>* newRoot) {
		 this->root = newRoot;
	}

	virtual void insert(const T& value) = 0;
	int leavsCount = 0;

private:
	Leaf<T>* root = nullptr;
	int treeHeight = 0;
};

