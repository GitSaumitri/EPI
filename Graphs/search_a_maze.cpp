/* 19.2 Search a maze (Page:243)
 *
 * Input: Given 2D array of black and white entries representing a maze with
 * designated entries and exit points, find the entrance to the exit, if one
 * exists.
 * 
 * g++ -std=c++11 -o search_a_maze search_a_maze.cpp
 */
#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define W WHITE
#define B BLACK
typedef enum { WHITE, BLACK } Color;
struct Coordinate {
    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }

    int x,y;
};

// check cur is within maze and is a white pixel
bool IsFeasible(const Coordinate& cur, const vector<vector<Color>>& maze){
    return cur.x >= 0 && cur.x < maze.size() && 
        cur.y >= 0 && cur.y < maze[cur.x].size() &&
        maze[cur.x][cur.y] == WHITE;
}

// Perform DFS to find a feasible path
bool SearchMazeHelper(const Coordinate& cur, const Coordinate& e, 
        vector<vector<Color>> *maze, vector<Coordinate> *path){

    if(cur == e){
        return true;
    }

    const array<array<int, 2>, 4> kShift = {{{0,1},{0,-1},{1,0},{-1,0}}};
    for (const array<int, 2>& s: kShift){
        Coordinate next{cur.x + s[0], cur.y +s[1]};
        if(IsFeasible(next, *maze)){
            (*maze)[next.x][next.y] = BLACK;
            path->emplace_back(next);
            if(SearchMazeHelper(next, e, maze, path)){
                    return true;
            }
            path->pop_back();
        }
    }
    return false;
}

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s, const Coordinate &e) {
    vector<Coordinate> path;
    maze[s.x][s.y] = BLACK;
    path.emplace_back(s);
    if(!SearchMazeHelper(s, e, &maze, &path)){
        path.pop_back();
    }
    return path;
}

int main(){

  /*    vector<vector<Color>> maze = {{1,0,0,0,0,0,1,1,0,0},
                             {0,0,1,0,0,0,0,0,0,0},
                             {1,0,1,0,0,1,1,0,1,1},
                             {0,0,0,1,1,1,0,0,1,0},
                             {0,1,1,0,0,0,0,0,0,0},
                             {0,1,1,0,0,1,0,1,1,0},
                             {0,0,0,0,1,1,1,0,1,1},
                             {1,0,1,0,1,0,1,0,0,0},
                             {1,0,1,1,0,0,0,1,1,1},
                             {0,0,0,0,0,0,0,1,1,0}}; */
      vector<vector<Color>> maze = {{B,W,W,W,W,W,B,B,W,W},
                             {W,W,B,W,W,W,W,W,W,W},
                             {B,W,B,W,W,B,B,W,B,B},
                             {W,W,W,B,B,B,W,W,B,W},
                             {W,B,B,W,W,W,W,W,W,W},
                             {W,B,B,W,W,B,W,B,B,W},
                             {W,W,W,W,B,B,B,W,B,B},
                             {B,W,B,W,B,W,B,W,W,W},
                             {B,W,B,B,W,W,W,B,B,B},
                             {W,W,W,W,W,W,W,B,B,W}}; 
      vector<vector<Color>> maze1 = {{B,W,W,W,W,W,B,B,W,W},
                             {W,W,B,W,W,W,W,W,W,W},
                             {B,W,B,W,W,B,B,W,B,B},
                             {W,W,W,B,B,B,W,W,B,W},
                             {W,B,B,W,W,W,W,W,W,W},
                             {W,B,B,W,W,B,W,B,B,W},
                             {W,W,W,W,B,B,B,W,B,B},
                             {B,W,B,W,B,W,B,W,W,W},
                             {B,B,B,B,W,W,W,B,B,B},
                             {W,W,W,W,W,W,W,B,B,W}}; 
    Coordinate start{9,0};
    Coordinate end{0,9};
    Coordinate temp;
    int i=0;
    printf("Searched Maze Path:\n");
    vector<Coordinate> path = SearchMaze(maze1,start,end);
    if(path.size()==0){
        cout << "There is no path from start to end\n";
        return 0;
    }
    for (std::vector<Coordinate>::iterator it = path.begin() ; it != path.end(); ++it){
        temp = *it;
        std::cout << '(' << temp.x << ','<< temp.y << ')';
    }
    std::cout << '\n';
    return 0;
}
