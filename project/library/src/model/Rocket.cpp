#include "model/Rocket.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pModel - string rocket model
/// \param pBasePrice - int rocket base price
Rocket::Rocket(const std::string &pModel, int pBasePrice) : Equipment(pModel, pBasePrice) {}
Rocket::Rocket() : Equipment() {}
Rocket::~Rocket() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of rocket model, base price, actual price
const std::string Rocket::getInfo() const {
    return "Rocket: \n" + Equipment::getInfo();
}

///
/// \return - returns double actual rocket price
const double Rocket::getActualEquipmentPrice() const {
    return Equipment::getActualEquipmentPrice() * 1.5;
}