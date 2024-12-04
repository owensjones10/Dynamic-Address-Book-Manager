// extPersonTypeImp.cpp

#include "../include/extPersonType.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
extPersonType::extPersonType() : personType(), birthDate(), address(), phoneNumber(""), personStatus("") {}

// Set the information for the person
void extPersonType::setInfo(const string &firstName, const string &lastName,
                            int month, int day, int year,
                            const string &street, const string &city,
                            const string &state, const string &zip,
                            const string &phone, const string &status)
{
    setName(firstName, lastName);
    birthDate.setDate(month, day, year);
    address.setAddress(street, city, state, zip);
    phoneNumber = phone;
    personStatus = status;
}

// Print all details of the person
void extPersonType::printInfo() const
{
    cout << "Name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Date of Birth: ";
    birthDate.printDate();
    cout << endl;
    cout << "Address: ";
    address.print();
    cout << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Status: " << personStatus << endl;
}

// Load person's data from a file/stream
bool extPersonType::loadFromStream(istream &in)
{
    string firstName, lastName, street, city, state, zip, phone, status;
    int month, day, year;

    if (in >> firstName >> lastName >> month >> day >> year)
    {
        in.ignore(100, '\n');
        getline(in, street);
        getline(in, city);
        getline(in, state);
        in >> zip >> phone >> status;
        setInfo(firstName, lastName, month, day, year, street, city, state, zip, phone, status);
        return true;
    }
    return false;
}

// Save person's data to a file/stream
void extPersonType::saveToStream(ostream &out) const
{
    out << getFirstName() << " " << getLastName() << " "
        << birthDate.getMonth() << " " << birthDate.getDay() << " " << birthDate.getYear() << endl;
    out << address.getStreet() << endl;
    out << address.getCity() << endl;
    out << address.getState() << endl;
    out << address.getZip() << " " << phoneNumber << " " << personStatus << endl;
}

// Overloaded comparison operators
bool extPersonType::operator<(const extPersonType &other) const
{
    return getLastName() < other.getLastName() ||
           (getLastName() == other.getLastName() && getFirstName() < other.getFirstName());
}

bool extPersonType::operator==(const extPersonType &other) const
{
    return getFirstName() == other.getFirstName() && getLastName() == other.getLastName();
}

bool extPersonType::operator!=(const extPersonType &other) const
{
    return !(*this == other);
}