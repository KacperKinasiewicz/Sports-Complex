#ifndef COURTRENTAL_COVEREDCOURT_H
#define COURTRENTAL_COVEREDCOURT_H

#include "Court.h"

class CoveredCourt : virtual public Court {
private:
    bool covered;
    int area;

public:
    CoveredCourt();
    CoveredCourt(const std::string &pName, int pBasePrice, bool pCovered, int pArea);
    virtual ~CoveredCourt() = 0;

    virtual const std::string getInfo() const override;
    virtual const double getActualCourtPrice() const override;

    const bool &isCovered() const;
    const int &getArea() const;
};

#endif //COURTRENTAL_COVEREDCOURT_H