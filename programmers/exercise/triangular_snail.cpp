#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    vector<char> check;
    for(int i = 0; i < s.size(); i ++ ){
        if( s.at(i) == '('){
            check.push_back(s.at(i));
        } else if (s.at(i) == ')')  {
            if(check.empty()){
                answer = false;
                break;
            }
            check.pop_back();
        }
    }

    if( check.size() != 0 ){
        answer = false;
    }
    
    return answer;
}
