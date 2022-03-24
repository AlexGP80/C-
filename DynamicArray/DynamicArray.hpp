using namespace std;

class DynamicArrayImpl;

class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray();
  int size();
  int &operator[](int i);
  void add(int n);
private:
  DynamicArrayImpl *impl;
};
