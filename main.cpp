#include <iostream>
#include <vector>
#include "Players.h"

using namespace std;

int main() {
    string TeamName;
    string BuyPlayer;
    string keyword;
    int balance = 1000;
    vector<Players> TeamPlayers;
    vector<Players> AllPlayers;
    vector<Players> FoundNames;

    Players Nuomaras("Nuomaras", 200, "LW");
    Players Mesis("Mesis", 500, "RW");
    Players Mbappe("Mbappe", 1200, "ST");

    AllPlayers.emplace_back(Nuomaras);
    AllPlayers.emplace_back(Mesis);
    AllPlayers.emplace_back(Mbappe);


    int input;
    bool choice = true;
    while (choice) {
        cout << "-----------------------" << endl;
        cout << "---------MENU----------" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Team menu" << endl;
        cout << "2. Buy a player" << endl;
        cout << "3. Sell a player" << endl;
        cout << "0. The end" << endl;
        cout << "Please enter your choice: ";
        cin >> input;

        switch (input) {
            case 1:
                cout << "-----------------------" << endl;
                cout << "---------TEAM MENU-----" << endl;
                cout << "-----------------------" << endl;
                cout << "1. Change team name" << endl;
                cout << "2. Team name" << endl;
                cout << "3. List current team" << endl;
                cout << "4. Check balance" << endl;
                cout << "0. Go back" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                        cout << "Please enter your team name: " ;
                        cin >> TeamName;
                        break;
                    case 2:
                        cout << "Your team name is " << TeamName << endl;
                        break;
                    case 3:
                        if (TeamPlayers.empty()) {
                            cout << "Currently you do not own any players, please go to buy menu" << endl;
                        } else {
                            cout << "Your current team is listed below: " << endl;
                            for (auto & TeamPlayer : TeamPlayers) {
                                if (!TeamPlayers.empty()) {
                                    cout << "Name: " << TeamPlayer.name << " Price: " << TeamPlayer.price << " Position: " << TeamPlayer.position << endl;
                                    }
                                }
                            }
                        break;
                    case 4:
                        cout << "Your balance: " << balance << endl;
                    case 0:
                        break;
                    default:
                        cout << "Not a valid choice, choose again" << endl;
                        break;
                }
                break;
            case 2:
                cout << "-----------------------" << endl;
                cout << "------BUY PLAYER-------" << endl;
                cout << "-----------------------" << endl;
                cout << "1. Print all available players" << endl;
                cout << "2. Search player" << endl;
                cout << "0. Go back" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                        if (AllPlayers.empty()) {
                            cout << "There is no available players to buy" << endl;
                        } else {
                            cout << "All available players are listed below: " << endl;
                            for (auto & AllPlayer : AllPlayers) {
                                cout << "Name: " << AllPlayer.name << " Price: " << AllPlayer.price << " Position: " << AllPlayer.position << endl;
                            }
                            cout << "Enter name of player you want to buy" << endl;
                            cin >> BuyPlayer;
                            for (int i = 0; i < AllPlayers.size(); ++i) {
                                if (BuyPlayer == AllPlayers[i].name and (balance - AllPlayers[i].price) >= 0) {
                                    TeamPlayers.emplace_back(AllPlayers[i]);
                                    cout << "Congratulations, you have purchased " << AllPlayers[i].name << endl;
                                    balance -= AllPlayers[i].price;
                                    AllPlayers.erase(AllPlayers.begin()+i);
                                } else if (BuyPlayer == AllPlayers[i].name and (balance - AllPlayers[i].price) < 0) {
                                    cout << "You do not have enough money, please sell players or choose cheaper one" << endl;
                                } else if (i == AllPlayers.size()){
                                    cout << "There is not such player, please choose again" << endl;
                                }
                            }
                        }
                        break;
                    case 2:
                        cout << "-----------------------" << endl;
                        cout << "-----SEARCH PLAYER-----" << endl;
                        cout << "-----------------------" << endl;
                        cout << "1. Search by name" << endl;
                        cout << "2. Search by position" << endl;
                        cout << "0. Go back" << endl;
                        cin >> input;
                        switch (input) {
                            case 1:
                                cout << "Search by name" << endl;
                                cout << "Please enter name:" << endl;
                                cin >> keyword;
                                for (int i = 0; i < AllPlayers.size(); ++i) {
                                    if (AllPlayers[i].name == keyword) {
                                        FoundNames.emplace_back(AllPlayers[i]);
                                    }
                                }
                                if (!FoundNames.empty()) {
                                    for (int i = 0; i < FoundNames.size(); ++i) {
                                        cout << "Name: " << FoundNames[i].name << " " << "Price: " << FoundNames[i].price << endl;
                                    }
                                } else {
                                    cout << "There is no such player" << endl;
                                }
                                FoundNames.clear();
                                break;
                            case 2:
                                cout << "Search by position" << endl;
                                cout << "Please enter position:" << endl;
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Not a valid choice, choose again" << endl;
                                break;
                        }
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Not a valid choice, choose again" << endl;
                        break;
                }
                break;
            case 3:
                cout << "-----------------------" << endl;
                cout << "-----SELL PLAYER-----" << endl;
                cout << "-----------------------" << endl;
                break;
            case 0:
                cout << "Your team name is: " << TeamName << endl;
                cout << "Your team is listed below: " << endl;
                for (int i = 0; i < TeamPlayers.size(); ++i) {
                    cout << "Name: " << TeamPlayers[i].name << " Price: " << TeamPlayers[i].price << " Position: " << TeamPlayers[i].position << endl;
                }
                cout << "Your balance: " << balance << endl;
                cout << "End of the Program" << endl;
                choice = false;
                break;
            default:
                cout << "Not a valid choice, choose again" << endl;
                break;
        }
    }

    return 0;
}

