#include <iostream>
#include "GreedyRobot.h"
#include <vector>
using namespace std;

static vector<string> possible_routes_;
//My approach
//1. Check if point is below, above the goal
//2. Move one step at a time while updating string pathname
//3. Keep moving recursively and keep repeating step 2.
//4. Once location is met, append string to possible routes and reset 
//5. Once all possible locations are met, print length of array and all possible routes


//Pitfalls and lost: How will it know that this combination has already been went through? 
//How to restart after meeting to the point after the first iteration.
//How to implement max distance for each move(do i use a counter and if its zero i can only move once now)
//When do i use the equaiton?



GreedyRobot::GreedyRobot() {
    max_distance_ = 0;
    robot_x_ = 0;
    robot_y_ = 0;
    treasure_x_ = 0; 
    treasure_y_ = 0;
    

}


GreedyRobot::GreedyRobot(int dis, int rX, int rY, int tX, int tY) {
    max_distance_ = dis;
    robot_x_ = rX;
    robot_y_ = rY;
    treasure_x_ = tX;
    treasure_y_ = tY;
    
}

bool GreedyRobot::CheckLocations(int rX, int rY, int tX, int tY) {
    if(rX == tX && tX == tY) 
    {
        return true;
    }
    else 
    {
        return false;
    }   

}


int GreedyRobot::CreatePath(int rX, int rY, string& cur_path ) {

    //base case
    if(CheckLocations(rX, rY, treasure_x_, treasure_y_)) 
    {
        possible_routes_.push_back(cur_path);
        return 1;
    }


    //Create NEWS functions and 

}





