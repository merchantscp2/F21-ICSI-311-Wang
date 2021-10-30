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
    bool Find(Person *person);
    void Search(SearchMode m, std::string search = "", DOBElement dobElement = NONE, int query = -1);
    void Add(Person *person);
    void Remove(Person person);
    void Update(Person *person, Person *updated);
};