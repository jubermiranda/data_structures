#pragma once

#include <iostream>

template <typename Data>
class b_tree {
private:
    BTNode<Data> *root;
    size_t node_count = 0;

public:
    b_tree() : root(nullptr) {}
    b_tree(const Data &data);

    bool empty() const;

    size_t size() const;
    size_t height() const;

    void insert(const Data &data);
    void remove(const Data &data);
    void clear();

    BTNode<Data> *find(const Data &data) const;

    // stream operator for development and debugging
    friend std::ostream &operator<<(std::ostream &os, const b_tree<Data> &tree);

private:
    // private constructor for creating a tree from an existing root node
    b_tree(BTNode<Data> *root) : root(root) {}
};

#include "b_tree_node.tpp"
