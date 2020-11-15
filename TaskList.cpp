#include "TaskList.h"

TaskList::TaskList()
{
  srand(time(NULL));

  ifstream inFS;
  inFS.open("tasks.txt");
  string line;

  if(inFS)
  {
    std::string line;
    string desc, temp;
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
    cout << "No file to read from! Initializing default tasks\n";
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
  ofstream outFS;
  outFS.open("tasks.txt");
  if(!outFS.is_open())
  {
    cout << "Could not open file." << endl;
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

void TaskList::deleteTask(string description)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist.erase(description); }
  else
  { cout << "The task with the specified description (" << description << ") could not be found." << endl;}
}

void TaskList::addTask(Task newTask)
{
  if(tasklist.find(newTask.getDescription()) != tasklist.end())
  { cout << "The task with the specified description (" << newTask.getDescription() << ") already exists." << endl;}
  else
  { tasklist[newTask.getDescription()] = newTask; }
}

void TaskList::viewTask(string description)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist[description].toString(); }
  else
  { cout << "The task with the specified description (" << description << ") could not be found." << endl;}
}

void TaskList::changeTime(string description, int newTime)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist[description].setTime(newTime); }
  else
  { cout << "The task with the specified description (" << description << ") could not be found." << endl; }
}

void TaskList::changePoints(string description, int newPoints)
{
  if(tasklist.find(description) != tasklist.end())
  { tasklist[description].setPoints(newPoints); }
  else
  { cout << "The task with the specified description (" << description << ") could not be found." << endl; }
}

void TaskList::changeDesc(string currDesc, string newDesc) //check whether current desc exists, newdesc exists
{
  if(currDesc == newDesc)
  { cout << "The current description and the new description are the same." << endl; }
  else if(tasklist.find(newDesc) != tasklist.end())
  { cout << "Another task has the description (" << newDesc << ")." << endl; }
  else if (tasklist.find(currDesc) == tasklist.end())
  { cout << "The task with the specified description (" << currDesc << ") could not be found." << endl; }
  else
  {
    Task temp = tasklist[currDesc];

    tasklist.erase(currDesc);
    tasklist[newDesc] = temp;
    tasklist[newDesc].setDescription(newDesc);
  }
}

void TaskList::getRandomTasks( vector<Task> *listTasks) //returns random vector of 5 tasks
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
