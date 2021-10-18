    import java.util.*;

    class Solution {
        public int[] solution(int n, String[] words) {
            int[] answer = new int[2];
            ArrayList<String> checkWordList = new ArrayList<>();


            int rotateCount = 1;
            int wordCount = 1;
            int currentCount = 1 ;
            boolean isWrongWord = false;
            for(int i = 0; i < words.length-1; i++) {
                wordCount++;
                currentCount++;
                String currentWord = words[i];
                String nextWord = words[i+1];

                char curLastWord = currentWord.charAt(currentWord.length()-1);
                char nextLastWord = nextWord.charAt(0);

                checkWordList.add(currentWord);

                if (curLastWord != nextLastWord || checkWordList.contains(nextWord) ) {
                    isWrongWord = true;
                    break;
                }

                if ((wordCount % n) == 0) {
                    currentCount = 0;
                    rotateCount ++;
                }
            }

            if (isWrongWord) {
                answer[0] = currentCount;    
                answer[1] = rotateCount;
            } else {
                answer[0] = 0;    
                answer[1] = 0;
            }

            return answer;
        }
    }
