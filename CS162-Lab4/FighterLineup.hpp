#include <string>
#include "Creature.hpp"

#ifndef FIGHTERLINEUP_HPP
#define FIGHTERLINEUP_HPP

using std::string;

struct Fighter {
     Fighter *nextFighter;
     Fighter *previousFighter;
     Creature *fighter;
};

class Fighterlineup {
private:
     string teamName;
     Fighter *currentFighter;
public:
     Fighterlineup(string teamName);
     string getTeamName();
     Fighter *getCurrentFighter();
     void setTeamName(string teamName);
     void setCurrentFighter(Fighter *fighter);
     void add(Creature *fighter);
     Creature *remove();
};

#endif