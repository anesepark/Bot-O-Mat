#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <vector>
#include <fstream>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <functional>

class TaskList{
  public:
    TaskList(); //reads from file
    ~TaskList();

    void saveTasks(); //writes to file

    void deleteTask(std::string description); //
    void addTask(Task newTask);

    void viewTask(std::string description);

    void changeTime(std::string description, int newTime);
    void changeDesc(std::string currDesc, std::string newDesc);
    void changePoints(std::string description, int newPoints);

    void getRandomTasks(std::vector<Task> *listTasks); //returns random vector of 5 tasks

    void toString(); //prints out all tasks

  private:
    std::string delimiter = ":";
    std::unordered_map<std::string, Task> tasklist;
};
#endif
