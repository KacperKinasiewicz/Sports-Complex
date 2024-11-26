#ifndef COURTRENTAL_COURTMANAGER_H
#define COURTRENTAL_COURTMANAGER_H

#include "StorageContainer.h"

class CourtManager {
private:
    CourtRepositoryPtr courtsRepository;

public:
    CourtManager();
    CourtManager(const StorageContainerPtr &pStorageContainer);
    ~CourtManager();

    void registerPingPongTable(const std::string &pName, int pBasePrice);
    void registerVolleyballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea);
    void registerBasketballCourt(const std::string &pName, int pBasePrice, bool pCovered, int pArea);
    void registerTennisCourt(const std::string &pName, int pBasePrice, bool pGrassed);
    void registerFootballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea, bool pGrassed);
    void unregisterCourt(const CourtPtr &pCourt);

    VectorCourtPtr findCourts(CourtPredicate &pCourtPredicate);
    VectorCourtPtr findAllCourts();

    CourtPtr getCourt(int pIndex) const;
    const CourtRepositoryPtr &getCourtsRepo();
};

#endif //COURTRENTAL_COURTMANAGER_H