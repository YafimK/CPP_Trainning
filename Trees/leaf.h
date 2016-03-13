#pragma once
const int DEFAULT_LEAF_VALUE = 0;

template <typename T>
class Leaf
{
public:
	explicit Leaf(Leaf<T>* newHead = nullptr,const T&  newLeafValue = DEFAULT_LEAF_VALUE, Leaf<T>* leafChildren = nullptr):val(newLeafValue), children(leafChildren), head(newHead){}

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
		this.val = newValue;
	}
	Leaf<T>* getLeafHead()
	{
		return head;
	}

	virtual Leaf<T>* getChildren() = 0;
	void setHead(Leaf<T>* newHead)
	{
		head = &newHead;
	};
	void markVisited()
	{
		visited = true;
	}
	void markUnVisited()
	{
		
		visited = false;
	}
	bool getVisitStat() const
	{
		return visited;
	}
private:
	T val;
	Leaf<T>* children;
	Leaf<T>* head;
	bool visited = false;
};
