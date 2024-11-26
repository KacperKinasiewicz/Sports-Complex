#ifndef COURTRENTAL_CLIENTMANAGER_H
#define COURTRENTAL_CLIENTMANAGER_H

#include "StorageContainer.h"

class ClientManager {
private:
    ClientRepositoryPtr clientsRepository;

public:
    ClientManager();
    ClientManager(const StorageContainerPtr &pStorageContainer);
    ~ClientManager();

    void registerClient(const std::string &pFirstName, const std::string &pLastName, const std::string &pPersonalID, const std::string &pCity, const std::string &pStreet, const std::string &pNumber, const ClientTypePtr &pClientType);
    void unregisterClient(const ClientPtr &pClient);

    VectorClientPtr findClients(ClientPredicate &pClientPredicate);
    VectorClientPtr findAllClients();

    ClientPtr getClient(int pIndex) const;
    const ClientRepositoryPtr &getClientsRepo();
};

#endif //COURTRENTAL_CLIENTMANAGER_H