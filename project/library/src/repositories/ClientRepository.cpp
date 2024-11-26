#include "repositories/ClientRepository.h"

// c -------------------------------------------------------------------------------------------------------------------
ClientRepository::ClientRepository() {}
ClientRepository::~ClientRepository() {}

// f -------------------------------------------------------------------------------------------------------------------
///
/// \param pIndex - int client index (position in repository vector + 1)
/// \return - returns client pointer to found client
ClientPtr ClientRepository::get(int pIndex) const {
    if(pIndex >= this->clients.size() || pIndex < 0)
        return nullptr;

    return this->clients[pIndex];
}

///
/// \param pClient - pointer to client wanted to be added to repository
/// \return - returns boolean information if the operation was successful
const bool ClientRepository::add(const ClientPtr &pClient) {
    if(pClient != nullptr && std::find(this->clients.begin(), this->clients.end(), pClient) == this->clients.end()) {
        this->clients.push_back(pClient);
        return true;
    }

    return false;
}

///
/// \param pClient - pointer to client wanted to be removed from repository
/// \return - returns boolean information if the operation was successful
const bool ClientRepository::remove(const ClientPtr &pClient) {
    if(pClient != nullptr && std::find(this->clients.begin(), this->clients.end(), pClient) != this->clients.end()) {
        this->clients.erase(std::remove(this->clients.begin(), this->clients.end(), pClient), this->clients.end());
        return true;
    }

    return false;
}

///
/// \return - returns string consisting of information of all clients being in repository
const std::string ClientRepository::report() const {
    std::string temp = "[Clients]\nNumber of clients: " + std::to_string(this->clients.size()) + "\n\n";

    for(int i = 0; i < this->clients.size(); i++) {
        temp += std::to_string(i+1) + ". " + this->clients[i]->getFullInfo() + "\n";
    }

    return temp;
}

///
/// \return - returns int amount of clients in repository
const int ClientRepository::size() const{
    return this->clients.size();
}

///
/// \param pClientPredicate - predicate pointer to function being used to find clients
/// \return - returns vector of found clients
const std::vector<ClientPtr> ClientRepository::findBy(const ClientPredicate &pClientPredicate) const {
    std::vector<ClientPtr> found;

    for(unsigned int i = 0; i < this->clients.size(); i++) {
        ClientPtr tempClient = this->clients[i];
        if(pClientPredicate(tempClient)) {
            found.push_back(tempClient);
        }
    }

    return found;
}

///
/// \return - returns vector of all clients
const std::vector<ClientPtr> ClientRepository::findAll() const {
    return findBy([](const ClientPtr pClient) { return true; });
}