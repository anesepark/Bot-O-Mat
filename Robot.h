#ifndef ROBOT_H
#define ROBOT_H

#include "Task.h"
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;
class Robot{
  public:
    Robot(string name, string robotType);
    Robot();
    ~Robot(); //destroy the vector once done;

    void setName(const string name);
    void setType(const string botType);

    string getName();
    string getType();
    int getPoints();
    int getTime();

    void addTask(Task job);
    void addTask(vector<Task> jobs);
    void printOut();

    int startJob(); //creates and joins thread (or should this be done in a robotlist class) : while loop for time
    int startJob(int specifiedTime);

  private:
    //void executeJob(int specifiedTime);
    //void executeJobReg();

    int timeTaken, timeLimit, pointsEarned;

    string name, robotType;
    vector<Task> tasks; //order tasks from least time to greatest time
};
#endif
