// addressBookType.h

#ifndef H_addressBookType
#define H_addressBookType

#include "orderedLinkedList.h"
#include "extPersonType.h"
#include <string>
#include <iostream>

class addressBookType : public orderedLinkedList<extPersonType>
{
public:
    // Constructor
    addressBookType();

    // Add a new entry to the address book
    void addEntry(const extPersonType &newEntry);

    // Delete an entry based on the last name
    void deleteEntry(const std::string &lastName);

    // Search for an entry by last name and display its details
    void searchEntry(const std::string &lastName) const;

    // Print all entries in the address book
    void printAll() const;

    // Load address book entries from a file
    void loadFromFile(const std::string &filename);

    // Save address book entries to a file
    void saveToFile(const std::string &filename) const;
};

#endif