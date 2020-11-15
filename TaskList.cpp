#include "TaskList.h"

TaskList::TaskList()
{
  srand(time(NULL));

  std::ifstream inFS;
  inFS.open("tasks.txt");
  std::string line;

  if(inFS)
  {
    std::string line;
    std::string desc, temp;
    int time = 0;
    int points = 0;
    while (!inFS.eof())
    {
        getline(inFS, line);

        if(line.empty())
          break;

        desc = line.substr(0, line.find(delimiter));

        line.erase(0, line.find(delimiter) + 1);
        time = stoi(line.substr(0, line.find(delimiter)));
        line.erase(0,line.find(delimiter) + 1);

        points = stoi(line);

        if(points == 0)
        {
          Task temp(desc, time);
          tasklist[desc] = temp;
        }
        else
        {
          Task temp(desc, time, points);
          tasklist[desc] = temp;
        }
    } //end of if
    inFS.close();
  }
  else //if there is no file made that stores all tasks
  {
    Task t1("sweep the house", 3000);
    Task t2("do the laundry", 10000);
    Task t3("do the dishes", 1000);
    Task t4("take out the recycling", 4000);
    Task t5("make a sammich", 1000);
    Task t6("mow the lawn", 20000);
    Task t7("rake the leaves", 18000);
    Task t8("give the dog a bath", 14500);
    Task t9("bake some cookies", 8000);
    Task t10("wash the car", 20000);

    tasklist["do the dishes"] = t1;
    tasklist["sweep the house"] = t2;
    tasklist["do the laundry"] = t3;
    tasklist["take out the recycling"] = t4;
    tasklist["make a sammich"] = t5;
    tasklist["mow the lawn"] = t6;
    tasklist["rake the leaves"] = t7;
    tasklist["give the dog a bath"] = t8;
    tasklist["bake some cookies"] = t9;
    tasklist["wash the car"] = t10;
  }
}

TaskList::~TaskList(){}

void TaskList::saveTasks() //writes to file
{
  std::ofstream outFS;
  outFS.open("tasks.txt");
  if(!outFS.is_open())
  {
    std::cout << "Could not open file." << std::endl;
    return;
  }

  for(auto t : tasklist)
  {
    outFS << t.second.getDescription()<< ": " << t.second.getTime() << ": ";
    if( t.second.isDefault() )
    { outFS << "0\n"; }
    else { outFS << t.second.getPoints() << "\n";}
  }

  outFS.close();
}

void TaskList::deleteTask(std::string description)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist.erase(description); }
  else
  { std::cout << "The task with the specified description (" << description << ") could not be found." << std::endl;}
}

void TaskList::addTask(Task newTask)
{
  if(tasklist.find(newTask.getDescription()) != tasklist.end())
  { std::cout << "The task with the specified description (" << newTask.getDescription() << ") already exists." << std::endl;}
  else
  { tasklist[newTask.getDescription()] = newTask; }
}

void TaskList::viewTask(std::string description)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist[description].toString(); }
  else
  { std::cout << "The task with the specified description (" << description << ") could not be found." << std::endl;}
}

void TaskList::changeTime(std::string description, int newTime)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist[description].setTime(newTime); }
  else
  { std::cout << "The task with the specified description (" << description << ") could not be found." << std::endl; }
}

void TaskList::changePoints(std::string description, int newPoints)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist[description].setPoints(newPoints); }
  else
  { std::cout << "The task with the specified description (" << description << ") could not be found." << std::endl; }
}

void TaskList::changeDesc(std::string currDesc, std::string newDesc) //check whether current desc exists, newdesc exists
{
  if(currDesc == newDesc)
  { std::cout << "The current description and the new description are the same." << std::endl; }
  else if(tasklist.find(newDesc) != tasklist.end())
  { std::cout << "Another task has the description (" << newDesc << ")." << std::endl; }
  else if (tasklist.find(currDesc) == tasklist.end())
  { std::cout << "The task with the specified description (" << currDesc << ") could not be found." << std::endl; }
  else
  {
    Task temp = tasklist[currDesc];

    tasklist.erase(currDesc);
    tasklist[newDesc] = temp;
    tasklist[newDesc].setDescription(newDesc);
  }
}

void TaskList::getRandomTasks(std::vector<Task> *listTasks) //returns random vector of 5 tasks
{
  int randnum;
  while(listTasks->size() < 5)
  {
    randnum = rand() % (tasklist.size()-1);
    auto randomTask = std::next(std::begin(tasklist), randnum);

    listTasks->push_back(randomTask->second);
  }
}

void TaskList::toString() //prints out all tasks
{
  for( auto t : tasklist)
  {
    t.second.toString();
  }
}
