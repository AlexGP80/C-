#include "LinkedList.h"

Node::Node(int value)
  :value{value}, next{nullptr}, prev{nullptr}
{
}

LinkedList::LinkedList()
  :head{nullptr}, tail{nullptr}, length{0}
{
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

int main(char *args) {
  LinkedList *list = new LinkedList();

  try {
    for (int i=0; i!=100'000'000; ++i) {
      list->append(i);
    }
  } catch (std::bad_alloc err) {
    delete list;
    list = nullptr;
    cout << err.what() << endl;
    return -1;
  }

  for (int i=0; i!=5; ++i)
    cout << list->pop() << endl;

  delete list;

}
