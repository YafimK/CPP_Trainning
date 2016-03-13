


#include "BinaryTree.h"

int main(void)
{
	BinaryTree<int> rt ({ 1,2,3,4,5,6,7,8,9,10,11,12 });
	BinaryTree<int> rr;
	rt.breadthFirst();
	rt.depthFirst();
	int a[]{1,2,3,4,5,6,7,8};
	BinaryTree<int> rg(a, 8);
	system("pause");
}
