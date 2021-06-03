//
// Created by mykol on 2021-06-02.
//

#include "Match.h"

Match::Match(string x, string y, string z) {
    stadium = x;
    place = y;
    opponent = z;
}

const string &Match::getStadium() const {
    return stadium;
}

const string &Match::getPlace() const {
    return place;
}

const string &Match::getOpponent() const {
    return opponent;
}

