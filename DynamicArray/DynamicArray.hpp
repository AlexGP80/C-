using namespace std;



class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray();
  int size();
  int &operator[](int i);
  void add(int n);
private:
  class DynamicArrayImpl;
  DynamicArrayImpl* impl; // TODO: Change to unique_ptr
  //TODO: make class non copyable
};
