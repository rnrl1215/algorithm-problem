import java.util.*;
import java.util.LinkedList;
import java.util.Queue; 
import java.util.Collections;

class Solution {
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        int ascii2 = (65+location);
        String targetName = new Character((char) ascii2).toString();
        
        List<Integer> priorityQue = new ArrayList<>(priorities.length);
        List<String> printList = new ArrayList<>(priorities.length);
        List<Integer> sortedQue = new ArrayList<>(priorities.length);
        
        for(int i = 0; i < priorities.length; i++) {
            priorityQue.add(priorities[i]);
            sortedQue.add(priorities[i]);
            
            int ascii = (65+i);
            
            String str = new Character((char) ascii).toString();
            printList.add(str);
        }
        
        Collections.sort(sortedQue,  Collections.reverseOrder());
        
        int printedNum = 0;
        while(!priorityQue.isEmpty()) {
            
            int prioty = priorityQue.get(0);
            int sorted = sortedQue.get(0);
            String printName = printList.get(0);
            
            if(prioty == sorted) {
                
                printedNum ++;
                priorityQue.remove(0);
                sortedQue.remove(0);
                printList.remove(0);
                
                if (targetName.equals(printName)) {
                    answer = printedNum;
                    break;
                }
                
            } else {
                priorityQue.remove(0);
                priorityQue.add(prioty);
                printList.remove(0);
                printList.add(printName);
            }
        }
  
        return answer;
    }
}
