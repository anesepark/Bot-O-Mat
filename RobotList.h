#ifndef ROBOTLIST_H
#define ROBOTLIST_H

#include "Robot.h"
#include "TaskList.h"
#include "Leaderboard.h"
#include <unordered_map>
#include <tuple>

class RobotList{
  public:
    RobotList();
    ~RobotList();

    void changeName(string currentName, string newName);
    void changeType(string currentName, string newType);

  //  void addRobot(Robot &newRobot);
    void addRobot(string name, string type);
    void deleteRobot(string name);
    void viewRobot(string name);

    void assignTasks(TaskList listOfTasks);

    void startJobs();
    void startJobsTime(int specifiedTime);

    void toString(); //prints out all robots
    void toStringPoints();

    void printBoard();
    void saveBoard();
    void saveRobots();


  private:
    void executeJobsTime(int specifiedTime, Robot rob);
    void executeJobs(Robot rob);
    bool updateBoard(string name, string type, int score);

    unordered_map<string, Robot> robots;
    vector<thread> threads;

    //first string is the name, second is the type
    std::vector<std::tuple<string, string, int>> leaders;

    string delimiter = ": ";

};
#endif
