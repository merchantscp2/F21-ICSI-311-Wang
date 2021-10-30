//
// Created by Amit Merchant on 10/28/2021.
//

#include "ADT.h"
// Default constructor. Initializes an empty tree.
ADT::ADT() {
    tree = new BST<Person>();
}

//    explicit ADT(Person *people[]) {
//        tree = new BST<Person>();
//
//        for(int i = 0; i < (sizeof(**people)/2 + 1); i++) {
//           tree->InsertNode(people[i]);
//        }
//    }

// Lists the tree in PREORDER, INORDER, or POSTORDER
void ADT::List(ListMode mode) {
    switch (mode) {
        case PREORDER:
            tree->preOrder(tree->root);
            break;
        case INORDER:
            tree->inOrder(tree->root);
            break;
        case POSTORDER:
            tree->postOrder(tree->root);
            break;
    }
}

// Checks if a person is in the tree
bool ADT::Find(Person *person, bool &found) {
    ADT::FindData(tree->root, person, found);
}

// Searches and lists: People with the same day of birth/month of birth/year of birth/ and also finds
// and lists all who have occurance of search
void ADT::Search(SearchMode mode, std::string search, DOBElement dobElement, int query) {
    if(mode == NAME)
        ADT::SearchName(tree->root, search);
    else
        switch(dobElement) {
            case DAY:
                ADT::SearchDay(tree->root, query);
                break;
            case MONTH:
                ADT::SearchMonth(tree->root, query);
                break;
            case YEAR:
                ADT::SearchYear(tree->root, query);
                break;
        }
}

// Adds a person to the tree
void ADT::Add(Person *person) {
    tree->InsertNode(person);
}

//    void AddFromArray(Person *p[]) {
//        for(auto & i : p) {
//            tree->InsertNode(&p[&i]);
//        }
//    }

// Removes a person from the tree
void ADT::Remove(Person person) {
    tree->root = tree->RemoveNode(tree->root, &person);
}

// Updates/modifies a person in the tree
void ADT::Update(Person *person, Person *updated) {
    tree->UpdateNode(tree->root, person, updated);
}


// Returns whether a person is present in a tree
bool ADT::FindData(Node<Person> *root, Person *person, bool &value) {
    // If it's null, return false
    if(root == nullptr) { return false; }
    // If we find one that's the same set value to true
    if(root->data->name == person->name) {
        value = true;
        return true;
    }
    // Recursively iterate through the tree to check all instances
    FindData(root->left, person, value);
    FindData(root->right, person, value);
}

// Find and print all instances with the same month
void ADT::SearchMonth(Node<Person> *root, int month) {
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
void ADT::SearchDay(Node<Person> *root, int day) {
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
void ADT::SearchYear(Node<Person> *root, int year) {
    if(root == nullptr) return;
    if(((int)root->data->dob_year) == year)
        std::cout << *root->data << "; ";
    SearchYear(root->left, year);
    SearchYear(root->right, year);
}

// Find and print all instances where the search string is a substring of the name
// Same logic as above
void ADT::SearchName(Node<Person> *root, const std::string& search) {
    if(root == nullptr) return;
    if(((std::string)root->data->name).find(search) != std::string::npos)
        std::cout << *root->data << "; ";
    SearchName(root->left, search);
    SearchName(root->right, search);
}