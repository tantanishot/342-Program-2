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
           //Debug print and check all values
    //cout << "Robot" << robot_x_ << robot_y_ << endl << "Treasure" << treasure_x_ << treasure_y_;
    
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
    //cout << "Robot: (" << rX << ", " << rY << "), Treasure: (" << tX << ", " << tY << ") ";
    //cout << "Treasure_x_: " << treasure_x_ << ", Treasure_y_: " << treasure_y_ << endl;  // Debug print
    if (rX == tX && rY == tY) 
    {
        //cout << "true" << endl;
        return true;
    } else 
    {
        //cout << "false" << endl;
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
    //cout << "Current Path: " << cur_path << endl;
    //cout << "Robot Position: (" << rX << ", " << rY << ")" << endl;
    //cout << "Treasure Position: (" << treasure_x_ << ", " << treasure_y_ << ")" << endl;
        //base case
        if(CheckLocations(rX, rY, treasure_x_,treasure_y_)) 
        {
            //cout << "Reached treasure at (" << rX << ", " << rY << ")" << endl;
            if(cur_path == "") 
            {
                return;
            }
            else
            {
            possible_routes_.push_back(cur_path);
            return;
            }
           
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





