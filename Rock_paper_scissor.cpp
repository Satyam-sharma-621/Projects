#include <iostream>
#include <cstdlib>
#include <ctime>
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

using namespace std;

int main()
{ 
  int player_throw = 0;
  int ai_throw = 0;
  bool draw = false;
  
  do
  {
    cout << "Select your throw." << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "Selection: ";
    cin >> player_throw;
    
    cout << endl;
    
    ai_throw = (rand() % 3) + 1;
    
    if (ai_throw == ROCK)
    {
      cout << "AI throws ROCK." << endl;
    }
    else if (ai_throw == PAPER)
    {
      cout << "AI throws PAPER." << endl;
    }
    else if (ai_throw == SCISSORS)
    {
      cout << "AI throws SCISSORS." << endl;
    }
    
    draw = false;
    
    
    if (player_throw == ai_throw)
    {
      draw = true;
      cout << "Draw! Play again!" << endl;
    }
    else if (player_throw == ROCK && ai_throw == SCISSORS)
    {
      cout << "ROCK beats SCISSORS! YOU WIN." << endl;
    }
    else if (player_throw == ROCK && ai_throw == PAPER)
    {
      cout << "PAPER beats ROCK! YOU LOSE." << endl;
    }
    else if (player_throw == PAPER && ai_throw == ROCK)
    {
      cout << "PAPER beats ROCK! YOU WIN." << endl;
    }
    else if (player_throw == PAPER && ai_throw == SCISSORS)
    {
      cout << "SCISSORS beats PAPER! YOU LOSE." << endl;
    }
    else if (player_throw == SCISSORS && ai_throw == PAPER)
    {
      cout << "SCISSORS beats PAPER! YOU WIN." << endl;
    }
    else if (player_throw == SCISSORS && ai_throw == ROCK)
    {
      cout << "ROCK beats SCISSORS! YOU LOSE." << endl;
    }
    
    cout << endl;
  
  } while (draw);

  return 0;
}
