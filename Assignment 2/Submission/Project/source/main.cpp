#include <iostream>
#include <fstream>
//#include "BST.h"
//#include "person.h"
#include "ADT.h"

// Read from file and add to array
void PopulatePeopleFromFile(Person pPeople[25]);
// Run tests that show completion of the rubric
void RunDatabaseTests(ADT *dDatabase, Person pPeople[25]);


// Driver/Tester Method
int main() {
    // Array to store the test data
    Person people[25];

    // Read from People.txt file
    PopulatePeopleFromFile(people);

    std::cout << "\n==================================================\n";
    std::cout << "Creating a new ADT with Person generic type\n";
    ADT *database = new ADT();

    std::cout << "Printing current database content (empty)\n";
    database->List(ADT::INORDER);

    std::cout << "Adding people to the database (25)\n";
    for(auto & i : people) {
        database->Add(&i);
    }

    RunDatabaseTests(database, people);

    return 0;
}

void RunDatabaseTests(ADT *dDatabase, Person pPeople[25]) {

    // Full Listing - Check
    std::cout << "\n>>Listing people Preorder<<\n";
    dDatabase->List(ADT::PREORDER);

    std::cout << "\n>>Listing database Inorder<<\n";
    dDatabase->List(ADT::INORDER);

    std::cout << "\n>>Listing database Postorder<<\n";
    dDatabase->List(ADT::POSTORDER);

    // Searching - Check
    std::cout << "\n>>Searching for " << pPeople[13] << "<< (exists in db)\n";
    bool found; // found bool
    dDatabase->Find(&pPeople[13], found = false); // Put whether or not its found in found
    std::cout << (found ? "Person was located\n" : "Person was not located\n"); // print if found or not

    // Create a new person to search for
    Person *gb = new Person("Gabe Brandt", 10, 2, 1980);
    std::cout << "\n>>Searching for " << *gb << " (does not exists in db)<<\n";
    dDatabase->Find(gb, found = false); // see if its found and store it in found
    std::cout << (found ? "Person was located\n" : "Person was not located\n"); // print if found or not
    free(gb);

    // Removing - Check
    std::cout << "\n>>Removing " << pPeople[0] << " from the database<<\n";
    dDatabase->Remove(pPeople[0]);

    std::cout << "Listing database Inorder\n";
    dDatabase->List(ADT::INORDER);

    // Search Listings - Check
    std::cout << "\n\n>>Listing all people with 'am' in their name<<\n";
    dDatabase->Search(ADT::NAME, "am");

    std::cout << "\n\n>>Listing all people born in October<<\n";
    dDatabase->Search(ADT::DOB, "", ADT::MONTH, 10);

    std::cout << "\n\n>>Listing all people born on the 25th<<\n";
    dDatabase->Search(ADT::DOB, "", ADT::DAY, 25);

    std::cout << "\n\n>>Listing all people born in 1999<<\n";
    dDatabase->Search(ADT::DOB, "", ADT::YEAR, 1999);

    std::cout << "\n\n>>Changing " << pPeople[5] << "'s name to Kevin Poopy and birth month to December<<\n";
    Person *kp = new Person(); // Create a new Person
    kp->copy(&pPeople[5]); // Copy from aarav
    kp->name = "Kevin Poopy"; // change the name to kevin
    kp->dob_month = 12; // change the birth month to december
    dDatabase->Update(&pPeople[5], kp); // Update it

    std::cout << "Listing database Inorder\n";
    dDatabase->List(ADT::INORDER);

}

void PopulatePeopleFromFile(Person pPeople[25])
{
    // New filestream for the testing data
    std::fstream peopleFile;
    peopleFile.open("People.txt", std::iostream::in);

    // If it's found and can be opened
    if(peopleFile.is_open()) {
        // String to hold the line, and an integer counter
        std::string ln;
        int i = 0;
        while (getline(peopleFile, ln)) {
            // Set the name to everything before the ,
            pPeople[i].name = ln.substr(0,ln.find_first_of(','));
            // set the dob_day to what's between , and /
            pPeople[i].dob_day = stoi(ln.substr(ln.find_first_of(',')+1, 2));
            // Set the dob_month to what's inbetween the two /'s
            pPeople[i].dob_month = stoi(ln.substr(ln.find('/',0)+1, 2));
            // Set the dob_year to whatever follows /
            pPeople[i].dob_year = stoi(ln.substr(ln.find('/', 0)+4, 4));
            i++; // increment counter
        }
        // Close the file
        peopleFile.close();
    }
}