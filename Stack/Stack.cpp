#include "Stack.h"
template <typename T>
void Stack<T>::push(const T& item)
{
	StackItem<T> newItem = new StackItem<T>(item);
	newItem.setNext(this->head);
	this->head = newItem;
}

template <typename T>
T* Stack<T>::pop() const
{
	T tempValue = nullptr;
	if(this->head!=nullptr)
	{
		StackItem<T>* tempItem = this->head;
		tempValue = tempItem->getValue();
		if(tempItem->getNext()!=nullptr)
		{
			this->head = tempItem.getNext();
		}
		delete tempItem;
	}
	return tempValue;
}

template <typename T>
Stack<T>::~Stack()
{
	while(this->head!=nullptr)
	{
		this->pop();
	}
}
