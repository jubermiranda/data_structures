#pragma once

#include "node.h"
#include <iostream>

namespace MY_DS {

template <typename Data> class b_tree {
private:
  BTNode<Data> *root;

public:
  b_tree() : root(nullptr) {}
  b_tree(const Data &data);

  bool empty() const;

  size_t size() const;
  size_t height() const;

  void insert(const Data &data);
  void remove(const Data &data);
  void clear();

  BTNode<Data> *find(const Data &data) const;

  // stream operator for development and debugging
  friend std::ostream &operator<<(std::ostream &os, const b_tree<Data> &tree);

  // private auxiliary methods
private:
  b_tree(BTNode<Data> *root) : root(root) {}
  size_t get_node_height(BTNode<Data> *node) const;
};

} // namespace MY_DS

#include "b_tree.tpp"
