#ifndef ROBOTLIST_H
#define ROBOTLIST_H

#include "Robot.h"
#include "TaskList.h"
#include <unordered_map>
#include <tuple>

class RobotList{
  public:
    RobotList();
    ~RobotList();

    void changeName(std::string currentName, std::string newName);
    void changeType(std::string currentName, std::string newType);

    void addRobot(std::string name, std::string type);
    void deleteRobot(std::string name);
    void viewRobot(std::string name);

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
    bool updateBoard(std::string name, std::string type, int score);

    std::unordered_map<std::string, Robot> robots;
    std::vector<std::thread> threads;

    //first std::string is the name, second is the type
    std::vector<std::tuple<std::string, std::string, int>> leaders;

    std::string delimiter = ": ";

};
#endif
