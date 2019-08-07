#include <string>
#include "Creature.hpp"
#include "Fighterlineup.hpp"
#include "Loserpile.hpp"

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

using std::string;

string getCreatureString(CREATURES creatureType);
Creature *initializeCreature(CREATURES creatureType, string creatureName, string creatureCName);
void playRound(Fighterlineup *team1, Fighterlineup *team2, Loserpile *losers);
bool attackAndDefend(Creature *attackingPlayer, Creature *defendingPlayer);
bool checkWinnerAndLoser(Fighterlineup *team1, Fighterlineup *team2, Loserpile *losers);
void healPlayers(Fighterlineup *team1, Fighterlineup *team2);
void printTitle(string name1, string name2);
void showWinners(Fighterlineup *team1, Fighterlineup *team2);
void showLosers(Loserpile *losers);
void closeGame();

#endif