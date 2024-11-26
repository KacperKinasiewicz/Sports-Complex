#ifndef COURTRENTAL_RENTMANAGER_H
#define COURTRENTAL_RENTMANAGER_H

#include "StorageContainer.h"

class RentManager {
private:
    RentRepositoryPtr rentsRepository;

public:
    RentManager();
    RentManager(const StorageContainerPtr &pStorageContainer);
    ~RentManager();

    void registerRent(pt::ptime pBeginTime, const ClientPtr &pRentClient, const CourtPtr &pRentCourt);
    void unregisterRent(const RentPtr &pRent);

    VectorRentPtr findRents(RentPredicate &pRentPredicate);
    VectorRentPtr findAllRents();

    RentPtr getRent(int pIndex) const;
    const RentRepositoryPtr &getRentsRepo();
};

#endif //COURTRENTAL_RENTMANAGER_H