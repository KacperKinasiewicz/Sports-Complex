#include "model/BasketballCourt.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string basketball court name
/// \param pBasePrice - int basketball court base price
/// \param pCovered - boolean info if the basketball court is covered
/// \param pArea - int basketball court area
BasketballCourt::BasketballCourt(const std::string &pName, int pBasePrice, bool pCovered, int pArea) : Court(pName,pBasePrice), CoveredCourt(pName, pBasePrice, pCovered, pArea) {}
BasketballCourt::BasketballCourt() : Court(), CoveredCourt() {}
BasketballCourt::~BasketballCourt() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of basketball court name, base price, actual price, info if basketball court is covered, area
const std::string BasketballCourt::getInfo() const {
    std::string temp = "BasketballCourt: \n" + CoveredCourt::getInfo();
    return temp;
}

///
/// \return - returns double actual basketball court price
const double BasketballCourt::getActualCourtPrice() const {
    return CoveredCourt::getActualCourtPrice() * 1.03;
}