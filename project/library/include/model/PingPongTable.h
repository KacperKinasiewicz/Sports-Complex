#ifndef COURTRENTAL_PINGPONGTABLE_H
#define COURTRENTAL_PINGPONGTABLE_H

#include "Court.h"

class PingPongTable : public Court {
public:
    PingPongTable();
    PingPongTable(const std::string &pName, int pBasePrice);
    ~PingPongTable();

    const std::string getInfo() const override;
    const double getActualCourtPrice() const override;
};

#endif //COURTRENTAL_PINGPONGTABLE_H