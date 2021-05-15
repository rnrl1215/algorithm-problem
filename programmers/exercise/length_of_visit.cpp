#include <string>
#include <iostream>
using namespace std;

int nodeVal[2000][2000];
int graphMap[2000][2000];

int substitution(int x, int y){
    return  nodeVal[x][y];   
}

int solution(string dirs) {
    int answer = 0;
    int cnt = 1;
    for(int i = 0; i <= 10; i ++){
        for(int j = 0; j <= 10; j++){
            nodeVal[i][j] = cnt++;
        }
    }
 
    int x = 5 , y = 5 ;
    for(int i = 0; i < dirs.size(); i++){
        if( dirs.at(i) == 'U' ){
            if( y+1 <= 10 ){
                int curPoint = substitution(x,y+1);
                int nextPoint = substitution(x,y);
                y++;
                if(graphMap[curPoint][nextPoint] != 1){
                    answer++;
                    graphMap[curPoint][nextPoint] = 1;
                    graphMap[nextPoint][curPoint] = 1;
                } 
            }
        } else if( dirs.at(i) == 'L' ) {
            if( x-1 >= 0 ){
                int curPoint = substitution(x-1,y);
                int nextPoint = substitution(x,y);
                x--;
                if(graphMap[curPoint][nextPoint] != 1){
                    answer++;
                    graphMap[curPoint][nextPoint] = 1;
                    graphMap[nextPoint][curPoint] = 1;
                } 
            }
        } else if ( dirs.at(i) == 'R' ) {
            if( x+1 <= 10 ){
                int curPoint = substitution(x+1,y);
                int nextPoint = substitution(x,y);
                x++;
                if(graphMap[curPoint][nextPoint] != 1){
                    answer++;
                    graphMap[curPoint][nextPoint] = 1;
                    graphMap[nextPoint][curPoint] = 1;
                } 
            }
        } else if( dirs.at(i) == 'D' ) {
            if( y-1 >= 0 ){
                int curPoint = substitution(x,y-1);
                int nextPoint = substitution(x,y);
                y--;
                if(graphMap[curPoint][nextPoint] != 1){
                    answer++;
                    graphMap[curPoint][nextPoint] = 1;
                    graphMap[nextPoint][curPoint] = 1;
                } 
            }
        }
    }
    
    return answer;
}
