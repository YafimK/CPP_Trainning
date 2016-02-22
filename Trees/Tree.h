#pragma once
#include "leaf.h"
static const int DEFAULT_TREE_SIZE = 0;

template <class T>
class Tree
{
public:
	explicit Tree() = delete;
	virtual ~Tree()
	{
		delete root;
	}

	Leaf<T>* getTreeRoot() const {
		return this->root;
	}
	Leaf<T>* setTreeRoot(Leaf<T>* newRoot) {
		return this->root = newRoot;
	}

	virtual void insert(const T& value) = 0;

private:
	Leaf<T>* root;
	int treeHeight;
	int leavsCount;
};

