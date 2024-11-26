#ifndef COURTRENTAL_BASKETBALLCOURT_H
#define COURTRENTAL_BASKETBALLCOURT_H

#include "CoveredCourt.h"

class BasketballCourt : public CoveredCourt {
public:
    BasketballCourt();
    BasketballCourt(const std::string &pName, int pBasePrice, bool pCovered, int pArea);
    ~BasketballCourt();

    const std::string getInfo() const override;
    const double getActualCourtPrice() const override;
};

#endif //COURTRENTAL_BASKETBALLCOURT_H