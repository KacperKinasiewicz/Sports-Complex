#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture {
    std::string testFirstName = "aaa";
    std::string testLastName = "aaaaaa";
    std::string testPersonalID = "123456789";
    AddressPtr testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
    DefaultPtr testDefault = std::make_shared<Default>();
    FitCarnetPtr testFitCarnet = std::make_shared<FitCarnet>();
    PatronPtr testPatron = std::make_shared<Patron>();
    TrainerPtr testTrainer = std::make_shared<Trainer>();
    ClientPtr testClient = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testAddress, testDefault);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testAddress, testDefault);
        BOOST_TEST(testFirstName == c->getFirstName());
        BOOST_TEST(testLastName == c->getLastName());
        BOOST_TEST(testPersonalID == c->getPersonalID());
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterTestPositive) {
        std::string testFNSTP = "bbb";
        testClient->setFirstName(testFNSTP);
        BOOST_TEST(testFNSTP == testClient->getFirstName());
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterTestNegative) {
        std::string testCSTN = "";
        testClient->setFirstName(testCSTN);
        BOOST_TEST(testFirstName == testClient->getFirstName());
    }

    BOOST_AUTO_TEST_CASE(LastNameSetterTestPositive) {
        std::string testLNSTP = "bbbbbb";
        testClient->setLastName(testLNSTP);
        BOOST_TEST(testLNSTP == testClient->getLastName());
    }

    BOOST_AUTO_TEST_CASE(LastNameSetterTestNegative) {
        std::string testLNSTN = "";
        testClient->setLastName(testLNSTN);
        BOOST_TEST(testLastName == testClient->getLastName());
    }

    BOOST_AUTO_TEST_CASE(AddressSetterTestPositive) {
        AddressPtr testASTP = std::make_shared<Address>("zgierz", "polna", "12312");
        testClient->setAddress(testASTP);
        BOOST_TEST(testASTP == testClient->getAddress());
    }

    BOOST_AUTO_TEST_CASE(AddressSetterTestNegative) {
        AddressPtr testASTN;
        testClient->setAddress(testASTN);
        BOOST_TEST(testAddress == testClient->getAddress());
    }

    BOOST_AUTO_TEST_CASE(ClientTypeSetterTestPositive) {
        testClient->setClientType(testFitCarnet);
        BOOST_TEST(testFitCarnet == testClient->getClientType());
    }

    BOOST_AUTO_TEST_CASE(ClientTypeSetterTestNegative) {
        FitCarnetPtr testCTSTN;
        testClient->setClientType(testCTSTN);
        BOOST_TEST(testCTSTN != testClient->getClientType());
    }

    BOOST_AUTO_TEST_CASE(DefaultCourtsTest) {
        testClient->setClientType(testDefault);
        BOOST_TEST(testClient->getClientType()->getMaxCourts() == 1);
    }

    BOOST_AUTO_TEST_CASE(FitCarnetCourtsTest) {
        testClient->setClientType(testFitCarnet);
        BOOST_TEST(testClient->getClientType()->getMaxCourts() == 1);
    }

    BOOST_AUTO_TEST_CASE(PatronCourtsTest) {
        testClient->setClientType(testPatron);
        BOOST_TEST(testClient->getClientType()->getMaxCourts() == 3);
    }

    BOOST_AUTO_TEST_CASE(TrainerCourtsTest) {
        testClient->setClientType(testTrainer);
        BOOST_TEST(testClient->getClientType()->getMaxCourts() == 5);
    }

    BOOST_AUTO_TEST_CASE(DefaultDiscountTest) {
        testClient->setClientType(testDefault);
        BOOST_TEST(testClient->getClientType()->applyDiscount(100) == 100);
    }

    BOOST_AUTO_TEST_CASE(FitCarnetDiscountTest) {
        testClient->setClientType(testFitCarnet);
        BOOST_TEST(testClient->getClientType()->applyDiscount(100) == 95);
    }

    BOOST_AUTO_TEST_CASE(PatronDiscountTest) {
        testClient->setClientType(testPatron);
        BOOST_TEST(testClient->getClientType()->applyDiscount(100) == 90);
    }

    BOOST_AUTO_TEST_CASE(TrainerDiscountTest) {
        testClient->setClientType(testTrainer);
        BOOST_TEST(testClient->getClientType()->applyDiscount(100) == 85);
    }

    BOOST_AUTO_TEST_SUITE_END()