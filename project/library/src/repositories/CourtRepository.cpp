#include "repositories/CourtRepository.h"

// c -------------------------------------------------------------------------------------------------------------------
CourtRepository::CourtRepository() {}
CourtRepository::~CourtRepository() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int court index (position in repository vector + 1)
/// \return - returns court pointer to found court
CourtPtr CourtRepository::get(int pIndex) const {
    if(pIndex >= this->courts.size() || pIndex < 0)
        return nullptr;

    return this->courts[pIndex];
}

///
/// \param pCourt - pointer to court wanted to be added to repository
/// \return - returns boolean information if the operation was successful
const bool CourtRepository::add(const CourtPtr &pCourt) {
    if(pCourt != nullptr && std::find(this->courts.begin(), this->courts.end(), pCourt) == this->courts.end()) {
        this->courts.push_back(pCourt);
        return true;
    }

    return false;
}

///
/// \param pCourt - pointer to court wanted to be removed from repository
/// \return - returns boolean information if the operation was successful
const bool CourtRepository::remove(const CourtPtr &pCourt) {
    if(pCourt != nullptr && std::find(this->courts.begin(), this->courts.end(), pCourt) != this->courts.end()) {
        this->courts.erase(std::remove(this->courts.begin(), this->courts.end(), pCourt), this->courts.end());
        return true;
    }

    return false;
}

///
/// \return - returns string consisting of information of all courts being in repository
const std::string CourtRepository::report() const {
    std::string temp = "[Courts]\nNumber of courts: " + std::to_string(this->courts.size()) + "\n\n";

    for(int i = 0; i < this->courts.size(); i++) {
        temp += std::to_string(i+1) + ". " + this->courts[i]->getInfo() + "\n";
    }

    return temp;
}

///
/// \return - returns int amount of courts in repository
const int CourtRepository::size() const{
    return this->courts.size();
}

///
/// \param pCourtPredicate - predicate pointer to function being used to find courts
/// \return - returns vector of found courts
const std::vector<CourtPtr> CourtRepository::findBy(const CourtPredicate &pCourtPredicate) const {
    std::vector<CourtPtr> found;

    for(unsigned int i = 0; i < this->courts.size(); i++) {
        CourtPtr tempCourt = this->courts[i];
        if(pCourtPredicate(tempCourt)) {
            found.push_back(tempCourt);
        }
    }

    return found;
}

///
/// \return - returns vector of all courts
const std::vector<CourtPtr> CourtRepository::findAll() const {
    return findBy([](const CourtPtr pCourt) { return true; });
}