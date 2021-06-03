//
// Created by mykol on 2021-06-02.
//

#ifndef FUTBOLO_KOMANDA_MATCH_H
#define FUTBOLO_KOMANDA_MATCH_H

#include <string>

using namespace std;

class Match {
private:
    string stadium;
    string place;
    string opponent;

public:
    const string &getStadium() const;
    const string &getPlace() const;
    const string &getOpponent() const;
    Match(string x, string y, string z);
};


#endif //FUTBOLO_KOMANDA_MATCH_H
