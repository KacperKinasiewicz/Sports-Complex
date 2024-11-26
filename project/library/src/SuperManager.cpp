#include "SuperManager.h"

// c -------------------------------------------------------------------------------------------------------------------
SuperManager::SuperManager() {}
SuperManager::~SuperManager() {}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \return - returns manager pointer to client manager
const ClientManagerPtr &SuperManager::getClientManager() {return this->clientManager;}

///
/// \return - returns manager pointer to court manager
const CourtManagerPtr &SuperManager::getCourtManager() {return this->courtManager;}

///
/// \return - returns manager pointer to equipment manager
const EquipmentManagerPtr &SuperManager::getEquipmentManager() {return this->equipmentManager;}

///
/// \return - returns manager pointer to rent manager
const RentManagerPtr &SuperManager::getRentManager() {return this->rentManager;}

///
/// \return - returns storage pointer to storage container
const StorageContainerPtr &SuperManager::getStorageContainer() {return this->storageContainer;}