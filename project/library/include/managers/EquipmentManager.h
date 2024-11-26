#ifndef COURTRENTAL_EQUIPMENTMANAGER_H
#define COURTRENTAL_EQUIPMENTMANAGER_H

#include "StorageContainer.h"

class EquipmentManager {
private:
    EquipmentRepositoryPtr equipmentsRepository;

public:
    EquipmentManager();
    EquipmentManager(const StorageContainerPtr &pStorageContainer);
    ~EquipmentManager();

    void registerRocket(const std::string &pModel, int pBasePrice);
    void registerBall(const std::string &pModel, int pBasePrice, const SegmentType &pSegment);
    void unregisterEquipment(const EquipmentPtr &pEquipment);

    VectorEquipmentPtr findEquipments(EquipmentPredicate &pEquipmentPredicate);
    VectorEquipmentPtr findAllEquipments();

    EquipmentPtr getEquipment(int pIndex) const;
    const EquipmentRepositoryPtr &getEquipmentsRepo();
};

#endif //COURTRENTAL_EQUIPMENTMANAGER_H