//https://vprog1215.tistory.com/121

import java.util.*;


class Solution
{
    public int solution(String s)
    {
        int answer = -1;
        Stack<Character> stack = new Stack<>();
        
        String tmpString = s;
        for (char c : tmpString.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == c) 
            {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        
        
        if(stack.isEmpty()) {
            answer = 1;
        } else {
            answer = 0;
        }
        
        return answer;
    }
}
