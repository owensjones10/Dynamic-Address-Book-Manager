#include "../include/addressType.h"
#include <iostream>
using namespace std;

addressType::addressType() : streetAddress(""), city(""), state(""), zipCode("") {}

void addressType::setAddress(const string &street, const string &city,
                             const string &state, const string &zip)
{
    streetAddress = street;
    this->city = city;
    this->state = state;
    zipCode = zip;
}

string addressType::getStreet() const { return streetAddress; }
string addressType::getCity() const { return city; }
string addressType::getState() const { return state; }
string addressType::getZip() const { return zipCode; }

void addressType::print() const
{
    cout << streetAddress << ", " << city << ", " << state << " " << zipCode;
}