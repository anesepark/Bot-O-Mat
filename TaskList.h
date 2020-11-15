#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
#include <vector>

class TaskList{
  public:
    TaskList(); //reads from file

    void saveTasks(); //writes to file

    void deleteTask(string description); //
    void addTask(Task newTask);

    void viewTask(string description);


    void changeTime(string description, int newTime);
    void changeDesc(string currDesc, string newDesc);

    Task getRandom(); //returns one random task, deletes it from the unordered_map
    //change completion time, etc?

    void tostring(); //prints out all tasks
  private:
    vector<Task> taskVector; //for assignment at a certain index
};
#endif
