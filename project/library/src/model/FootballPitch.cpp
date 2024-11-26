#include "model/FootballPitch.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string football pitch name
/// \param pBasePrice - int football pitch base price
/// \param pCovered - boolean info if the football pitch is covered
/// \param pArea - int football pitch area
/// \param pGrassed - boolean info if the football pitch is grassed
FootballPitch::FootballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea, bool pGrassed) : Court(pName,pBasePrice), CoveredCourt(pName, pBasePrice, pCovered, pArea), GrassPitch(pName, pBasePrice, pGrassed) {}
FootballPitch::FootballPitch() : Court(), CoveredCourt(), GrassPitch() {}
FootballPitch::~FootballPitch() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of football pitch name, base price, actual price, info if football pitch is covered, area, info if football pitch is grassed
const std::string FootballPitch::getInfo() const {
    std::string temp = "FootballPitch: \n" + CoveredCourt::getInfo();
    if(this->GrassPitch::isGrassed()) temp += "Grassed: YES \n";
    else temp += "Grassed: NO \n";
    return temp;
}

///
/// \return - returns double actual football pitch price
const double FootballPitch::getActualCourtPrice() const {
    return CoveredCourt::getActualCourtPrice() + GrassPitch::getActualCourtPrice() * 1.05 - this->CoveredCourt::getBasePrice();
}