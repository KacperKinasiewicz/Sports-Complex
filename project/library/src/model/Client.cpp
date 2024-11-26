#include "model/Client.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pFirstName - string client first name
/// \param pLastName - string client last name
/// \param pPersonalID - string client personal ID
/// \param pAddress - address pointer to client address
/// \param pClientType - client type pointer to client type
Client::Client(const std::string &pFirstName, const std::string &pLastName, const std::string &pPersonalID, const AddressPtr &pAddress, const ClientTypePtr &pClientType) : firstName(pFirstName), lastName(pLastName), personalID(pPersonalID), address(pAddress), clientType(pClientType) {}
Client::Client() {}
Client::~Client() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of client first name, last name, personal ID
const std::string Client::getInfo() const {
    std::string temp = "";
    temp += "Client\nFirst name: " + this->firstName + "\nLast name: " + this->lastName + "\nPersonal ID: " + this->personalID + "\n";
    return temp;
}

///
/// \return - returns string consisting of client first name, last name, personal ID, address info, client type info
const std::string Client::getFullInfo() const {
    std::string temp = "";
    temp += this->getInfo() + "Type: " + this->clientType->getTypeInfo() + "\n" + this->address->getInfo();
    return temp;
}

///
/// \return - returns string consisting of client actual rents
const std::string Client::getRentsInfo() const {
    std::string temp = "";

    for(int i = 0; i < this->currentRents.size(); i++)
        temp += std::to_string(i+1) + this->currentRents[i]->getInfo() + "<br>";

    return temp;
}

///
/// \param pNewRent - rent pointer to new client rent to start
void Client::appendRent(const RentPtr &pNewRent) {
    if(this->currentRents.size()<this->clientType->getMaxCourts()) this->currentRents.push_back(pNewRent);
}

///
/// \param pOldRent - rent pointer to old client rent to end
void Client::removeRent(const RentPtr &pOldRent) {
    if(pOldRent!=NULL) this->currentRents.erase(std::remove(this->currentRents.begin(), this->currentRents.end(), pOldRent), this->currentRents.end());
}

///
/// \param pPrice - double price to apply discount
/// \return - returns double price after the discount depending of client type
const double Client::applyDiscount(double pPrice) const {
    if(pPrice>=0) return this->clientType->applyDiscount(pPrice);
    else return pPrice;
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string client first name
const std::string &Client::getFirstName() const {return this->firstName;}

///
/// \return - returns string client last name
const std::string &Client::getLastName() const {return this->lastName;}

///
/// \return - returns string client personal ID
const std::string &Client::getPersonalID() const {return this->personalID;}

///
/// \return - returns address pointer to client address
const AddressPtr &Client::getAddress() const {return this->address;} // ?

///
/// \return - returns client type pointer to client type
const ClientTypePtr &Client::getClientType() const {return this->clientType;} // ?

///
/// \return - returns vector of actual client rents
const VectorRentPtr &Client::getCurrentRents() const {return this->currentRents;} // ?

// s -------------------------------------------------------------------------------------------------------------------
///
/// \param pFirstName - string client first name
void Client::setFirstName(const std::string &pFirstName) {if(pFirstName != "") this->firstName = pFirstName;}

///
/// \param pLastName - string client last name
void Client::setLastName(const std::string &pLastName) {if(pLastName != "") this->lastName = pLastName;}

///
/// \param pAddress - address pointer to client address
void Client::setAddress(const AddressPtr &pAddress) {if(pAddress != nullptr) this->address = pAddress;} // ?

///
/// \param pClientType - client type pointer to client type
void Client::setClientType(const ClientTypePtr &pClientType) {if(pClientType != nullptr) this->clientType = pClientType;} // ?