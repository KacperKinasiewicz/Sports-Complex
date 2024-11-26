#include "model/TennisCourt.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string tennis court name
/// \param pBasePrice - int tennis court base price
/// \param pGrassed - boolean info if the tennis court is grassed
TennisCourt::TennisCourt(const std::string &pName, int pBasePrice, bool pGrassed) : Court(pName,pBasePrice), GrassPitch(pName, pBasePrice, pGrassed) {}
TennisCourt::TennisCourt() : Court(), GrassPitch() {}
TennisCourt::~TennisCourt() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of volleyball pitch name, base price, actual price, info if tennis court is grassed
const std::string TennisCourt::getInfo() const {
    std::string temp = "TennisCourt: \n" + GrassPitch::getInfo();
    return temp;
}

///
/// \return - returns double actual tennis court price
const double TennisCourt::getActualCourtPrice() const {
    return GrassPitch::getActualCourtPrice() * 1.1;
}