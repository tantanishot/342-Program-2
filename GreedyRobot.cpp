#include <iostream>
#include "GreedyRobot.h"
#include <vector>
using namespace std;

//static vector<string> possible_routes_;
//My approach
//1. Check if point is below, above the goal
//2. Move one step at a time while updating string pathname
//3. Keep moving recursively and keep repeating step 2.
//4. Once location is met, append string to possible routes and reset 
//5. Once all possible locations are met, print length of array and all possible routes


//Pitfalls/lost and questions: 
//How will it know that this combination path has already been went through? 
//In my code you have: base case ==, you can go NEWS          
//How to restart after meeting to the treasure after the first iteration.
//How to implement max distance for each move(do i use a counter and if its zero i can only move once now)(CHECK)



GreedyRobot::GreedyRobot() {
    max_distance_ = 0;
    robot_x_ = 0;
    robot_y_ = 0;
    treasure_x_ = 0; 
    treasure_y_ = 0;
    
    maxS_ = max_distance_;
     maxW_ = max_distance_;
      maxE_ = max_distance_;
       maxN_ = max_distance_;
    

}


    
GreedyRobot::GreedyRobot(int dis, int rX, int rY, int tX, int tY) {
    max_distance_ = dis;
    robot_x_ = rX;
    robot_y_ = rY;
    treasure_x_ = tX;
    treasure_y_ = tY;
    //Represents maximum moves for each direction
    maxS_ = max_distance_;
     maxW_ = max_distance_;
      maxE_ = max_distance_;
       maxN_ = max_distance_;
    
}



    int GreedyRobot::GetRobotX() {
        return this->robot_x_;
    }
    int GreedyRobot::GetRobotY(){
        return this->robot_y_;
    }
    int GreedyRobot::GetTreasureX() {
        return this->treasure_x_;
    }
    int GreedyRobot::GetTreasureY() {
        return this->treasure_y_;
    }
    

bool GreedyRobot::CheckLocations(int rX, int rY, int tX, int tY) {
    if(rX == tX && rY == tY) 
    {
        return true;
    }
    else 
    {
        return false;
    }   

}

 ostream& operator<<(ostream& out, GreedyRobot& other_robot) {  
    if(other_robot.possible_routes_.size() == 0) 
    {
        cout << "There are no possible routes" << endl;
    }
    else 
    {
    for(int i = 0; i < other_robot.possible_routes_.size(); i++) {
        out << other_robot.possible_routes_[i] << endl;
    }   
    out << "Number of paths: " << other_robot.possible_routes_.size() << endl;
    }
    return out;
 }



void GreedyRobot::CreatePath(int rX, int rY, const string& cur_path) {
    //base case
    if(CheckLocations(rX, rY, treasure_x_, treasure_y_)) 
    {
        //cout << "Reached treasure at (" << rX << ", " << rY << ")" << endl;
        possible_routes_.push_back(cur_path);
        return;
    }
    //Create NEWS functions and 
    //if robot is below target move up
    if(rY < treasure_y_ && maxN_ != 0) 
    {
        maxN_--;
        //resets maximum moves for the other directions back to max distance
        maxW_ = max_distance_;
        maxE_ = max_distance_;
        maxS_ = max_distance_;
        CreatePath(rX, rY + 1, cur_path + "N");
    }
     if(rY > treasure_y_ && maxS_ != 0) 
    {
        maxS_--;
        //resets maximum moves for the other directions back to max distance
        maxW_ = max_distance_;
        maxE_ = max_distance_;
        maxN_ = max_distance_;
        CreatePath(rX, rY - 1, cur_path + "S");
    }
    //if robot is abovetarget move down
    if(rX < treasure_x_ && maxE_ != 0) 
    {
        maxE_--;
        //resets maximum moves for the other directions back to max distance
        maxW_ = max_distance_;
        maxN_ = max_distance_;
        maxS_ = max_distance_;
        CreatePath(rX + 1, rY, cur_path + "E");
    }
    if(rX > treasure_x_ && maxW_ != 0) 
    {
        maxW_--;
        //resets maximum moves for the other directions back to max distance
        maxE_ = max_distance_;
        maxN_ = max_distance_;
        maxS_ = max_distance_;
        CreatePath(rX - 1, rY, cur_path + "W");
    }
    //?
    return;
}





