#ifndef COURTRENTAL_COURTREPOSITORY_H
#define COURTRENTAL_COURTREPOSITORY_H

#include "typedefs.h"
#include "../model/Court.h"

class CourtRepository {
private:
    VectorCourtPtr courts = {};

public:
    CourtRepository();
    ~CourtRepository();

    CourtPtr get(int pIndex) const;
    const bool add(const CourtPtr &pCourt);
    const bool remove(const CourtPtr &pCourt);

    const std::string report() const;
    const int size() const;

    const VectorCourtPtr findBy(const CourtPredicate &pCourtPredicate) const;
    const VectorCourtPtr findAll() const;
};

#endif //COURTRENTAL_COURTREPOSITORY_H