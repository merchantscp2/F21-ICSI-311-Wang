//Separating implementations gives unresolvable linker errors.
#include "BST.h"
#include "person.h"

// Returns whether a data is present in a tree
template <typename T>
bool BST<T>::FindData(Node<T> *root, T *data) {
    // If it's null, quit
    if(root == nullptr) return false;
    // If we find one that's the same return true
    if(root->data == data) return true;
    // Recursively iterate through the tree to check all instances
    FindData(root->left, data);
    FindData(root->right, data);
}

// Find and print all instances with the same month
template <typename T>
void BST<T>::SearchMonth(Node<T> *root, int month) {
    // If it's null, quit
    if(root == nullptr) return;
    // If the month of the node matches the search
    if(((int)root->data->dob_month) == month)
        std::cout << *root->data << "; "; // Print it out
    // Recursively iterate through the tree
    SearchMonth(root->left, month);
    SearchMonth(root->right, month);
}

// Find and print al instances with same birth day
template <typename T>
void BST<T>::SearchDay(Node<T> *root, int day) {
    // If it's null, quit
    if(root == nullptr) return;
    // If the data matches the day, print it
    if(((int)root->data->dob_day) == day)
        std::cout << *root->data << "; ";
    // Iterate through all of the tree to check
    SearchDay(root->left, day);
    SearchDay(root->right, day);
}

// Find and print all inscances with same birth year. Same as above
template <typename T>
void BST<T>::SearchYear(Node<T> *root, int year) {
    if(root == nullptr) return;
    if(((int)root->data->dob_year) == year)
        std::cout << *root->data << "; ";
    SearchYear(root->left, year);
    SearchYear(root->right, year);
}

// Find and print all instances where the search string is a substring of the name
// Same logic as above
template <typename T>
void BST<T>::SearchName(Node<T> *root, std::string search) {
    if(root == nullptr) return;
    if(((std::string)root->data->name).find(search) != std::string::npos)
        std::cout << *root->data << "; ";
    SearchName(root->left, search);
    SearchName(root->right, search);
}

// Update the node's fields.
template <typename T>
void BST<T>::UpdateNode(Node<T> *root, T *data, T *replace) {
    if(root == nullptr) return; // If null, quit
    if(root->data == data) { // If we find one that matches
        root->data->update(replace); // Update the fields
        return; // Exit
    }
    // Recursively check the entire tree
    UpdateNode(root->left, data, replace);
    UpdateNode(root->right, data, replace);
}

template <typename T>
Node<T> *BST<T>::RemoveNode(Node<T> *root, T *data) {
    // if the root's null, return the root
    if (root == nullptr) {
        std::cout << "null root!";
        return root;
    }
    // If it's the one we want to delete
    if(*data == *root->data) {
        //std::cout << "FOUND! TIme to delete!";
        // If the node doesn't have children, return null
        if (root->left==nullptr and root->right==nullptr)
            return nullptr;

            // If the node doesn't have a left
        else if (root->left == nullptr) {
            Node<T>* temp = root->right; // switch it over
            free(root);
            return temp;
        }
            // If the node doesn't have a right
        else if (root->right == nullptr) {
            Node<T>* temp = root->left; // switch it over
            free(root);
            return temp;
        }

        // find the leftmost node
        Node<T>* temp = root->right;
        while (temp && temp->left != nullptr)
            temp = temp->left;

        // Move the data over
        root->data = temp->data;
        // remove the others
        root->right = RemoveNode(root->right, temp->data);
    }

    // if it's going to be to the left hand side
    else if (*data < *root->data) {
        //std::cout << "Less than!" << *root->data;
        // Iterate again but on the left
        root->left = RemoveNode(root->left, data);
    }

    // If it should be on the right side
    else if (*data > *root->data) {
        //std::cout << "Greater than!" << *root->data;
        // Iterate through the right
        root->right = RemoveNode(root->right, data);
    }
    else
        return root;
}


// Adds a node to the tree from a datatype
template <typename T>
void BST<T>::InsertNode (T *data) {
    // Create the node and give it its values
    Node<T> *node = new Node<T>();
    node->data = data;
    node->left = node->right = nullptr;

    // If there's no root, make it the root
    if(root == nullptr)
        root = node;
    else { // otherwise
        // start looking through. Set the current one to root
        Node<T> *current= root;
        Node<T> *parent = current;
        while(true) { // till we get to the end
            parent = current; // set the parent to the previously currne ont
            // If the node's data value is less than the parents, we need to go left
            if(*node->data < *parent->data) {
                current = current->left;
                // if the current is null, set its parents left node to our node and exit
                if(current == nullptr) {
                    parent->left = node;
                    return;
                }
            } else { // if its greater, we need to go right
                current = current->right;
                // if the current is null, set its parents right node to our node and exit
                if(current == nullptr) {
                    parent->right = node;
                    return;
                }
            }
        }
    }
}

// Traverse and print the tree in order recursively
template <typename T>
void BST<T>::inOrder(Node<T> *n) {
    if(n == nullptr) return;
    inOrder(n->left);
    std::cout << *n->data << std::endl;
    inOrder(n->right);
}

// Traverse and print the tree in preorder recursively
template <typename T>
void BST<T>::preOrder(Node<T> *n) {
    if(n == nullptr) return;
    std::cout << *n->data << std::endl;
    preOrder(n->left);
    preOrder(n->right);
}

// traverse and print the tree in postorder recursively
template <typename T>
void BST<T>::postOrder(Node<T> *n) {
    if(n == nullptr) return;
    postOrder(n->right);
    postOrder(n->left);
    std::cout << *n->data << std::endl;
}

// default construct that sets root to nullptr
template <typename T>
BST<T>::BST() {
    root = nullptr;
}

// defines what classes can be used in the generic. Linker issues w/o it.
template class BST<Person>;