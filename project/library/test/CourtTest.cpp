#include <boost/test/unit_test.hpp>
#include "model/BasketballCourt.h"
#include "model/FootballPitch.h"
#include "model/PingPongTable.h"
#include "model/TennisCourt.h"
#include "model/VolleyballPitch.h"

struct TestSuiteCourtFixture {
    const std::string testName = "BOJO";
    int testBasePrice = 100;
    int testArea = 10;
    FootballPitchPtr testCourt = std::make_shared<FootballPitch>(testName, testBasePrice, true, testArea, true);
    PingPongTablePtr pingpong1 = std::make_shared<PingPongTable>("pingpong1", 100);
    BasketballCourtPtr basket1 = std::make_shared<BasketballCourt>("basket1", 100, true, 10);
    BasketballCourtPtr basket2 = std::make_shared<BasketballCourt>("basket2", 100, false, 10);
    BasketballCourtPtr basket3 = std::make_shared<BasketballCourt>("basket3", 200, true, 10);
    VolleyballPitchPtr volleyball1 = std::make_shared<VolleyballPitch>("volleyball1", 100, true, 10);
    VolleyballPitchPtr volleyball2 = std::make_shared<VolleyballPitch>("volleyball2", 100, false, 10);
    VolleyballPitchPtr volleyball3 = std::make_shared<VolleyballPitch>("volleyball3", 200, true, 10);
    TennisCourtPtr tennis1 = std::make_shared<TennisCourt>("tennis1", 100, true);
    TennisCourtPtr tennis2 = std::make_shared<TennisCourt>("tennis2", 100, false);
    TennisCourtPtr tennis3 = std::make_shared<TennisCourt>("tennis3", 200, true);
    FootballPitchPtr football1 = std::make_shared<FootballPitch>("football1", 100, true, 10, true);
    FootballPitchPtr football2 = std::make_shared<FootballPitch>("football2", 100, false, 10, true);
    FootballPitchPtr football3 = std::make_shared<FootballPitch>("football3", 100, true, 10, false);
    FootballPitchPtr football4 = std::make_shared<FootballPitch>("football4", 100, false, 10, false);
    FootballPitchPtr football5 = std::make_shared<FootballPitch>("football5", 200, true, 10, true);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteCourt, TestSuiteCourtFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        FootballPitchPtr f = std::make_shared<FootballPitch>(testName, testBasePrice, true, testArea, true);
        BOOST_TEST(testName == f->getName());
        BOOST_TEST(testBasePrice == f->getBasePrice());
        BOOST_TEST(true == f->isCovered());
        BOOST_TEST(testArea == f->getArea());
        BOOST_TEST(true == f->isGrassed());
        BOOST_TEST(false == f->isRented());
    }

    BOOST_AUTO_TEST_CASE(BasePriceSetterTestPositive) {
        int testBPSTP = 10;
        testCourt->setBasePrice(testBPSTP);
        BOOST_TEST(testBPSTP == testCourt->getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(BasePriceSetterTestNegative) {
        int testBPSTN = -1;
        testCourt->setBasePrice(testBPSTN);
        BOOST_TEST(testBasePrice == testCourt->getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(RentedSetterTestPositive) {
        testCourt->setRented(true);
        BOOST_TEST(true == testCourt->isRented());
    }

    BOOST_AUTO_TEST_CASE(Pingpong1PriceTest) {
        BOOST_TEST(95 == int(pingpong1->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Basket1PriceTest) {
        BOOST_TEST(154 == int(basket1->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Basket2PriceTest) {
        BOOST_TEST(103 == int(basket2->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Basket3PriceTest) {
        BOOST_TEST(309 == int(basket3->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Volleyball1PriceTest) {
        BOOST_TEST(157 == int(volleyball1->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Volleyball2PriceTest) {
        BOOST_TEST(105 == int(volleyball2->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Volleyball3PriceTest) {
        BOOST_TEST(315 == int(volleyball3->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Tennis1PriceTest) {
        BOOST_TEST(137 == int(tennis1->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Tennis2PriceTest) {
        BOOST_TEST(110 == int(tennis2->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Tennis3PriceTest) {
        BOOST_TEST(275 == int(tennis3->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Football1PriceTest) {
        BOOST_TEST(181 == int(football1->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Football2PriceTest) {
        BOOST_TEST(131 == int(football2->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Football3PriceTest) {
        BOOST_TEST(155 == int(football3->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Football4PriceTest) {
        BOOST_TEST(105 == int(football4->getActualCourtPrice()));
    }

    BOOST_AUTO_TEST_CASE(Football5PriceTest) {
        BOOST_TEST(362 == int(football5->getActualCourtPrice()));
    }

BOOST_AUTO_TEST_SUITE_END()