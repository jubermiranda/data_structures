#pragma once

#include "b_tree.h"
#include "node.h"

namespace MY_DS {

template <typename Data> b_tree<Data>::b_tree(const Data &data) {
  root = new BTNode<Data>(data);
  node_count = 1;
}

template <typename Data> bool b_tree<Data>::empty() const {
  return this->root == nullptr;
}

template <typename Data> size_t b_tree<Data>::size() const {
  return node_count;
}

template <typename Data> size_t b_tree<Data>::height() const {
  return root ? (this->get_node_height(this->root)) : 0;
}

template <typename Data> void b_tree<Data>::insert(const Data &data) {
  if (this->empty()) {
    this->root = new BTNode<Data>(data);
    node_count++;
    return;
  }

  BTNode<Data> *current = this->root;
  while (true) {
    if (data < current->data) {
      if (current->left == nullptr) {
        current->left = new BTNode<Data>(data);
        node_count++;
        return;
      } else {
        current = current->left;
      }
    } else if (data > current->data) {
      if (current->right == nullptr) {
        current->right = new BTNode<Data>(data);
        node_count++;
        return;
      } else {
        current = current->right;
      }
    } else {
      // data already exists in the tree
      return;
    }
  }
}

template <typename Data> void b_tree<Data>::remove(const Data &data) {
  if (this->empty()) {
    return; // nothing to remove
  }
  throw std::runtime_error("Remove operation not implemented yet");
}

} // namespace MY_DS
