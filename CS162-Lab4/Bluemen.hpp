#include <string>
#include "Creature.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

using std::string;

class Bluemen : public Creature {
public:
     Bluemen(string name, string cName);
     int attack();
     int defend();
     bool charm();
     void updateStrengthPts(int defenseRoll, int opponentAttackRoll);
     void checkDefenseLevel();
     void showTheBlueMen(int strengthPts);
};

#endif