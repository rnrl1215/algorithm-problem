//https://vprog1215.tistory.com/117?category=993734

import java.util.*;

class Solution {
    
    public int solve(int[] numbers, int target, int sum, int idx) {

        if (idx == numbers.length) {
           if(sum == target)  {
                return 1;    
            } else  {
                return 0;
            }
        }
        
       
        int result = 0;        
        result += solve(numbers, target, sum+numbers[idx], idx+1);
        result += solve(numbers, target, sum-numbers[idx], idx+1);
        return result;
    }
    
    public int solution(int[] numbers, int target) {

        int answer = 1;
 
        answer = solve(numbers, target, numbers[0], 1) + solve(numbers, target, -numbers[0], 1);

        return answer;
    }
}
