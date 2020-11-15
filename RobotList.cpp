#include "RobotList.h"

RobotList::RobotList() //create leaderboard
{
    std::ifstream inFS;
    inFS.open("leaderboard.txt");
    std::string line;

    if(inFS)
    {
      std::string name, type;
      int points = 0;
      while (!inFS.eof())
      {
          getline(inFS, line);

          if(line.empty())
            break;
          if(line == "Overall Points:" || line == "By Category:")
          {
            continue;
          }
          name = line.substr(0, line.find(delimiter));

          line.erase(0, line.find(delimiter)+2);
          type = line.substr(0, line.find(delimiter));
          line.erase(0,line.find(delimiter) + 2);

          points = stoi(line);

          auto lead = std::make_tuple(name, type, points);
          leaders.push_back(lead);

      } //end of while
      inFS.close();
    }
    else //if there is no file made that stores leaders
    {
      leaders.push_back(std::make_tuple("n/a", "n/a", 0));
      leaders.push_back(std::make_tuple("n/a", "unipedal", 0));
      leaders.push_back(std::make_tuple("n/a", "bipedal", 0));
      leaders.push_back(std::make_tuple("n/a", "quadrupedal", 0));
      leaders.push_back(std::make_tuple("n/a", "arachnid", 0));
      leaders.push_back(std::make_tuple("n/a", "radial", 0));
      leaders.push_back(std::make_tuple("n/a", "aeronautical", 0));
    }

    std::ifstream rblst;
    rblst.open("robots.txt");
    std::string line2;

    if(rblst)
    {
      std::string name, robotType;
      while (!rblst.eof())
      {
          getline(rblst, line2);
          if(line2.empty())
            break;

          name = line2.substr(0, line2.find(delimiter));

          line2.erase(0, line2.find(delimiter)+2);
          robotType = line2.substr(0, line2.find(delimiter));

          Robot tempfriend(name, robotType);
          robots[name] = tempfriend;
      } //end of while
      rblst.close();
    }

}
RobotList::~RobotList(){ saveBoard(); }

bool RobotList::updateBoard(std::string name, std::string type, int points)
{
  bool updated = false;
  auto challenger = std::make_tuple(name, type, points);

  if(std::get<2>(leaders.at(0)) < points) //checking for overall points
  {
    leaders.at(0) = challenger;
    updated = true;
  }

  for(int i = 1; i < 7; i++)
  {
    if(std::get<2>(leaders.at(i)) < points && std::get<1>(leaders.at(i)) == type)
    {
      leaders.at(i) = challenger;
      updated = true;
      break;
    }
  }
  return updated;
}

void RobotList::printBoard()
{
  std::cout << "Overall Points:\n";
  std::cout << std::get<0>(leaders.at(0)) << ": " << std::get<1>(leaders.at(0)) << ": " << std::get<2>(leaders.at(0)) << "\n" ;
  std::cout << "By Category:\n";
  for(int i = 1; i < 7; i++)
  {
    std::cout << std::get<0>(leaders.at(i))<< ": " << std::get<1>(leaders.at(i)) << ": " << std::get<2>(leaders.at(i)) << "\n";
  }
}

void RobotList::saveBoard()
{
  std::ofstream outFS;
  outFS.open("leaderboard.txt");
  if(!outFS.is_open())
  {
    std::cout << "Could not open file." << std::endl;
    return;
  }

  outFS << "Overall Points:\n";
  outFS << std::get<0>(leaders.at(0)) << ": " << std::get<1>(leaders.at(0)) << ": " << std::get<2>(leaders.at(0)) << "\n" ;
  outFS << "By Category:\n";
  for(int i = 1; i < 7; i++)
  {
    outFS << std::get<0>(leaders.at(i))<< ": " << std::get<1>(leaders.at(i)) << ": " << std::get<2>(leaders.at(i)) << "\n";
  }
  outFS.close();
}

void RobotList::saveRobots()
{
  std::ofstream outFS;
  outFS.open("robots.txt");

  if(!outFS.is_open())
  {
    std::cout << "Could not open file." << std::endl;
    return;
  }

  for( auto rob : robots)
  {
    outFS << rob.second.getName() << ": " << rob.second.getType() << std::endl;
  }
}
void RobotList::changeName(std::string currentName, std::string newName)
{
  if(robots.find(currentName) == robots.end()) //could not find the new name in list
  {
    Robot temp = robots[currentName];
    robots.erase(currentName);

    robots[newName] = temp;
    robots[newName].setName(newName);
  }
  else
  { std::cout << "A robot with that name already exists." << std::endl; }
}


void RobotList::changeType(std::string currentName, std::string newType)
{
  if(robots.find(currentName) != robots.end()) //if we found the robot
  {
    robots.at(currentName).setType(newType); //change type
  }
  else //did not find robot
  {
    std::cout << "Robot with the name " << currentName << " could not be found." << std::endl;
  }
}

void RobotList::addRobot(std::string name, std::string type)
{

  if(robots.find(name) == robots.end()) //if we found the robot
  {
    std::cout << "Success! Robot with the name " << name << " and type " << type << " created." << std::endl;
    Robot newfriend(name, type);
    robots[name] = newfriend;
  }
  else //did not find robot
  { std::cout << "A robot with that name already exists." << std::endl; }

}

void RobotList::deleteRobot(std::string name)
{
  if(robots.find(name) != robots.end())
  { robots.erase(name); }
  else
  { std::cout << "Robot with the name " << name << " could not be found." << std::endl; }
}

void RobotList::viewRobot(std::string name)
{
  auto found = robots.find(name);

  if(found != robots.end())
  {
    std::cout << "Name: " << robots[name].getName() << "\tType: " << robots[name].getType() << std::endl;
  }
  else
  { std::cout << "Robot with the name " << name << " could not be found." << std::endl; }
}

void RobotList::assignTasks(TaskList listOfTasks)
{
  for(auto &rob : robots)
  {
    listOfTasks.getRandomTasks(rob.second.getTasks());
  }

}

void RobotList::startJobs()
{
  for(auto rob : robots)
  {
    std::thread temp(RobotList::executeJobs, this, std::ref(robots[rob.second.getName()]));
    threads.emplace_back(move(temp));
  }


  for (std::thread &t : threads)
  {
    t.join();
  }


  for(auto rob : robots)
  {
    if(updateBoard(rob.second.getName(), rob.second.getType(), rob.second.getPoints()))
          std::cout << "New highscore from: " << rob.second.getName() << std::endl;
  }
}

void RobotList::startJobsTime(int specifiedTime)
{
  for(auto &rob : robots)
  {
    std::thread temp(RobotList::executeJobsTime, this, specifiedTime, std::ref(robots[rob.second.getName()]));
    threads.emplace_back(move(temp));
  }
  for (std::thread &t : threads)
  {
    t.join();
  }

  for(auto rob : robots)
  {
    std::cout << "Name: " << rob.second.getName() << "\tPoints: " << rob.second.getPoints() << std::endl;
    if(updateBoard(rob.second.getName(), rob.second.getType(), rob.second.getPoints()))
          std::cout << "New highscore from: " << rob.second.getName() << std::endl;
  }
}

void RobotList::executeJobsTime(int specifiedTime, Robot rob)
{
  robots[rob.getName()].startJob(specifiedTime);
}

void RobotList::executeJobs(Robot rob)
{
  robots[rob.getName()].startJob();
}

void RobotList::toString()
{
  if(robots.size() == 0)
  {
    std::cout << "No robots currently in the list.\n";
    return;
  }
  for (auto rob : robots)
  {
    std::cout << "Name: " << rob.second.getName() << "\tType: " << rob.second.getType() << std::endl;
  }
}

void RobotList::toStringPoints()
{
  for (auto rob : robots)
  {
    std::cout << "Name: " << rob.second.getName() << "\tType: " << rob.second.getType() << "\tPoints: " << rob.second.getPoints() << std::endl;
  }
}
