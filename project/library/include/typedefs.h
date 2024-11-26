#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <boost/date_time.hpp>

// class ---------------------------------------------------------------------------------------------------------------
class BasketballCourt;
class Court;
class CoveredCourt;
class FootballPitch;
class GrassPitch;
class PingPongTable;
class TennisCourt;
class VolleyballPitch;

class Equipment;
class Rocket;
class Ball;

class Client;
class Address;
class ClientType;
class Default;
class FitCarnet;
class Patron;
class Trainer;

class Rent;

class ClientRepository;
class CourtRepository;
class EquipmentRepository;
class RentRepository;
class StorageContainer;

class ClientManager;
class CourtManager;
class EquipmentManager;
class RentManager;
class SuperManager;

// typedefs ------------------------------------------------------------------------------------------------------------
typedef std::shared_ptr<BasketballCourt> BasketballCourtPtr;
typedef std::shared_ptr<Court> CourtPtr;
typedef std::shared_ptr<CoveredCourt> CoveredCourtPtr;
typedef std::shared_ptr<FootballPitch> FootballPitchPtr;
typedef std::shared_ptr<GrassPitch> GrassPitchPtr;
typedef std::shared_ptr<PingPongTable> PingPongTablePtr;
typedef std::shared_ptr<TennisCourt> TennisCourtPtr;
typedef std::shared_ptr<VolleyballPitch> VolleyballPitchPtr;

typedef std::shared_ptr<Equipment> EquipmentPtr;
typedef std::shared_ptr<Rocket> RocketPtr;
typedef std::shared_ptr<Ball> BallPtr;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Default> DefaultPtr;
typedef std::shared_ptr<FitCarnet> FitCarnetPtr;
typedef std::shared_ptr<Patron> PatronPtr;
typedef std::shared_ptr<Trainer> TrainerPtr;

typedef std::shared_ptr<Rent> RentPtr;

typedef std::vector<ClientPtr> VectorClientPtr;
typedef std::vector<CourtPtr> VectorCourtPtr;
typedef std::vector<EquipmentPtr> VectorEquipmentPtr;
typedef std::vector<RentPtr> VectorRentPtr;

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<CourtRepository> CourtRepositoryPtr;
typedef std::shared_ptr<EquipmentRepository> EquipmentRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;
typedef std::shared_ptr<StorageContainer> StorageContainerPtr;

typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<CourtManager> CourtManagerPtr;
typedef std::shared_ptr<EquipmentManager> EquipmentManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;
typedef std::shared_ptr<SuperManager> SuperManagerPtr;

typedef std::function<bool(const ClientPtr &pClient)> ClientPredicate;
typedef std::function<bool(const CourtPtr &pCourt)> CourtPredicate;
typedef std::function<bool(const EquipmentPtr &pEquipment)> EquipmentPredicate;
typedef std::function<bool(const RentPtr &pRent)> RentPredicate;

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

#endif