#include <string>
#include "BST.h"
#include "person.h"

// Class for the Abstract Data Type
struct ADT {
public:
    // Helpers
    enum ListMode {PREORDER, INORDER, POSTORDER};
    enum SearchMode {NAME, DOB};
    enum DOBElement {NONE, MONTH, DAY, YEAR};

    // The tree that the ADT is going to be the "front-end" for
    BST<Person> *tree;

    // Method Definitions
    ADT();
    void List(ListMode m);
    bool Find(Person *person, bool &found);
    void Search(SearchMode m, std::string search = "", DOBElement dobElement = NONE, int query = -1);
    void Add(Person *person);
    void Remove(Person person);
    void Update(Person *person, Person *updated);
    bool FindData(Node<Person> *root, Person *person, bool &found);
    void SearchMonth(Node<Person> *root, int month);
    void SearchDay(Node<Person> *root, int day);
    void SearchYear(Node<Person> *root, int year);
    void SearchName(Node<Person> *root, const std::string& search);
};