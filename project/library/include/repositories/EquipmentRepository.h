#ifndef COURTRENTAL_EQUIPMENTREPOSITORY_H
#define COURTRENTAL_EQUIPMENTREPOSITORY_H

#include "typedefs.h"
#include "../model/Equipment.h"

class EquipmentRepository {
private:
    VectorEquipmentPtr equipments = {};

public:
    EquipmentRepository();
    ~EquipmentRepository();

    EquipmentPtr get(int pIndex) const;
    const bool add(const EquipmentPtr &pEquipment);
    const bool remove(const EquipmentPtr &pEquipment);

    const std::string report() const;
    const int size() const;

    const VectorEquipmentPtr findBy(const EquipmentPredicate &pEquipmentPredicate) const;
    const VectorEquipmentPtr findAll() const;
};

#endif //COURTRENTAL_EQUIPMENTREPOSITORY_H