#ifndef ROBOT_H
#define ROBOT_H

#include "Task.h"
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>
#include <iostream>

class Robot{
  public:
    Robot(std::string name, std::string robotType);
    Robot();
    ~Robot(); //destroy the vector once done;

    void setName(const std::string name);
    void setType(const std::string botType);

    std::string getName();
    std::string getType();
    int getPoints();
    int getTime();
    std::vector<Task>* getTasks();

    void addTasks(std::vector<Task> *jobs);
    void toString();
    void startJob();
    void startJob(int specifiedTime);

  private:
    int timeTaken, pointsEarned;

    std::string name, robotType;
    std::vector<Task> *tasks; //order tasks from least time to greatest time
};
#endif
