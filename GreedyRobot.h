#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
#include <vector>
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
        vector <string> possible_routes_;


    public:     
        GreedyRobot();
        GreedyRobot(int dis, int rX, int rY, int tX, int tY);
        bool CheckLocations(int rX, int rY, int tX, int tY);
        void CreatePath(int rX, int rY, const string& cur_path);



        //setter and getters 
        int GetRobotX();
        int GetRobotY();
        int GetTreasureX();
        int GetTreasureY();

        //might be unnecessary
        string GetPath();

        //to make things easier i think i will operator overload
        //my robot object
        friend ostream& operator<<(ostream& out, GreedyRobot& other_robot); 

        //Probably wont use these methods
        void MoveNorth(int dis, int rX, int rY, int tX, int tY);
        void MoveEast(int dis, int rX, int rY, int tX, int tY);
        void MoveWest(int dis, int rX, int rY, int tX, int tY);
        void MoveSouth(int dis, int rX, int rY, int tX, int tY);
        




    
};
#endif 


