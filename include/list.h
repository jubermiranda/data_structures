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

  void push(const DataType &new_node);

private:
  size_t crr_size;
  Node<DataType> *root;

  void clear();
};

// --
// IMPL

template <typename DataType>
void List<DataType>::push(const DataType &new_data) {
  Node<DataType> *new_node = new Node<DataType>(new_data);
  if (root == nullptr) {
    root = new_node;
    crr_size++;
    return;
  }

  Node<DataType> *aux = root;
  while (aux->next != nullptr) {
    if (aux->next->data > new_node->data) {
      new_node->next = aux->next;
      aux->next = new_node;
      crr_size++;
      return;
    }
    aux = aux->next;
  }

  aux->next = new_node;
  crr_size++;
}

};     // namespace MY_DS
#endif // MY_DS_LINKED_H_
