#ifndef COURTRENTAL_GRASSPITCH_H
#define COURTRENTAL_GRASSPITCH_H

#include "Court.h"

class GrassPitch : virtual public Court {
private:
    bool grassed;

public:
    GrassPitch();
    GrassPitch(const std::string &pName, int pBasePrice, bool pGrassed);
    virtual ~GrassPitch() = 0;

    virtual const std::string getInfo() const override;
    virtual const double getActualCourtPrice() const override;

    const bool &isGrassed() const;
};

#endif //COURTRENTAL_GRASSPITCH_H