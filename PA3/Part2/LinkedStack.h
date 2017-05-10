//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template<typename T> 
class LinkedStack;

template<typename T>
class LinkedStack
{
private:
	DoublyLinkedList<T> dll;
public:
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };
   LinkedStack<T>() : dll() {}
   ~LinkedStack<T>() { dll.~DoublyLinkedList<T>(); }
   bool isEmpty() const { return dll.isEmpty(); }
   void push(const T elem) { dll.insertFirst(elem); }
   T pop() throw(StackEmptyException);
   T top() const throw(StackEmptyException);
   template <typename Y>
   friend std::ostream& operator<<(std::ostream& out, const LinkedStack<Y>& stack);
};
   
template<typename T>
T LinkedStack<T>::pop() throw(StackEmptyException) {
	if (dll.isEmpty()) {
		throw StackEmptyException();
	}
	else {
		return dll.removeFirst();
	}
}

template<typename T>
T LinkedStack<T>::top() const throw(StackEmptyException) {
	if (dll.isEmpty()) {
		throw StackEmptyException();
	}
	else {
		return dll.first();
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
	out << stack.dll;
	return out;
}

#endif
