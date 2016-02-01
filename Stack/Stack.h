#pragma once
const int DEFAULT_STACK_SIZE = 0;

/*
Minimal Stack Impl'
*/
template <typename T>
class Stack
{
public:
	Stack():size(DEFAULT_STACK_SIZE), head(nullptr){};
	~Stack();
	void push(const T& item);
	T* pop() const;

protected:
	class StackItem
	{
	public:

		StackItem(const T& value):nodeValue(value){};

		inline StackItem* getNext() const
		{
			return this->next;
		};
		inline void setNext(StackItem& nextNode)
		{
			next = nextNode;
		}
		inline const T& getValue() const
		{
			return this->nodeValue;
		}

		inline ~StackItem()
		{
			delete next;
			delete nodeValue;
		};

	private:
		StackItem* next;
		T& nodeValue;
	};

private:
	int size;
	StackItem* head;

};

