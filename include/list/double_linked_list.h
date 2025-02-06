#ifndef DOUBLE_LINKED_H_
#define DOUBLE_LINKED_H_

#include "node.h"
#include <cstddef>

namespace MY_DS {

template <typename T> class DoubleLinkedList {
private:
  DNode<T> *root;
  size_t crr_size;

public:
  DoubleLinkedList();
  ~DoubleLinkedList();

  void push_front(const T &value);
  void push_back(const T &value);
  void pop_front();
  void pop_back();

  T front() const;
  T back() const;

  bool is_empty() const;
  size_t size() const;

  void clear();
};

} // namespace MY_DS

// IMPL
#include "double_linked_list.tpp"

#endif // DOUBLE_LINKED_H_
