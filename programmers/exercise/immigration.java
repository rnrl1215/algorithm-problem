//https://vprog1215.tistory.com/126?category=993734


import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        
        Arrays.sort(times);

        // 최소 시간
        long minTime = 1;

        // 최대 시간
        long maxTime = (long)times[times.length-1] * n;


        // 시작시간 보다 최소시간이 클때만 반복
        while(minTime <= maxTime) {

            // 시간의 중간값 계산 이분탐색
            long midTime = (minTime+maxTime)/2;

            // 검사한 사람의 수
            long examinedPeople = 0;

            // mid 타임 에서 얼마나 검사 할수 있는지 체크
            for (int i = 0; i < times.length; i++) {
                examinedPeople += midTime/times[i];
            }

            // 검사받은 수가 검사받아야할 사람보다 적으면 시간대 증가
            if ( n > examinedPeople ) {
                minTime = midTime +1;

            // 검사받을 수가 검사받아야할 사람보다 작거나 같으면 
            // 더 작은 값에서 검사 수행
            } else {
                maxTime = midTime -1;
                answer = midTime;
            }
        }

        return answer;
    }
}
