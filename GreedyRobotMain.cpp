#include "GreedyRobot.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
GreedyRobot newRobot(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));


//for now
string empty = "";
newRobot.CreatePath(newRobot.GetRobotX(),newRobot.GetRobotY(), empty);
cout << newRobot;
return 0;
}