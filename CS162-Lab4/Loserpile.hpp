#include "Creature.hpp"

#ifndef LOSERPILE_HPP
#define LOSERPILE_HPP

struct Loser {
     Loser  *previousLoser;
     Creature *loser;
};

class Loserpile {
private:
     Loser  *currentLoser;
public:
     Loserpile();
     Loser  *getCurrentLoser();
     void setCurrentLoser(Loser *loser);
     void add(Creature *loser);
     Creature *remove();
};

#endif