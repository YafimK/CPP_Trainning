#pragma once
#include "BstLeaf.h"
#include "Tree.h"
#include <initializer_list>
#include <memory>
#include <queue>
#include <iostream>

template <class T>
class BinaryTree:Tree<T>
{
public:
	BinaryTree<T>()
	{

	}
	BinaryTree<T>(std::initializer_list<T> newLeafs)
	{
		for(const T& newLeaf: newLeafs)
		{
			insert(newLeaf);
		}
	}

	BinaryTree<T>(T data[], const int size)
	{
		balanceTree(data, 0, size-1);
	}

	 ~BinaryTree()
	{
		
	}
	virtual void insert(const T& insertVal) override
	{
		
		BstLeaf<T>* cursorPtr = getTreeRoot();
		BstLeaf<T>* tempPtrLeaf = nullptr;
		while(cursorPtr != nullptr)
		{
			tempPtrLeaf = cursorPtr;
			if(cursorPtr->getValue() == insertVal)
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
			if(tempPtrLeaf == nullptr)
			{
				this->setTreeRoot(new BstLeaf<T>(tempPtrLeaf, insertVal));
			}
			else if(tempPtrLeaf->getValue() > insertVal)
			{
				tempPtrLeaf->setleftLeaf(new BstLeaf<T>(tempPtrLeaf,insertVal));
			}
			else if(tempPtrLeaf->getValue() < insertVal)
			{
				tempPtrLeaf->setRightLeaf(new BstLeaf<T>(tempPtrLeaf,insertVal));
			}
			++Tree<T>::leavsCount;
		}
		tempPtrLeaf = nullptr;
	}

	BstLeaf<T>* search(const T& searchVal)
	{
		BstLeaf<T>* cursor = getTreeRoot();
		return search(cursor, searchVal);
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

	void breadthFirst()
	{
		std::queue<BstLeaf<T>*> leafQueue;
		BstLeaf<T>* cursor = getTreeRoot();
		if(cursor != nullptr)
		{
			leafQueue.push(cursor);
			while(!leafQueue.empty())
			 {
				 cursor = leafQueue.front();
				 std::cout << cursor->getValue();	
				 leafQueue.pop();
				 cursor->markVisited();
				 if(cursor->getleftLeaf())
				 {
					 leafQueue.push(cursor->getleftLeaf());
				 }
				 if (cursor->getRightLeaf())
				 {
					 leafQueue.push(cursor->getRightLeaf());
				 }
				 cursor->markUnVisited();
			 }
		}
		std::cout << std::endl;
		cursor = nullptr;
	}
	void depthFirst()
	{
		dft(getTreeRoot());
		std::cout << std::endl;
	}

	virtual BstLeaf<T>* getTreeRoot()
	{
		return this->root;
	}
	virtual void setTreeRoot(BstLeaf<T>* newRoot)
	{
		 this->root = newRoot;
	}

private:
	void balanceTree(T data[], int first, int last)
	{
		if(first<=last)
		{
			int middle = (first + last) / 2;
			std::cout << data[middle] << std::endl;
			insert(data[middle]);
			balanceTree(data, first, middle-1);
			balanceTree(data, middle + 1, last);
		}
	}
	void dft(BstLeaf<T>* cursor)
	{
		if (cursor)
		{
			dft(cursor->getleftLeaf());
			dft(cursor->getRightLeaf());
			std::cout << cursor->getValue();
		}
		
	}
	BstLeaf<T>* root = nullptr;
};
