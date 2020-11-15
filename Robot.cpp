#include "Robot.h"

Robot::Robot(string name, string robotType)
{
  this->name = name;
  this->robotType = robotType;
  this->pointsEarned = 0;
  this->timeTaken = 0;

  tasks = new vector<Task>;
}

Robot::Robot(){}
Robot::~Robot()
{
  delete tasks;
  tasks = NULL;
}

void Robot::setType(const string botType)
{
  robotType = botType;
}

void Robot::setName(const string name)
{
  this->name = name;
}
string Robot::getName()
{
  return name;
}

int Robot::getPoints()
{
  return pointsEarned;
}

string Robot::getType()
{
  return robotType;
}

int Robot::getTime()
{
  return timeTaken;
}
void Robot::addTask(Task job)
{
  if(tasks->size() < 6)
    tasks->push_back(job);
  else
    cout << "This robot already has 5 jobs." << endl;
}
vector<Task>* Robot::getTasks()
{
  return tasks;
}
void Robot::addTasks(vector<Task> *jobs)
{
  *tasks = *jobs;
  //cout << endl;
}


void Robot::startJob() //no specified restriction time
{
  while(tasks->size() > 0)
  {
    this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

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

  while(timeLeft > 0 && !tasks->empty())
  {
    this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks->at(0).updateTime() == 0) //if the task at beginning of work list is done
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
  cout << "Name: " << name << "\tType: " << robotType << endl;
}


void Robot::printTasks()
{
  for(int i = 0; i < 5; i++)
  {
    (&tasks->at(i))->toString();
  }
}

//void Robot::sortTasks() //sorting 5 tasks according to eta of task
