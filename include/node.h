#pragma once

template <typename Data> class Node {
public:
  Data data;
  Node<Data> *next;

  Node(const Data &value, Node<Data> *next_node = nullptr)
      : data(value), next(next_node){};
};

template <typename Data> class DNode {
public:
  Data data;
  DNode<Data> *next;
  DNode<Data> *prev;

  DNode(const Data &value, DNode<Data> *next_node = nullptr, DNode<Data> *prev_node = nullptr)
      : data(value), next(next_node), prev(prev_node){};
};

template <typename Data> class BTNode {
public:
    Data data;
    BTNode<Data> *left;
    BTNode<Data> *right;


    BTNode(const Data &value, BTNode<Data> *left_node = nullptr, BTNode<Data> *right_node = nullptr)
        : data(value), left(left_node), right(right_node){};

};
