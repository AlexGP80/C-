#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
  Node(int data, vector<int> *neighbors);
  ~Node();
  int data;
  vector<int> *neighbors;
};


class Graph {
public:
  Graph();
  ~Graph();
  void insert(int data, vector<int> *neighbors);
  void print();
private:

  unordered_map<int, Node *> *nodes;
};

#endif
