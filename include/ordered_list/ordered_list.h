#pragma once

#include <cstddef>
#include <list>

namespace MY_DS {

template <typename T> class OrdList {
private:
  std::list<T> data;

public:
  typedef typename std::list<T>::const_iterator const_iterator;

  void insert(const T&);
  void remove(const T&);

  size_t size() const;
  const_iterator begin() const;
  const_iterator end() const;
};

#include "ordered_list.tpp"

} // namespace MY_DS
