#include "Graph.hpp"

Node::Node(int data, vector<int> *neighbors) {
  this->data = data;
  this->neighbors = neighbors;
}

Node::~Node() {
  this->data = 0;
  delete this->neighbors;
  this->neighbors = nullptr;
}

Graph::Graph() {
  this->nodes = new unordered_map<int, Node *>();
}

Graph::~Graph() {
  for (auto item = this->nodes->begin(); item != nodes->end(); item++) {
    delete item->second;
    item->second = nullptr;
  }
  delete this->nodes;
  this->nodes = nullptr;
}

void Graph::insert(int data, initializer_list<int> neighbors) {
  vector<int> *checked_neighbors = new vector<int>();
  for (int neighbor: neighbors) {
    if (this->nodes->count(neighbor) || neighbor == data) {
      checked_neighbors->push_back(neighbor);
    }
  }

  if (this->nodes->count(data)) {
    delete this->nodes->at(data);
    this->nodes->at(data) = new Node(data, checked_neighbors);
  } else {
    this->nodes->insert({data, new Node(data, checked_neighbors)});
  }
}

void Graph::print() {
  for (auto item = this->nodes->begin(); item != this->nodes->end(); ++item) {
    cout << item->first << ": ";
    Node *node = item->second;
    for (int neighbor: *(node->neighbors)) {
      cout << neighbor << " ";
    }
    cout << endl;
  }
}









int main(int, char**) {
  Graph g;
  g.insert(251, {});
  g.insert(542, {251,13}); //13 should not be inserted
  g.insert(308, {251});
  g.insert(100, {308, 542});
  g.insert(846, {846, 251});
  g.insert(251, {542, 308, 846});
  g.print();
  return 0;
}
