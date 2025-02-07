#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <stdexcept>

namespace MY_DS {

template <typename T> class List;
template <typename T> class DNode;

template <typename T> class iterator {
  friend class MY_DS::List<T>;

private:
  List<T> *src;
  typename List<T>::DNode *crr;

  iterator(List<T> *src_list, DNode<T> *pos) : src(src_list), crr(pos) {}

public:
  T &operator*() const {
    if (this->crr == nullptr)
      throw std::invalid_argument("End of list");
    return this->crr->data;
  }
};

}; // namespace MY_DS

#endif // ITERATOR_H_
