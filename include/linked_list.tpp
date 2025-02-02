#ifndef LINKED_TPP_
#define LINKED_TPP_

#include "node.h"

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
  Node<T> *new_node(value, this->root);
  this->root = new_node;
  crr_size++;
} 

} // namespace MY_DS

#endif // LINKED_TPP_
