#pragma once

#include "node.h"
#include "sb_tree.h"

namespace MY_DS {

template <typename Data> void sb_tree<Data>::insert(const Data &data) {
  if (this->is_empty()) {
    this->root = new BTNode<Data>(data);
    return;
  }

  BTNode<Data> *current = this->root;
  while (true) {
    if (data < current->data) {
      if (current->left == nullptr) {
        current->left = new BTNode<Data>(data);
        return;
      } else {
        current = current->left;
        continue;
      }
    } else if (data > current->data) {
      if (current->right == nullptr) {
        current->right = new BTNode<Data>(data);
        return;
      } else {
        current = current->right;
        continue;
      }
    } else {
      return;
    }
  }
}

template <typename Data> void sb_tree<Data>::remove(const Data &data) {
  if (this->is_empty()) {
    return;
  }
  throw std::runtime_error("Remove operation not implemented yet");
}


};
