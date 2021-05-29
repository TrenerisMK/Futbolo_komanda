//
// Created by mykol on 2021-05-09.
//

#ifndef FUTBOLO_KOMANDA_PLAYERS_H
#define FUTBOLO_KOMANDA_PLAYERS_H
#include <string>

using namespace std;

class Players {
public:
    string name;
    int price;
    string position;
    Players(string x, int y, string z);
};

#endif //FUTBOLO_KOMANDA_PLAYERS_H
