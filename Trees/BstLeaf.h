#pragma once
#include "leaf.h"

template <typename T>
class BstLeaf:public Leaf<T>
{
public:
	BstLeaf<T>* getChildren() override
	{
		return bstLeafChildren;
	};

	explicit BstLeaf(BstLeaf<T>* headLeaf = nullptr, const T& leafValue = DEFAULT_LEAF_VALUE, BstLeaf<T>* lefLeaf = nullptr, BstLeaf<T>* righNode = nullptr):
		Leaf(headLeaf, leafValue, bstLeafChildren), leftLeaf(lefLeaf), rightLeaf(righNode), bstLeafChildren(nullptr)
	{}

	~BstLeaf()
	{
		//Validate the leafs aint empty

		delete[] bstLeafChildren;
		//TODO: delete array and children
	}

	BstLeaf<T>* getleftLeaf()
	{
		return leftLeaf;
	}

	BstLeaf<T>* getRightLeaf()
	{
		return rightLeaf;
	}

	void setleftLeaf(BstLeaf<T>* newLeaf)
	{
		leftLeaf = newLeaf;
	}

	void setRightLeaf(BstLeaf<T>* newLeaf)
	{
		rightLeaf = newLeaf;
	}

private:
	BstLeaf<T> *leftLeaf, *rightLeaf;
	BstLeaf<T> *bstLeafChildren;
};

