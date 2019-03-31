//
// Created by tsamos on 20/3/2019.
//

#include "State.h"



State::State(int table[HEIGHT][HEIGHT]) {

    for(int i=0; i<WIDTH; i++){
        for(int j=0;j<WIDTH;j++){
            board[i][j]=table[i][j];
            if(board[i][j]==-1){
                free_x=i;
                free_y=j;
            }
        }
    }

}

State::State() {

}


bool State::setFree(int x, int y) { }
string State ::getPath() {
    unsigned i;
    string s;
    if (path.size()>0)
    {
        for (i=0;i<path.size()-1;i++)
            s+=path.at(i)+", ";
        s+=path.at(i)+ "\n";
    }
    return s;
}


bool State::goDown(State &n) {
    if( free_x<HEIGHT-1){
        n=*this;
        n.board[n.free_x][n.free_y]= n.board[n.free_x+1][n.free_y];
        n.free_x++;
        n.board[n.free_x][n.free_y]=-1;
        n.path.push_back("DOWN");
        return true;
    }
    return false;
}
bool State::goLeft(State &n) {
    if(free_y>0){
        n=*this;
        n.board[n.free_x][n.free_y]=n.board[n.free_x][n.free_y-1];
        n.free_y--;
        n.board[n.free_x][n.free_y]=-1;
        n.path.push_back("LEFT");
        return true;

    }
    return false;
}
bool State::goRight(State &n) {
    if (free_y < WIDTH-1) {
        n=*this;
        n.board[n.free_x][n.free_y]= n.board[n.free_x][n.free_y+1];
        n.free_y++;
        n.board[n.free_x][n.free_y]=-1;
        n.path.push_back("RIGHT");
        return true;
    }
    return false;
}
bool State::goUp(State &n) {
    if(free_x>0){
        n=*this;
        n.board[n.free_x][n.free_y]= n.board[n.free_x-1][n.free_y];
        n.free_x--;
        n.board[n.free_x][n.free_y]=-1;
        n.path.push_back("Up");
        return true;
    }
    return false;
}
int State::getFreeX() { return free_x;}
int State::getFreeY() { return free_y;}

bool operator< (const State& a,const State& o)
{
    return (a.toString() < o.toString());
}
string State::toString () const
{
    stringstream ot;
    ot << free_x<<"-"<<free_y<<"-";
    for(int i = 0; i<WIDTH;i++){
        for(int j=0; j<HEIGHT; j++){
            ot<<board[i][j]<<"-";
        }
    }
    return ot.str();
}
State State::operator= (State o)
{
    for(int i = 0; i<WIDTH;i++){
        for(int j=0; j<HEIGHT; j++){
            (board[i][j] = o.board[i][j]);
        }
    }
    free_y= o.free_y;
    free_x = o.free_x;
    path = o.path;
    return *this;
}

bool State::operator==(const State &o) const {
    if(free_y!=o.free_y ||free_x != o.free_y){
        return false;
    }
    for(int i = 0; i<WIDTH;i++){
        for(int j=0; j<HEIGHT; j++){
            if(board[i][j] != o.board[i][j])
                return false;
        }
    }
    return true;
}


vector <State> State::expand()
{
    vector <State> children;
    State child;

    if (goUp(child))
        children.push_back(child);
    if (goDown(child))
        children.push_back(child);
    if (goLeft(child))
        children.push_back(child);
    if (goRight(child))
        children.push_back(child);

    return children;
}
