#ifndef COURTRENTAL_ROCKET_H
#define COURTRENTAL_ROCKET_H

#include "Equipment.h"

class Rocket : public Equipment {
public:
    Rocket();
    Rocket(const std::string &pModel, int pBasePrice);
    ~Rocket();

    virtual const std::string getInfo() const override;
    virtual const double getActualEquipmentPrice() const override;
};

#endif //COURTRENTAL_ROCKET_H