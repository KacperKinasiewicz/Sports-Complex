#include <boost/test/unit_test.hpp>
#include "model/Ball.h"
#include "model/Rocket.h"

struct TestSuiteEquipmentFixture {
    const std::string testModel = "EQ123";
    int testBasePrice = 100;
    BallPtr testFootball = std::make_shared<Ball>(testModel, testBasePrice, Football);
    BallPtr testBasketball = std::make_shared<Ball>(testModel, testBasePrice, Basketball);
    BallPtr testVolleyball = std::make_shared<Ball>(testModel, testBasePrice, Volleyball);
    RocketPtr testRocket = std::make_shared<Rocket>(testModel, testBasePrice);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteEquipment, TestSuiteEquipmentFixture)

    BOOST_AUTO_TEST_CASE(ParameterBallConstrutorTest) {
        BallPtr b = std::make_shared<Ball>(testModel, testBasePrice, Football);
        BOOST_TEST(testModel == b->getModel());
        BOOST_TEST(testBasePrice == b->getBasePrice());
        BOOST_TEST("Football" == b->getSegmentType());
    }

    BOOST_AUTO_TEST_CASE(ParameterRocketConstrutorTest) {
        RocketPtr r = std::make_shared<Rocket>(testModel, testBasePrice);
        BOOST_TEST(testModel == r->getModel());
        BOOST_TEST(testBasePrice == r->getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(BasePriceSetterTestPositive) {
        int testBPSTP = 10;
        testFootball->setBasePrice(testBPSTP);
        BOOST_TEST(testBPSTP == testFootball->getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(BasePriceSetterTestNegative) {
        int testBPSTN = -1;
        testFootball->setBasePrice(testBPSTN);
        BOOST_TEST(testBasePrice == testFootball->getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(RentedSetterTestPositive) {
        testFootball->setRented(true);
        BOOST_TEST(true == testFootball->isRented());
    }

    BOOST_AUTO_TEST_CASE(RocketPriceTest) {
        BOOST_TEST(150 == int(testRocket->getActualEquipmentPrice()));
    }

    BOOST_AUTO_TEST_CASE(FootballPriceTest) {
        BOOST_TEST(130 == int(testFootball->getActualEquipmentPrice()));
    }

    BOOST_AUTO_TEST_CASE(BasketballPriceTest) {
        BOOST_TEST(120 == int(testBasketball->getActualEquipmentPrice()));
    }

    BOOST_AUTO_TEST_CASE(VolleyballPriceTest) {
        BOOST_TEST(110 == int(testVolleyball->getActualEquipmentPrice()));
    }

BOOST_AUTO_TEST_SUITE_END()