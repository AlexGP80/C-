#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <unordered_map>
#include <vector>
#include <iostream>
#include <random>

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
  void insert(int data, initializer_list<int> neighbors);
  void print();
private:

  unordered_map<int, Node *> *nodes;
};

#endif
