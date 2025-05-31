#include <stdexcept>

#include "stack.h"

namespace MY_DS {

template <typename T> Stack<T>::Stack() : crr_size(0), stack_top(nullptr) {}

template <typename T> Stack<T>::~Stack() { this->clear(); }

template <typename T> const T Stack<T>::top() const {
  if (this->crr_size == 0)
    throw new std::runtime_error("empty stack");
  if (this->stack_top == nullptr)
    throw new std::runtime_error("empty stack");
  return this->stack_top.data;
}

template <typename T> void Stack<T>::push(T data) {
  Node<T> *new_node = new Node<T>(data, this->stack_top);
  this->stack_top = new_node;
  this->crr_size++;
}

template <typename T> T Stack<T>::pop() {
  if (this->crr_size == 0)
    throw new std::runtime_error("empty stack");
  Node<T> *to_delete = this->stack_top;
  this->stack_top = this->stack_top.next;

  T data = to_delete->data;
  delete(to_delete);
  this->crr_size--;

  return data;
}


template <typename T> bool Stack<T>::is_empty() const{
  return (this->crr_size == 0);
}

template <typename T> size_t Stack<T>::size() const{
  return this->crr_size;
}

template <typename T> void Stack<T>::clear() {
  if (this->crr_size == nullptr)
    return;

  Node<T> *aux;
  while (this->stack_top != nullptr) {
    aux = this->stack_top;
    this->stack_top = this->stack_top.next;
    delete (aux);
  }
}

} // namespace MY_DS
