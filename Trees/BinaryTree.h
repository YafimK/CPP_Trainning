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
			BinaryTree<T>::insert(newLeaf);
		}
	}

	BinaryTree<T>(T (data)[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			BinaryTree<T>::insert(data[i]);
		}
	}

	 ~BinaryTree()
	{
		
	}
	virtual void insert(const T& insertVal) override
	{
		
		BstLeaf<T>* cursorPtr = dynamic_cast<BstLeaf<T>*>(Tree<T>::getTreeRoot());
		BstLeaf<T>* tempPtrLeaf = nullptr;
		while(cursorPtr != nullptr)
		{
			tempPtrLeaf = dynamic_cast<BstLeaf<T>*>(cursorPtr);
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
		Leaf<T>* cursor = Tree<T>::getTreeRoot();
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
		BstLeaf<T>* cursor = dynamic_cast<BstLeaf<T>*>(Tree<T>::getTreeRoot());
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
		dft(dynamic_cast<BstLeaf<T>*>((Tree<T>::getTreeRoot())));
		std::cout << std::endl;
	}

private:

	void dft(BstLeaf<T>* cursor)
	{
		if (cursor)
		{
			dft(cursor->getleftLeaf());
			dft(cursor->getRightLeaf());
			std::cout << cursor->getValue();
		}
		
	}
};
