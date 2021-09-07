//https://vprog1215.tistory.com/205

import java.util.*;


class Solution {
    public int[] solution(String s) {
    
        s = s.replace("{","");
        s = s.replace("}}","");
        System.out.println(s);
        String []splitArray = s.split("}");
        
        List<int[]> setIntList = new ArrayList<>();
    
        Arrays.sort(splitArray, (s1,s2)-> {return s1.length()-s2.length(); } );    
        
        for(int i = 0; i < splitArray.length; i++) {
            String []tuple = splitArray[i].split(",");
            int []tupleArray = Arrays.stream(tuple).filter(s2->!s2.isEmpty()).mapToInt(Integer::parseInt).toArray();
            setIntList.add(tupleArray);
        }
        
        
        List<Integer> answerList = new ArrayList<>();
        for(int i = 0; i <setIntList.size(); i++) {
            int [] arr = setIntList.get(i);
            for(int j = 0; j < arr.length; j++) {
                if(!answerList.contains(arr[j]))
                {
                    answerList.add(arr[j]);
                }
            }
        }
        
        int []answer = answerList.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}
