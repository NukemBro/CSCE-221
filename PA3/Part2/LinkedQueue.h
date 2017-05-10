//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template<typename T> 
class LinkedQueue;
   
template<typename T>
class LinkedQueue {
private:
	DoublyLinkedList<T> dll;
public:
   // user-defined exceptions
   class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };
   LinkedQueue<T>() : dll() {}
   ~LinkedQueue<T>() { dll.~DoublyLinkedList<T>(); }
   bool isEmpty() const { return dll.isEmpty(); }
   T first() const throw(QueueEmptyException);
   void enqueue(T elem) { dll.insertLast(elem); };
   T dequeue() throw(QueueEmptyException);
   template<typename Y>
   friend std::ostream& operator<<(std::ostream& out, const LinkedQueue<Y>& queue);
};

template<typename T>
T LinkedQueue<T>::first() const throw(QueueEmptyException) {
	if (dll.isEmpty()) {
		throw QueueEmptyException();
	} else {
		return dll.first();
	}
}

template<typename T>
T LinkedQueue<T>::dequeue() throw(QueueEmptyException) {
	if (dll.isEmpty()) {
		throw QueueEmptyException();
	}
	else {
		return dll.removeFirst();
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue)
{
	out << queue.dll;
	return out;
}

#endif
