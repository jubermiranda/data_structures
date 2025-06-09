#pragma once

#include "b_tree.h"
#include "node.h"
#include <cstdio>

namespace MY_DS {

template <typename Data> bool b_tree<Data>::is_empty() const {
  return this->root == nullptr;
}

template <typename Data> size_t b_tree<Data>::size() const {
  // TODO: impl
  return 0;
}


template <typename Data> void b_tree<Data>::insert(const Data &data) {
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
      // data already exists in the tree
      return;
    }
  }
}

template <typename Data> void b_tree<Data>::remove(const Data &data) {
  if (this->is_empty()) {
    return; // nothing to remove
  }
  throw std::runtime_error("Remove operation not implemented yet");
}

template <typename Data> 
std::string b_tree<Data>::to_string(tree_print_mode mode) const {
  if (this->is_empty()) {
    return "Empty Tree";
  }
  std::ostringstream out;

  if(mode == tree_print_mode::PRE_ORDER)
    out << *this->root << std::endl;  

  out << this->get_left_subtree().to_string(mode) << std::endl;

  if(mode == tree_print_mode::ORDER)
    out << *this->root << std::endl;  

  out << this->get_right_subtree().to_string(mode) << std::endl;

  if(mode == tree_print_mode::POST_ORDER)
    out << *this->root << std::endl;  

  return out.str();
}

template <typename Data> b_tree<Data> b_tree<Data>::get_left_subtree() const {
  if(this->is_empty())
    throw std::invalid_argument("Cannot get left subtree of an empty tree");
  return b_tree<Data>(this->root->left);
}

template<typename Data> b_tree<Data> b_tree<Data>::get_right_subtree() const {
  if(this->is_empty()){
    throw std::invalid_argument("Cannot get right subtree of an empty tree");
  }
  return b_tree<Data>(this->root->right);
}


} // namespace MY_DS
