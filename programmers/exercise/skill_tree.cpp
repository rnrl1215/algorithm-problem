//https://vprog1215.tistory.com/78

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool checkOrderFunction(string aSkill, string aSkillTree);

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    // skill tree에서 하나씩 꺼내 가능성을 체크한다.
    for(int i = 0; i <skill_trees.size(); i++)
    {
        if( checkOrderFunction(skill, skill_trees[i]) ){
            answer++;
        }
    }
    
    return answer;
}


bool checkOrderFunction(string aSkill, string aSkillTree)
{
    
    // skill index 초기화
    int checkOrderArry[10001];
    for (int i = 0; i < aSkill.size(); i++)
    {
        checkOrderArry[i] = -1;
    }
    
    // skill tree 에서 skill의 index 찾아 넣어준다.
    for (int i = 0; i < aSkill.size(); i++)
    {
        string::size_type loc = aSkillTree.find(aSkill.at(i), 0);
        int num = loc;
        if (loc < aSkillTree.size()) {
            checkOrderArry[i] = num;
        }
    }
    
    bool notFindFlag = false;
    for (int i = 0; i < aSkill.size(); i++)
    {

        // 선행 스킬을 안찍고 다음 스킬을 찍었으면 불가
        if (notFindFlag) {
            if (checkOrderArry[i] != -1) {
                return false;
            }
        }
        
        // 해당 스킬을 스킬트리에서 못찾음.
        if (checkOrderArry[i] == -1) {
            notFindFlag = true;
            continue;
        }
        
        // 선행스킬대로 순서가 되어 있는지 검사. 다음 스킬이 존재하지 않으면 못찾았다는 걸 표시
        // 선행스킬보다 먼저 찍었는지 검사.
        // -1 이라면 다음 스킬을 안찍었다는 것을 표시
        if (checkOrderArry[i] > checkOrderArry[i+1] && i+1 < aSkill.size()) {
            if (checkOrderArry[i+1] == -1) {
                notFindFlag = true;
                continue;
            }
            return false;
        }
    }
    
    // 정상적으로 되어 있으면 true
    return true;
}
