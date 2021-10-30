#include <iostream>
#include <string>
// Person object
struct Person {
    // Person's information
    std::string name;
    int dob_day, dob_month, dob_year;

    // Constructors
    Person() = default;
    Person(std::string name, int dob_day, int dob_month, int dob_year) {
        this->name = name;
        this->dob_day = dob_day;
        this->dob_month = dob_month;
        this->dob_year = dob_year;
    }
    explicit Person(std::string name) {
        this->name = name;
        this->dob_day = this->dob_month = this->dob_year = -1;
    }

    // Method that copies another Person object's values (if changed/wanted) into this
    void update(Person *p) {
        this->name = (p->name.length() > 0) ? p->name : this->name;
        this->dob_day = (p->dob_day == -1) ? this->dob_day : p->dob_day;
        this->dob_month = (p->dob_month == -1) ? this->dob_month : p->dob_month;
        this->dob_year = (p->dob_year == -1) ? this->dob_year : p->dob_year;
    }

    // Overloaded < operator checks the first character of the name
    friend bool operator < (const Person &lhs, const Person& rhs) {
         //std::cout << "lhs: " << lhs.name.at(0) << " rhs: " << rhs.name.at(0) << "\n";
         return (lhs.name.at(0) < rhs.name.at(0));
    }

    // Overloaded > operator checks the first character of the name
    friend bool operator > (const Person &lhs, const Person& rhs) {
        //std::cout << "lhs: " << lhs.name.at(0) << " rhs: " << rhs.name.at(0) << "\n";
        return (lhs.name.at(0) > rhs.name.at(0));
    }

    // Evaluate == if the names are equal
    friend bool operator == (const Person &lhs, const Person& rhs) {
        //std::cout << "lhs: " << lhs.name << " rhs: " << rhs.name << "\n";
        return (lhs.name == rhs.name);
    }

    // Evaluate != if the names aren't equal
    friend bool operator != (const Person &lhs, const Person& rhs) {
        //std::cout << "lhs: " << lhs.name << " rhs: " << rhs.name << "\n";
        return (lhs.name != rhs.name);
    }

    // Practiaclly a toString method. Overrides << to print out the name and dob
    friend std::ostream& operator << (std::ostream& o, const Person& p)
    {
        return o << p.name<< ", " << p.dob_month << "/" << p.dob_day << "/" << p.dob_year;
    }
};

