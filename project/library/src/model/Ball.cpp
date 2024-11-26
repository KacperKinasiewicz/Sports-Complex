#include "model/Ball.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pModel - string ball model
/// \param pBasePrice - int ball base price
/// \param pSegment - segment ball type (Football, Basketball or Volleyball)
Ball::Ball(const std::string &pModel, int pBasePrice, const SegmentType &pSegment) : Equipment(pModel, pBasePrice), segment(pSegment) {}
Ball::Ball() : Equipment() {}
Ball::~Ball() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of ball model, base price, actual price and type
const std::string Ball::getInfo() const {
    return "Ball: \n" + Equipment::getInfo() + "BallType: " + this->getSegmentType() + "\n";
}

///
/// \return - returns double actual ball price depending of ball type
const double Ball::getActualEquipmentPrice() const {
    return Equipment::getActualEquipmentPrice() * this->getSegmentCost();
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string ball type
const std::string Ball::getSegmentType() const {
    switch(this->segment) {
        case 0:
            return "Football";
        case 1:
            return "Basketball";
        case 2:
            return "Volleyball";
        default:
            return "UNDEFINIED";
    }
}

///
/// \return - returns double price rate depending of ball type
const double Ball::getSegmentCost() const {
    switch(this->segment) {
        case 0:
            return 1.3;
        case 1:
            return 1.2;
        case 2:
            return 1.1;
        default:
            return 1;
    }
}