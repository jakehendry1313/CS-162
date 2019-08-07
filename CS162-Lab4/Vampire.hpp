#include <string>
#include "Creature.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

using std::string;

class Vampire : public Creature {
public:
     Vampire(string name, string cName);
     int attack();
     int defend();
     bool charm();
     void vampWink();
     void updateStrengthPts(int defenseRoll, int opponentAttackRoll);
};

#endif