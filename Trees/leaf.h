#pragma once
const int DEFAULT_TREE_SIZE=0;

template <typename T>
class Leaf
{
public:
	Leaf(const T&  newLeafValue=0, Leaf<T>* leafChildren=nullptr):val(newLeafValue), children(leafChildren), size(DEFAULT_TREE_SIZE){}
	

private:
	T val;
	Leaf<T>& children;
	int size;
};
