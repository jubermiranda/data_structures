#ifndef MY_DS_LINKED_H_
#define MY_DS_LINKED_H_

#include <stdexcept>
#include <string>

#include "node.h"

using std::string;

namespace MY_DS {

template <typename DataType> class List {
public:
  List() : crr_size(0), root(nullptr){};

  bool is_empty() const { return crr_size == 0; };
  size_t size() const { return crr_size; };

private:
  size_t crr_size;
  Node<DataType> *root;

  void clear();
};

// --
// IMPL


};     // namespace MY_DS
#endif // MY_DS_LINKED_H_
