#include "Leaderboard.h"

Leaderboard::Leaderboard()
{
  //open file: if empty, print
}

bool Leaderboard::updateBoard(Robot challenger)
{
  if(challenger.getPoints() > firstPlace.getPoints())
  {
    firstPlace = challenger;

    leaders.at(2) = leaders.at(1);
    leaders.at(1) = leaders.at(0);
    leaders.at(0) = challenger;

    return true;
  }
  else if(leaders.at(1).getPoints() < challenger.getPoints())
  {
    leaders.at(2) = leaders.at(0);
    leaders.at(1) = challenger;

    return true;
  }
  else if (leaders.at(2).getPoints() < challenger.getPoints())
  {
    leaders.at(2) = challenger;

    return true;
  }

  return false;
}

void Leaderboard::toString()
{
  cout << "First Place: " ;
  leaders.at(0).toString();

  cout << "Second Place: " ;
  leaders.at(1).toString();

  cout << "Third Place: " ;
  leaders.at(2).toString();
}

void Leaderboard::saveBoard()
{
  //write to file
}
