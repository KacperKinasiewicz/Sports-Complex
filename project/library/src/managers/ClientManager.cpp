#include "managers/ClientManager.h"

// c -------------------------------------------------------------------------------------------------------------------
///
/// \param pStorageContainer - storage container pointer to storage container in which there is a client repository
ClientManager::ClientManager(const StorageContainerPtr &pStorageContainer) : clientsRepository(pStorageContainer->getClientRepository()) {}
ClientManager::ClientManager() {}
ClientManager::~ClientManager() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pFirstName - string client first name
/// \param pLastName - string client last name
/// \param pPersonalID - string client personal ID
/// \param pCity - string client address city
/// \param pStreet - string client address street
/// \param pNumber - string client address number
/// \param pClientType - client type pointer to client type
void ClientManager::registerClient(const std::string &pFirstName, const std::string &pLastName, const std::string &pPersonalID, const std::string &pCity, const std::string &pStreet, const std::string &pNumber, const ClientTypePtr &pClientType) {
    AddressPtr pAddress = std::make_shared<Address>(pCity, pStreet, pNumber);
    ClientPtr newClient = std::make_shared<Client>(pFirstName, pLastName, pPersonalID, pAddress, pClientType);
    this->clientsRepository->add(newClient);
}

///
/// \param pClient - client pointer to client wanted to be unregistered from repository
void ClientManager::unregisterClient(const ClientPtr &pClient) {
    this->clientsRepository->remove(pClient);
}

///
/// \param pClientPredicate - predicate pointer to function being used to find clients
/// \return - returns vector of found clients
VectorClientPtr ClientManager::findClients(ClientPredicate &pClientPredicate) {return this->clientsRepository->findBy(pClientPredicate);}

///
/// \return - returns vector of all clients
VectorClientPtr ClientManager::findAllClients() {return this->clientsRepository->findAll();}

// g -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int client index (position in repository vector + 1)
/// \return - returns client pointer to found client
ClientPtr ClientManager::getClient(int pIndex) const {return this->clientsRepository->get(pIndex);}


///
/// \return - returns repository pointer to client repository
const ClientRepositoryPtr &ClientManager::getClientsRepo() {return this->clientsRepository;}