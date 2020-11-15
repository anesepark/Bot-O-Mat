#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
using namespace std;
class Task{

  public:
    Task(string desc, int millitime);
    Task();

    string getDescription();
    //void setDescription(const String desc);

    int getTime();
    //void setTime(const int newTime);

    int getPoints();
    //void setPoints(const int newPoints);

    int updateTime(); //deducts 100 milliseconds from eta, returns total time remaining;

    void toString();

  private:
    string description;
    int eta;
    int points;
};
#endif
