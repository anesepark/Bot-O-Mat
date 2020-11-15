#include "RobotList.h"

RobotList::RobotList(){}
RobotList::~RobotList(){}

void RobotList::changeName(string currentName, string newName)
{
  if(robots.find(currentName) != robots.end()) //could not find the new name in list
  {
    Robot temp = robots[currentName];
    robots.erase(currentName);

    robots[newName] = temp;
    robots[newName].setName(newName);
  }
  else
  {
    cout << "A robot with that name already exists." << endl;
  }
}

//ERROR SOMEWHERE HERE

void RobotList::changeType(string currentName, string newType)
{
  if(robots.find(currentName) != robots.end()) //if we found the robot
  {
    robots.at(currentName).setType(newType); //change type
  }
  else //did not find robot
  {
    cout << "Robot with the name " << currentName << " could not be found." << endl;
  }
}

void RobotList::addRobot(Robot newRobot)
{
  robots[newRobot.getName()] = newRobot;
  //robots.insert({newRobot.getName(), newRobot});
}

void RobotList::deleteRobot(string name)
{
  if(robots.find(name) != robots.end())
  {
    robots.erase(name);
  }
  else
  {
    cout << "Robot with the name " << name << " could not be found." << endl;
  }
}

void RobotList::viewRobot(string name)
{
  auto found = robots.find(name);

  if(found != robots.end())
  {
    cout << "Name: " << robots[name].getName() << "\tType: " << robots[name].getType() << endl;
  }
  else
  {
    cout << "Robot with the name " << name << " could not be found." << endl;
  }
}

//TO HERE

void RobotList::startJobs()
{
  for(auto rob : robots)
  {
    cout << "No time initialize threads" << endl;
    thread temp(&RobotList::executeJobs, this, ref(rob.second));
    threads.emplace_back(move(temp));
  }

  for (thread &t : threads)
  {
    cout << "No time specified join" << endl;
    t.join();
  }
}

void RobotList::startJobsTime(int specifiedTime)
{
  for(auto rob : robots)
  {
    cout << "initializing threads: specified time" << endl;
    thread temp(&RobotList::executeJobsTime, this, ref(specifiedTime), ref(rob.second));
    threads.emplace_back(move(temp));
  }

  for (thread &t : threads)
  {
    cout << "joining" << endl;
    t.join();
  }
  cout << "done" << endl;
}

void RobotList::executeJobsTime(int specifiedTime, Robot rob)
{
  cout << "we are executing the job: time limit included" << endl;
  rob.startJob(specifiedTime);
}

void RobotList::executeJobs(Robot rob)
{
  cout << "no time limit: take it easy." << endl;
  rob.startJob();
}

void RobotList::toString()
{
  for (auto rob : robots)
  {
    cout << "Name: " << rob.second.getName() << "\tType: " << rob.second.getType() << endl;
  }
}

void RobotList::toStringPoints()
{
  for (auto rob : robots)
  {
    cout << "Name: " << rob.second.getName() << "\tType: " << rob.second.getType() << "\tPoints: " << rob.second.getPoints() << endl;
  }
}
