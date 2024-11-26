#ifndef COURTRENTAL_CLIENT_H
#define COURTRENTAL_CLIENT_H

#include "typedefs.h"
#include "ClientType.h"
#include "Address.h"
#include "Rent.h"

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    VectorRentPtr currentRents = {};

public:
    Client();
    Client(const std::string &pFirstName, const std::string &pLastName, const std::string &pPersonalID, const AddressPtr &pAddress, const ClientTypePtr &pClientType); // 2 ostatnie parametry ?
    ~Client();

    const std::string getInfo() const;
    const std::string getFullInfo() const;
    const std::string getRentsInfo() const;
    void appendRent(const RentPtr &pNewRent);
    void removeRent(const RentPtr &pOldRent);
    const double applyDiscount(double pPrice) const;

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    const AddressPtr &getAddress() const;
    const ClientTypePtr &getClientType() const;
    const VectorRentPtr &getCurrentRents() const;

    void setFirstName(const std::string &pFirstName);
    void setLastName(const std::string &pLastName);
    void setAddress(const AddressPtr &pAddress); // ?
    void setClientType(const ClientTypePtr &pClientType); // ?
};

#endif //COURTRENTAL_CLIENT_H