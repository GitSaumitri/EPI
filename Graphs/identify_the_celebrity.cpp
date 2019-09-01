/* 19.1 Identify the celebrity
 *
 *
 * Input: F be an nxn boolean 2D array representing the "knows" relation for
 * n people - F[a][b] is true if and only if a knows b.
 *
 *
 *g++ -std=c++11 -o identify_the_celebrity identify_the_celebrity.cpp
 */ 

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int CelebrityFinding1(const vector<deque<bool>>& F){
    //start checking the relation from F[0][1]
    int i=0,j=1;

    while(j<F.size()){
        if(F[i][j]){
            i = j++; // all candidates j' < j are not celebrity candidate
        }else { //F[i][j] == false
            ++j; //i is still celebrity candidate but j is not
        }
    }

    return i;
}

int CelebrityFinding(const vector<vector<bool>>&F){
    //start checking the relation from F[0][1]
    int i=0,j=1;

    while(j<F.size()){
        if(F[i][j]){
            i = j++; // all candidates j' < j are not celebrity candidate
        }else { //F[i][j] == false
            ++j; //i is still celebrity candidate but j is not
        }
    }

    return i;
}

int main(){

    vector<vector<bool>> F = {{1,0,0,0,1},
                             {0,1,0,0,1},
                             {0,0,1,0,1},
                             {0,0,0,1,1},
                             {0,0,0,0,1}};

    printf("Celebrity: %d\n",CelebrityFinding(F));
    return 0;
}
