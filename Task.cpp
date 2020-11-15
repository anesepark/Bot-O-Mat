#include "Task.h"

Task::Task(string desc, int millitime)
{
  this->description = desc;
  this->eta = millitime;
  points = (int) millitime/100; //one point for every 100 milliseconds the task is
}

Task::Task(){}

string Task::getDescription()
{
  return description;
}

int Task::getTime()
{
  return eta;
}

int Task::getPoints()
{
  return points;
}
void Task::toString()
{
  cout << description << ": " << eta << " milliseconds\n";
  //return description + ": " + eta;
}

int Task::updateTime()
{
  eta -= 100;
  return eta;
}
