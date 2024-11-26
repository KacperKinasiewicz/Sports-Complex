#ifndef COURTRENTAL_EQUIPMENT_H
#define COURTRENTAL_EQUIPMENT_H

#include "typedefs.h"

class Equipment {
private:
    std::string model;
    int basePrice;
    bool rented = false;

public:
    Equipment();
    Equipment(const std::string &pModel, int pBasePrice);
    virtual ~Equipment() = 0;

    virtual const std::string getInfo() const;
    virtual const double getActualEquipmentPrice() const;

    const std::string &getModel() const;
    const int &getBasePrice() const;
    const bool &isRented() const;

    void setBasePrice(int newBasePrice);
    void setRented(bool option);
};

#endif //COURTRENTAL_EQUIPMENT_H