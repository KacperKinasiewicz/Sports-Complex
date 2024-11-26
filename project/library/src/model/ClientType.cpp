#include "model/ClientType.h"

ClientType::~ClientType() {}

// Default -------------------------------------------------------------------------------------------------------------
///
/// \return - returns int info how many court client can rent
const int Default::getMaxCourts() const {return 1;}
///
/// \param pPrice - double price to apply discount
/// \return - returns double price after the discount
const double Default::applyDiscount(double pPrice) const {return pPrice;}
///
/// \return - returns string client type
const std::string Default::getTypeInfo() const {return "Default";}

// FitCarnet -----------------------------------------------------------------------------------------------------------
///
/// \return - returns int info how many court client can rent
const int FitCarnet::getMaxCourts() const {return 1;}
///
/// \param pPrice - double price to apply discount
/// \return - returns double price after the discount
const double FitCarnet::applyDiscount(double pPrice) const {return pPrice * 0.95;}
///
/// \return - returns string client type
const std::string FitCarnet::getTypeInfo() const {return "FitCarnet";}

// Patron --------------------------------------------------------------------------------------------------------------
///
/// \return - returns int info how many court client can rent
const int Patron::getMaxCourts() const {return 3;}
///
/// \param pPrice - double price to apply discount
/// \return - returns double price after the discount
const double Patron::applyDiscount(double pPrice) const {return pPrice * 0.90;}
///
/// \return - returns string client type
const std::string Patron::getTypeInfo() const {return "Patron";}

// Trainer -------------------------------------------------------------------------------------------------------------
///
/// \return - returns int info how many court client can rent
const int Trainer::getMaxCourts() const {return 5;}
///
/// \param pPrice - double price to apply discount
/// \return - returns double price after the discount
const double Trainer::applyDiscount(double pPrice) const {return pPrice * 0.85;}
///
/// \return - returns string client type
const std::string Trainer::getTypeInfo() const {return "Trainer";}