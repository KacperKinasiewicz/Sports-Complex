#ifndef COURTRENTAL_RENT_H
#define COURTRENTAL_RENT_H

#include "Client.h"
#include "Court.h"
#include "Equipment.h"

class Rent : public std::enable_shared_from_this<Rent> {
private:
    int id;
    static int nextId;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
    int rentCost = 0;
    ClientPtr rentClient;
    CourtPtr rentCourt;
    VectorEquipmentPtr rentEquipment = {};

public:
    Rent();
    Rent(pt::ptime pBeginTime, const ClientPtr &pRentClient, const CourtPtr &pRentCourt);
    ~Rent();

    const std::string getInfo() const;
    const int getRentHours() const;
    void endRent(pt::ptime pEndTime);
    void appendEquipment(EquipmentPtr pEquipment);
    const double getRentEquipmentPrice() const;
    void addClient();

    const int &getId() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    const int &getRentCost() const;
    const ClientPtr &getRentClient() const;
    const CourtPtr &getRentCourt() const;
    const VectorEquipmentPtr &getRentEquipment() const;
};

#endif //COURTRENTAL_RENT_H
