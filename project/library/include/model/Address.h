#ifndef COURTRENTAL_ADDRESS_H
#define COURTRENTAL_ADDRESS_H

#include "typedefs.h"

class Address {
private:
    std::string city;
    std::string street;
    std::string number;

public:
    Address();
    Address(const std::string &pCity, const std::string &pStreet, const std::string &pNumber);
    ~Address();

    const std::string getInfo() const;

    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;

    void setCity(const std::string &pCity);
    void setStreet(const std::string &pStreet);
    void setNumber(const std::string &pNumber);
};

#endif //COURTRENTAL_ADDRESS_H