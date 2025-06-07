#pragma once

#include <ostream>
#include <sstream>
template <typename Data> class Node {
public:
  Data data;
  Node<Data> *next;

  Node(const Data &value, Node<Data> *next_node = nullptr)
      : data(value), next(next_node) {};
};

template <typename Data> class DNode {
public:
  Data data;
  DNode<Data> *next;
  DNode<Data> *prev;

  DNode(const Data &value, DNode<Data> *next_node = nullptr,
        DNode<Data> *prev_node = nullptr)
      : data(value), next(next_node), prev(prev_node) {};
};

template <typename Data> class BTNode {
public:
  Data data;
  BTNode<Data> *left;
  BTNode<Data> *right;

  BTNode(const Data &value, BTNode<Data> *left_node = nullptr,
         BTNode<Data> *right_node = nullptr)
      : data(value), left(left_node), right(right_node) {};
  virtual ~BTNode() {}
  virtual std::string to_string() const {
    std::ostringstream os;
    os << data;
    return os.str();
  }
};

template <typename Data>
std::ostream &operator<<(std::ostream &os, const BTNode<Data> &node) {
  return os << node.to_string();
}
