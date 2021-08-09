//https://vprog1215.tistory.com/152

class Solution {
    
	
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Arrays.sort(phone_book);
        
        for(int i = 0; i < phone_book.length-1; i++) {
            if(phone_book[i+1].indexOf(phone_book[i]) == 0) {
                answer = false;
                break;
            }
        }
        

        return answer;
    }
}
