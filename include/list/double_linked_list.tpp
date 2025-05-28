#pragma once

#include "double_linked_list.h"

#include <stdexcept>

namespace MY_DS {

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : root(nullptr), crr_size(0) {}

template <typename T> DoubleLinkedList<T>::~DoubleLinkedList() {
  this->clear();
}

template <typename T> void DoubleLinkedList<T>::push_front(const T &value) {
  this->root = new DNode<T>(value, this->root);
  if(this->root->next != nullptr)
    this->root->next->prev = this->root;
  crr_size++;
}

template <typename T> void DoubleLinkedList<T>::push_back(const T &value) {
  if (this->root == nullptr) {
    this->root = new DNode<T>(value);
    crr_size++;
    return;
  }

  DNode<T> *crr_pos = this->root;
  while (crr_pos->next != nullptr)
    crr_pos = crr_pos->next;

  crr_pos->next = new DNode<T>(value, nullptr, crr_pos);
  crr_size++;
}

template <typename T> void DoubleLinkedList<T>::pop_front() {
  if (this->root != nullptr) {
    DNode<T> *aux = this->root;
    this->root = this->root->next;
    delete aux;
    crr_size--;
  }
}

template <typename T> void DoubleLinkedList<T>::pop_back() {
  if (this->root != nullptr) {
    if (this->crr_size == 1) {
      delete this->root;
      this->root = nullptr;
      crr_size--;
      return;
    }

    DNode<T> *crr = this->root;
    while (crr->next != nullptr)
      crr = crr->next;

    DNode<T> *aux = crr->prev;
    aux->next = nullptr;
    delete crr;

    crr_size--;
  }
}

template <typename T> T DoubleLinkedList<T>::front() const {
  if (this->root == nullptr)
    throw std::runtime_error("Empty list");

  return this->root->data;
}

template <typename T> T DoubleLinkedList<T>::back() const {
  if (this->root == nullptr)
    throw std::runtime_error("Empty list");

  DNode<T> *aux = this->root;
  while (aux->next != nullptr)
    aux = aux->next;

  return aux->data;
}

template <typename T> bool DoubleLinkedList<T>::is_empty() const {
  return (this->crr_size == 0);
}

template <typename T> size_t DoubleLinkedList<T>::size() const {
  return this->crr_size;
}

template <typename T> void DoubleLinkedList<T>::clear() {
  while (this->root != nullptr) {
    DNode<T> *aux = this->root;
    this->root = root->next;
    delete aux;
  }
  this->crr_size = 0;
}

} // namespace MY_DS
