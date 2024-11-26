#include "model/Rent.h"

// c -------------------------------------------------------------------------------------------------------------------
int Rent::nextId = 1;

///
/// \param pBeginTime - ptime rent begin time
/// \param pRentClient - client pointer to rent client
/// \param pRentCourt - court pointer to rent court
Rent::Rent(pt::ptime pBeginTime, const ClientPtr &pRentClient, const CourtPtr &pRentCourt) : rentClient(pRentClient), rentCourt(pRentCourt) {
    this->id = nextId++;

    this->rentCourt->setRented(true);

    if(pBeginTime == pt::not_a_date_time)
        this->beginTime = pt::second_clock::local_time();
    else
        this->beginTime = pBeginTime;
}
Rent::Rent() {}
Rent::~Rent() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns string consisting of rent begin time, client, court
const std::string Rent::getInfo() const {
    std::string temp = "";

    temp += "[Rent]\nID: " + std::to_string(this->getId())
          + "\nClient: " + this->rentClient->getFirstName() + " " + this->rentClient->getLastName()
          + "\nCourt: " + this->rentCourt->getName()
          + "\nBegin time: " + pt::to_simple_string(this->getBeginTime())
          + "\nEnd time: " + pt::to_simple_string(this->getEndTime())
          + "\nRent hours: " + std::to_string(this->getRentHours())
          + "\nEquipment price: " + std::to_string(this->getRentEquipmentPrice())
          + "\nRent cost: " + std::to_string(this->getRentCost()) + "\n ";

    return temp;
}

///
/// \return - returns int rent hours
const int Rent::getRentHours() const {
    if(this->endTime==pt::not_a_date_time || pt::second_clock::local_time() < this->endTime)
        return 0;
    else if(pt::time_period(beginTime, endTime).length().total_seconds() < 60)
        return  0;
    else
        return (pt::time_period(beginTime, endTime).length().hours()) + 1;
}

///
/// \param pEndTime - ptime rent end time
void Rent::endRent(pt::ptime pEndTime) {
    if(this->endTime == pt::not_a_date_time)
    {
        if(pEndTime == pt::not_a_date_time) {
            if(pt::second_clock::local_time() < this->beginTime)
                this->endTime = this->beginTime;
            else
                this->endTime = pt::second_clock::local_time();
        }

        else if(pEndTime < this->beginTime)
            this->endTime = this->beginTime;

        else
            this->endTime = pEndTime;

        this->rentCost = this->getRentHours() * this->rentClient->applyDiscount(this->rentCourt->getActualCourtPrice() + this->getRentEquipmentPrice());
        this->rentCourt->setRented(false);
        this->rentClient->removeRent(shared_from_this());
        for(int i = 0; i < this->rentEquipment.size(); i++)
            rentEquipment[i]->setRented(false);
    }
}

///
/// \param pEquipment - equipment pointer to equipment wanted to rent
void Rent::appendEquipment(EquipmentPtr pEquipment) {
    if(!pEquipment->isRented()) {
        this->rentEquipment.push_back(pEquipment);
        pEquipment->setRented(true);
    }
}

///
/// \return - returns double summary rent equipment price
const double Rent::getRentEquipmentPrice() const {
    double temp = 0;

    for(int i = 0; i < this->rentEquipment.size(); i++)
        temp += this->rentEquipment[i]->getActualEquipmentPrice();

    return temp;
}

///
void Rent::addClient() {
    this->rentClient->appendRent(shared_from_this());
}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns int rent id
const int &Rent::getId() const {return this->id;}

///
/// \return - returns ptime rent begin time
const pt::ptime &Rent::getBeginTime() const {return this->beginTime;}

///
/// \return - returns ptime rent end time
const pt::ptime &Rent::getEndTime() const {return this->endTime;}

///
/// \return - returns int rent cost
const int &Rent::getRentCost() const {return this->rentCost;}

///
/// \return - returns client pointer to rent client
const ClientPtr &Rent::getRentClient() const {return this->rentClient;}

///
/// \return - returns court pointer to rent court
const CourtPtr &Rent::getRentCourt() const {return this->rentCourt;}

///
/// \return - returns vector with rent equipment
const VectorEquipmentPtr &Rent::getRentEquipment() const {return this->rentEquipment;}