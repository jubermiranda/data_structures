#ifndef LINKED_TPP_
#define LINKED_TPP_

#include "node.h"
#include <regex.h>

namespace MY_DS {

template <typename T>
LinkedList<T>::LinkedList() : root(nullptr), crr_size(0) {}

template <typename T> LinkedList<T>::~LinkedList() {
  while (this->root != nullptr) {
    Node<T> *aux = this->root;
    this->root = root->next;
    delete aux;
  }
}

template <typename T> void LinkedList<T>::push_front(const T &value) {
  this->root = new Node<T>(value, this->root);
  crr_size++;
}

template <typename T> void LinkedList<T>::push_back(const T &value) {
  if(this->root == nullptr){
    this->root = new Node<T>(value);
    crr_size++;
    return;
  }

  Node<T>* crr_pos = this->root;
  while(crr_pos->next != nullptr) crr_pos = crr_pos->next;
  crr_pos->next = new Node<T>(value);
  crr_size++;
}

} // namespace MY_DS

#endif // LINKED_TPP_
