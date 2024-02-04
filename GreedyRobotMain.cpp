#include "GreedyRobot.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {  
//only 6 arguments are allowed in this case
if(argc != 6)  
{
    cout << "Int Arguments must be 5 integers exact";
}
else 
{
GreedyRobot newRobot(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
string empty = "";
newRobot.CreatePath(newRobot.GetRobotX(),newRobot.GetRobotY(), empty);
//operator overload robot movement
cout << newRobot;
return 0;
}

}