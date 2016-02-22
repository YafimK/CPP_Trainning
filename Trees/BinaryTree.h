#pragma once
#include "BstLeaf.h"
#include "Tree.h"
#include <initializer_list>
#include <memory>

template <class T>
class BinaryTree:Tree<T>
{
public:
	explicit BinaryTree()
	{
		
	}

	 BinaryTree(std::initializer_list<T> newLeafs)
	{
		for(const T& newLeaf: newLeafs)
		{
			this.BinaryTree<T>::insert(newLeaf);
		}
	}

	virtual void insert(const T& insertVal) override
	{
		std::unique_ptr<BstLeaf<T>> cursorPtr = dynamic_cast<BstLeaf<T>>(Tree<T>::getTreeRoot());
		BstLeaf<T>* tempPtrLeaf = nullptr;
		while(cursorPtr!=nullptr)
		{
			tempPtrLeaf = cursorPtr;
			if(cursorPtr->getValue()==insertVal)
			{
				break;
			}
			else if(cursorPtr->getValue()<insertVal)
			{
				cursorPtr = cursorPtr->getRightLeaf();
			}
			else if(cursorPtr->getValue() > insertVal)
			{
				cursorPtr = cursorPtr->getleftLeaf();
			}
		}

		if(cursorPtr == nullptr)
		{
			if(tempPtrLeaf->getValue()<insertVal)
			{
				tempPtrLeaf->setleftLeaf(&tempPtrLeaf,new BstLeaf<T>(insertVal));
			}
			else if(tempPtrLeaf->getValue() > insertVal)
			{
				tempPtrLeaf->setRightLeaf(&tempPtrLeaf,new BstLeaf<T>(insertVal));
			}
		}
		delete tempPtrLeaf;
	}

	BstLeaf<T>* search(const T& searchVal)
	{
		BstLeaf<T>* cursor = dynamic_cast<BstLeaf<T>>(Tree<T>::getTreeRoot());
		return {};
	}

	BstLeaf<T>* search(BstLeaf<T>* startNode, const T& searchVal)
	{
		BstLeaf<T>* cursor = startNode;
		while(startNode!=nullptr)
		{
			if(startNode->getValue()==searchVal)
			{
				return &startNode;
			}
			else if(startNode->getValue()<searchVal)
			{
				cursor = startNode->getRightLeaf();
			} 
			else if(startNode->getValue() > searchVal)
			{
				cursor = startNode->getleftLeaf();
			}
		}
		return nullptr;
	}

	void breadthFirst
private:
};
