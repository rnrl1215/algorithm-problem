// https://vprog1215.tistory.com/95?category=993734

#include <string>
#include <vector>

using namespace std;


bool solve(int node, vector<vector<int>> &computers) 
{
    if (!computers[node][node]) {
        return false;
    }
    
    computers[node][node] = 0;
        
    for (int i = 0; i < computers.size(); i++ ) {
        if (computers[node][i]) {
            solve(i, computers);
        }
    }
    
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(computers[i][i] && solve(i, computers)) {
            answer++;
        }
    }
    return answer;
}
