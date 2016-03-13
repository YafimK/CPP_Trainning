#pragma once
#include "BinaryTree.h"

template <class T>
class AvlTree<T>:BinaryTree<T>
{

	AvlTree<T>(T data[], const int size)
	{
		balanceSortedTree(data, 0, size - 1);
	}

	static void rotateRight(BinaryTree<T>& workTree, BstLeaf<T>& rotatedLeaf)
	{
		if (workTree != nullptr & rotatedLeaf != nullptr)
		{
			BstLeaf<T>* parentParentLeaf = dynamic_cast<BstLeaf<T>*>(rotatedLeaf.getLeafHead()->getLeafHead());
			parentParentLeaf->setRightLeaf(rotatedLeaf);
			BstLeaf<T>* tempLeaf = rotatedLeaf.getRightLeaf();
			rotatedLeaf.setRightLeaf(rotatedLeaf.getLeafHead());
			rotatedLeaf.getRightLeaf()->setleftLeaf(tempLeaf);
			rotatedLeaf.setHead(parentParentLeaf);
		}
	}

	void balanceSortedTree(T data[], int first, int last)
	{
		if (first <= last)
		{
			int middle = (first + last) / 2;
			std::cout << data[middle] << std::endl;
			insert(data[middle]);
			balanceSortedTree(data, first, middle - 1);
			balanceSortedTree(data, middle + 1, last);
		}
	}
};
