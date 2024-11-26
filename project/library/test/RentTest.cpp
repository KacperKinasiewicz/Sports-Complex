#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/BasketballCourt.h"
#include "model/FootballPitch.h"
#include "model/PingPongTable.h"
#include "model/TennisCourt.h"
#include "model/VolleyballPitch.h"
#include "model/Rocket.h"
#include "model/Ball.h"

struct TestSuiteRentFixture {
    const pt::ptime testBeginTime = pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0));
    AddressPtr testAddress = std::make_shared<Address>("Lodz", "MainStreet", "10");
    DefaultPtr testDefault = std::make_shared<Default>();
    ClientPtr testClient= std::make_shared<Client>("Andrew", "Garfield", "123456789", testAddress, testDefault);
    FootballPitchPtr testCourt= std::make_shared<FootballPitch>("BOJO", 100, true, 10, true);
    BallPtr testFootball = std::make_shared<Ball>("EQ121", 100, Football);
    BallPtr testBasketball = std::make_shared<Ball>("EQ122", 100, Basketball);
    BallPtr testVolleyball = std::make_shared<Ball>("EQ123", 100, Volleyball);
    RentPtr testRent= std::make_shared<Rent>(testBeginTime, testClient, testCourt);
    pt::ptime eTime1 = pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0));
    pt::ptime eTime2 = pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(1));
    pt::ptime eTime3 = pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(2));
    pt::ptime eTime4 = pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(59));
    pt::ptime eTime5 = pt::ptime(gr::date(2001,1,1),pt::hours(2)+pt::minutes(0));
    pt::ptime eTime6 = pt::ptime(gr::date(2001,1,1),pt::hours(2)+pt::minutes(1));
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        RentPtr r = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r->addClient();
        BOOST_TEST(0 == r->getRentEquipment().size());
        r->appendEquipment(testFootball);
        BOOST_TEST(2 == r->getId());
        BOOST_TEST(testBeginTime == r->getBeginTime());
        BOOST_TEST(pt::not_a_date_time == r->getEndTime());
        BOOST_TEST(0 == r->getRentCost());
        BOOST_TEST(testClient == r->getRentClient());
        BOOST_TEST(testCourt == r->getRentCourt());
        BOOST_TEST(1 == r->getRentEquipment().size());
        BOOST_TEST(testCourt->isRented() == true);
        BOOST_TEST(testFootball->isRented() == true);
        BOOST_TEST(testClient->getCurrentRents().size() == 1);
        r->endRent(eTime3);
    }

    BOOST_AUTO_TEST_CASE(ReturnEverythingTest) {
        RentPtr rr = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        rr->addClient();
        rr->appendEquipment(testBasketball);
        rr->endRent(eTime3);
        BOOST_TEST(testCourt->isRented() == false);
        BOOST_TEST(testBasketball->isRented() == false);
        BOOST_TEST(testClient->getCurrentRents().size() == 0);
        BOOST_TEST(rr->getRentEquipment().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(BeginTimeTest) { //begintime == not_a_date_time
        const pt::ptime testBeginTime00 = pt::not_a_date_time;
        RentPtr r = std::make_shared<Rent>(testBeginTime00, testClient, testCourt);
        BOOST_TEST(pt::second_clock::local_time() == r->getBeginTime());
    }

    BOOST_AUTO_TEST_CASE(EndRentTest1) { //not a date time example, localtime > begintime
        pt::ptime eTime00 = pt::not_a_date_time;
        RentPtr r00 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r00->endRent(eTime00);
        BOOST_TEST(pt::second_clock::local_time() == r00->getEndTime());
    }

    BOOST_AUTO_TEST_CASE(EndRentTest2) { //not a date time example, localtime < begintime
        pt::ptime eTime00 = pt::not_a_date_time;
        const pt::ptime testBeginTime00 = pt::ptime(gr::date(2025,1,1),pt::hours(1)+pt::minutes(0));
        RentPtr r00 = std::make_shared<Rent>(testBeginTime00, testClient, testCourt);
        r00->endRent(eTime00);
        BOOST_TEST(testBeginTime00 == r00->getEndTime());
    }

    BOOST_AUTO_TEST_CASE(EndRentTest3) { //overwrite endtime
        RentPtr r01 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r01->endRent(eTime1);
        BOOST_TEST(eTime1 == r01->getEndTime());
        r01->endRent(eTime2);
        BOOST_TEST(eTime1 == r01->getEndTime());
    }

    BOOST_AUTO_TEST_CASE(EndRentTest4) { //endtime < begintime
        pt::ptime eTime02 = pt::ptime(gr::date(2001,1,1),pt::hours(0)+pt::minutes(0));
        RentPtr r02 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r02->endRent(eTime02);
        BOOST_TEST(testBeginTime == r02->getEndTime());
    }

    BOOST_AUTO_TEST_CASE(GetRentHoursTest1) { //endtime == begintime exaple
        RentPtr r1 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r1->endRent(eTime1);
        BOOST_TEST(0 == r1->getRentHours());
    }

    BOOST_AUTO_TEST_CASE(GetRentHoursTest2) { //endtime > begintime (1 min) example
        RentPtr r2 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r2->endRent(eTime2);
        BOOST_TEST(1 == r2->getRentHours());
    }

    BOOST_AUTO_TEST_CASE(GetRentHoursTest3) { //endtime > begintime (2 min) example
        RentPtr r3 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r3->endRent(eTime3);
        BOOST_TEST(1 == r3->getRentHours());
    }

    BOOST_AUTO_TEST_CASE(GetRentHoursTest4) { //endtime > begintime (59 min) example
        RentPtr r4 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r4->endRent(eTime4);
        BOOST_TEST(1 == r4->getRentHours());
    }

    BOOST_AUTO_TEST_CASE(GetRentHoursTest5) { //endtime > begintime (60 min) example
        RentPtr r5 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r5->endRent(eTime5);
        BOOST_TEST(2 == r5->getRentHours());
    }

    BOOST_AUTO_TEST_CASE(GetRentHoursTest6) { //endtime > begintime (61 min) example
        RentPtr r6 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        r6->endRent(eTime6);
        BOOST_TEST(2 == r6->getRentHours());
    }

    BOOST_AUTO_TEST_CASE(GetEquipmentPriceTest) {
        RentPtr req = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        req->addClient();
        req->appendEquipment(testFootball);
        req->appendEquipment(testBasketball);
        req->appendEquipment(testVolleyball);
        BOOST_TEST(req->getRentEquipmentPrice() == 360);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTest1) { //1 hour
        RentPtr rct1 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        rct1->addClient();
        rct1->appendEquipment(testBasketball);
        rct1->endRent(eTime3);
        BOOST_TEST(rct1->getRentCost()==301);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTest2) { //2 hours
        RentPtr rct2 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        rct2->addClient();
        rct2->appendEquipment(testBasketball);
        rct2->endRent(eTime6);
        BOOST_TEST(rct2->getRentCost()==602);
    }

    BOOST_AUTO_TEST_CASE(GetRentCostTest3) { //court baseprice changed after endrent
        RentPtr rct3 = std::make_shared<Rent>(testBeginTime, testClient, testCourt);
        rct3->addClient();
        rct3->appendEquipment(testBasketball);
        rct3->endRent(eTime3);
        testCourt->setBasePrice(200);
        BOOST_TEST(rct3->getRentCost()==301);
    }

BOOST_AUTO_TEST_SUITE_END()