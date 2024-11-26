#include "SuperManager.h"

using namespace std;


// variables ===========================================================================================================
int chooseAction();
int chooseDisplayAction();
int chooseAddAction();
int chooseRemoveAction();
void actions(int option);
void addActions(int option);
void displayActions(int option);
void removeActions(int option);

std::string getString();
int getInt();
pt::ptime getDate();

SuperManagerPtr supermanager = std::make_shared<SuperManager>();
AddressPtr address = std::make_shared<Address>("city", "street", "number");


// main ================================================================================================================
int main()
{
    system("clear");
    while(true) { actions(chooseAction()); }
    return 0;
}


// choose actions ======================================================================================================
int chooseAction() {
    int option;

    cout << "Options:" << endl
         << "1. Display" << endl
         << "2. Add" << endl
         << "3. Exit" << endl << endl
         << "> ";

    option = getInt();
    return option;
}

// chooseDisplayAction -------------------------------------
int chooseDisplayAction() {
    int option;

    cout << "Options:" << endl
         << "1. Display Clients" << endl
         << "2. Display Courts" << endl
         << "3. Display Equipment" << endl
         << "4. Display Rents" << endl
         << "5. Go back" << endl << endl
         << "> ";

    option = getInt();
    return option;
}

// chooseAddAction -----------------------------------------
int chooseAddAction() {
    int option;

    cout << "Options:" << endl
         << "1. Add Client" << endl
         << "2. Add Court" << endl
         << "3. Add Equipment" << endl
         << "4. Rent Court" << endl
         << "5. End Rent" << endl
         << "6. Go back" << endl << endl
         << "> ";

    option = getInt();
    return option;
}

// chooseRemoveAction --------------------------------------
int chooseRemoveAction() {
    int option;

    cout << "Options:" << endl
         << "1. Add Client" << endl
         << "2. Add Court" << endl
         << "3. Add Equipment" << endl
         << "4. Rent Court" << endl
         << "5. Go back" << endl << endl
         << "> ";

    option = getInt();
    return option;
}


// Actions =============================================================================================================
void actions(int option) {
    switch (option) {
        case 1:
            system("clear");
            displayActions(chooseDisplayAction());
            break;

        case 2:
            system("clear");
            addActions(chooseAddAction());
            break;

        case 3:
            system("clear");
            exit(0);
            break;

        default:
            system("clear");
            break;
    }
}


// displayActions ======================================================================================================
void displayActions(int option) {
    switch(option) {
        case 1:
            system("clear");
            cout << supermanager->getClientManager()->getClientsRepo()->report() << endl;
            break;

        case 2:
            system("clear");
            cout << supermanager->getCourtManager()->getCourtsRepo()->report() << endl;
            break;

        case 3:
            system("clear");
            cout << supermanager->getEquipmentManager()->getEquipmentsRepo()->report() << endl;
            break;

        case 4:
            system("clear");
            cout << supermanager->getRentManager()->getRentsRepo()->report() << endl;
            break;

        case 5:
            system("clear");
            actions(chooseAction());
            break;

        default:
            system("clear");
            break;
    }
}


// addActions ==========================================================================================================
void addActions(int option) {
    switch(option) {

// Add Client ----------------------------------------------------------------------------------------------------------
        case 1: {

    // variables
            int clientTypeChoice;
            ClientTypePtr pClientType;

    // couts
            system("clear");
            cout << "[New Client]" << endl;

        // first name
            cout << endl << "First name" << endl << "> ";
            std::string pFirstName = getString();

        // last name
            cout << endl << "Last name" << endl << "> ";
            std::string pLastName = getString();

        // personal id
            cout << endl << "Personal ID" << endl << "> ";
            std::string pPersonalID = getString();

        // city
            cout << endl << "City" << endl << "> ";
            std::string pCity = getString();

        // street
            cout << endl << "Street" << endl << "> ";
            std::string pStreet = getString();

        // number
            cout << endl << "Number" << endl << "> ";
            std::string pNumber = getString();

        // client type
            cout << endl << "Client type:" << endl
                 << "1 - Default" << endl
                 << "2 - FitCarnet" << endl
                 << "3 - Patron" << endl
                 << "4 - Trainer" << endl << "> ";

            do {
                clientTypeChoice = getInt();
                switch(clientTypeChoice) {
                    case 1:
                        pClientType = std::make_shared<Default>();
                        break;
                    case 2:
                        pClientType = std::make_shared<FitCarnet>();
                        break;
                    case 3:
                        pClientType = std::make_shared<Patron>();
                        break;
                    case 4:
                        pClientType = std::make_shared<Trainer>();
                        break;
                    default:
                        cout << endl << "Unknown option. Please enter a valid option" << endl << "> ";
                        break;
                }
            } while(clientTypeChoice < 1 || clientTypeChoice > 4);

    // register client
            supermanager->getClientManager()->registerClient(pFirstName, pLastName, pPersonalID, pCity, pStreet, pNumber, pClientType);

            int pIndex = supermanager->getClientManager()->getClientsRepo()->size()-1;
            system("clear");
            cout << "[Client Succesfully Registered]" << endl << endl << supermanager->getClientManager()->getClientsRepo()->get(pIndex)->getFullInfo() << endl << endl;
            break;
        }

// Add Court -----------------------------------------------------------------------------------------------------------
        case 2: {

    // variables
            int courtTypeChoice;
            bool pCovered;
            int pArea;
            bool pGrassed;

    // couts
            system("clear");
            cout << "[New Court]" << endl;

        // court type
            cout << endl << "Court type:" << endl
                 << "1 - PingPongTable" << endl
                 << "2 - VolleyballPitch" << endl
                 << "3 - BasketballCourt" << endl
                 << "4 - TennisCourt" << endl
                 << "5 - FootballPitch" << endl << "> ";

            do {
                courtTypeChoice = getInt();
                if(courtTypeChoice < 1 || courtTypeChoice > 5)
                    cout << endl << "Unknown option. Please enter a valid option" << endl << "> ";
            } while(courtTypeChoice < 1 || courtTypeChoice > 5);

        // name
            cout << endl << "Name" << endl << "> ";
            std::string pName = getString();

        // base price
            cout << endl << "Base price" << endl << "> ";
            int pCourtBasePrice = getInt();

        // covered / area
            if(courtTypeChoice == 2 || courtTypeChoice == 3 || courtTypeChoice == 5) {
                cout << endl << "Covered" << endl
                     << "0 - No" << endl
                     << "1 - Yes" << endl << "> ";
                pCovered = getInt();

                cout << endl << "Area" << endl << "> ";
                pArea = getInt();
            }

        // grassed
            if(courtTypeChoice == 4 || courtTypeChoice == 5) {
                cout << endl << "Grassed" << endl
                     << "0 - No" << endl
                     << "1 - Yes" << endl << "> ";
                pGrassed = getInt();
            }

    // register court
            switch(courtTypeChoice) {
                case 1: {
                    supermanager->getCourtManager()->registerPingPongTable(pName, pCourtBasePrice);
                    int pIndex = supermanager->getCourtManager()->getCourtsRepo()->size()-1;
                    system("clear");
                    cout << "[PingPongTable Succesfully Registered]" << endl << endl << supermanager->getCourtManager()->getCourtsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
                case 2: {
                    supermanager->getCourtManager()->registerVolleyballPitch(pName, pCourtBasePrice, pCovered, pArea);
                    int pIndex = supermanager->getCourtManager()->getCourtsRepo()->size()-1;
                    system("clear");
                    cout << "[VolleyballPitch Succesfully Registered]" << endl << endl << supermanager->getCourtManager()->getCourtsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
                case 3: {
                    supermanager->getCourtManager()->registerBasketballCourt(pName, pCourtBasePrice, pCovered, pArea);
                    int pIndex = supermanager->getCourtManager()->getCourtsRepo()->size()-1;
                    system("clear");
                    cout << "[BasketballCourt Succesfully Registered]" << endl << endl << supermanager->getCourtManager()->getCourtsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
                case 4: {
                    supermanager->getCourtManager()->registerTennisCourt(pName, pCourtBasePrice, pGrassed);
                    int pIndex = supermanager->getCourtManager()->getCourtsRepo()->size()-1;
                    system("clear");
                    cout << "[TennisCourt Succesfully Registered]" << endl << endl << supermanager->getCourtManager()->getCourtsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
                case 5: {
                    supermanager->getCourtManager()->registerFootballPitch(pName, pCourtBasePrice, pCovered, pArea, pGrassed);
                    int pIndex = supermanager->getCourtManager()->getCourtsRepo()->size()-1;
                    system("clear");
                    cout << "[FootballPitch Succesfully Registered]" << endl << endl << supermanager->getCourtManager()->getCourtsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
            }
            break;
        }

// Add Equipment -------------------------------------------------------------------------------------------------------
        case 3: {

    // variables
            int equipmentTypeChoice;
            int ballTypeChoice;
            SegmentType pSegmentType;

    // couts
            system("clear");
            cout << "[New Equipment]" << endl;

        // type
            cout << endl << "Equipment type:" << endl
                 << "1 - Ball" << endl
                 << "2 - Rocket" << endl
                 << "> ";

            do {
                equipmentTypeChoice = getInt();
                if (equipmentTypeChoice < 1 || equipmentTypeChoice > 2)
                    cout << endl << "Unknown option. Please enter a valid option" << endl << "> ";
            } while (equipmentTypeChoice < 1 || equipmentTypeChoice > 2);

        // model
            cout << endl << "Model" << endl << "> ";
            std::string pModel = getString();

        // base price
            cout << endl << "Base price" << endl << "> ";
            int pEquipmentBasePrice = getInt();

        // ball type
            if(equipmentTypeChoice == 1) {
                cout << endl << "Ball type" << endl
                     << "1 - Football" << endl
                     << "2 - Basketball" << endl
                     << "3 - Volleyball" << endl
                     << "> ";

                do {
                    ballTypeChoice = getInt();
                    if (ballTypeChoice == 1) pSegmentType = Football;
                    else if (ballTypeChoice == 2) pSegmentType = Basketball;
                    else if (ballTypeChoice == 3) pSegmentType = Volleyball;

                    else
                        cout << endl << "Unknown option. Please enter a valid option" << endl
                             << "> ";
                } while(ballTypeChoice < 1 || ballTypeChoice > 3);
            }

    // register equipment
            switch(equipmentTypeChoice) {
                case 1: {
                    supermanager->getEquipmentManager()->registerBall(pModel, pEquipmentBasePrice, pSegmentType);

                    int pIndex = supermanager->getEquipmentManager()->getEquipmentsRepo()->size()-1;
                    system("clear");
                    cout << "[Ball Succesfully Registered]" << endl << endl << supermanager->getEquipmentManager()->getEquipmentsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
                case 2: {
                    supermanager->getEquipmentManager()->registerRocket(pModel, pEquipmentBasePrice);

                    int pIndex = supermanager->getEquipmentManager()->getEquipmentsRepo()->size()-1;
                    system("clear");
                    cout << "[Rocket Succesfully Registered]" << endl << endl << supermanager->getEquipmentManager()->getEquipmentsRepo()->get(pIndex)->getInfo() << endl << endl;
                    break;
                }
            }
            break;
        }

// Add Rent ------------------------------------------------------------------------------------------------------------
        case 4: {

    // variables
            int equipmentOption;
            bool optionClient = false;
            bool optionCourt = false;
            bool optionEquipment = false;
            ClientPtr pClient;
            CourtPtr pCourt;
            EquipmentPtr pEquipment;

    // couts
            system("clear");
            cout << "[New Rent]" << endl;

        // begin date
            cout << endl << "Begin date (YYYY-MM-DD HH:MM:SS)" << endl << "> ";
            pt::ptime pBeginDate = getDate();

        // client index
            system("clear");
            cout << supermanager->getClientManager()->getClientsRepo()->report() << endl;
            do {
                cout << "Client index" << endl << "> ";
                int pClientIndex = getInt()-1;

                if(pClientIndex < supermanager->getClientManager()->getClientsRepo()->size()) {
                    pClient = supermanager->getClientManager()->getClient(pClientIndex);

                    if (pClient->getCurrentRents().size() < pClient->getClientType()->getMaxCourts())
                        optionClient = true;
                    else {
                        system("clear");
                        cout << supermanager->getClientManager()->getClientsRepo()->report() << endl;
                        cout << "Error: This client can not rent more courts! Choose somebody else" << endl << endl;
                    }
                }
                else {
                    system("clear");
                    cout << supermanager->getClientManager()->getClientsRepo()->report() << endl;
                    cout << "Error: Unknown value! Please enter a valid index" << endl << endl;
                }
            } while(!optionClient);

        // court index
            system("clear");
            cout << supermanager->getCourtManager()->getCourtsRepo()->report() << endl;
            do {
                cout << "Court index" << endl << "> ";
                int pCourtIndex = getInt()-1;

                if(pCourtIndex < supermanager->getCourtManager()->getCourtsRepo()->size()) {
                    pCourt = supermanager->getCourtManager()->getCourt(pCourtIndex);

                    if (!pCourt->isRented())
                        optionCourt = true;
                    else {
                        system("clear");
                        cout << supermanager->getCourtManager()->getCourtsRepo()->report() << endl;
                        cout << "Error: This court is currently rented! Choose something else" << endl << endl;
                    }
                }
                else {
                    system("clear");
                    cout << supermanager->getCourtManager()->getCourtsRepo()->report() << endl;
                    cout << "Error: Unknown value! Please enter a valid index" << endl << endl;
                }
            } while(!optionCourt);

    // addRent / registerRent
            supermanager->getRentManager()->registerRent(pBeginDate, pClient, pCourt);
            int pRentID = supermanager->getRentManager()->getRentsRepo()->size();

        // equipment index
            system("clear");
            cout << "Do u want to rent some equipment?" << endl
                 << "1 - Yes" << endl
                 << "2 - No" << endl << "> ";
            equipmentOption = getInt();

            switch(equipmentOption) {
                case 1: {
                    int equipmentOption2;
                    do {
                        system("clear");
                        cout << supermanager->getEquipmentManager()->getEquipmentsRepo()->report() << endl;
                        optionEquipment = false;

                        do {
                            cout << "Equipment index" << endl << "> ";
                            int pEquipmentIndex = getInt()-1;

                            if(pEquipmentIndex < supermanager->getEquipmentManager()->getEquipmentsRepo()->size()) {
                                pEquipment = supermanager->getEquipmentManager()->getEquipment(pEquipmentIndex);

                                if(!pEquipment->isRented()) {
                                    optionEquipment = true;
                                    supermanager->getRentManager()->getRentsRepo()->get(pRentID)->appendEquipment(pEquipment);
                                }
                                else {
                                    system("clear");
                                    cout << supermanager->getEquipmentManager()->getEquipmentsRepo()->report() << endl;
                                    cout << "Error: This equipment is currently rented! Choose something else" << endl;
                                }
                            }
                            else {
                                system("clear");
                                cout << supermanager->getEquipmentManager()->getEquipmentsRepo()->report() << endl;
                                cout << "Error: Unknown value! Please enter a valid index" << endl << endl;
                            }
                        } while(!optionEquipment);

                        system("clear");
                        cout << "Do u want to rent more equipment?" << endl
                             << "1 - Yes" << endl
                             << "2 - No" << endl << "> ";
                        equipmentOption2 = getInt();
                    } while(equipmentOption2 == 1);
                    break;
                }

                case 2:
                    system("clear");
                    break;

                default:
                    system("clear");
                    break;
            }

            system("clear");
            cout << "[Rent Succesfully Registered]" << endl << endl << supermanager->getRentManager()->getRentsRepo()->get(pRentID)->getInfo() << endl << endl;
            break;
        }

// End Rent ------------------------------------------------------------------------------------------------------------
        case 5: {

    // variables
            int pRentID;
            bool optionRent = false;
            RentPtr pRent;

    // couts
            system("clear");

        // rent id
            cout << supermanager->getRentManager()->getRentsRepo()->report() << endl;

            do {
                cout << "Rent ID" << endl << "> ";
                pRentID = getInt();

                if(pRentID <= supermanager->getRentManager()->getRentsRepo()->size() && pRentID > 0) {
                    pRent = supermanager->getRentManager()->getRent(pRentID);

                    if (pRent->getEndTime() == pt::not_a_date_time)
                        optionRent = true;
                    else {
                        system("clear");
                        cout << supermanager->getRentManager()->getRentsRepo()->report() << endl;
                        cout << "Error: This rent is ended yet! Choose something else" << endl << endl;
                    }
                }
                else {
                    system("clear");
                    cout << supermanager->getRentManager()->getRentsRepo()->report() << endl;
                    cout << "Error: Unknown value! Please enter a valid index" << endl << endl;
                }
            } while(!optionRent);

        // end time
            system("clear");
            cout << "[End Rent]" << endl << endl;
            cout << "End date (YYYY-MM-DD HH:MM:SS)" << endl << "> ";
            pt::ptime pEndTime = getDate();

    // end rent
            supermanager->getRentManager()->getRent(pRentID)->endRent(pEndTime);
            system("clear");
            cout << "[Rent Succesfully Ended]" << endl << endl << supermanager->getRentManager()->getRentsRepo()->get(pRentID)->getInfo() << endl << endl;
            break;
        }

// Go Back -------------------------------------------------------------------------------------------------------------
        case 6:
            system("clear");
            actions(chooseAction());
            break;

        default:
            system("clear");
            break;
    }
}


// get =================================================================================================================
std::string getString() {
    std::string temp;
    cin >> temp;
    return temp;
}

// getInt --------------------------------------------------
int getInt() {
    int temp;

    while(true) {
        if(cin >> temp) {
            if (temp >= 0)
                return temp;

            cout << endl << "Error: Value cannot be less than 0" << endl
                 << "> ";
        }

        else {
            cout << endl << "Error: Invalid input. Please enter a number" << endl
                 << "> ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// getDate--------------------------------------------------
pt::ptime getDate() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        std::string temp;
        std::getline(std::cin, temp);

        try {
            pt::ptime date = pt::time_from_string(temp);
            return date;
        } catch (const std::exception &e) {
            std::cout << endl << "Error: Please enter a valid date" << endl << "> ";
        }
    }
}