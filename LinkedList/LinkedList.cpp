#include "LinkedList.h"

Node::Node(int value)
  :value{value}, next{nullptr}, prev{nullptr}
{
}

LinkedList::LinkedList()
  :head{nullptr}, tail{nullptr}, length{0}
{
}

LinkedList::LinkedList(initializer_list<int> list)
  :head{nullptr}, tail{nullptr}, length{0}
{
  for (int i: list) {
    this->append(i);
  }
}

LinkedList::~LinkedList()
{
  while (this->head != nullptr) {
    Node* node = this->head;
    this->head = node->next;
    delete node;
    node = nullptr;
  }
}

void LinkedList::append(int value)
{
  Node* new_node = new Node(value);
  new_node->prev = this->tail;
  this->tail = new_node;
  if (this->head == nullptr) {
    this->head = new_node;
  }
  if (new_node->prev != nullptr) {
    new_node->prev->next = new_node;
  }
  this->length += 1;
}

int LinkedList::pop()
{
  if (this->length == 0 || this->head == nullptr)
    throw out_of_range{"pop on empty list"};

  Node *node_to_pop = this->head;
  this->head = node_to_pop->next;

  if (this->head != nullptr)
    this->head->prev = nullptr;
  else
    this->tail = nullptr;

  this->length -= 1;

  int value = node_to_pop->value;

  delete node_to_pop;
  node_to_pop = nullptr;

  return value;

}

int main(int, char**) {
  LinkedList list = {1,2,3,4,5,6,7,8,9,10};


  for (int i=0; i!=15; ++i) {
    try {
      cout << list.pop() << endl;
    } catch (out_of_range err) {
      cout << err.what() << endl;
    }
  }

}
