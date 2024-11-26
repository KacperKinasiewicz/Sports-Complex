#include "model/CoveredCourt.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string covered court name
/// \param pBasePrice - int covered court base price
/// \param pCovered - boolean info if court is covered
/// \param pArea - int covered court area
CoveredCourt::CoveredCourt(const std::string &pName, int pBasePrice, bool pCovered, int pArea) : Court(pName, pBasePrice), covered(pCovered), area(pArea) {}
CoveredCourt::CoveredCourt() : Court() {}
CoveredCourt::~CoveredCourt() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of court name, base price, actual price, info if court is covered, area
const std::string CoveredCourt::getInfo() const {
    std::string temp = Court::getInfo();
    if(this->covered) temp += "Covered: YES \n";
    else temp += "Covered: NO \n";
    temp += "Area: " + std::to_string(this->area) + "\n";
    return temp;
}

///
/// \return - returns double actual court price depending of info if court is covered
const double CoveredCourt::getActualCourtPrice() const {
    if(this->covered) return Court::getActualCourtPrice() * 1.5;
    else return Court::getActualCourtPrice();
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns boolean info if court is covered
const bool &CoveredCourt::isCovered() const {return this->covered;}
///
/// \return - returns int court area
const int &CoveredCourt::getArea() const {return this->area;}