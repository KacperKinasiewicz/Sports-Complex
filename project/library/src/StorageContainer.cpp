#include "StorageContainer.h"

StorageContainer::~StorageContainer(){}
StorageContainer::StorageContainer() {
    DefaultPtr ctd = std::make_shared<Default>();
    FitCarnetPtr ctf = std::make_shared<FitCarnet>();
    PatronPtr ctp = std::make_shared<Patron>();
    TrainerPtr ctt = std::make_shared<Trainer>();

    AddressPtr address1 = std::make_shared<Address>("Lodz", "Lodzka", "1/2");
    pt::ptime bTime=pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0));
    pt::ptime eTime1=pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(0));
    pt::ptime eTime2=pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(1));
    pt::ptime eTime3=pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(2));
    pt::ptime eTime4=pt::ptime(gr::date(2001,1,1),pt::hours(1)+pt::minutes(59));
    pt::ptime eTime5=pt::ptime(gr::date(2001,1,1),pt::hours(2)+pt::minutes(0));
    pt::ptime eTime6=pt::ptime(gr::date(2001,1,1),pt::hours(2)+pt::minutes(1));

    ClientPtr client1 = std::make_shared<Client>("aaa", "aaaaaa", "123456789", address1, ctd);
    ClientPtr client2 = std::make_shared<Client>("bbb", "bbbbbb", "123456789", address1, ctf);
    ClientPtr client3 = std::make_shared<Client>("ccc", "cccccc", "123456789", address1, ctp);
    ClientPtr client4 = std::make_shared<Client>("ddd", "dddddd", "123456789", address1, ctt);
    ClientPtr client5 = std::make_shared<Client>("ddd", "dddddd", "123456789", address1, ctt);
    ClientPtr client6 = std::make_shared<Client>("ddd", "dddddd", "123456789", address1, ctt);

    PingPongTablePtr pingpong1 = std::make_shared<PingPongTable>("pingpong1", 100);

    BasketballCourtPtr basket1 = std::make_shared<BasketballCourt>("basket1", 10, true, 10);
    BasketballCourtPtr basket2 = std::make_shared<BasketballCourt>("basket2", 10, false, 10);
    BasketballCourtPtr basket3 = std::make_shared<BasketballCourt>("basket3", 20, true, 10);

    VolleyballPitchPtr volleyball1 = std::make_shared<VolleyballPitch>("volleyball1", 10, true, 10);
    VolleyballPitchPtr volleyball2 = std::make_shared<VolleyballPitch>("volleyball2", 10, false, 10);
    VolleyballPitchPtr volleyball3 = std::make_shared<VolleyballPitch>("volleyball3", 20, true, 10);

    TennisCourtPtr tennis1 = std::make_shared<TennisCourt>("tennis1", 10, true);
    TennisCourtPtr tennis2 = std::make_shared<TennisCourt>("tennis2", 10, false);
    TennisCourtPtr tennis3 = std::make_shared<TennisCourt>("tennis3", 20, true);

    FootballPitchPtr football1 = std::make_shared<FootballPitch>("football1", 10, true, 10, true);
    FootballPitchPtr football2 = std::make_shared<FootballPitch>("football2", 10, false, 10, true);
    FootballPitchPtr football3 = std::make_shared<FootballPitch>("football3", 10, true, 10, false);
    FootballPitchPtr football4 = std::make_shared<FootballPitch>("football4", 10, false, 10, false);
    FootballPitchPtr football5 = std::make_shared<FootballPitch>("football5", 20, true, 10, true);

    BallPtr ball1 = std::make_shared<Ball>("ball1", 10, Football);
    BallPtr ball2 = std::make_shared<Ball>("ball2", 10, Basketball);
    BallPtr ball3 = std::make_shared<Ball>("ball3", 10, Volleyball);
    BallPtr ball4 = std::make_shared<Ball>("ball4", 20, Football);
    RocketPtr rocket1 = std::make_shared<Rocket>("rocket1", 10);
    RocketPtr rocket2 = std::make_shared<Rocket>("rocket2", 20);

    RentPtr rent1 = std::make_shared<Rent>(bTime, client1, football1);
    RentPtr rent2 = std::make_shared<Rent>(bTime, client2, basket1);
    RentPtr rent3 = std::make_shared<Rent>(bTime, client3, tennis1);
    RentPtr rent4 = std::make_shared<Rent>(bTime, client4, volleyball1);
    RentPtr rent5 = std::make_shared<Rent>(bTime, client5, football1);
    RentPtr rent6 = std::make_shared<Rent>(bTime, client6, football2);

    rent1->addClient();
    rent2->addClient();
    rent3->addClient();
    rent4->addClient();
    rent5->addClient();
    rent6->addClient();

    rent1->endRent(eTime1);
    rent2->endRent(eTime2);
    rent3->endRent(eTime3);
    rent4->endRent(eTime4);
    rent5->endRent(eTime5);
    rent6->endRent(eTime6);

    this->clientRepository->add(client1);
    this->clientRepository->add(client2);
    this->clientRepository->add(client3);
    this->clientRepository->add(client4);

    this->courtRepository->add(pingpong1);
    this->courtRepository->add(basket1);
    this->courtRepository->add(basket2);
    this->courtRepository->add(basket3);
    this->courtRepository->add(volleyball1);
    this->courtRepository->add(volleyball2);
    this->courtRepository->add(volleyball3);
    this->courtRepository->add(tennis1);
    this->courtRepository->add(tennis2);
    this->courtRepository->add(tennis3);
    this->courtRepository->add(football1);
    this->courtRepository->add(football2);
    this->courtRepository->add(football3);
    this->courtRepository->add(football4);
    this->courtRepository->add(football5);

    this->equipmentRepository->add(ball1);
    this->equipmentRepository->add(ball2);
    this->equipmentRepository->add(ball3);
    this->equipmentRepository->add(ball4);
    this->equipmentRepository->add(rocket1);
    this->equipmentRepository->add(rocket2);

    this->rentRepository->add(rent1);
    this->rentRepository->add(rent2);
    this->rentRepository->add(rent3);
    this->rentRepository->add(rent4);
    this->rentRepository->add(rent5);
    this->rentRepository->add(rent6);
}

///
/// \return - returns repository pointer to client repository
ClientRepositoryPtr StorageContainer::getClientRepository() {return this->clientRepository;}

///
/// \return - returns repository pointer to court repository
CourtRepositoryPtr StorageContainer::getCourtRepository() {return this->courtRepository;}

///
/// \return - returns repository pointer to equipment repository
EquipmentRepositoryPtr StorageContainer::getEquipmentRepository() {return this->equipmentRepository;}

///
/// \return - returns repository pointer to rent repository
RentRepositoryPtr StorageContainer::getRentRepository() {return this->rentRepository;}