#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
using namespace std;

class GreedyRobot {
    private:
        int max_distance_;
        //Each value for robot and treasure
        //represent x and y values for each object
        int robot_x_;
        int robot_y_;
        int treasure_x_;
        int treasure_y_;
        string path_names_;
        int maxN_, maxE_, maxW_, maxS_;



    public:     
        GreedyRobot();
        GreedyRobot(int dis, int rX, int rY, int tX, int tY);
        bool CheckLocations(int rX, int rY, int tX, int tY);
        int CreatePath(int rX, int rY, string cur_path);
        void MoveNorth(int dis, int rX, int rY, int tX, int tY);
        void MoveEast(int dis, int rX, int rY, int tX, int tY);
        void MoveWest(int dis, int rX, int rY, int tX, int tY);
        void MoveSouth(int dis, int rX, int rY, int tX, int tY);
        




    
};
#endif 


