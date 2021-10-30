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

    bool FindData(Node<T> *root, T *data);
    void SearchMonth(Node<T> *root, int month);
    void SearchDay(Node<T> *root, int day);
    void SearchYear(Node<T> *root, int year);
    void SearchName(Node<T> *root, std::string search);
    void UpdateNode(Node<T> *root, T *data, T *replace);
    Node<T> *RemoveNode(Node<T> *rt, T *data);
    void InsertNode (T *data);
    void inOrder(Node<T> *n);
    void preOrder(Node<T> *n);
    void postOrder(Node<T> *n);
};