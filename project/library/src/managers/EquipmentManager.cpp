#include "managers/EquipmentManager.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pStorageContainer - storage container pointer to storage container in which there is a equipment repository
EquipmentManager::EquipmentManager(const StorageContainerPtr &pStorageContainer) : equipmentsRepository(pStorageContainer->getEquipmentRepository()) {}
EquipmentManager::EquipmentManager() {}
EquipmentManager::~EquipmentManager() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pModel - string rocket model
/// \param pBasePrice - int rocket base price
void EquipmentManager::registerRocket(const std::string &pModel, int pBasePrice) {
    RocketPtr newEquipment = std::make_shared<Rocket>(pModel, pBasePrice);
    this->equipmentsRepository->add(newEquipment);
}

///
/// \param pModel - string ball model
/// \param pBasePrice - int ball base price
/// \param pSegment - segment ball type (Football, Basketball or Volleyball)
void EquipmentManager::registerBall(const std::string &pModel, int pBasePrice, const SegmentType &pSegment) {
    BallPtr newEquipment = std::make_shared<Ball>(pModel, pBasePrice, pSegment);
    this->equipmentsRepository->add(newEquipment);
}

///
/// \param pEquipment - equipment pointer to equipment wanted to be unregistered from repository
void EquipmentManager::unregisterEquipment(const EquipmentPtr &pEquipment) {
    this->equipmentsRepository->remove(pEquipment);
}

///
/// \param pEquipmentPredicate - predicate pointer to function being used to find equipments
/// \return - returns vector of found equipments
VectorEquipmentPtr EquipmentManager::findEquipments(EquipmentPredicate &pEquipmentPredicate) {return this->equipmentsRepository->findBy(pEquipmentPredicate);}

///
/// \return  - returns vector of all equipments
VectorEquipmentPtr EquipmentManager::findAllEquipments() {return this->equipmentsRepository->findAll();}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int equipment index (position in repository vector + 1)
/// \return - returns equipment pointer to found equipment
EquipmentPtr EquipmentManager::getEquipment(int pIndex) const {return this->equipmentsRepository->get(pIndex);}

///
/// \return - returns repository pointer to equipment repository
const EquipmentRepositoryPtr &EquipmentManager::getEquipmentsRepo() {return this->equipmentsRepository;}