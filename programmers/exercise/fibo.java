//https://vprog1215.tistory.com/157


class Solution {
    
    private long []dp;
   
    
    public long fibo(int n) {
        if(dp[n] != 0) {
            return dp[n];
        }
        dp[n] = (fibo(n-1) + fibo(n-2)); 
        return dp[n] % 1234567;
    }
    
    
    public int solution(int n) {
        int answer = 0;
        dp = new long[1000001];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        long answer1 = fibo(n);
        answer = (int)answer1;
        return answer;
    }
}
