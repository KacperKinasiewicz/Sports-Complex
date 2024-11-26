#ifndef COURTRENTAL_CLIENTREPOSITORY_H
#define COURTRENTAL_CLIENTREPOSITORY_H

#include "typedefs.h"
#include "../model/Client.h"

class ClientRepository {
private:
    VectorClientPtr clients = {};

public:
    ClientRepository();
    ~ClientRepository();

    ClientPtr get(int pIndex) const;
    const bool add(const ClientPtr &pClient);
    const bool remove(const ClientPtr &pClient);

    const std::string report() const;
    const int size() const;

    const VectorClientPtr findBy(const ClientPredicate &pClientPredicate) const;
    const VectorClientPtr findAll() const;
};

#endif //COURTRENTAL_CLIENTREPOSITORY_H