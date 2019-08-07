#include <string>
#include "Creature.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

using std::string;

class Harrypotter : public Creature {
private:
     bool hasRevived;

public:
     Harrypotter(string name, string cName);
     void setHasRevived(bool hasRevived);
     bool getHasRevived();
     int attack();
     int defend();
     bool charm();
     void updateStrengthPts(int defenseRoll, int opponentAttackRoll);
};

#endif