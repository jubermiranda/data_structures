#include "list_iter/list.h"
#include <stdexcept>

using namespace MY_DS;

template <typename T> bool List<T>::operator==(const List<T> &other) const {
  if (*this != other) {
    if (other == nullptr)
      return false;

    return (this->head == other.head && this->tail == other.tail &&
            this->num_items == other.num_items);
  } else
    return true;
}

template <typename T> bool List<T>::operator!=(const List<T> &other) const {
  return (!(*this == other));
}

template <typename T> bool List<T>::operator==(void *ptr) const {
  return false;
}

template <typename T> bool List<T>::operator!=(void *ptr) const {
  return (!(this == ptr));
}

template <typename T> List<T>::List() {
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

template <typename T> List<T>::List(const List<T> &other) {
  head = nullptr;
  tail = nullptr;
  num_items = 0;

  for (auto iter = other.begin(); iter != other.end(); ++iter) {
    push_back(*iter);
  }
}

template <typename T> List<T> &List<T>::operator=(const List<T> &other) {
  if (*this != other) {
    List<T> tmp_copy(other);
    swap(tmp_copy);
  }
  return *this;
}

template <typename T> List<T>::~List<T>() { this->clear(); }

template <typename T> void List<T>::push_front(const T &item) {
  head = new DNode<T>(item, head, nullptr);
  if (head->next != nullptr)
    head->next->prev = head;
  if (tail == nullptr)
    tail = head;

  num_items++;
}

template <typename T> void List<T>::push_back(const T &item) {
  if (tail != nullptr) {
    tail->next = new DNode<T>(item, nullptr, tail);
    tail = tail->next;
    num_items++;
  } else
    push_front(item);
}

template <typename T> void List<T>::pop_front() {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform pop_front");

  DNode<T> *to_remove = head;
  head = head->next;
  delete to_remove;

  if (head != nullptr)
    head->prev = nullptr;
  else
    tail = nullptr;

  num_items--;
}

template <typename T> void List<T>::pop_back() {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform pop_front");

  DNode<T> *to_remove = tail;
  tail = tail->prev;
  delete to_remove;

  if (tail != nullptr)
    tail->next = nullptr;
  else
    head = nullptr;

  num_items--;
}

template <typename T>
iterator<T> List<T>::insert(iterator<T> pos, const T &item) {
  if (pos.crr == head) {
    push_front(item);
    return begin();
  } else if (pos.crr == nullptr) {
    push_back(item);
    return iterator<T>(this, tail);
  }

  DNode<T> *new_node = new DNode<T>(item, pos.crr, pos.crr->prev);
  pos.crr->prev->next = new_node;
  pos.crr->prev = new_node;
  num_items++;

  return iterator<T>(this, new_node);
}

template <typename T> iterator<T> List<T>::erase(iterator<T> pos) {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform erase");
  if (pos == end())
    throw std::runtime_error("cannot erase end iterator");
  iterator<T> to_remove = pos++;

  if (to_remove.crr == head) {
    pop_front();
  } else if (to_remove.crr == tail) {
    pop_back();
  } else {
    to_remove.crr->prev->next = to_remove.crr->next;
    to_remove.crr->next->prev = to_remove.crr->prev;
    delete to_remove.crr;
  }

  return pos;
}

template <typename T> T &List<T>::front() {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform erase");
  return (head->data);
}

template <typename T> const T &List<T>::front() const {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform erase");
  return (head->data);
}

template <typename T> T &List<T>::back() {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform erase");
  return (tail->data);
}

template <typename T> const T &List<T>::back() const {
  if (is_empty())
    throw std::runtime_error("empty list. cannot perform erase");
  return (tail->data);
}

template <typename T> const iterator<T> List<T>::begin() const {
  // TODO
}

template <typename T> iterator<T> List<T>::begin() {
  // TODO
}

template <typename T> const iterator<T> List<T>::end() const {
  // TODO
}

template <typename T> iterator<T> List<T>::end() {
  // TODO
}

template <typename T> void List<T>::swap(List<T> other) {
  // TODO
}

template <typename T> bool List<T>::is_empty() const {
  // TODO
}

template <typename T> size_t List<T>::size() const {
  // TODO
}

template <typename T> void List<T>::clear() {
  while (head != nullptr) {
    DNode<T> *aux = head;
    head = head->next;
    delete aux;
  }
  tail = nullptr;
  num_items = 0;
}

