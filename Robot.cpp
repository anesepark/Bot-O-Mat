#include "Robot.h"

Robot::Robot(std::string name, std::string robotType)
{
  this->name = name;
  this->robotType = robotType;
  this->pointsEarned = 0;
  this->timeTaken = 0;

  tasks = new std::vector<Task>;
}

Robot::Robot(){}
Robot::~Robot()
{
  delete tasks;
  tasks = NULL;
}

void Robot::setType(const std::string botType)
{
  robotType = botType;
}

void Robot::setName(const std::string name)
{
  this->name = name;
}
std::string Robot::getName()
{
  return name;
}

int Robot::getPoints()
{
  return pointsEarned;
}

std::string Robot::getType()
{
  return robotType;
}

int Robot::getTime()
{
  return timeTaken;
}


std::vector<Task>* Robot::getTasks()
{
  return tasks;
}
void Robot::addTasks(std::vector<Task> *jobs)
{
  *tasks = *jobs;
}


void Robot::startJob() //no specified restriction time
{
  while(tasks->size() > 0) //while there are still tasks to do
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks->at(0).updateTime() == 0) //if the task at beginning of work list is done
    {
      pointsEarned += tasks->at(0).getPoints(); //adds amount of points the task is worth
      tasks->erase(tasks->begin()); //takes the task off of the list
    }

    timeTaken += 100;
    if(tasks->empty()) //if all tasks are done
    { break; }
  }
}

void Robot::startJob(int specifiedTime) //specified time restriction
{
  int timeLeft = specifiedTime;

  while(timeLeft > 0 && !tasks->empty()) //while there is still time left and tasks to do
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks->at(0).updateTime() <= 0) //if the task at beginning of work list is done
    {
      pointsEarned += tasks->at(0).getPoints(); //adds amount of points the task is worth
      tasks->erase(tasks->begin()); //takes the task off of the list
    }

    timeLeft -= 100;
    timeTaken += 100;

    if(tasks->empty()) //if all tasks are done
    { break;}

  }
}

void Robot::toString()
{
  std::cout << "Name: " << name << "\tType: " << robotType << std::endl;
}
