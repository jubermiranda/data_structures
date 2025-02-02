#ifndef NODE_H_
#define NODE_H_

template <typename T> class Node {
private:
  T data;
  Node<T> *next;

public:
  Node(const T &value, Node<T> *next_node = nullptr)
      : data(value), next(next_node){};
};

#endif // NODE_H_
