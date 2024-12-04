#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "../include/addressBookType.h"

using namespace std;

void loadAddressBook(addressBookType &adBook, bool &flag);
void showMenu();

int main()
{
    cout << "Current working directory: " << filesystem::current_path() << endl;

    addressBookType addressBook;
    string filename;
    string firstName, lastName;
    bool flag = false;
    int choice;

    // Load entries from the file
    loadAddressBook(addressBook, flag);

    if (flag)
    {
        cout << "Input file does not exist. Program terminates!" << endl;
        return 1;
    }

    // Display menu and process user input
    do
    {
        showMenu();
        cin >> choice;
        cin.ignore(100, '\n'); // Ignore trailing newline

        switch (choice)
        {
        case 1: // Add a new entry
        {
            extPersonType newEntry;
            cout << "Enter details for new entry (First Name, Last Name, DOB (MM DD YYYY), Address, Phone, Status):" << endl;
            string street, city, state, zip, phone, status;
            int month, day, year;

            cout << "First Name: ";
            getline(cin, firstName);
            cout << "Last Name: ";
            getline(cin, lastName);
            cout << "Date of Birth (MM DD YYYY): ";
            cin >> month >> day >> year;
            cin.ignore(100, '\n');
            cout << "Street: ";
            getline(cin, street);
            cout << "City: ";
            getline(cin, city);
            cout << "State: ";
            getline(cin, state);
            cout << "ZIP: ";
            getline(cin, zip);
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Status: ";
            getline(cin, status);

            newEntry.setInfo(firstName, lastName, month, day, year, street, city, state, zip, phone, status);
            addressBook.addEntry(newEntry);
        }
        break;

        case 2: // Delete an entry
            cout << "Enter the last name of the person to delete: ";
            getline(cin, lastName);
            addressBook.deleteEntry(lastName);
            break;

        case 3: // Search for an entry
            cout << "Enter the last name of the person to search: ";
            getline(cin, lastName);
            addressBook.searchEntry(lastName);
            break;

        case 4: // Display all entries
            addressBook.printAll();
            break;

        case 5: // Save to file
            cout << "Enter the file name to save the address book: ";
            getline(cin, filename);
            addressBook.saveToFile(filename);
            break;

        case 6: // Load from file
            cout << "Enter the file name to load the address book: ";
            getline(cin, filename);
            addressBook.loadFromFile(filename);
            break;

        case 9: // Exit
            cout << "Program terminated!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 9);

    return 0;
}

void loadAddressBook(addressBookType &adBook, bool &flag)
{
    ifstream infile;
    string filename;

    cout << "Enter file name to load address book: ";
    cin >> filename;
    cin.ignore(100, '\n');

    string filepath = "../data/" + filename; // Adjust path based on your directory structure
    infile.open(filepath);

    if (!infile)
    {
        cerr << "Error: File \"" << filepath << "\" does not exist." << endl;
        flag = true;
        return;
    }

    extPersonType temp;
    while (temp.loadFromStream(infile)) // Load each entry into the address book
    {
        adBook.addEntry(temp);
    }

    infile.close();
    cout << "Address book loaded successfully from " << filepath << endl;
}

void showMenu()
{
    cout << "\n*** Address Book Manager ***" << endl;
    cout << "1: Add a new entry" << endl;
    cout << "2: Delete an entry" << endl;
    cout << "3: Search for an entry" << endl;
    cout << "4: Display all entries" << endl;
    cout << "5: Save address book to file" << endl;
    cout << "6: Load address book from file" << endl;
    cout << "9: Exit" << endl;
    cout << "Enter your choice: ";
}