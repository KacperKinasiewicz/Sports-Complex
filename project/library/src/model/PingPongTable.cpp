#include "model/PingPongTable.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string ping pong table name
/// \param pBasePrice - int ping pong table base price
PingPongTable::PingPongTable(const std::string &pName, int pBasePrice) : Court(pName, pBasePrice) {}
PingPongTable::PingPongTable() : Court() {}
PingPongTable::~PingPongTable() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of ping pong table name, base price and actual price
const std::string PingPongTable::getInfo() const {
    std::string temp = "PingPongTable: \n" + Court::getInfo();
    return temp;
}

///
/// \return - returns double actual ping pong table price
const double PingPongTable::getActualCourtPrice() const {
    return Court::getActualCourtPrice() * 0.95;
}