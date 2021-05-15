//https://vprog1215.tistory.com/55
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s){

    int answer = 0;
    int findCount = 0;
    int index = 0;
    int minCount = 987654321;
    string findString="";
    string compressString = "";

    for(int i =1; i <= s.size(); i++)
    {
        findCount = i;
        findString = s.substr(0,findCount);
        int matchCount = 0;
        for(int j = 0; j< s.size(); j+=findCount){
            string tmpString = s.substr(j,findCount);
            if( findString ==  tmpString ){
                matchCount++;
            } else {
                if( matchCount>1){
                    compressString += to_string(matchCount)+findString;
                } else {
                    compressString += findString;
                }
                findString = tmpString;
                j-=findCount;
                matchCount = 0;
            }
        }

        if( matchCount>1){
            compressString += to_string(matchCount)+findString;
        } else{
            compressString+=findString;
        }
        
        if( compressString.size() < minCount ){
            minCount = compressString.size();
        }
        compressString="";
    }
    answer = minCount;
    return answer;
}
