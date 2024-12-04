#ifndef H_addressType
#define H_addressType

#include <string>
#include <iostream>

class addressType
{
public:
    addressType();
    void setAddress(const std::string &street, const std::string &city,
                    const std::string &state, const std::string &zip);
    std::string getStreet() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getZip() const;
    void print() const;

private:
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
};

#endif