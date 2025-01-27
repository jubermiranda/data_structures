#ifndef MY_DS_LINKED_H_
#define MY_DS_LINKED_H_

#include <stdexcept>
#include <string>

using std::string;

namespace MY_DS {

template <typename DataType> class Node {
public:
  Node(DataType data);
  Node(DataType data, Node *next);
  ~Node();

private:
  DataType data;
  Node *next;
};

template <typename DataType> class List {
public:
  List() : crr_size(0), root(nullptr){};
  ~List();

  bool is_empty() const;
  size_t size() const;

private:
  size_t crr_size;
  Node<DataType> *root;
};

// --
// IMPL

}; // namespace MY_DS

#endif // MY_DS_LINKED_H_
