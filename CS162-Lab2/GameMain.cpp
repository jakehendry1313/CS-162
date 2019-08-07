/**************************************************************************
** Program name: Project 3  - BlueMen.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is main function that will make the program start and
**               show the results of all possible results based on the user's
**               choice in the menu.
****************************************************************************/
#include "menu.hpp"
#include "Characters.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>


void randomCombat();
void playRound(Characters* pOffense, Characters* pDefense, int round, bool player);
void printRound(Characters* pOffense, Characters* pDefense);

int main()
{
     std::srand(static_cast<unsigned int>(time(0)));

     Characters* O1 = nullptr;
     Characters* O2 = nullptr;

     userMenu mainMenu;
     int mainChoice = 0;
     userMenu combatMenu;
     int combatChoice = 0;

     mainMenu.add_choice("Let's Play Fantasty Combat Battle Simulator");
     mainMenu.add_choice("Play All Possible Battles!");
     mainMenu.add_choice("Quit the Game");

     combatMenu.add_choice("Vampire\t\t1d12\t\t1d6(Charm)\t1\t18");
     combatMenu.add_choice("Barbarian\t\t2d6\t\t2d6\t\t0\t12");
     combatMenu.add_choice("Blue Men\t\t2d10\t\t3d6\t\t3\t12(Mob)");
     combatMenu.add_choice("Medusa\t\t2d6(Glare)\t1d6\t\t3\t8");
     combatMenu.add_choice("Harry Potter\t2d6\t\t2d6\t\t0\t10/20(Hogwarts)");

     std::cout << "Welcome to the Fantasy Combat Simulator\n";
     mainChoice = mainMenu.makeChoice();

     while (mainChoice != 3) 
     {
          if (mainChoice == 1) 
          {
               delete O1;
               O1 = nullptr;
               delete O2;
               O2 = nullptr;

               std::string p1Round;
               std::string p2Round;

               std::cout << "Please select Player 1's Character Type\n";
               std::cout << "Character Type\t\tAttack\t\tDefense\t\tArmor\tStrength Points\n";
               combatChoice = combatMenu.makeChoice();

               if (combatChoice == 1)
                    O1 = new Vampire();
               else if (combatChoice == 2)
                    O1 = new Barbarian();
               else if (combatChoice == 3)
                    O1 = new BlueMen();
               else if (combatChoice == 4)
                    O1 = new Medusa();
               else if (combatChoice == 5)
                    O1 = new HarryPotter();

               std::cout << "\nPlayer 1 is ready to fight with " << O1->get_name() << ". Good Luck!\n\n";

               std::cout << "Please select Player 2's Character Type\n";
               std::cout << "Character Type\t\tAttack\t\tDefense\t\tArmor\tStrength Points\n";
               combatChoice = combatMenu.makeChoice();

               if (combatChoice == 1)
                    O2 = new Vampire();
               else if (combatChoice == 2)
                    O2 = new Barbarian();
               else if (combatChoice == 3)
                    O2 = new BlueMen();
               else if (combatChoice == 4)
                    O2 = new Medusa();
               else if (combatChoice == 5)
                    O2 = new HarryPotter();

               std::cout << "\nPlayer 2 is ready to fight with " << O2->get_name() << ". Good Luck!\n\n";

               std::cout << "Let's start the Battle Simulator!\n";

               printRound(O1, O2);

               O1->recover_strength();
               O2->recover_strength();
          }

          else if (mainChoice == 2) 
          {
               randomCombat();
          }

          mainChoice = mainMenu.makeChoice();
     }

     delete O1;
     delete O2;
}

/*********************************************************************
* This function will list all of the possible outcomes for every
* character.
*********************************************************************/
void randomCombat()
{
     int numCreatures = 5;
     int matches = 0;
     std::string p1Round;
     std::string p2Round;

     std::vector<Characters*> set1;
     std::vector<Characters*> set2;

     set1.push_back(new Vampire());
     set1.push_back(new Barbarian());
     set1.push_back(new BlueMen());
     set1.push_back(new Medusa());
     set1.push_back(new HarryPotter());

     set2.push_back(new Vampire());
     set2.push_back(new Barbarian());
     set2.push_back(new BlueMen());
     set2.push_back(new Medusa());
     set2.push_back(new HarryPotter());

     for (int i = 0; i < numCreatures; i++) {
          for (int j = 0; j < numCreatures; j++) {

               Characters* O1 = set1[j];
               Characters* O2 = set2[i];

               std::cout << "Let the Battles Begin!\n";

               printRound(O1, O2);

               O1->recover_strength();
               O2->recover_strength();
               matches++;
          }
     }

     std::cout << "There were " << matches << " mathces played during the tournament.\n";

     for (size_t i = 0; i < set1.size(); i++) {
          delete set1[i];
     }
     for (size_t j = 0; j < set2.size(); j++) {
          delete set2[j];
     }
}

/*********************************************************************
* This function will prompt the program to run through
*********************************************************************/
void playRound(Characters * pOffense, Characters * pDefense, int round, bool pStart)
{
     std::string p1Round;
     std::string p2Round;
     std::string pOff;
     std::string pDef;

     while (!pOffense->defeated() && !pDefense->defeated()) 
     {
          int damage = 0;
          int defenseRoll;
          int offenseRoll = pOffense->attack_roll();
          if (pOffense->get_special() == "GLARE") {
               offenseRoll = 100;
          }

          defenseRoll = pDefense->defense_roll(offenseRoll);

          if (!pStart) 
          {
               pOff = "O1: ";
               pDef = "O2: ";
          }

          else 
          {
               pOff = "O2: ";
               pDef = "O1: ";
          }

          if (round % 2 == 1) {
               p1Round = "Attack:  ";

               if (pOffense->get_special() != "") 
               {
                    p1Round = p1Round + "(" + pOffense->get_special() + ")";
               }

               else 
               {
                    p1Round = p1Round + std::to_string(offenseRoll);
               }

               p2Round = "|  Defense: ";

               if (pDefense->get_special() != "") 
               {
                    p2Round = p2Round + "(" + pDefense->get_special() + ")";
               }

               else 
               {
                    p2Round = p2Round + std::to_string(pDefense->get_defPoints()) + " + armor: " + std::to_string(pDefense->get_armor());
               }

               std::cout << std::setw(10) << round << std::setw(33) << p1Round << std::setw(33) << p2Round;
               std::cout << std::setw(5) << pDef + "-" << std::setw(5) << defenseRoll;
               std::cout << std::setw(5) << pDef << std::setw(5) << pDefense->get_strength() << std::endl;
          }

          if (round % 2 == 0) {
               p1Round = "Defense:  ";

               if (pDefense->get_special() != "") 
               {
                    p1Round = p1Round + "(" + pDefense->get_special() + ")";
               }

               else 
               {
                    p1Round = p1Round + std::to_string(pDefense->get_defPoints()) + " + armor: " + std::to_string(pDefense->get_armor());
               }

               p2Round = "|  Attack: ";
               if (pOffense->get_special() != "") {
                    p2Round = p2Round + "(" + pOffense->get_special() + ")";
               }

               else {
                    p2Round = p2Round + std::to_string(offenseRoll);
               }

               std::cout << std::setw(10) << round << std::setw(33) << p1Round << std::setw(33) << p2Round;
               std::cout << std::setw(5) << pDef + "-" << std::setw(5) << defenseRoll;
               std::cout << std::setw(5) << pDef << std::setw(5) << pDefense->get_strength() << std::endl << std::endl;
          }

          round++;

          if (!pDefense->defeated()) {
               pStart = !pStart;
               playRound(pDefense, pOffense, round, pStart);
          }

     }
}

/*********************************************************************
* this function will print all of the possible battles for the program
*********************************************************************/
void printRound(Characters * O1, Characters * O2)
{
     std::string p1Round;
     std::string p2Round;

     int round = 1;
     bool pStart;


     pStart = (rand() % 2);

     p1Round = O1->get_name() + " (STR: " + std::to_string(O1->get_strength()) + ")";
     p2Round = O2->get_name() + " (STR: " + std::to_string(O2->get_strength()) + ")";

     if (!pStart) {
          std::cout << "Player 1 (O1) Will Start the Combat Game\n";
          std::cout << std::string(95, '-') << std::endl;

          std::cout << std::left << std::setw(10) << "Roll #";
          std::cout << std::setw(5) << "O1: " << std::setw(28) << p1Round;
          std::cout << std::setw(8) << "|  O2: " << std::setw(25) << p2Round;
          std::cout << std::setw(10) << "Damage" << std::setw(10) << "Strength" << std::endl;

          playRound(O1, O2, round, pStart);

          std::cout << std::string(95, '-') << std::endl;
          std::cout << std::setw(10) << "" << std::setw(20) << "O1 Final Strength Pts: " << std::setw(10) << O1->get_strength();
          std::cout << std::setw(20) << "|  O2 Final Strength Pts: " << std::setw(10) << O2->get_strength() << std::endl << std::endl;
     }

     else if (pStart) 
     {
          std::cout << "Player 2 (O2) Will Start the Combat Game\n";
          std::cout << std::string(95, '-') << std::endl;

          std::cout << std::left << std::setw(10) << "Roll #";
          std::cout << std::setw(5) << "O2: " << std::setw(28) << p2Round;
          std::cout << std::setw(8) << "|  O1: " << std::setw(25) << p1Round;
          std::cout << std::setw(10) << "Damage" << std::setw(10) << "Strength" << std::endl;

          playRound(O2, O1, round, pStart);

          std::cout << std::string(95, '-') << std::endl;
          std::cout << std::setw(10) << "" << std::setw(20) << "O2 Final Strength Pts: " << std::setw(10) << O2->get_strength();
          std::cout << std::setw(20) << "|  O1 Final Strength Pts: " << std::setw(10) << O1->get_strength() << std::endl << std::endl;
     }

     std::cout << std::string(95, '=') << std::endl;
     if (O1->defeated()) {
          std::cout << "Player2's " << O2->get_name() << " is the winner!\n\n";
     }
     else if (O2->defeated()) {
          std::cout << "Player1's " << O1->get_name() << " is the winner!\n\n";
     }
}