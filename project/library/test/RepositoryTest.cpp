#include <boost/test/unit_test.hpp>
#include "StorageContainer.h"
#include "repositories/ClientRepository.h"
#include "repositories/CourtRepository.h"
#include "repositories/EquipmentRepository.h"
#include "repositories/RentRepository.h"

struct TestSuiteRepositoryFixture {
// Repositories
    ClientRepositoryPtr clientRepository = std::make_shared<ClientRepository>();
    CourtRepositoryPtr courtRepository = std::make_shared<CourtRepository>();
    EquipmentRepositoryPtr equipmentRepository = std::make_shared<EquipmentRepository>();
    RentRepositoryPtr rentRepository = std::make_shared<RentRepository>();

// Client
    AddressPtr address = std::make_shared<Address>("Lodz", "Lodzka", "1/2");
    DefaultPtr clientTypeDefault = std::make_shared<Default>();

    ClientPtr client1 = std::make_shared<Client>("aaa", "aaaaaa", "111111111", address, clientTypeDefault);
    ClientPtr client2 = std::make_shared<Client>("bbb", "bbbbbb", "222222222", address, clientTypeDefault);

// Court
    PingPongTablePtr pingpong1 = std::make_shared<PingPongTable>("pingpong1", 100);
    BasketballCourtPtr basketball1 = std::make_shared<BasketballCourt>("basket1", 10, true, 10);

// Equipment
    BallPtr ball1 = std::make_shared<Ball>("ball1", 10, Football);
    RocketPtr rocket1 = std::make_shared<Rocket>("rocket1", 10);

// Rent
    RentPtr rent1 = std::make_shared<Rent>(pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0)), client1, pingpong1);
    RentPtr rent2 = std::make_shared<Rent>(pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0)), client2, basketball1);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepository, TestSuiteRepositoryFixture)
// ClientRepository ----------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(ClientRepositoryGetTestPositive) {
        clientRepository->add(client1);

        BOOST_TEST(clientRepository->get(0) == client1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetTestNegative) {
        BOOST_TEST(clientRepository->get(0) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddTestPositive) {
        BOOST_TEST(clientRepository->add(client1) == true);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddTestNegative) {
        BOOST_TEST(clientRepository->add(client1) == true);
        BOOST_TEST(clientRepository->add(client1) == false);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveTestPositive) {
        clientRepository->add(client1);

        BOOST_TEST(clientRepository->remove(client1) == true);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveTestNegative) {
        BOOST_TEST(clientRepository->remove(client1) == false);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositorySizeTest) {
        clientRepository->add(client1);
        clientRepository->add(client2);

        BOOST_TEST(clientRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByTestPositive) {
        clientRepository->add(client1);
        clientRepository->add(client2);

        ClientPredicate predicate = [](const ClientPtr& pClient) {
            return pClient->getFirstName() == "aaa";
        };

        BOOST_TEST(clientRepository->findBy(predicate).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByTestNegative) {
        ClientPredicate predicate = [](const ClientPtr& pClient) {
            return pClient->getFirstName() == "aaa";
        };

        BOOST_TEST(clientRepository->findBy(predicate).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindAllTestPositive) {
        clientRepository->add(client1);
        clientRepository->add(client2);

        BOOST_TEST(clientRepository->findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindAllTestNegative) {
        BOOST_TEST(clientRepository->findAll().size() == 0);
    }

// CourtRepository -----------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(CourtRepositoryGetTestPositive) {
        courtRepository->add(pingpong1);

        BOOST_TEST(courtRepository->get(0) == pingpong1);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryGetTestNegative) {
        BOOST_TEST(courtRepository->get(0) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryAddTestPositive) {
        BOOST_TEST(courtRepository->add(pingpong1) == true);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryAddTestNegative) {
        BOOST_TEST(courtRepository->add(pingpong1) == true);
        BOOST_TEST(courtRepository->add(pingpong1) == false);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryRemoveTestPositive) {
        courtRepository->add(pingpong1);

        BOOST_TEST(courtRepository->remove(pingpong1) == true);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryRemoveTestNegative) {
        BOOST_TEST(courtRepository->remove(pingpong1) == false);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositorySizeTest) {
        courtRepository->add(pingpong1);
        courtRepository->add(basketball1);

        BOOST_TEST(courtRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryFindByTestPositive) {
        courtRepository->add(pingpong1);
        courtRepository->add(basketball1);

        CourtPredicate predicate = [](const CourtPtr& pCourt) {
            return pCourt->getName() == "pingpong1";
        };

        BOOST_TEST(courtRepository->findBy(predicate).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryFindByTestNegative) {
        CourtPredicate predicate = [](const CourtPtr& pCourt) {
            return pCourt->getName() == "pingpong1";
        };

        BOOST_TEST(courtRepository->findBy(predicate).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryFindAllTestPositive) {
        courtRepository->add(pingpong1);
        courtRepository->add(basketball1);

        BOOST_TEST(courtRepository->findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(CourtRepositoryFindAllTestNegative) {
        BOOST_TEST(courtRepository->findAll().size() == 0);
    }

// EquipmentRepository -------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(EquipmentRepositoryGetTestPositive) {
        equipmentRepository->add(ball1);

        BOOST_TEST(equipmentRepository->get(0) == ball1);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryGetTestNegative) {
        BOOST_TEST(equipmentRepository->get(0) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryAddTestPositive) {
        BOOST_TEST(equipmentRepository->add(ball1) == true);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryAddTestNegative) {
        BOOST_TEST(equipmentRepository->add(ball1) == true);
        BOOST_TEST(equipmentRepository->add(ball1) == false);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryRemoveTestPositive) {
        equipmentRepository->add(ball1);

        BOOST_TEST(equipmentRepository->remove(ball1) == true);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryRemoveTestNegative) {
        BOOST_TEST(equipmentRepository->remove(ball1) == false);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositorySizeTest) {
        equipmentRepository->add(ball1);
        equipmentRepository->add(rocket1);

        BOOST_TEST(equipmentRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryFindByTestPositive) {
        equipmentRepository->add(ball1);
        equipmentRepository->add(rocket1);

        EquipmentPredicate predicate = [](const EquipmentPtr& pEquipment) {
            return pEquipment->getModel() == "ball1";
        };

        BOOST_TEST(equipmentRepository->findBy(predicate).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryFindByTestNegative) {
        EquipmentPredicate predicate = [](const EquipmentPtr& pEquipment) {
            return pEquipment->getModel() == "ball1";
        };

        BOOST_TEST(equipmentRepository->findBy(predicate).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryFindAllTestPositive) {
        equipmentRepository->add(ball1);
        equipmentRepository->add(rocket1);

        BOOST_TEST(equipmentRepository->findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(EquipmentRepositoryFindAllTestNegative) {
        BOOST_TEST(equipmentRepository->findAll().size() == 0);
    }

// RentRepository ------------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(RentRepositoryGetTestPositive) {
        rentRepository->add(rent1);

        BOOST_TEST(rentRepository->get(rent1->getId()) == rent1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryGetTestNegative) {
        BOOST_TEST(rentRepository->get(rent1->getId()) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddTestPositive) {
        BOOST_TEST(rentRepository->add(rent1) == true);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddTestNegative) {
        BOOST_TEST(rentRepository->add(rent1) == true);
        BOOST_TEST(rentRepository->add(rent1) == false);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveTestPositive) {
        rentRepository->add(rent1);

        BOOST_TEST(rentRepository->remove(rent1) == true);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveTestNegative) {
        BOOST_TEST(rentRepository->remove(rent1) == false);
    }

    BOOST_AUTO_TEST_CASE(RentRepositorySizeTest) {
        rentRepository->add(rent1);
        rentRepository->add(rent2);

        BOOST_TEST(rentRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindByTestPositive) {
        rentRepository->add(rent1);
        rentRepository->add(rent2);

        RentPredicate predicate = [this](const RentPtr& pRent) {
            return pRent->getId() == rent1->getId();
        };

        BOOST_TEST(rentRepository->findBy(predicate).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindByTestNegative) {
        RentPredicate predicate = [](const RentPtr& pRent) {
            return pRent->getId() == 1;
        };

        BOOST_TEST(rentRepository->findBy(predicate).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindAllTestPositive) {
        rentRepository->add(rent1);
        rentRepository->add(rent2);

        BOOST_TEST(rentRepository->findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindAllTestNegative) {
        BOOST_TEST(rentRepository->findAll().size() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()