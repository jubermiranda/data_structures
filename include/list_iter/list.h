#ifndef ITER_LIST_H_
#define ITER_LIST_H_

#include <cstddef>
#include "iterator.h"

namespace MY_DS {

template <typename T> class List {
private:
#include "../node.h"
public:
  friend class iterator<T>;

private:
  DNode<T> *begin;
  DNode<T> *end;
  size_t num_items;

public:
  List();
  List(const List<T> &other);
  ~List();
  List<T> &operator=(const List<T> &other);

  void push_front(const T &item);
  void push_back(const T &item);
  void pop_front();
  void pop_back();

  iterator<T> insert(iterator<T> pos, const T &item);
  iterator<T> erase(iterator<T> pos);
};

} // namespace MY_DS

#include "list.tpp"

#endif // ITER_LIST_H_
