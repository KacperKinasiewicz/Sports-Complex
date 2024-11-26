#ifndef COURTRENTAL_VOLLEYBALLPITCH_H
#define COURTRENTAL_VOLLEYBALLPITCH_H

#include "CoveredCourt.h"

class VolleyballPitch : public CoveredCourt {
public:
    VolleyballPitch();
    VolleyballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea);
    ~VolleyballPitch();

    const std::string getInfo() const override;
    const double getActualCourtPrice() const override;
};

#endif //COURTRENTAL_VOLLEYBALLPITCH_H