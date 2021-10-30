#include <iostream>
#include <string>
#include "node.h"

// Generic Binary Search Tree
template <class T>
struct BST {
    // The root node of the tree
    Node<T> *root;

    // Definitions
    BST();


    void UpdateNode(Node<T> *root, T *data, T *replace);
    Node<T> *RemoveNode(Node<T> *rt, T *data);
    void InsertNode (T *data);
    void inOrder(Node<T> *n);
    void preOrder(Node<T> *n);
    void postOrder(Node<T> *n);
};