#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
using namespace std;
class Task{

  public:
    Task(string desc, int millitime);
    Task(string desc, int millitime, int points);
    Task();

    string getDescription();
    int getTime();
    int getPoints();

    void setTime(const int newTime);
    void setPoints(const int newPoints);
    void setDescription(const string desc);

    bool isDefault();
    int updateTime(); //deducts 100 milliseconds from eta, returns total time remaining;

    void toString();

  private:
    bool defPoints;
    string description;
    int eta;
    int points;
};
#endif
