#include <string>
#include "Creature.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

using std::string;

class Barbarian : public Creature {
public:
     Barbarian(string name, string cName);
     int attack();
     int defend();
     bool charm();
     void updateStrengthPts(int defenseRoll, int opponentAttackRoll);
};

#endif