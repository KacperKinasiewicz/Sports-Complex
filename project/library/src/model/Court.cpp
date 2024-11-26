#include "model/Court.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string court name
/// \param pBasePrice - int court base price
Court::Court(const std::string &pName, int pBasePrice) : name(pName), basePrice(pBasePrice) {}
Court::Court() {}
Court::~Court() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of court name, base price, actual price
const std::string Court::getInfo() const {
    std::string temp = "Name: " + this->name + "\n" + "BasePrice: " + std::to_string(this->basePrice) + "\n" + "ActualCourtPrice: " + std::to_string(this->getActualCourtPrice()) + "\n";
    if(this->rented) temp += "Rented: YES \n";
    else temp += "Rented: NO \n";
    return temp;
}

///
/// \return - returns double actual court price depending of court type
const double Court::getActualCourtPrice() const {
    return this->basePrice;
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string court name
const std::string &Court::getName() const {return this->name;}
///
/// \return - returns int court base price
const int &Court::getBasePrice() const {return this->basePrice;}
///
/// \return - returns boolean info if court is rented
const bool &Court::isRented() const {return this->rented;}

// s -------------------------------------------------------------------------------------------------------------------
///
/// \param pBasePrice - int court base price
void Court::setBasePrice(int pBasePrice) {if(pBasePrice>=0) this->basePrice = pBasePrice;}
///
/// \param pOption - boolean info if court is rented
void Court::setRented(bool pOption) {this->rented = pOption;}