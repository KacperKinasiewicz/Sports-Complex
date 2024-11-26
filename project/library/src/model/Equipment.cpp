#include "model/Equipment.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pModel - string equipment model
/// \param pBasePrice - int equipment base price
Equipment::Equipment(const std::string &pModel, int pBasePrice) : model(pModel), basePrice(pBasePrice) {}
Equipment::Equipment() {}
Equipment::~Equipment() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of ball model, base price, actual price
const std::string Equipment::getInfo() const {
    std::string temp = "Model: " + this->model + "\n" + "BasePrice: " + std::to_string(this->basePrice) + "\n" + "ActualEquipmentPrice: " + std::to_string(this->getActualEquipmentPrice()) + "\n";
    if(this->rented) temp += "Rented: YES \n";
    else temp += "Rented: NO \n";
    return temp;
}

///
/// \return - returns double actual equipment price
const double Equipment::getActualEquipmentPrice() const {
    return this->basePrice;
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string equipment model
const std::string &Equipment::getModel() const {return this->model;}
///
/// \return - returns int equipment base price
const int &Equipment::getBasePrice() const {return this->basePrice;}
///
/// \return - returns boolean info if equipment is rented
const bool &Equipment::isRented() const {return this->rented;}

// s -------------------------------------------------------------------------------------------------------------------
///
/// \param newBasePrice - int equipment base price
void Equipment::setBasePrice(int newBasePrice) {if(newBasePrice>=0) this->basePrice = newBasePrice;}
///
/// \param option - boolean info if equipment is rented
void Equipment::setRented(bool option) {this->rented = option;}