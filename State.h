//
// Created by tsamos on 20/3/2019.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#define WIDTH  3
#define HEIGHT 3

using namespace std;



class State {
 private:

     int free_x,free_y;
     vector <string> path;

 public:
    int board[WIDTH][HEIGHT];
     State(int table[HEIGHT][WIDTH ]);
     State();

     bool setFree(int x ,int y );
     bool goUp(State &n);
     bool goDown(State &n);
     bool goLeft(State &n);
     bool goRight(State &n);
     int  getFreeX();
     int  getFreeY();
     friend bool operator< (const State& a,const State& o);
     string toString()const ;
     bool operator==(const State& o) const ;
     string getPath();
     State operator= (State o);

     vector <State> expand();



};


#endif //UNTITLED_BOARD_H
