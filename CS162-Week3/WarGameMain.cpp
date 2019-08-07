#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
class Die
{
protected:
     int numSides;
     string dieType;
public:

     Die(int n)
     {
          numSides = n;
          dieType = "Not Loaded"; //default is not loaded
     }

     //virtual function will be overloaded in derived class
     virtual int roll()
     {
          //returns a random number in the range 1 - numSides
          return rand() % numSides + 1;
     }

     string getDieType()
     {
          return dieType;
     }

     int getNumSides()
     {
          return numSides;
     }
};

class LoadedDie : public Die
{


public:

     LoadedDie(int n) : Die(n)
     {
          turn = 1;
          dieType = "Loaded";
     }

     /*Overriding the roll function to have a biased behaviour of returning the highest number for every alternate roll */
     int roll()
     {
          //every odd turn return the numSides, (biased) and in even turn number usual roll from Die class.
          int val = turn == 1 ? numSides : Die::roll();
          turn = (turn + 1) % 2;
          return val;
     }

private:
     int turn;
};

class Game
{
private:
     //store the dice for the players

     Die *d1, *d2;

     //array to hold the result of each round for the 2 players. max is 100 roundss
     int rounds[100][2];
     int numRounds;

public:
     Game()
     {
          d1 = d2 = NULL;
     }

     void input()
     {
          string response;
          int faces;

          srand(time(NULL));


          cout << "How many faces for the die of Player 1? ";
          cin >> faces;
          cout << "Use loaded die for Player 1 (yes/no) ? ";
          cin >> response;

          if (response.compare("yes") == 0)
               d1 = new LoadedDie(faces);
          else
               d1 = new Die(faces);


          cout << "How many faces for the die of Player 2? ";
          cin >> faces;
          cout << "Use loaded die for Player 2 (yes/no) ? ";
          cin >> response;

          if (response.compare("yes") == 0)
               d2 = new LoadedDie(faces);
          else
               d2 = new Die(faces);

          cout << "How many rounds in the game?";
          cin >> numRounds;

     }

     void play()
     {
          for (int i = 0; i < numRounds; i++)
          {
               rounds[i][0] = d1->roll(); //player1
               rounds[i][1] = d2->roll(); //player2
          }
     }

     void results()
     {
          int points1 = 0, points2 = 0;

          cout << "Number of rounds played: " << numRounds << endl << endl;
          cout << "Player 1 uses " << d1->getDieType() << " die with " << d1->getNumSides() << " faces." << endl;
          cout << "Player 2 uses " << d2->getDieType() << " die with " << d2->getNumSides() << " faces." << endl;

          cout << "Player 1 \t Player 2 \t " << endl << endl;

          for (int i = 0; i < numRounds; i++)
          {
               cout << rounds[i][0] << "\t \t\t" << rounds[i][1] << endl;

               if (rounds[i][0] > rounds[i][1])
                    points1++;
               else if (rounds[i][0] < rounds[i][1])
                    points2++;

          }
          cout << "Player 1 wins " << points1 << " times." << endl;
          cout << "Player 2 wins " << points2 << " times." << endl;

          if (points1 > points2)
               cout << "Player 1 wins !";
          else if (points2 > points1)
               cout << "Player 2 wins !";
          else
               cout << "Its a draw !!";
     }
};

int main()
{
     Game g;
     g.input();
     g.play();
     g.results();

     system("pause");
     return 0;
}