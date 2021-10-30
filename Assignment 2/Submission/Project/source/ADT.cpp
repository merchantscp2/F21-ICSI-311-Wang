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
bool ADT::Find(Person *person) {
    tree->FindData(tree->root, person);
}

// Searches and lists: People with the same day of birth/month of birth/year of birth/ and also finds
// and lists all who have occurance of search
void ADT::Search(SearchMode mode, std::string search, DOBElement dobElement, int query) {
    if(mode == NAME)
        tree->SearchName(tree->root, search);
    else
        switch(dobElement) {
            case DAY:
                tree->SearchDay(tree->root, query);
                break;
            case MONTH:
                tree->SearchMonth(tree->root, query);
                break;
            case YEAR:
                tree->SearchYear(tree->root, query);
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