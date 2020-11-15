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
    vector<Task>* getTasks();

    void addTask(Task job);
    void addTasks(vector<Task> *jobs);
    void toString();
    void printTasks();
    void startJob();
    void startJob(int specifiedTime);

  private:
    int timeTaken, pointsEarned;

    string name, robotType;
    vector<Task> *tasks; //order tasks from least time to greatest time
};
#endif
