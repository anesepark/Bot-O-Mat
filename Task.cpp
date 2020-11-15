#include "Task.h"

Task::Task(std::string desc, int millitime)
{
  this->description = desc;
  this->eta = millitime;
  points = (int) millitime/100; //one point for every 100 milliseconds the task is
  defPoints = true;
}

Task::Task(std::string desc, int millitime, int points)
{
  this->description = desc;
  this->eta = millitime;
  this->points = points;
  defPoints = false;
}

Task::Task(){}

std::string Task::getDescription()
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

bool Task::isDefault()
{
  return defPoints;
}
void Task::setPoints(const int newPoints)
{
  points = newPoints;
  defPoints = false;
}

void Task::setTime(const int newTime)
{
  eta = newTime;
}

void Task::setDescription(const std::string desc)
{
  description = desc;
}


void Task::toString()
{
  std::cout << description << ": " << eta << " milliseconds\t" << points << " points\n";
}

int Task::updateTime()
{
  eta -= 100;
  return eta;
}
