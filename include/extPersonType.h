// extPersonType.h

#ifndef H_extPersonType
#define H_extPersonType

#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>
#include <iostream>

class extPersonType : public personType
{
public:
    extPersonType(); // Default constructor

    void setInfo(const std::string &firstName, const std::string &lastName,
                 int month, int day, int year,
                 const std::string &street, const std::string &city,
                 const std::string &state, const std::string &zip,
                 const std::string &phone, const std::string &status);

    void printInfo() const;

    bool loadFromStream(std::istream &in);
    void saveToStream(std::ostream &out) const;

    // Overloaded comparison operators
    bool operator<(const extPersonType &other) const;
    bool operator==(const extPersonType &other) const;
    bool operator!=(const extPersonType &other) const;

private:
    dateType birthDate;
    addressType address;
    std::string phoneNumber;
    std::string personStatus;
};

#endif