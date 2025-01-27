#ifndef MY_DS_NODE_H_
#define MY_DS_NODE_H_

template <typename DataType> class Node {
public:
  Node(DataType data);
  Node(DataType data, Node<DataType> *next);

  DataType data;
  Node<DataType> *next;
};

// --
// IMPL

template <typename DataType> 
Node<DataType>::Node(DataType data) {
  this->data = data;
  this->next = nullptr;
}

template <typename DataType> 
Node<DataType>::Node(DataType data, Node<DataType> *next) {
  this->data = data;
  this->next = next;
}


#endif // MY_DS_NODE_H_
