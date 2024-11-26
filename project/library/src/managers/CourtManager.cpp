#include "managers/CourtManager.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pStorageContainer - storage container pointer to storage container in which there is a court repository
CourtManager::CourtManager(const StorageContainerPtr &pStorageContainer) : courtsRepository(pStorageContainer->getCourtRepository()) {}
CourtManager::CourtManager() {}
CourtManager::~CourtManager() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pName - string ping pong table name
/// \param pBasePrice - int ping pong table base price
void CourtManager::registerPingPongTable(const std::string &pName, int pBasePrice) {
    PingPongTablePtr newCourt = std::make_shared<PingPongTable>(pName, pBasePrice);
    this->courtsRepository->add(newCourt);
}

///
/// \param pName - string volleyball pitch name
/// \param pBasePrice - int volleyball pitch base price
/// \param pCovered - boolean information if volleyball pitch is covered
/// \param pArea - int volleyball pitch area
void CourtManager::registerVolleyballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea) {
    VolleyballPitchPtr newCourt = std::make_shared<VolleyballPitch>(pName, pBasePrice, pCovered, pArea);
    this->courtsRepository->add(newCourt);
}

///
/// \param pName - string basketball court name
/// \param pBasePrice - int basketball court base price
/// \param pCovered - boolean information if basketball court is covered
/// \param pArea - int basketball court area
void CourtManager::registerBasketballCourt(const std::string &pName, int pBasePrice, bool pCovered, int pArea) {
    BasketballCourtPtr newCourt = std::make_shared<BasketballCourt>(pName, pBasePrice, pCovered, pArea);
    this->courtsRepository->add(newCourt);
}

///
/// \param pName - string tennis court name
/// \param pBasePrice - int tennis court base price
/// \param pGrassed - boolean information if tennis court is grassed
void CourtManager::registerTennisCourt(const std::string &pName, int pBasePrice, bool pGrassed) {
    TennisCourtPtr newCourt = std::make_shared<TennisCourt>(pName, pBasePrice, pGrassed);
    this->courtsRepository->add(newCourt);
}

///
/// \param pName - string football pitch name
/// \param pBasePrice - int football pitch base price
/// \param pCovered - boolean information if football pitch is covered
/// \param pArea - int football pitch area
/// \param pGrassed - boolean information if football pitch is grassed
void CourtManager::registerFootballPitch(const std::string &pName, int pBasePrice, bool pCovered, int pArea, bool pGrassed) {
    FootballPitchPtr newCourt = std::make_shared<FootballPitch>(pName, pBasePrice, pCovered, pArea, pGrassed);
    this->courtsRepository->add(newCourt);
}

///
/// \param pCourt - court pointer to court wanted to be unregistered from repository
void CourtManager::unregisterCourt(const CourtPtr &pCourt) {
    this->courtsRepository->remove(pCourt);
}

///
/// \param pCourtPredicate - predicate pointer to function being used to find court
/// \return - returns vector of found court
VectorCourtPtr CourtManager::findCourts(CourtPredicate &pCourtPredicate) {return this->courtsRepository->findBy(pCourtPredicate);}

///
/// \return - returns vector of all courts
VectorCourtPtr CourtManager::findAllCourts() {return this->courtsRepository->findAll();}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int court index (position in repository vector + 1)
/// \return - returns court pointer to found court
CourtPtr CourtManager::getCourt(int pIndex) const {return this->courtsRepository->get(pIndex);}

///
/// \return - returns repository pointer to court repository
const CourtRepositoryPtr &CourtManager::getCourtsRepo() {return this->courtsRepository;}