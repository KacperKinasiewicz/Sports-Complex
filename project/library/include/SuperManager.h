#ifndef COURTRENTAL_SUPERMANAGER_H
#define COURTRENTAL_SUPERMANAGER_H

#include "StorageContainer.h"
#include "managers/ClientManager.h"
#include "managers/CourtManager.h"
#include "managers/EquipmentManager.h"
#include "managers/RentManager.h"

class SuperManager {
private:
    StorageContainerPtr storageContainer = std::make_shared<StorageContainer>();
    ClientManagerPtr clientManager = std::make_shared<ClientManager>(storageContainer);
    CourtManagerPtr courtManager = std::make_shared<CourtManager>(storageContainer);
    EquipmentManagerPtr equipmentManager = std::make_shared<EquipmentManager>(storageContainer);
    RentManagerPtr rentManager = std::make_shared<RentManager>(storageContainer);

public:
    SuperManager();
    ~SuperManager();

    const ClientManagerPtr &getClientManager();
    const CourtManagerPtr &getCourtManager();
    const EquipmentManagerPtr &getEquipmentManager();
    const RentManagerPtr &getRentManager();
    const StorageContainerPtr &getStorageContainer();
};

#endif //COURTRENTAL_SUPERMANAGER_H