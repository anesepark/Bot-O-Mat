#include "RobotList.h"
#include "TaskList.h"

#include <iostream>

int main()
{
  RobotList robots;
  TaskList tasks;

  std::string lcv = "yes";
  int outermenu, robotmenu, taskmenu, waitTime;

  std::string botTypes[] = {"unipedal", "bipedal", "quadrupedal", "arachnid", "radial", "aeronautical"};
  std::string typeOptions = "1. unipedal\n2. bipedal\n3. quadrupedal\n4. arachnid\n5. radial\n6. aeronautical\n";
  std::string generalPrompt = "1. Robot Configuration Menu\n2. Task Configuration Menu\n3. Look at Leaderboards\n4. Run Robots!\n";
  std::string robotPrompt = "1. Add a robot\n2. Delete a robot\n3. Edit a robot's name\n4. Edit a robot's type\n5. View all current robots\n6. Exit back to main menu\n";
  std::string taskPrompt = "1. Add a task\n2. Delete a task\n3. Edit a task's point value\n4. Edit a task's description\n5. Edit a task's ETA\n6. View all current tasks\n7. Exit back to main menu\n";

  std::cout << "*****************************************************" << std::endl;
  std::cout << "              Welcome to Bot-O-Mat!                  " << std::endl;
  std::cout << "*****************************************************" << std::endl;
  std::cout << std::endl;
  while(1)
  {
    std::cout << "Please select an option:\n";
    std::cout << generalPrompt;

    std::cin >> outermenu;

    while(outermenu < 1 || outermenu > 4)
    {
      std::cout << "Please choose a valid number. Here are your choices:" << std::endl;
      std::cout << generalPrompt;

      std::cin >> outermenu;
    }

    std::cout << std::endl;

    switch(outermenu)
    {
      case 1: //Robot configuration
      {
        while(1)
        {
          std::string name, newName;
          int robotType;
          std::cout << "Welcome to the Robot Configuration Menu! Here are your options:" << std::endl;
          std::cout << robotPrompt;
          std::cin >> robotmenu;

          while(robotmenu < 1 || robotmenu > 6)
          {
            std::cout << "Please choose a valid number. Here are your choices:" << std::endl;
            std::cout << robotPrompt;

            std::cin >> robotmenu;
          }

          if(robotmenu == 6)
            break;

          switch(robotmenu)
          {
            case 1: //create a robot
            {
              std::cout << "Please enter the name of the robot you would like to create: " << std::endl;
              std::cin >> name;
              std::cout << "\nHere are all the possible robot types. Please enter the number corresponding to which robot type you'd like your robot to be: " << std::endl;
              std::cout << typeOptions;

              std::cin >>robotType;
              robotType--;
              while(robotType < 0 || robotType > 5)
              {
                std::cout << "Please enter a valid number. Here are your choices: " << std::endl;
                std::cout << typeOptions;

                std::cin >>robotType;
                robotType --;
              }

              robots.addRobot(name, botTypes[robotType]);
              break;
            }

            case 2:
            {
              std::cout << "Enter the name of the robot you would like to delete: ";
              std::cin >> name;

              robots.deleteRobot(name);

              break;
            }

            case 3: //edit robot's name
            {
              std::cout << "Enter the name of the robot you would like to change: ";
              std::cin >> name;
              std::cout << std::endl;
              std::cout << "Enter the new name of the robot: " ;
              std::cin >> newName;

              robots.changeName(name, newName);

              break;
            }

            case 4: //edit robot's type
            {
              std::cout << "Enter the name of the robot you would like to change: ";
              std::cin >> name;
              std::cout << std::endl;
              std::cout << "Enter the new type of the robot. Here are your options: " << std::endl ;
              std::cout << typeOptions;

              std::cin >>robotType;
              robotType--;
              while(robotType < 0 || robotType > 5)
              {
                std::cout << "Please enter a valid number. Here are your choices: " << std::endl;
                std::cout << typeOptions;

                std::cin >>robotType;
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
              std::cout << "Error." << std::endl;
              break;
          }//end inner switch

          std::cout << std::endl;
        }//end of while loop

        break;
      }//end of switch statement for robot config menu

      case 2: //Task configuration
      {
        while(1)
        {
          std::string taskname, newtaskname, nl;
          int points, tasktime;
          std::cout << "Welcome to the Task Configuration menu! Here are your options: " << std::endl;
          std::cout << taskPrompt;

          std::cin >> taskmenu;
          while(taskmenu < 1 || taskmenu > 7)
          {
            std::cout << "Please choose a valid number. Here are your choices:" << std::endl;
            std::cout << taskPrompt;

            std::cin >> taskmenu;
          }

          if(taskmenu == 7)
            break;

          switch(taskmenu)
          {
              case 1: //create a task
              {
                std::cout << "Enter the description of the task you would like to create:" << std::endl;
                getline(std::cin, nl);
                getline(std::cin, taskname);
                std::cout << "Enter the ETA of the task: " << std::endl;
                std::cin >> tasktime;
                std::cout << "Would you like to enter the amount of points this task is worth? To go with the default point system, press 0: " << std::endl;
                std::cin >>points;

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
                std::cout << "Enter the description of the task you'd like to delete: " << std::endl;
                getline(std::cin, nl);
                getline(std::cin, taskname);

                tasks.deleteTask(taskname);
                break;
              }
              case 3: //edit a task's point value
              {
                std::cout << "Enter the description of the task you'd like to change the points of: " << std::endl;
                getline(std::cin, nl);
                getline(std::cin, taskname);
                std::cout << "Enter how many points this task is worth: " << std::endl;
                std::cin >> points;

                tasks.changePoints(taskname, points);
                break;
              }
              case 4: //edit a task's description
              {
                std::cout << "Enter the description of the task you'd like to change: " << std::endl;
                getline(std::cin, nl);
                getline(std::cin, taskname);
                std::cout << "Enter the new description of the task: " << std::endl;
                getline(std::cin, nl);
                getline(std::cin, newtaskname);

                tasks.changeDesc(taskname, newtaskname);
                break;
              }
              case 5: //edit a task's eta
              {
                std::cout << "Enter the description of the task you'd like to change the ETA of: " << std::endl;
                getline(std::cin, nl);
                getline(std::cin, taskname);
                std::cout << "Enter how long this task should take to complete: " << std::endl;
                std::cin >> tasktime;

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
          std::cout << std::endl;
        } //end of while loop
        break;
      }//end of Task Config Menu
      case 3: //Look at the leaderboards;
        robots.printBoard();
        std::cout << std::endl;
        break;
      case 4: //Run Robots
      {
        robots.assignTasks(tasks);
        std::cout << "Would you like to determine the maximum wait time for all robots? Please enter in milliseconds (If you don't want to, enter 0): " << std::endl;
        std::cin >> waitTime;
        while(waitTime < -1)
        {
          std::cout << "Too low! Please enter a valid wait time." << std::endl;
          std::cin >> waitTime;
        }

        std::cout << "\nTime to run all robots! Please keep in mind that the robots will be run in REAL TIME. Sit tight until they're done!" << std::endl;
        if(waitTime == 0)
          robots.startJobs();
        else
          robots.startJobsTime(waitTime);

        break;
      }

      default:
        std::cout << "Error." << std::endl;
        break;
    }//end of general menu switch

    if(outermenu == 4)
    {
      std::string savebots;
      std::cout << "Here are the results: " << std::endl;
      robots.toStringPoints();
      std::cout << std::endl;
      std::cout << "Here is the leaderboard: " << std::endl;
      robots.saveBoard();
      robots.printBoard();

      std::cout << std::endl;
      std::cout << "Do you want to play another round? Type 'y' or 'yes' if yes, anything else otherwise: " << std::endl;
      std::cin >> lcv;

      if(lcv != "y" && lcv != "yes")
      {
        std::cout << "Before you exit, would you like to save the robots you've created? Type 'y' or 'yes' if yes, anything else otherwise: " << std::endl;
        std::cin >> savebots;
        if(savebots == "yes" || savebots == "y")
        {
          robots.saveRobots();
        }
        break;
      }

    }
  }

  std::cout << "This program uses text files to save your leaderboard, robot, and task information. You can find them under 'leaderboard.txt', 'robot.txt', and 'tasks.txt' respectively. Thank you!" << std::endl;
  return 0;
}
