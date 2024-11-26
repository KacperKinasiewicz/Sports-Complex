#include <boost/test/unit_test.hpp>
#include "model/Address.h"

struct TestSuiteAddressFixture {
    const std::string testCity = "London";
    const std::string testStreet = "Accacia Avenue";
    const std::string testNumber = "22";
    AddressPtr testAddress = std::make_shared<Address>(testCity, testStreet, testNumber);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        AddressPtr a = std::make_shared<Address>(testCity, testStreet, testNumber);
        BOOST_TEST(testCity == a->getCity());
        BOOST_TEST(testStreet == a->getStreet());
        BOOST_TEST(testNumber == a->getNumber());
    }

    BOOST_AUTO_TEST_CASE(CitySetterTestPositive) {
        std::string testCSTP = "Zgierz";
        testAddress->setCity(testCSTP);
        BOOST_TEST(testCSTP == testAddress->getCity());
    }

    BOOST_AUTO_TEST_CASE(CitySetterTestNegative) {
        std::string testCSTN = "";
        testAddress->setCity(testCSTN);
        BOOST_TEST(testCity == testAddress->getCity());
    }

    BOOST_AUTO_TEST_CASE(StreetSetterTestPositive) {
        std::string testSSTP = "Polna";
        testAddress->setCity(testSSTP);
        BOOST_TEST(testSSTP == testAddress->getCity());
    }

    BOOST_AUTO_TEST_CASE(StreetSetterTestNegative) {
        std::string testSSTN = "";
        testAddress->setCity(testSSTN);
        BOOST_TEST(testCity == testAddress->getCity());
    }

    BOOST_AUTO_TEST_CASE(NumberSetterTestPositive) {
        std::string testNSTP = "666";
        testAddress->setCity(testNSTP);
        BOOST_TEST(testNSTP == testAddress->getCity());
    }

    BOOST_AUTO_TEST_CASE(NumberSetterTestNegative) {
        std::string testNSTN = "";
        testAddress->setCity(testNSTN);
        BOOST_TEST(testCity == testAddress->getCity());
    }

BOOST_AUTO_TEST_SUITE_END()