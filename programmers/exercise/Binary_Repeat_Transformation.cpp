//https://vprog1215.tistory.com/82

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void solve(int size, int &delCnt, int &cnvCnt );

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<int> binVector;
    int delCnt = 0;
    int cnvCnt = 1;
    
    for(int i = 0 ; i < s.size(); i++){
        if( s.at(i) == '0'){
            delCnt++;
        } else {
            binVector.push_back(1);
        }
    }
    solve(binVector.size(), delCnt, cnvCnt);
    answer.push_back(cnvCnt);
    answer.push_back(delCnt);
    return answer;
}

void solve(int size, int &delCnt, int &cnvCnt)
{
    if(size == 1){
        return;
    }
    
    int nmg = 0;
    int val = size;
    int binaryCnt = 0;
    while(val != 0){
        nmg = val%2;
        val = val/2;
        if(nmg == 1){
            binaryCnt++;
        } else {
            delCnt++;
        }
    }
    
    cnvCnt++;
    solve(binaryCnt,delCnt,cnvCnt);
}
