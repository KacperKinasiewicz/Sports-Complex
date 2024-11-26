#ifndef COURTRENTAL_STORAGECONTAINER_H
#define COURTRENTAL_STORAGECONTAINER_H

#include "typedefs.h"
#include "repositories/ClientRepository.h"
#include "repositories/CourtRepository.h"
#include "repositories/EquipmentRepository.h"
#include "repositories/RentRepository.h"
#include "model/BasketballCourt.h"
#include "model/FootballPitch.h"
#include "model/PingPongTable.h"
#include "model/TennisCourt.h"
#include "model/VolleyballPitch.h"
#include "model/Rocket.h"
#include "model/Ball.h"
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Rent.h"

class StorageContainer {
private:
    ClientRepositoryPtr clientRepository = std::make_shared<ClientRepository>();
    CourtRepositoryPtr courtRepository = std::make_shared<CourtRepository>();
    EquipmentRepositoryPtr equipmentRepository = std::make_shared<EquipmentRepository>();
    RentRepositoryPtr rentRepository = std::make_shared<RentRepository>();

public:
    StorageContainer();
    ~StorageContainer();

    ClientRepositoryPtr getClientRepository();
    CourtRepositoryPtr getCourtRepository();
    EquipmentRepositoryPtr getEquipmentRepository();
    RentRepositoryPtr getRentRepository();
};

#endif //COURTRENTAL_STORAGECONTAINER_H