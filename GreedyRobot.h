#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
using namespace std;

class GreedyRobot {
    private:
        int max_distance_;
        int robot_x_;
        int robot_y_;
        int treasure_x_;
        int treasure_y_;
        string path_names_;



    public:     
        GreedyRobot();
        GreedyRobot(int dis, int rX, int rY, int tX, int tY);
        void CheckLocations(int dis, int rX, int rY, int tX, int tY);
        void MoveNorth(int dis, int rX, int rY, int tX, int tY);
        void MoveEast(int dis, int rX, int rY, int tX, int tY);
        void MoveWest(int dis, int rX, int rY, int tX, int tY);
        void MoveSouth(int dis, int rX, int rY, int tX, int tY);
        




    
};
#endif 


