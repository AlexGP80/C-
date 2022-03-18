#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
using namespace std;

// LinkedList.h
/** A LinkedList using ints to do some recap
*
*
**/

// Node
class Node {
private:
  Node(int value);
  int value;
  Node* next;
  Node* prev;

  friend class LinkedList;
};

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void append(int value);
  int pop();
private:
  int length;
  Node* head;
  Node* tail;
};

#endif /* LINKED_LIST_H_ */
