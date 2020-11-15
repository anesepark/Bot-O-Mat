#include "RobotList.h"
#include "TaskList.h"

#include <iostream>
using namespace std;

int main()
{
  RobotList robots;
  TaskList tasks;

  string lcv = "yes";
  int outermenu, robotmenu, taskmenu, waitTime;

  string botTypes[] = {"unipedal", "bipedal", "quadrupedal", "arachnid", "radial", "aeronautical"};
  string typeOptions = "1. unipedal\n2. bipedal\n3. quadrupedal\n4. arachnid\n5. radial\n6. aeronautical\n";
  string generalPrompt = "1. Robot Configuration Menu\n2. Task Configuration Menu\n3. Look at Leaderboards\n4. Run Robots!\n";
  string robotPrompt = "1. Add a robot\n2. Delete a robot\n3. Edit a robot's name\n4. Edit a robot's type\n5. View all current robots\n6. Exit back to main menu\n";
  string taskPrompt = "1. Add a task\n2. Delete a task\n3. Edit a task's point value\n4. Edit a task's description\n5. Edit a task's ETA\n6. View all current tasks\n7. Exit back to main menu\n";

  cout << "*****************************************************" << endl;
  cout << "              Welcome to Bot-O-Mat!                  " << endl;
  cout << "*****************************************************" << endl;
  cout << endl;
  while(1)
  {
    cout << "Please select an option:\n";
    cout << generalPrompt;

    cin >> outermenu;

    while(outermenu < 1 || outermenu > 4)
    {
      cout << "Please choose a valid number. Here are your choices:" << endl;
      cout << generalPrompt;

      cin >> outermenu;
    }

    cout << endl;

    switch(outermenu)
    {
      case 1: //Robot configuration
      {
        while(1)
        {
          string name, newName;
          int robotType;
          cout << "Welcome to the Robot Configuration Menu! Here are your options:" << endl;
          cout << robotPrompt;
          cin >> robotmenu;

          while(robotmenu < 1 || robotmenu > 6)
          {
            cout << "Please choose a valid number. Here are your choices:" << endl;
            cout << robotPrompt;

            cin >> robotmenu;
          }

          if(robotmenu == 6)
            break;

          switch(robotmenu)
          {
            case 1: //create a robot
            {
              cout << "Please enter the name of the robot you would like to create: " << endl;
              cin >> name;
              cout << "\nHere are all the possible robot types. Please enter the number corresponding to which robot type you'd like your robot to be: " << endl;
              cout << typeOptions;

              cin >>robotType;
              robotType--;
              while(robotType < 0 || robotType > 5)
              {
                cout << "Please enter a valid number. Here are your choices: " << endl;
                cout << typeOptions;

                cin >>robotType;
                robotType --;
              }

              robots.addRobot(name, botTypes[robotType]);
              break;
            }

            case 2:
            {
              cout << "Enter the name of the robot you would like to delete: ";
              cin >> name;

              robots.deleteRobot(name);

              break;
            }

            case 3: //edit robot's name
            {
              cout << "Enter the name of the robot you would like to change: ";
              cin >> name;
              cout << endl;
              cout << "Enter the new name of the robot: " ;
              cin >> newName;

              robots.changeName(name, newName);

              break;
            }

            case 4: //edit robot's type
            {
              cout << "Enter the name of the robot you would like to change: ";
              cin >> name;
              cout << endl;
              cout << "Enter the new type of the robot. Here are your options: " << endl ;
              cout << typeOptions;

              cin >>robotType;
              robotType--;
              while(robotType < 0 || robotType > 5)
              {
                cout << "Please enter a valid number. Here are your choices: " << endl;
                cout << typeOptions;

                cin >>robotType;
                robotType --;
              }

              robots.changeType(name, botTypes[robotType]);
              break;
            }

            case 5: //view all current robots
            {
              robots.toString();
              break;
            }
            default:
              cout << "Error." << endl;
              break;
          }//end inner switch

          cout << endl;
        }//end of while loop

        break;
      }//end of switch statement for robot config menu

      case 2: //Task configuration
      {
        while(1)
        {
          string taskname, newtaskname, nl;
          int points, tasktime;
          cout << "Welcome to the Task Configuration menu! Here are your options: " << endl;
          cout << taskPrompt;

          cin >> taskmenu;
          while(taskmenu < 1 || taskmenu > 7)
          {
            cout << "Please choose a valid number. Here are your choices:" << endl;
            cout << taskPrompt;

            cin >> taskmenu;
          }

          if(taskmenu == 7)
            break;

          switch(taskmenu)
          {
              case 1: //create a task
              {
                cout << "Enter the description of the task you would like to create:" << endl;
                getline(cin, nl);
                getline(cin, taskname);
                cout << "Enter the ETA of the task: " << endl;
                cin >> tasktime;
                cout << "Would you like to enter the amount of points this task is worth? To go with the default point system, press 0: " << endl;
                cin >>points;

                if(points == 0)
                {
                  Task temp(taskname, tasktime);
                  tasks.addTask(temp);
                }
                else
                {
                  Task temp(taskname, tasktime, points);
                  tasks.addTask(temp);
                }
                break;
              }
              case 2: //delete a task
              {
                cout << "Enter the description of the task you'd like to delete: " << endl;
                getline(cin, nl);
                getline(cin, taskname);

                tasks.deleteTask(taskname);
                break;
              }
              case 3: //edit a task's point value
              {
                cout << "Enter the description of the task you'd like to change the points of: " << endl;
                getline(cin, nl);
                getline(cin, taskname);
                cout << "Enter how many points this task is worth: " << endl;
                cin >> points;

                tasks.changePoints(taskname, points);
                break;
              }
              case 4: //edit a task's description
              {
                cout << "Enter the description of the task you'd like to change: " << endl;
                getline(cin, nl);
                getline(cin, taskname);
                cout << "Enter the new description of the task: " << endl;
                getline(cin, nl);
                getline(cin, newtaskname);

                tasks.changeDesc(taskname, newtaskname);
                break;
              }
              case 5: //edit a task's eta
              {
                cout << "Enter the description of the task you'd like to change the ETA of: " << endl;
                getline(cin, nl);
                getline(cin, taskname);
                cout << "Enter how long this task should take to complete: " << endl;
                cin >> tasktime;

                tasks.changeTime(taskname, tasktime);
                break;
              }
              case 6: //view all current tasks
              {
                tasks.toString();
              }
              default:
                break;
          }//end of switch statement for task menu
          cout << endl;
        } //end of while loop
        break;
      }//end of Task Config Menu
      case 3: //Look at the leaderboards;
        robots.printBoard();
        cout << endl;
        break;
      case 4: //Run Robots
      {
        robots.assignTasks(tasks);
        cout << "Would you like to determine the maximum wait time for all robots? Please enter in milliseconds (If you don't want to, enter 0): " << endl;
        cin >> waitTime;
        while(waitTime < -1)
        {
          cout << "Too low! Please enter a valid wait time." << endl;
          cin >> waitTime;
        }

        cout << "\nTime to run all robots! Please keep in mind that the robots will be run in REAL TIME. Sit tight until they're done!" << endl;
        if(waitTime == 0)
          robots.startJobs();
        else
          robots.startJobsTime(waitTime);

        break;
      }

      default:
        cout << "Error." << endl;
        break;
    }//end of general menu switch

    if(outermenu == 4)
    {
      string savebots;
      cout << "Here are the results: " << endl;
      robots.toStringPoints();
      cout << endl;
      cout << "Here is the leaderboard: " << endl;
      robots.saveBoard();
      robots.printBoard();

      cout << endl;
      cout << "Do you want to play another round? Type 'y' or 'yes' if yes, anything else otherwise: " << endl;
      cin >> lcv;

      if(lcv != "y" && lcv != "yes")
      {
        cout << "Before you exit, would you like to save the robots you've created? Type 'y' or 'yes' if yes, anything else otherwise: " << endl;
        cin >> savebots;
        if(savebots == "yes" || savebots == "y")
        {
          robots.saveRobots();
        }
        break;
      }

    }
  }

  cout << "This program uses text files to save your leaderboard, robot, and task information. You can find them under 'leaderboard.txt', 'robot.txt', and 'tasks.txt' respectively. Thank you!" << endl;
  return 0;
}
