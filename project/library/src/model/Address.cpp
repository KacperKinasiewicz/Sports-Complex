#include "model/Address.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pCity - string address city name
/// \param pStreet - string address street name
/// \param pNumber - string address number
Address::Address(const std::string &pCity, const std::string &pStreet, const std::string &pNumber) : city(pCity), street(pStreet), number(pNumber) {}
Address::Address() {}
Address::~Address() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of city, street, number with spaces between
const std::string Address::getInfo() const {
    std::string temp = "";

    temp += "Address: " + this->city + " ul. " + this->street + " " + this->number + "\n";

    return temp;
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string city
const std::string &Address::getCity() const {return this->city;}

///
/// \return - returns string street
const std::string &Address::getStreet() const {return this->street;}

///
/// \return - returns string number
const std::string &Address::getNumber() const {return this->number;}

// s -------------------------------------------------------------------------------------------------------------------
///
/// \param pCity - city
void Address::setCity(const std::string &pCity) {if(pCity != "") this->city = pCity;}

///
/// \param pStreet - street
void Address::setStreet(const std::string &pStreet) {if(pStreet != "") this->street = pStreet;}

///
/// \param pNumber - number
void Address::setNumber(const std::string &pNumber) {if(pNumber != "") this->number = pNumber;}