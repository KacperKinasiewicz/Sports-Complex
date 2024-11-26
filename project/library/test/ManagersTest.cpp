#include <boost/test/unit_test.hpp>
#include "SuperManager.h"

struct TestSuiteManagerFixture {
    SuperManagerPtr testSuperManager = std::make_shared<SuperManager>();
    DefaultPtr ctd = std::make_shared<Default>();
    FitCarnetPtr ctf = std::make_shared<FitCarnet>();
    PatronPtr ctp = std::make_shared<Patron>();
    TrainerPtr ctt = std::make_shared<Trainer>();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteManager, TestSuiteManagerFixture)
// ClientManager ----------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(RegisterClientTest) {
        testSuperManager->getClientManager()->registerClient("Andrew", "Garfield", "123456789", "Lodz", "MainStreet", "10", ctd);
        BOOST_TEST(testSuperManager->getStorageContainer()->getClientRepository()->size() == 5);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        testSuperManager->getClientManager()->unregisterClient(testSuperManager->getClientManager()->getClient(5));
        BOOST_TEST(testSuperManager->getStorageContainer()->getClientRepository()->size() == 4);
    }

    BOOST_AUTO_TEST_CASE(GetClientRepositoryTest) {
        BOOST_TEST(testSuperManager->getStorageContainer()->getClientRepository() == testSuperManager->getClientManager()->getClientsRepo());
    }

// CourtManager ----------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(RegisterCourtTest) {
        testSuperManager->getCourtManager()->registerPingPongTable("pingpong1", 100);
        BOOST_TEST(testSuperManager->getStorageContainer()->getCourtRepository()->size() == 16);
    }

    BOOST_AUTO_TEST_CASE(UnregisterCourtTest) {
        testSuperManager->getClientManager()->unregisterClient(testSuperManager->getClientManager()->getClient(16));
        BOOST_TEST(testSuperManager->getStorageContainer()->getCourtRepository()->size() == 15);
    }

    BOOST_AUTO_TEST_CASE(GetCourtRepositoryTest) {
        BOOST_TEST(testSuperManager->getStorageContainer()->getCourtRepository() == testSuperManager->getCourtManager()->getCourtsRepo());
    }

// EquipmentManager ----------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(RegisterEquipmentTest) {
        testSuperManager->getEquipmentManager()->registerBall("ball1", 10, Football);
        BOOST_TEST(testSuperManager->getStorageContainer()->getEquipmentRepository()->size() == 7);
    }
    BOOST_AUTO_TEST_CASE(UnregisterEquipmentTest) {
        testSuperManager->getEquipmentManager()->unregisterEquipment(testSuperManager->getEquipmentManager()->getEquipment(7));
        BOOST_TEST(testSuperManager->getStorageContainer()->getEquipmentRepository()->size() == 6);
    }

    BOOST_AUTO_TEST_CASE(GetEquipmentRepositoryTest) {
        BOOST_TEST(testSuperManager->getStorageContainer()->getEquipmentRepository() == testSuperManager->getEquipmentManager()->getEquipmentsRepo());
    }

// RentManager ----------------------------------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(RegisterRentTest) {
        pt::ptime bTime = pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0));
        ClientPtr testClient = testSuperManager->getClientManager()->getClient(1);
        CourtPtr testCourt = testSuperManager->getCourtManager()->getCourt(1);
        testSuperManager->getRentManager()->registerRent(bTime, testClient, testCourt);
        BOOST_TEST(testSuperManager->getStorageContainer()->getRentRepository()->size() == 7);
    }

    BOOST_AUTO_TEST_CASE(UnregisterRentTest) {
        testSuperManager->getRentManager()->unregisterRent(testSuperManager->getRentManager()->getRent(7));
        BOOST_TEST(testSuperManager->getStorageContainer()->getRentRepository()->size() == 6);
    }

    BOOST_AUTO_TEST_CASE(GetRentRepositoryTest) {
        BOOST_TEST(testSuperManager->getStorageContainer()->getRentRepository() == testSuperManager->getRentManager()->getRentsRepo());
    }

BOOST_AUTO_TEST_SUITE_END()