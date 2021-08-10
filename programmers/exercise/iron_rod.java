//https://vprog1215.tistory.com/154


import java.util.*;


public class Main {
    public static void main (String[] args) {
         Scanner input = new Scanner(System.in);
         String str = input.next();
         str = str.replace("()","C");
         
         Stack<Character> stack = new Stack<>();
         
         int count = 0;
         
         for(int i = 0; i < str.length(); i++) {
             if (Character.compare(str.charAt(i), '(') == 0) {
                 stack.push(str.charAt(i));
             } else if (Character.compare(str.charAt(i), ')') == 0) {
                 stack.pop();
                 count++;
             } else {
                 count += stack.size();
             }
         }
         
         System.out.println(count);
    }
}
