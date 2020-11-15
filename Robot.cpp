#include "Robot.h"

Robot::Robot(string name, string robotType)
{
  this->name = name;
  this->robotType = robotType;
  this->pointsEarned = 0;
  this->timeTaken = 0;
}

Robot::Robot(){}
Robot::~Robot(){}

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
  if(tasks.size() < 6)
    tasks.push_back(job);
  else
    cout << "This robot already has 5 jobs." << endl;
}

void Robot::addTask(vector<Task> jobs)
{
  tasks = jobs;
}


int Robot::startJob() //no specified restriction time
{
  cout << "Hi there!" << endl;
  //std::thread robotJob(executeJobReg);
  //executeJobReg();
  //robotJob.join();
  while(tasks.size() > 0)
  {
    this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks.at(0).updateTime() == 0) //if the task at beginning of work list is done
    {
      pointsEarned += tasks.at(0).getPoints(); //adds amount of points the task is worth
      tasks.erase(tasks.begin()); //takes the task off of the list
    }

    timeTaken += 100;
    if(tasks.empty()) //if all tasks are done
    {
      cout << name << " (type " << robotType << ") has finished all its tasks!" << endl;
      break;
    }
  }


  return pointsEarned;
}

/*
void Robot::executeJobReg()
{
  auto startTime = std::chrono::system_clock::now(); //gets current time in milliseconds

  while(tasks.size() > 0)
  {
    this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks.at(0).updateTime() == 0) //if the task at beginning of work list is done
    {
      pointsEarned += tasks.at(0).getPoints(); //adds amount of points the task is worth
      tasks.erase(tasks.begin()); //takes the task off of the list
    }

    if(tasks.empty()) //if all tasks are done
    {
      break;
    }
  }
  auto endTime = std::chrono::system_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
  timeTaken = duration.count();
}
*/
int Robot::startJob(int specifiedTime) //specified time restriction
{
  cout << "heyyyy" << endl;
  //auto startTime = std::chrono::system_clock::now(); //gets current time in milliseconds
  int timeLeft = specifiedTime;

  while(timeLeft > 0 && !tasks.empty())
  {
    cout << "in while loop" << endl;
    this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks.at(0).updateTime() == 0) //if the task at beginning of work list is done
    {
      pointsEarned += tasks.at(0).getPoints(); //adds amount of points the task is worth
      tasks.erase(tasks.begin()); //takes the task off of the list

    }
    timeLeft -= 100;
    timeTaken += 100;

    if(tasks.empty()) //if all tasks are done
    {
      cout << this->name << " (type " << this->robotType << ") has finished all its tasks in the given time frame!" << endl;
      break;
    }
  }

  if(timeLeft == 0)
  {
    cout << this->name << " (type " << this->robotType << ") could not complete tasks in the alloted timeframe." << endl;
  }
  return pointsEarned;
}

void Robot::printOut()
{
  cout << "Name: " << name << "\tType: " << robotType << endl;
}
/*
void Robot::executeJob(int specifiedTime)
{
  //auto startTime = std::chrono::system_clock::now(); //gets current time in milliseconds
  int timeLeft = specifiedTime;

  while(timeLeft > 0 && !tasks.empty())
  {
    this_thread::sleep_for(std::chrono::milliseconds(100)); //does work for 100 milliseconds

    if(tasks.at(0).updateTime() == 0) //if the task at beginning of work list is done
    {
      pointsEarned += tasks.at(0).getPoints(); //adds amount of points the task is worth
      tasks.erase(tasks.begin()); //takes the task off of the list

    }
    timeLeft -= 100;
    timeTaken += 100;

    if(tasks.empty()) //if all tasks are done
    {
      break;
    }
  }
  //auto endTime = std::chrono::system_clock::now();
  //auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
  //timeTaken = duration.count();
}

//void Robot::sortTasks() //sorting 5 tasks according to eta of task
*/
