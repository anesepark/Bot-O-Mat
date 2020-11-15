#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "Robot.h"
#include <iostream>

using namespace std;
class Leaderboard{
  public:
    Leaderboard();//read from file
    ~Leaderboard();

    bool updateBoard(Robot challenger);
    void toString();

    void saveBoard();

  private:
    vector<Robot> leaders; //vector of 3 Robots
    Robot firstPlace;
};
#endif
