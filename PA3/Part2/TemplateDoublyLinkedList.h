//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================
#ifndef TEMPLATEDOUBLYLINKEDLIST_H
#define TEMPLATEDOUBLYLINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;


// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
	explicit EmptyDLinkedListException(char const* msg = NULL) : range_error(msg) {}
};

template <typename T>
class DoublyLinkedList; // class declaration

// list node
template <typename T>
class DListNode {
private:
	T obj;
	DListNode<T> *prev, *next;
	friend class DoublyLinkedList<T>;
public:
	DListNode<T>(T e = T(), DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
		: obj(e), prev(p), next(n) {} // O(1) complexity
	T getElem() const { return obj; } // O(1) complexity
	DListNode<T> * getNext() const { return next; } // O(1) complexity
	DListNode<T> * getPrev() const { return prev; } // O(1) complexity
};

// doubly linked list
template <typename T>
class DoublyLinkedList {
protected:
	DListNode<T> header, trailer;
public:
	DoublyLinkedList<T>() : // constructor O(1) complexity
		header(T()), trailer(T())
	{
		header.next = &trailer; trailer.prev = &header;
	}
	DoublyLinkedList<T>(const DoublyLinkedList& dll); // copy constructor O(n) complexity
	~DoublyLinkedList<T>(); // destructor O(n) complexity
	DoublyLinkedList& operator=(const DoublyLinkedList& dll); // assignment operator O(n) complexity
	DListNode<T> *getFirst() const { return header.next; } // getFirst O(1) complexity
	const DListNode<T> *getAfterLast() const { return &trailer; } // getAfterLast O(1) complexity
	bool isEmpty() const { return header.next == &trailer; } // isEmpty O(1) complexity
	T first() const; // first O(1) complexity
	T last() const; // last O(1) complexity
	void insertFirst(T newobj); // insertFirst O(1) complexity
	T removeFirst(); // removeFirst O(1) complexity
	void insertLast(T newobj); // insertLast O(1) complexity
	T removeLast(); // removeLast O(1) complexity
	void clear(); // clear O(n) complexity
};
// output operator
template <typename T>
// O(n) complexity
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);

// copy constructor
template <typename T>
// O(n) complexity
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& dll)
{
	// Initialize the list
	header.next = &trailer;
	trailer.prev = &header;

	DListNode<T> *dllHead = dll.getFirst();
	while (dllHead != dll.getAfterLast()) {
		insertLast(dllHead->getElem());
		dllHead = dllHead->next;
	}
}

// assignment operator
template <typename T>
// O(n) complexity
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
	if (this != &dll) {
		this->clear();
		DListNode<T> *dllHead = dll.getFirst();
		while (dllHead != dll.getAfterLast()) {
			insertLast(dllHead->getElem());
			dllHead = dllHead->next;
		}
	}
	return *this;
}

// insert the object to the first of the linked list
template <typename T>
// O(1) complexity
void DoublyLinkedList<T>::insertFirst(T newobj)
{
	DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
	if (isEmpty()) {
		trailer.prev = newNode;
	}
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the object to the last of the linked list
template <typename T>
// O(1) complexity
void DoublyLinkedList<T>::insertLast(T newobj)
{
	DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object of the list
template <typename T>
// O(1) complexity
T DoublyLinkedList<T>::removeFirst()
{
	if (isEmpty()) {
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else {
		DListNode<T> *deleteNode = header.next;
		header.next = header.next->next;
		T obj = deleteNode->obj;
		delete deleteNode;
		return obj;
	}
}

// remove the last object of the list
template <typename T>
// O(1) complexity
T DoublyLinkedList<T>::removeLast()
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode<T> *node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	T obj = node->obj;
	delete node;
	return obj;
}

// destructor
template <typename T>
// O(n) complexity
DoublyLinkedList<T>::~DoublyLinkedList()
{
	DListNode<T> *prev_node, *node = header.next;
	while (node != &trailer) {
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// return the first object
template <typename T>
// O(1) complexity
T DoublyLinkedList<T>::first() const
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	else
		return header.next->getElem();
}

// return the last object
template <typename T>
// O(1) complexity
T DoublyLinkedList<T>::last() const
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	else
		return trailer.prev->getElem();
}

// clears the linkedlist
template <typename T>
// O(n) complexity
void DoublyLinkedList<T>::clear()
{
	DListNode<T> *prev_node, *node = header.next;
	while (node != &trailer) {
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// output operator
template <typename T>
// O(n) complexity
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
	DListNode<T> *head = dll.getFirst();
	while (head != dll.getAfterLast()) {
		cout << head->getElem() << " ";
		head = head->getNext();
	}
	return out;
}

#endif
