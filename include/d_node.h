#ifndef D_NODE_H_
#define D_NODE_H_

template <typename T> class DNode {
public:
  T data;
  DNode<T> *next;
  DNode<T> *prev;

  DNode(const T &value, DNode<T> *next_node = nullptr, DNode<T> *prev_node = nullptr)
      : data(value), next(next_node), prev(prev_node){};
};

#endif // D_NODE_H_
