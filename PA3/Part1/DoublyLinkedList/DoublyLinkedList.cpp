//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "DoublyLinkedList.h"

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  
  DListNode *dllHead = dll.getFirst();
  while (dllHead != dll.getAfterLast()) {
	  insertLast(dllHead->getElem());
	  dllHead = dllHead->next;
  }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
	if (this != &dll) {
		this->clear();
		DListNode *dllHead = dll.getFirst();
		while (dllHead != dll.getAfterLast()) {
			insertLast(dllHead->getElem());
			dllHead = dllHead->next;
		}
	}
	return *this;
}

// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  if (isEmpty()) {
	  trailer.prev = newNode;
  }
  header.next->prev = newNode;
  header.next = newNode;
}

// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
	if (isEmpty()) {
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	}
	else {
		DListNode *deleteNode = header.next;
		header.next = header.next->next;
		int obj = header.next->obj;
		delete deleteNode;
		return obj;
	}
}

// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}


// return the first object
int DoublyLinkedList::first() const
{ 
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	else
		return header.next->getElem();
}

// return the last object
int DoublyLinkedList::last() const
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	else
		return trailer.prev->getElem();
}

// clears the linkedlist
void DoublyLinkedList::clear() 
{
	DListNode *prev_node, *node = header.next;
	while (node != &trailer) {
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
	DListNode *head = dll.getFirst();
	while (head != dll.getAfterLast()) {
		cout << head->getElem() << " ";
		head = head->getNext();
	}
	return out;
}
