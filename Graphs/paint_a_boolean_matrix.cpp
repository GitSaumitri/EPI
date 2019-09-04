/* 19.3 Paint a boolean matrix (Page:345)
 *
 * Implement a routine that takes a nxm boolean array A together with an
 * entry(x,y) and flips the color of the region associated with (x,y).
 */
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<array>
using namespace std;

void FlipColor(int x,int y, vector<deque<bool>>* A_ptr){
    vector<deque<bool>>& A= *A_ptr;
    const array<array<int, 2>, 4> kDirs = {{{{0,1}},{{0,-1}},{{1,0}},{{-1,0}}}};

    const bool color = A[x][y];
    queue<pair<int, int>> q;
    A[x][y] = !color; //flips
    q.emplace(x,y);

    while(!q.empty()){
        pair<int,int> curr = q.front();
        for(const array<int,2>& dir: kDirs){
            const int next_x = curr.first + dir[0],next_y = curr.second + dir[1];
            if(next_x >= 0 && next_x < A.size() && next_y >=0 && next_y < A[next_x].size() && A[next_x][next_y]==color){
                //flip the color
                A[next_x][next_y]=!color;
                q.emplace(next_x,next_y);
            }
        }
        q.pop();
    }
}

void FlipColorDFS(int x, int y, vector<deque<bool>>* A_ptr){
    vector<deque<bool>>& A = *A_ptr;
    const array<array<int,2>,4> kDirs = {{{{0,1}},{{0,-1}},{{1,0}},{{-1,0}}}};
    const bool color = A[x][y];

    A[x][y] = !color; //flips
    for(const array<int, 2>& dir: kDirs){
        const int next_x = x + dir[0], next_y = y + dir[1];
        if(next_x >= 0 && next_x < A.size() && next_y >=0 && next_y < A[next_x].size() && A[next_x][next_y]==color){
            FlipColorDFS(next_x,next_y,A_ptr);
        }
    }
}

int main(){

    vector<deque<bool>> A = {{1,0,1,0,0,0,1,1,1,1},
                                 {0,0,1,0,0,1,0,0,1,1},
                                 {1,1,1,0,0,1,1,0,1,1},
                                 {0,1,0,1,1,1,1,0,1,0},
                                 {1,0,1,0,0,0,0,1,0,0},
                                 {1,0,1,0,0,1,0,1,1,1},
                                 {0,0,0,0,1,0,1,0,0,1},
                                 {1,0,1,0,1,0,1,0,0,0},
                                 {1,0,1,1,0,0,0,1,1,1},
                                 {0,0,0,0,0,0,0,1,1,0}};
    int start_x =4;
    int start_y =4;
    cout<< "Before Flip:\n";
    for (std::vector<deque<bool>>::iterator it = A.begin() ; it != A.end(); ++it){
        deque<bool> temp = *it;
        for (std::deque<bool>::iterator it1 = temp.begin() ; it1 != temp.end(); ++it1){
            std::cout << ' ' << *it1;
        }
        std::cout << '\n';
    }
    FlipColorDFS(start_x,start_y, &A);
    cout<< "After Flip:" << start_x << " " << start_y <<"\n";
    for (std::vector<deque<bool>>::iterator it = A.begin() ; it != A.end(); ++it){
        deque<bool> temp = *it;
        for (std::deque<bool>::iterator it1 = temp.begin() ; it1 != temp.end(); ++it1){
            std::cout << ' ' << *it1;
        }
        std::cout << '\n';
    }

}
