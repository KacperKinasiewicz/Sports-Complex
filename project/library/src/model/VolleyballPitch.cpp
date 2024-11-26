#include "model/VolleyballPitch.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string volleyball pitch name
/// \param pBasePrice - int volleyball pitch base price
/// \param pCovered - boolean info if the volleyball pitch is covered
/// \param pArea - int volleyball pitch area
VolleyballPitch::VolleyballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea) : Court(pName, pBasePrice), CoveredCourt(pName, pBasePrice, pCovered, pArea) {}
VolleyballPitch::VolleyballPitch() : Court(), CoveredCourt() {}
VolleyballPitch::~VolleyballPitch() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of volleyball pitch name, base price, actual price, info if volleyball pitch is covered, area
const std::string VolleyballPitch::getInfo() const {
    std::string temp = "VolleyballPitch: \n" + CoveredCourt::getInfo();
    return temp;
}

///
/// \return - returns double actual volleyball pitch price
const double VolleyballPitch::getActualCourtPrice() const {
    return CoveredCourt::getActualCourtPrice() * 1.05;
}