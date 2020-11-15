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

    void deleteTask(string description); //
    void addTask(Task newTask);

    void viewTask(string description);

    void changeTime(string description, int newTime);
    void changeDesc(string currDesc, string newDesc);
    void changePoints(string description, int newPoints);

    void getRandomTasks(vector<Task> *listTasks); //returns random vector of 5 tasks

    void toString(); //prints out all tasks

  private:
    string delimiter = ":";
    unordered_map<string, Task> tasklist;
};
#endif
