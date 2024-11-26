#include "repositories/RentRepository.h"

// c -------------------------------------------------------------------------------------------------------------------
RentRepository::RentRepository() {}
RentRepository::~RentRepository() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int rent index (position in repository vector + 1)
/// \return - returns rent pointer to found rent
RentPtr RentRepository::get(int pId) const {
    for(int i = 0; i < this->rents.size(); i++)
        if(this->rents[i]->getId() == pId)
            return this->rents[i];

    return nullptr;
}

///
/// \param pRent - pointer to rent wanted to be added to repository
/// \return - returns boolean information if the operation was successful
const bool RentRepository::add(const RentPtr &pRent) {
    if(pRent != nullptr && std::find(this->rents.begin(), this->rents.end(), pRent) == this->rents.end()) {
        this->rents.push_back(pRent);
        return true;
    }

    return false;
}

///
/// \param pRent - pointer to rent wanted to be removed from repository
/// \return - returns boolean information if the operation was successful
const bool RentRepository::remove(const RentPtr &pRent) {
    if(pRent != nullptr && std::find(this->rents.begin(), this->rents.end(), pRent) != this->rents.end()) {
        this->rents.erase(std::remove(this->rents.begin(), this->rents.end(), pRent), this->rents.end());
        return true;
    }

    return false;
}

///
/// \return - returns string consisting of information of all rents being in repository
const std::string RentRepository::report() const {
    std::string temp = "[Rents]\nNumber of rents: " + std::to_string(this->rents.size()) + "\n\n";

    for(int i = 0; i < this->rents.size(); i++) {
        temp += std::to_string(i+1) + ". " + this->rents[i]->getInfo() + "\n";
    }

    return temp;
}

///
/// \return - returns int amount of rents in repository
const int RentRepository::size() const{
    return this->rents.size();
}

///
/// \param pRentPredicate - predicate pointer to function being used to find rents
/// \return - returns vector of found rents
const std::vector<RentPtr> RentRepository::findBy(const RentPredicate &pRentPredicate) const {
    std::vector<RentPtr> found;

    for(unsigned int i = 0; i < this->rents.size(); i++) {
        RentPtr tempRent = this->rents[i];
        if(pRentPredicate(tempRent)) {
            found.push_back(tempRent);
        }
    }

    return found;
}

///
/// \return - returns vector of all rents
const std::vector<RentPtr> RentRepository::findAll() const {
    return findBy([](const RentPtr pRent) { return true; });
}