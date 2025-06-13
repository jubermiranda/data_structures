#pragma once

#include "node.h"
#include "sb_tree.h"
#include <stdexcept>

namespace MY_DS {

template <typename Data> bool sb_tree<Data>::insert(const Data &data) {
  return this->insert(this->root, data);
}

template <typename Data> bool sb_tree<Data>::erase(const Data &data) {
  
  return this->erase(this->root, data);
}

template <typename Data> bool sb_tree<Data>::insert(BTNode<Data>*& crr_root, const Data& target){
  if (this->is_empty()) {
    this->root = new BTNode<Data>(target);
    return false;
  }

  BTNode<Data> *current = this->root;
  while (true) {
    if (target < current->data) {
      if (current->left == nullptr) {
        current->left = new BTNode<Data>(target);
        return true;
      } else {
        current = current->left;
        continue;
      }
    } else if (target > current->data) {
      if (current->right == nullptr) {
        current->right = new BTNode<Data>(target);
        return true;
      } else {
        current = current->right;
        continue;
      }
    } else {
      return false;
    }
  }
}

template <typename Data> bool sb_tree<Data>::erase(BTNode<Data>*& crr_root, const Data& target){
  if (this->is_empty()) {
    return false;
  }

  if(target < crr_root->data){
    return this->erase(crr_root->left, target);
  }
  if(target > crr_root->data){
    return this->erase(crr_root->right, target);
  }

  if( crr_root->is_leaf() ){
    delete(crr_root);
    crr_root = nullptr;

  } else if(crr_root->left == nullptr) {
    BTNode<Data> *to_delete = crr_root;
    crr_root = crr_root->right;
    delete(to_delete);
  } else if(crr_root->right == nullptr){
    BTNode<Data> *to_delete = crr_root;
    crr_root = crr_root->left;
    delete(to_delete);
  }
}

template <typename Data> const Data* sb_tree<Data>::find(BTNode<Data>* crr_root, const Data& target) const{
  throw new std::runtime_error("not impl");
}

template <typename Data> void replace_root(BTNode<Data>*& old_root, BTNode<Data>*& crr_root){
  throw new std::runtime_error("not impl");
}

};
