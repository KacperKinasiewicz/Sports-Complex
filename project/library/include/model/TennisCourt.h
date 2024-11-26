#ifndef COURTRENTAL_TENNISCOURT_H
#define COURTRENTAL_TENNISCOURT_H

#include "GrassPitch.h"

class TennisCourt : public GrassPitch {
public:
    TennisCourt();
    TennisCourt(const std::string &pName, int pBasePrice, bool pGrassed);
    ~TennisCourt();

    const std::string getInfo() const override;
    const double getActualCourtPrice() const override;
};

#endif //COURTRENTAL_TENNISCOURT_H