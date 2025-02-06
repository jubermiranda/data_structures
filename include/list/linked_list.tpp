#ifndef LINKED_TPP_
#define LINKED_TPP_

#include "linked_list.h"

#include <stdexcept>

namespace MY_DS {

template <typename T>
LinkedList<T>::LinkedList() : root(nullptr), crr_size(0) {}

template <typename T> LinkedList<T>::~LinkedList() {
  this->clear();
}

template <typename T> void LinkedList<T>::push_front(const T &value) {
  this->root = new Node<T>(value, this->root);
  crr_size++;
}

template <typename T> void LinkedList<T>::push_back(const T &value) {
  if (this->root == nullptr) {
    this->root = new Node<T>(value);
    crr_size++;
    return;
  }

  Node<T> *crr_pos = this->root;
  while (crr_pos->next != nullptr)
    crr_pos = crr_pos->next;
  crr_pos->next = new Node<T>(value);
  crr_size++;
}

template <typename T> void LinkedList<T>::pop_front() {
  if (this->root != nullptr) {
    Node<T> *aux = this->root;
    this->root = this->root->next;
    delete aux;
    crr_size--;
  }
}

template <typename T> void LinkedList<T>::pop_back() {
  if (this->root != nullptr) {
    if (this->crr_size == 1) {
      delete this->root;
      this->root = nullptr;
      crr_size--;
      return;
    }
    if (this->crr_size == 2) {
      delete this->root->next;
      this->root->next = nullptr;
      crr_size--;
      return;
    }

    Node<T> *aux = this->root;
    while (aux->next->next != nullptr)
      aux = aux->next;
    delete aux->next;
    aux->next = nullptr;
    crr_size--;
  }
}

template <typename T> T LinkedList<T>::front() const {
  if (this->root == nullptr)
    throw std::runtime_error("Empty list");

  return this->root->data;
}

template <typename T> T LinkedList<T>::back() const {
  if (this->root == nullptr)
    throw std::runtime_error("Empty list");

  Node<T> *aux = this->root;
  while (aux->next != nullptr)
    aux = aux->next;

  return aux->data;
}

template <typename T> bool LinkedList<T>::is_empty() const {
  return (this->crr_size == 0);
}

template <typename T> size_t LinkedList<T>::size() const {
  return this->crr_size;
}

template <typename T> void LinkedList<T>::clear() {
  while (this->root != nullptr) {
    Node<T> *aux = this->root;
    this->root = root->next;
    delete aux;
  }
  this->crr_size = 0;
}

} // namespace MY_DS

#endif // LINKED_TPP_
