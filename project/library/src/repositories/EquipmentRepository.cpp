#include "repositories/EquipmentRepository.h"

// c -------------------------------------------------------------------------------------------------------------------
EquipmentRepository::EquipmentRepository() {}
EquipmentRepository::~EquipmentRepository() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int equipment index (position in repository vector + 1)
/// \return - returns equipment pointer to found equipment
EquipmentPtr EquipmentRepository::get(int pIndex) const {
    if(pIndex >= this->equipments.size() || pIndex < 0)
        return nullptr;

    return this->equipments[pIndex];
}

///
/// \param pEquipment - pointer to equipment wanted to be added to repository
/// \return - returns boolean information if the operation was successful
const bool EquipmentRepository::add(const EquipmentPtr &pEquipment) {
    if(pEquipment != nullptr && std::find(this->equipments.begin(), this->equipments.end(), pEquipment) == this->equipments.end()) {
        this->equipments.push_back(pEquipment);
        return true;
    }

    return false;
}

///
/// \param pEquipment - pointer to equipment wanted to be removed from repository
/// \return - returns boolean information if the operation was successful
const bool EquipmentRepository::remove(const EquipmentPtr &pEquipment) {
    if(pEquipment != nullptr && std::find(this->equipments.begin(), this->equipments.end(), pEquipment) != this->equipments.end()) {
        this->equipments.erase(std::remove(this->equipments.begin(), this->equipments.end(), pEquipment), this->equipments.end());
        return true;
    }

    return false;
}

///
/// \return - returns string consisting of information of all equipments being in repository
const std::string EquipmentRepository::report() const {
    std::string temp = "[Equipment]\nNumber of equipment: " + std::to_string(this->equipments.size()) + "\n\n";

    for(int i = 0; i < this->equipments.size(); i++) {
        temp += std::to_string(i+1) + ". " + this->equipments[i]->getInfo() + "\n";
    }

    return temp;
}

///
/// \return - returns int amount of equipments in repository
const int EquipmentRepository::size() const{
    return this->equipments.size();
}

///
/// \param pEquipmentPredicate - predicate pointer to function being used to find equipments
/// \return - returns vector of found equipments
const std::vector<EquipmentPtr> EquipmentRepository::findBy(const EquipmentPredicate &pEquipmentPredicate) const {
    std::vector<EquipmentPtr> found;

    for(unsigned int i = 0; i < this->equipments.size(); i++) {
        EquipmentPtr tempEquipment = this->equipments[i];
        if(pEquipmentPredicate(tempEquipment)) {
            found.push_back(tempEquipment);
        }
    }

    return found;
}

///
/// \return - returns vector of all equipments
const std::vector<EquipmentPtr> EquipmentRepository::findAll() const {
    return findBy([](const EquipmentPtr pEquipment) { return true; });
}