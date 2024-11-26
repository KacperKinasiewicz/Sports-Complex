#include "managers/RentManager.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pStorageContainer - storage container pointer to storage container in which there is a rent repository
RentManager::RentManager(const StorageContainerPtr &pStorageContainer) : rentsRepository(pStorageContainer->getRentRepository()) {}
RentManager::RentManager() {}
RentManager::~RentManager() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pBeginTime - ptime rent begin time
/// \param pRentClient - client pointer to rent client
/// \param pRentCourt - court pointer to rent court
void RentManager::registerRent(pt::ptime pBeginTime, const ClientPtr &pRentClient, const CourtPtr &pRentCourt) {
    if(pRentClient->getCurrentRents().size() < pRentClient->getClientType()->getMaxCourts() && !pRentCourt->isRented()) {
        RentPtr newRent = std::make_shared<Rent>(pBeginTime, pRentClient, pRentCourt);
        newRent->addClient();
        this->rentsRepository->add(newRent);
    }
}

///
/// \param pRent - rent pointer to rent wanted to be unregistered from repository
void RentManager::unregisterRent(const RentPtr &pRent) {
    this->rentsRepository->remove(pRent);
}

///
/// \param pRentPredicate - predicate pointer to function being used to find rents
/// \return - returns vector of found rents
VectorRentPtr RentManager::findRents(RentPredicate &pRentPredicate) {return this->rentsRepository->findBy(pRentPredicate);}

///
/// \return - returns vector of all rents
VectorRentPtr RentManager::findAllRents() {return this->rentsRepository->findAll();}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int rent index (position in repository vector + 1)
/// \return - returns rent pointer to found rent
RentPtr RentManager::getRent(int pIndex) const {return this->rentsRepository->get(pIndex);}

///
/// \return - returns repository pointer to rent repository
const RentRepositoryPtr &RentManager::getRentsRepo() {return this->rentsRepository;}