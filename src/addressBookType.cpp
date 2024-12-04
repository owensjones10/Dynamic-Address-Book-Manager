// addressBookTypeImp.cpp

#include "../include/addressBookType.h"
#include <fstream>
#include <iostream>

using namespace std;

// Constructor
addressBookType::addressBookType() : orderedLinkedList<extPersonType>() {}

// Add a new entry to the address book
void addressBookType::addEntry(const extPersonType &newEntry)
{
    insert(newEntry); // Insert the entry into the ordered linked list
    cout << "Entry added successfully.\n";
}

// Delete an entry based on the last name
void addressBookType::deleteEntry(const string &lastName)
{
    bool found = false;
    traverse([&](const extPersonType &entry)
             {
        if (entry.getLastName() == lastName)
        {
            found = true;
            deleteNode(entry);
            cout << "Entry deleted successfully.\n";
        } });

    if (!found)
    {
        cout << "Entry not found.\n";
    }
}

// Search for an entry by last name and display its details
void addressBookType::searchEntry(const string &lastName) const
{
    bool found = false;
    traverse([&](const extPersonType &entry)
             {
        if (entry.getLastName() == lastName)
        {
            found = true;
            entry.printInfo();
        } });

    if (!found)
    {
        cout << "Entry not found.\n";
    }
}

// Print all entries in the address book
void addressBookType::printAll() const
{
    cout << "Printing all entries in the address book:\n";
    traverse([](const extPersonType &entry)
             { entry.printInfo(); });
}

// Load address book entries from a file
void addressBookType::loadFromFile(const string &filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    extPersonType temp;
    int count = 0;

    while (temp.loadFromStream(infile)) // Assumes extPersonType has a loadFromStream method
    {
        addEntry(temp);
        count++;
    }

    infile.close();
    cout << count << " entries loaded from " << filename << endl;
}

// Save address book entries to a file
void addressBookType::saveToFile(const string &filename) const
{
    ofstream outfile(filename);
    if (!outfile)
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    traverse([&](const extPersonType &entry)
             {
                 entry.saveToStream(outfile); // Assumes extPersonType has a saveToStream method
             });

    outfile.close();
    cout << "Address book saved to " << filename << endl;
}