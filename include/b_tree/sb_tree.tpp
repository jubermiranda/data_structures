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
  if (this->is_empty())
    return false;
  if(target < crr_root->data)
    return this->erase(crr_root->left, target);
  if(target > crr_root->data)
    return this->erase(crr_root->right, target);

  // remove leaf node
  if( crr_root->is_leaf() ){
    delete(crr_root);
    crr_root = nullptr;
    return true;
  }

  BTNode<Data> *to_delete = crr_root;
  if(crr_root->left == nullptr) {
    crr_root = crr_root->right;
  } else if(crr_root->right == nullptr){
    crr_root = crr_root->left;
  } else {
    BTNode<Data>*& replacement = find_replacement(crr_root->left);
    crr_root->data = replacement->data;
    to_delete = replacement;
    replacement = replacement->left;
  }
  delete(to_delete);
}

template <typename Data> const Data* sb_tree<Data>::find(const Data& target) const{
  return this->find(this->root, target);
}

template <typename Data> const Data* sb_tree<Data>::find(BTNode<Data>* crr_root, const Data& target) const{
  if(crr_root == nullptr)
    return nullptr;

  if(target < crr_root->data){
    return find(crr_root->left, target);
  } else if( target > crr_root->data){
    return find(crr_root->right, target);
  }

  return &(crr_root->data);
}

template <typename Data> 
BTNode<Data>*& sb_tree<Data>::find_replacement(BTNode<Data>*& crr_root){
  if(crr_root->right == nullptr)
    return crr_root;
  return find_replacement(crr_root->right);
}
};
