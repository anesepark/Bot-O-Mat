#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task{

  public:
    Task(std::string desc, int millitime);
    Task(std::string desc, int millitime, int points);
    Task();

    std::string getDescription();
    int getTime();
    int getPoints();

    void setTime(const int newTime);
    void setPoints(const int newPoints);
    void setDescription(const std::string desc);

    bool isDefault();
    int updateTime(); //deducts 100 milliseconds from eta, returns total time remaining;

    void toString();

  private:
    bool defPoints;
    std::string description;
    int eta;
    int points;
};
#endif
