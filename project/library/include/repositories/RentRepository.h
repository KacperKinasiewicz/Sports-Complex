#ifndef COURTRENTAL_RENTREPOSITORY_H
#define COURTRENTAL_RENTREPOSITORY_H

#include "typedefs.h"
#include "../model/Rent.h"

class RentRepository {
private:
    VectorRentPtr rents = {};

public:
    RentRepository();
    ~RentRepository();

    RentPtr get(int pId) const;
    const bool add(const RentPtr &pRent);
    const bool remove(const RentPtr &pRent);

    const std::string report() const;
    const int size() const;

    const VectorRentPtr findBy(const RentPredicate &pRentPredicate) const;
    const VectorRentPtr findAll() const;
};

#endif //COURTRENTAL_RENTREPOSITORY_H