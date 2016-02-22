#pragma once
const int DEFAULT_LEAF_VALUE = 0;

template <typename T>
class Leaf
{
public:
	explicit Leaf(Leaf<T>* newHead = nullptr,const T&  newLeafValue = DEFAULT_LEAF_VALUE, Leaf<T>* leafChildren = nullptr, Leaf<T>* leafHead = nullptr):val(newLeafValue), children(leafChildren), head(&newHead){}

	virtual ~Leaf()
	{
		delete[] children;
	}
	T getValue() const
	{
		return val;
	}
	void setValue(const T& newValue)
	{
		val = newValue;
	}

	virtual Leaf<T>* getChildren() = 0;
	void setHead(Leaf<T>* newHead)
	{
		head = &newHead;
	};

private:
	T val;
	Leaf<T>* children;
	Leaf<T>* head;
};
