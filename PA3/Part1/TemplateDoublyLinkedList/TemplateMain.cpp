//============================================================================
// Copyright   : Grant Hruzek ©
//============================================================================

#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {
  // --------------String data type testing---------------//
  cout << "--------------String data type testing---------------" << endl;
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList<string> dll;
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList<string> dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; ++i) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;
  cout << endl;
  
  // EXTRA STRING TESTING CASES
  cout << "--------------------Extra String Testing Cases---------------------" << endl;
  DoublyLinkedList<string> dll4;
  cout << "Creating a list of nodes from 10 ... 100" << endl;
  for (int i=10;i<=100;i+=10) {
	stringstream ss;
    ss << i;
    dll4.insertLast(ss.str());
  }
  cout << "list4: " << dll4 << endl << endl;
  //checking if list is empty using isEmpty;
  cout << "Is the list empty? " << boolalpha << dll4.isEmpty() << endl;
  cout << endl;
  
  // getting first and last 
  cout << "Getting First Value: " << dll4.first() << endl;
  cout << "Getting Last Value: " << dll4.last() << endl;
  cout << endl;
  
  cout << "Clearing this list" << endl;
  dll4.clear();
  cout << "list4: " << dll4 << endl << endl;
  cout << "Is the list empty? " << boolalpha << dll4.isEmpty() << endl;
  cout << endl;
  
  // --------------Double data type testing---------------//
  cout << "--------------Double data type testing---------------" << endl;
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList<double> dllA;
  cout << "list: " << dllA << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10.1,20.1,30.1,..,100.1" << endl;
  for (double i=10.1; i<=100.1; i+=10.0) {
    dllA.insertLast(i);
  }
  cout << "list: " << dllA << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10.1,20.1,30.1,..,100.1" << endl;
  for (double i=10.1; i<=100.1; i+=10.0) {
    dllA.insertFirst(i);
  }
  cout << "list: " << dllA << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList<double> dllB(dllA);
  cout << "list2: " << dllB << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList<double> dllC;
  dllC=dllA;
  cout << "list3: " << dllC << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dllA.removeLast();
  }
  cout << "list: " << dllA << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; ++i) {
    dllA.removeFirst();
  }
  cout << "list: " << dllA << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dllB << endl;
  cout << "list3: " << dllC << endl;
  cout << endl;
  
  // EXTRA DOUBLE TESTING CASES
  cout << "--------------------Extra Double Testing Cases---------------------" << endl;
  DoublyLinkedList<double> dllD;
  cout << "Creating a list of nodes from 10.1 ... 100.1" << endl;
  for (double i=10.1;i<=100.1;i+=10) {
    dllD.insertLast(i);
  }
  cout << "list4: " << dllD << endl << endl;
  //checking if list is empty using isEmpty;
  cout << "Is the list empty? " << boolalpha << dllD.isEmpty() << endl;
  cout << endl;
  
  // getting first and last 
  cout << "Getting First Value: " << dllD.first() << endl;
  cout << "Getting Last Value: " << dllD.last() << endl;
  cout << endl;
  
  cout << "Clearing this list" << endl;
  dllD.clear();
  cout << "list4: " << dllD << endl << endl;
  cout << "Is the list empty? " << boolalpha << dllD.isEmpty() << endl;
  cout << endl;
  
  // --------------int data type testing---------------//
  cout << "--------------int data type testing---------------" << endl;
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList<int> dllInt1;
  cout << "list: " << dllInt1 << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    dllInt1.insertLast(i);
  }
  cout << "list: " << dllInt1 << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    dllInt1.insertFirst(i);
  }
  cout << "list: " << dllInt1 << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList<int> dllInt2(dllInt1);
  cout << "list2: " << dllInt2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList<int> dllInt3;
  dllInt3=dllInt1;
  cout << "list3: " << dllInt3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dllInt1.removeLast();
  }
  cout << "list: " << dllInt1 << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; ++i) {
    dllInt1.removeFirst();
  }
  cout << "list: " << dllInt1 << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dllInt2 << endl;
  cout << "list3: " << dllInt3 << endl;
  cout << endl;
  
  // EXTRA INT TESTING CASES
  cout << "--------------------Extra Int Testing Cases---------------------" << endl;
  DoublyLinkedList<int> dllInt4;
  cout << "Creating a list of nodes from 10 ... 100" << endl;
  for (int i=10;i<=100;i+=10) {
    dllInt4.insertLast(i);
  }
  cout << "list4: " << dllInt4 << endl << endl;
  //checking if list is empty using isEmpty;
  cout << "Is the list empty? " << boolalpha << dllInt4.isEmpty() << endl;
  cout << endl;
  
  // getting first and last 
  cout << "Getting First Value: " << dllInt4.first() << endl;
  cout << "Getting Last Value: " << dllInt4.last() << endl;
  cout << endl;
  
  cout << "Clearing this list" << endl;
  dllInt4.clear();
  cout << "list4: " << dllInt4 << endl << endl;
  cout << "Is the list empty? " << boolalpha << dllInt4.isEmpty() << endl;
  cout << endl;
  
  return 0;
}
