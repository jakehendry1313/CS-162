#include <string>
#include "Creature.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

using std::string;

class Medusa : public Creature {
public:
     Medusa(string name, string cName);
     int attack();
     int defend();
     bool charm();
     void glare();
     void updateStrengthPts(int defenseRoll, int opponentAttackRoll);
};

#endif