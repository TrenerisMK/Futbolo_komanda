#include <iostream>
#include <vector>
#include "Players.h"
#include "Match.h"
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int DvejetainePaieska(vector<Players> &sarasas, int kaire, int desine, string keyword) {
    sort( sarasas.begin( ), sarasas.end( ), [ ]( const Players& lhs, const Players& rhs )
    {
        return lhs.name < rhs.name;
    });

    while (kaire <= desine) {
        int vidurioElementas = kaire + (desine - kaire) / 2;

        if (sarasas[vidurioElementas].name == keyword) {
            cout << "Name: " << sarasas[vidurioElementas].name << " " << "Position: " << sarasas[vidurioElementas].position << " " << "Price: " << sarasas[vidurioElementas].price << endl;
            return vidurioElementas;
        }
        if (sarasas[vidurioElementas].name < keyword) {
            kaire = vidurioElementas + 1;
        } else {
            desine = vidurioElementas - 1;
        }
    }
    return -1;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printTeam(vector<Players> &sarasas, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << "Name: " << sarasas[i].name << " " << "Position: " << sarasas[i].position << " " << "Price: " << sarasas[i].price << endl;
}

void bubbleSort(vector<Players> &sarasas, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (sarasas[j].price > sarasas[j+1].price)
                swap(&sarasas[j].price, &sarasas[j+1].price);
}

void insertionSort2(vector<Players> &sarasas, int n)
{
    int i, j;
    string key;
    for (i = 1; i < n; i++)
    {
        key = sarasas[i].position;
        j = i - 1;

        while (j >= 0 && sarasas[j].position > key)
        {
            sarasas[j + 1].position = sarasas[j].position;
            j = j - 1;
        }
        sarasas[j + 1].position = key;
    }
}


void insertionSort(vector<Players> &sarasas, int n)
{
    int i, j;
    string key;
    for (i = 1; i < n; i++)
    {
        key = sarasas[i].name;
        j = i - 1;

        while (j >= 0 && sarasas[j].name > key)
        {
            sarasas[j + 1].name = sarasas[j].name;
            j = j - 1;
        }
        sarasas[j + 1].name = key;
    }
}

int main() {
    string TeamName;
    string BuyPlayer;
    string keyword;

    int balance = 10000000;
    int priceword = 0;

    vector<Players> TeamPlayers;
    vector<Players> AllPlayers;
    vector<Players> SearchEngine;
    vector<Match> Matches;

    queue<Match> ScheduledMatches;
    queue<Match> ScheduledMatches2;

    stack<int> TeamCount;

    Match match1("Anfield", "Liverpool", "Liverpool F.C.");
    Match match2("Old Trafford", "Manchester", "Manchester United");
    Match match3("Stamford Bridge", "London", "Chelsea");
    Match match4("Wanda Metropolitan", "Madrid", "Athletic Madrid");
    Match match5("Allianz", "Turin", "Juventus");


    Matches.emplace_back(match1);
    Matches.emplace_back(match2);
    Matches.emplace_back(match3);
    Matches.emplace_back(match4);
    Matches.emplace_back(match5);

    Players Nuomaras("Neymar", 1320000, "LW");
    Players Mesis("Messi", 1005000, "RW");
    Players Mbappe("Mbappe", 820000, "ST");
    Players Lewandowski("Lewandowski", 12450000, "ST");
    Players Alcantara("Alcantara", 525000, "CM");
    Players Muller("Muller", 770000, "CAM");
    Players Rashford("Rashford", 865000, "ST");
    Players Garcia("Garcia", 115000, "CB");
    Players Kante("Kante", 780000, "CMD");
    Players Aguero("Aguero", 455000, "ST");
    Players Haaland("Haaland", 1225000, "ST");
    Players Mount("Mount", 490000, "CAM");
    Players Foden("Foden", 795000, "CAM");
    Players Emerson("Emerson", 270000, "RB");
    Players Pedri("Pedri", 240000, "CM");
    Players Camavinga("Camavinga", 290000, "CM");
    Players Fati("Fati", 170000, "LW");
    Players Konate("Konate", 295000, "CB");
    Players James("James", 305000, "RB");
    Players Ronaldo("Ronaldo", 630000, "ST");
    Players Mendy("Mendy", 180000, "GK");
    Players Davies("Davies", 530000, "LB");
    Players Traore("Traore", 190000, "RW");
    Players Greenwood("Greenwood", 295000, "RM");
    Players Kounde("Kounde", 445000, "CB");
    Players Junior("Junior", 205000, "LW");
    Players Hakimi("Hakimi", 560000, "RM");
    Players Alaba("Alaba", 315000, "CB");
    Players Chilwell("Chilwell", 405000, "LB");
    Players Chiellini("Chiellini", 180000, "CB");

    AllPlayers.emplace_back(Rashford);
    AllPlayers.emplace_back(Garcia);
    AllPlayers.emplace_back(Mbappe);
    AllPlayers.emplace_back(Lewandowski);
    AllPlayers.emplace_back(Alcantara);
    AllPlayers.emplace_back(Kante);
    AllPlayers.emplace_back(Aguero);
    AllPlayers.emplace_back(Haaland);
    AllPlayers.emplace_back(Mount);
    AllPlayers.emplace_back(Foden);
    AllPlayers.emplace_back(Emerson);
    AllPlayers.emplace_back(Pedri);
    AllPlayers.emplace_back(Camavinga);
    AllPlayers.emplace_back(Fati);
    AllPlayers.emplace_back(Konate);
    AllPlayers.emplace_back(James);
    AllPlayers.emplace_back(Ronaldo);
    AllPlayers.emplace_back(Mendy);
    AllPlayers.emplace_back(Davies);
    AllPlayers.emplace_back(Traore);
    AllPlayers.emplace_back(Greenwood);
    AllPlayers.emplace_back(Kounde);
    AllPlayers.emplace_back(Hakimi);
    AllPlayers.emplace_back(Alaba);
    AllPlayers.emplace_back(Chilwell);
    AllPlayers.emplace_back(Chiellini);

    int input;
    bool choice = true;

    cout << "Football team building game" << endl;
    cout << "You have to build your own team 11 players within money limit of 10.000.000" << endl;

    while (choice) {
        cout << "-----------------------" << endl;
        cout << "---------MENU----------" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Team menu" << endl;
        cout << "2. Buy a player" << endl;
        cout << "3. Sell a player" << endl;
        cout << "4. Match menu" << endl;
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
                cout << "5. Sort current team by price" << endl;
                cout << "6. Sort current team by name" << endl;
                cout << "7. Sort current team by position" << endl;
                cout << "0. Go back" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                        cout << "Please enter your team name: ";
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
                            for (auto &TeamPlayer : TeamPlayers) {
                                if (!TeamPlayers.empty()) {
                                    cout << "Name: " << TeamPlayer.name << " Price: " << TeamPlayer.price
                                         << " Position: " << TeamPlayer.position << endl;
                                }
                            }
                            cout << "IN TOTAL YOU HAVE PLAYERS: " << TeamPlayers.size() << endl;
                        }
                        break;
                    case 4:
                        cout << "Your balance: " << balance << endl;
                        break;
                    case 5:
                        if (!TeamPlayers.empty()) {
                            int n;
                            n = TeamPlayers.size();
                            cout << "Your team has been successfully sorted by price" << endl;
                            bubbleSort(TeamPlayers, n);
                            printTeam(TeamPlayers, n);
                        } else {
                            cout << "Currently you do not own any players" << endl;
                            cout << "Please go to buy menu" << endl;
                        }
                        break;
                    case 6:
                        if (!TeamPlayers.empty()) {
                            cout << "Your team has been successfully sorted by name" << endl;
                            int n;
                            n = TeamPlayers.size();
                            insertionSort(TeamPlayers, n);
                            printTeam(TeamPlayers, n);
                        } else {
                            cout << "Currently you do not own any players" << endl;
                            cout << "Please go to buy menu" << endl;
                        }
                        break;
                    case 7:
                        if (!TeamPlayers.empty()) {
                            cout << "Your team has been successfully sorted by position" << endl;
                            int n;
                            n = TeamPlayers.size();
                            insertionSort2(TeamPlayers, n);
                            printTeam(TeamPlayers, n);
                        } else {
                            cout << "Currently you do not own any players" << endl;
                            cout << "Please go to buy menu" << endl;
                        }
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
                            for (auto &AllPlayer : AllPlayers) {
                                cout << "Name: " << AllPlayer.name << " Price: " << AllPlayer.price << " Position: "
                                     << AllPlayer.position << endl;
                            }
                            cout << "-------------------------------" << endl;
                            if (TeamCount.size() < 11) {
                                cout << "Enter name of player you want to buy" << endl;
                                cin >> BuyPlayer;
                                for (int i = 0; i < AllPlayers.size(); ++i) {
                                    if (BuyPlayer == AllPlayers[i].name and (balance - AllPlayers[i].price) >= 0) {
                                        TeamPlayers.emplace_back(AllPlayers[i]);
                                        cout << "Congratulations, you have purchased " << AllPlayers[i].name << endl;
                                        balance -= AllPlayers[i].price;
                                        AllPlayers.erase(AllPlayers.begin() + i);
                                        TeamCount.push(1);
                                    } else if (BuyPlayer == AllPlayers[i].name and (balance - AllPlayers[i].price) < 0) {
                                        cout << "You do not have enough money, please sell players or choose cheaper one"
                                             << endl;
                                    } else if (BuyPlayer != AllPlayers[i].name and i == AllPlayers.size()) {
                                        cout << "There is not such player, please choose again" << endl;
                                    }
                                }
                            } else {
                                cout << "You have reached the limit of how many players you can own" << endl;
                                cout << "If you wish to buy this player, please sell of your player or players" << endl;
                            }
                        }
                        break;
                    case 2:
                        cout << "-----------------------" << endl;
                        cout << "-----SEARCH PLAYER-----" << endl;
                        cout << "-----------------------" << endl;
                        cout << "1. Search by name" << endl;
                        cout << "2. Search by position" << endl;
                        cout << "3. Search by price" << endl;
                        cout << "0. Go back" << endl;
                        cin >> input;
                        switch (input) {
                            case 1:
                                cout << "Search by name" << endl;
                                cout << "Please enter name:" << endl;
                                cin >> keyword;
                                int index;
                                index = DvejetainePaieska(AllPlayers, 0, (int) AllPlayers.size() - 1, keyword);
                                if (index != -1) {
                                    cout << "There is such player " << endl;
                                    cout << DvejetainePaieska(AllPlayers, 0, (int)AllPlayers.size()-1, keyword) << endl;
                                } else {
                                    cout << "There is no such player" << endl;
                                }
                                break;
                            case 2:
                                cout << "Search by position" << endl;
                                cout << "Please enter position:" << endl;
                                cin >> keyword;
                                for (int i = 0; i < AllPlayers.size(); ++i) {
                                    if (AllPlayers[i].position == keyword) {
                                        SearchEngine.emplace_back(AllPlayers[i]);
                                    }
                                }
                                if (!SearchEngine.empty()) {
                                    cout << "Found players by position " << keyword << ":" << endl;
                                    for (int i = 0; i < SearchEngine.size(); ++i) {
                                        cout << "Name: " << SearchEngine[i].name << " " << "Position: "
                                             << SearchEngine[i].position << " " << "Price: " << SearchEngine[i].price
                                             << endl;
                                    }
                                } else {
                                    cout << "There is no such position" << endl;
                                }
                                SearchEngine.clear();
                                break;
                            case 3:
                                cout << "Search by price" << endl;
                                cout << "Please enter price:" << endl;
                                cin >> priceword;
                                for (int i = 0; i < AllPlayers.size(); ++i) {
                                    if (AllPlayers[i].price == priceword) {
                                        SearchEngine.emplace_back(AllPlayers[i]);
                                    }
                                }
                                if (!SearchEngine.empty()) {
                                    cout << "Players for price " << priceword << endl;
                                    for (int i = 0; i < SearchEngine.size(); ++i) {
                                        cout << "Name: " << SearchEngine[i].name << " " << "Position: " << SearchEngine[i].position << " " << "Price: " << SearchEngine[i].price << endl;
                                    }
                                } else {
                                    cout << "There are no players for such price" << endl;
                                }
                                SearchEngine.clear();
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Not a valid choice, choose again" << endl;
                                 break;
                        }
                }
                break;
            case 3:
                cout << "-----------------------" << endl;
                cout << "-----SELL PLAYER-------" << endl;
                cout << "-----------------------" << endl;
                if (TeamPlayers.empty()) {
                    cout << "Currently you do not own any players, please go to buy menu" << endl;
                } else {
                    cout << "Your current team is listed below: " << endl;
                    for (auto &TeamPlayer : TeamPlayers) {
                        cout << "Name: " << TeamPlayer.name << " Price: " << TeamPlayer.price << " Position: "
                             << TeamPlayer.position << endl;
                    }
                    cout << "Please enter name of the player you want to sell" << endl;
                    cin >> BuyPlayer;
                    for (int i = 0; i < TeamPlayers.size(); ++i) {
                        if (BuyPlayer == TeamPlayers[i].name) {
                            AllPlayers.emplace_back(TeamPlayers[i]);
                            cout << "Congratulations, you have sold " << TeamPlayers[i].name << endl;
                            balance += TeamPlayers[i].price;
                            TeamPlayers.erase(TeamPlayers.begin() + i);
                            TeamCount.pop();
                        } else if (BuyPlayer != TeamPlayers[i].name and i == (TeamPlayers.size()) -1){
                            cout << "There is not such player, please choose again" << endl;
                            }
                        }
                    }
                break;
            case 4:
                cout << "-----------------------" << endl;
                cout << "-----PLAY A MATCH------" << endl;
                cout << "-----------------------" << endl;
                cout << "1. Schedule matches" << endl;
                cout << "2. Check scheduled matches" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                        if (TeamPlayers.size() < 11) {
                            for (int i = 0; i < Matches.size(); ++i) {
                                cout << "Stadium name: " << Matches[i].getStadium() << " " << "City: " << Matches[i].getPlace() << " " << "Opponent: " << Matches[i].getOpponent() << endl;
                            }
                            cout << "Choose your opponent" << endl;
                            string opponent;
                            cin >> opponent;
                            for (int i = 0; i < Matches.size(); ++i) {
                                if (opponent == Matches[i].getOpponent()) {
                                    ScheduledMatches.emplace(Matches[i]);
                                    cout << "Congratulations you have successfully added " << Matches[i].getOpponent() << " " << "as your opponent" << endl;
                                    Matches.erase(Matches.begin() + i);
                                } else if (opponent != Matches[i].getOpponent() and i == Matches.size()) {
                                    cout << "There is no such opponent, please choose again" << endl;
                                }
                            }
                        } else {
                            cout << "Currently you do not own 11 players, please go to buy menu" << endl;
                        }
                        break;
                    case 2:
                        if (!ScheduledMatches.empty()) {

                            cout << "Scheduled matches: " << endl;
                            while (!ScheduledMatches.empty()) {
                                cout << ScheduledMatches.front().getStadium() << " " << ScheduledMatches.front().getPlace() << " " << ScheduledMatches.front().getOpponent() << endl;
                                ScheduledMatches2.push(ScheduledMatches);
                                ScheduledMatches.pop();
                            }
                        } else {
                            cout << "You have not schedule any matches" << endl;
                        }
                        break;
                    case 0:
                        break;
                }
                break;
            case 0:
                cout << "Your team name is: " << TeamName << endl;
                cout << "Your team is listed below: " << endl;
                for (int i = 0; i < TeamPlayers.size(); ++i) {
                    cout << "Name: " << TeamPlayers[i].name << " Price: " << TeamPlayers[i].position << " Position: " << TeamPlayers[i].price << endl;
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
}