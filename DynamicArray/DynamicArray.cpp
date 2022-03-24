#include "DynamicArray.hpp"
#include <iostream>

class DynamicArray::DynamicArrayImpl {
public:
  int size;
  int maxSize;
  int *arrayholder; // TODO: Change to unique_ptr

  DynamicArrayImpl() : size{0}, maxSize{50}
  {
    this->arrayholder = new int[maxSize];
    for (int i=0; i!=this->maxSize; ++i) {
      this->arrayholder[i] = 0;
    }
  }

  ~DynamicArrayImpl()
  {
    delete [] this->arrayholder;
    this->arrayholder = nullptr;
    this->size = 0;
    this->maxSize = 0;
  }
};

DynamicArray::DynamicArray()
{
    this->impl = new DynamicArray::DynamicArrayImpl();
}

DynamicArray::~DynamicArray()
{
  delete this->impl;
  this->impl = nullptr;
}

int DynamicArray::size()
{
  return this->impl->size;
}

int &DynamicArray::operator[](int i)
{
  // FIXME: when i is greater or equal than size
  return this->impl->arrayholder[i];
}

void DynamicArray::add(int n) {
  if (this->impl->size == this->impl->maxSize) {
    this->impl->maxSize *= 2;
    int *newArrayHolder = new int[this->impl->maxSize];
    for (int i = 0; i!=this->impl->maxSize; ++i) {
      if (i < this->impl->size) {
        newArrayHolder[i] = this->impl->arrayholder[i];
      } else {
        newArrayHolder[i] = 0;
      }
    }
    delete [] this->impl->arrayholder;
    this->impl->arrayholder = newArrayHolder;
    newArrayHolder = nullptr;
  }

  this->impl->arrayholder[this->impl->size] = n;
  this->impl->size += 1;
}

int main(int, char **) {
  DynamicArray dArray;
  for (int i=0; i!=1000; ++i) {
    dArray.add(i);
  }
  for (int i=0; i!=1000; ++i) {
    cout << dArray[i] << endl;
  }
  return 0;
}
