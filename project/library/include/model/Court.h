#ifndef COURTRENTAL_COURT_H
#define COURTRENTAL_COURT_H

#include "typedefs.h"

class Court {
private:
    std::string name;
    int basePrice;
    bool rented = false;

public:
    Court();
    Court(const std::string &pName, int pBasePrice);
    virtual ~Court() = 0;

    virtual const std::string getInfo() const;
    virtual const double getActualCourtPrice() const;

    const std::string &getName() const;
    const int &getBasePrice() const;
    const bool &isRented() const;

    void setBasePrice(int newBasePrice);
    void setRented(bool option);
};

#endif //COURTRENTAL_COURT_H