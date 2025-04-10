#pragma once

#include <stdexcept>

namespace MY_DS {

template <typename T> class List;
template <typename T> class DNode;

template <typename T> class iterator {
  friend class MY_DS::List<T>;

private:
  List<T> *src;
  DNode<T> *crr;

  iterator(List<T> *src_list, DNode<T> *pos) : src(src_list), crr(pos) {}

public:
  T &operator*() const {
    valid_crr_node();
    return this->crr->data;
  }
  T *operator->() const {
    valid_crr_node();
    return &(this->crr->data);
  }
  iterator<T> &operator++() {
    valid_crr_node();
    this->crr = this->crr->next;
    return *this;
  }
  iterator<T> &operator--() {
    valid_prev_node();
    this->crr = this->crr->prev;
    return *this;
  }
  iterator<T> &operator++(int) {
    iterator<T> initial = *this;
    this->operator++();
    return initial;
  }
  iterator<T> &operator--(int) {
    iterator<T> initial = *this;
    this->operator--();
    return initial;
  }
  bool operator==(const iterator<T> &other) const {
    return this->crr == other.crr;
  }
  bool operator!=(const iterator<T> &other) const {
    return !(this->operator==(other));
  }

private:
  void valid_crr_node() const {
    if (this->crr == nullptr)
      throw std::invalid_argument("End of list");
  }
  void valid_prev_node() const {
    if (this->crr != nullptr && this->crr->prev != nullptr)
      return;
    throw std::invalid_argument("Invalid previous node");
  }
};

template <typename T> class const_iterator {
  friend class MY_DS::List<T>;

private:
  List<T> *src;
  DNode<T> *crr;

  const_iterator(List<T> *src_list, DNode<T> *pos) : src(src_list), crr(pos) {}

public:
  const T &operator*() const {
    valid_crr_node();
    return this->crr->data;
  }
  const T *operator->() const {
    valid_crr_node();
    return &(this->crr->data);
  }
  const_iterator<T> &operator++() {
    valid_crr_node();
    this->crr = this->crr->next;
    return *this;
  }
  const_iterator<T> &operator--() {
    valid_prev_node();
    this->crr = this->crr->prev;
    return *this;
  }
  const_iterator<T> &operator++(int) {
    const_iterator<T> initial = *this;
    this->operator++();
    return initial;
  }
  const_iterator<T> &operator--(int) {
    const_iterator<T> initial = *this;
    this->operator--();
    return initial;
  }

  bool operator==(const_iterator<T> &other) const {
    return this->crr == other.crr;
  }
  bool operator!=(const_iterator<T> &other) const {
    return !(this->operator==(other));
  }

private:
  void valid_crr_node() const {
    if (this->crr == nullptr)
      throw std::invalid_argument("End of list");
  }
  void valid_prev_node() const {
    if (this->crr != nullptr && this->crr->prev != nullptr)
      return;
    throw std::invalid_argument("Invalid previous node");
  }
};

}; // namespace MY_DS
