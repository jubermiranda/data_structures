#ifndef MY_DS_NODE_H_
#define MY_DS_NODE_H_

template <typename DataType> class Node {
public:
  Node(DataType data);
  Node(DataType data, Node<DataType> *next);
  ~Node();

  DataType data() { return _data; }
  Node<DataType> *next() { return _next; }


private:
  DataType _data;
  Node<DataType> *_next;
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

template <typename DataType> 
Node<DataType>::~Node() {
  if(this->_next != nullptr)
    ~(this->_next);
}

#endif // MY_DS_NODE_H_
