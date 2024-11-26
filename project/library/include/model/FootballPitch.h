#ifndef COURTRENTAL_FOOTBALLPITCH_H
#define COURTRENTAL_FOOTBALLPITCH_H

#include "CoveredCourt.h"
#include "GrassPitch.h"

class FootballPitch : public CoveredCourt, public GrassPitch {
public:
    FootballPitch();
    FootballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea, bool pGrassed);
    ~FootballPitch();

    const std::string getInfo() const override;
    const double getActualCourtPrice() const override;
};

#endif //COURTRENTAL_FOOTBALLPITCH_H