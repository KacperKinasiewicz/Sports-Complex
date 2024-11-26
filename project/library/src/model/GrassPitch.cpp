#include "model/GrassPitch.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string grass pitch name
/// \param pBasePrice - int grass pitch base price
/// \param pGrassed - boolean info if pitch is grassed
GrassPitch::GrassPitch(const std::string &pName, int pBasePrice, bool pGrassed) : Court(pName, pBasePrice), grassed(pGrassed) {}
GrassPitch::GrassPitch() : Court() {}
GrassPitch::~GrassPitch() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of pitch name, base price, actual price, info if court is grassed
const std::string GrassPitch::getInfo() const {
    std::string temp = Court::getInfo();
    if(this->grassed) temp += "Grassed: YES \n";
    else temp += "Grassed: NO \n";
    return temp;
}

///
/// \return - returns double actual pitch price depending of info if pitch is grassed
const double GrassPitch::getActualCourtPrice() const {
    if(this->grassed) return Court::getActualCourtPrice()*1.25;
    else return Court::getActualCourtPrice();
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns boolean info if pitch is grassed
const bool &GrassPitch::isGrassed() const {return this->grassed;}