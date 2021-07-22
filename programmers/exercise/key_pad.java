//https://vprog1215.tistory.com/114

class Solution {
 
    private int mDRightX = 0;
    private int mDRightY = 0;
    
    private int mDLeftX = 0;
    private int mDLeftY = 0;
  
    private int mTargetX = 0;
    private int mTargetY = 0;
  
    private int [][] keyPad = { {3,1}, //0
                                {0,0}, //1
                                {0,1}, //2
                                {0,2}, //3
                                {1,0}, //4
                                {1,1}, //5
                                {1,2}, //6
                                {2,0}, //7
                                {2,1}, //8
                                {2,2}, //9
                               };
        
    public int getLength(int x, int y, int dx, int dy) {
        int length = Math.abs((x-dx)) + Math.abs((y-dy));
        return length;
    }
    
    public String solve(int number, String hand) {
        int leftHandCount = getLength(keyPad[number][0], keyPad[number][1], mDLeftX, mDLeftY);
        int righthandCount = getLength(keyPad[number][0], keyPad[number][1], mDRightX, mDRightY);
        
        
        boolean isLeft = false;
        
        if(number ==1 || number == 4 || number ==7) {
            isLeft = true;
        } else if(number == 3 || number == 6 || number == 9) {
            isLeft = false;
        } else {
            if (leftHandCount < righthandCount) {
                isLeft = true;
            } else if(leftHandCount > righthandCount) {
                isLeft = false;
            } else {
                if(hand.equals("right")) {
                    isLeft = false;
                } else {   
                    isLeft = true;
                }
            }
        }
        
        String ret = "";
        if(isLeft) {
            ret = "L";
            mDLeftX = keyPad[number][0];
            mDLeftY = keyPad[number][1];
        } else {
            mDRightX = keyPad[number][0];
            mDRightY = keyPad[number][1];    
            ret = "R";
        }
        
        
        return ret;
    }
    
    public String solution(int[] numbers, String hand) {
        String answer = "";
        
        mDLeftX = 3;
        mDLeftY = 0;
        
        mDRightX = 3;
        mDRightY = 2;
        
        for(int i = 0; i < numbers.length; i++) 
        {
            answer += solve(numbers[i], hand);
        }
        
        return answer;
    }
}
