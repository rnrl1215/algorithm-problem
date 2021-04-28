package com.company;
import java.util.Scanner;
public class Main {

    static int answer;

    public static void combination(int n, int r, int index, int target, int []cards, int []choice, int goalNum) {
        if (r == 0) {
            int tmp = 0;
            for (int i = 0; i < index; i++) {
                tmp+=choice[i];
            }

            if (tmp <= goalNum) {
                if(answer <= tmp) {
                    answer = tmp;
                }
            }
        } else if (target == n) {
            return;
        } else {

            choice[index] = cards[target];
            combination(n, r - 1, index + 1, target + 1, cards, choice, goalNum);
            combination(n, r, index, target + 1, cards, choice, goalNum);
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        answer = -1;

        int cardNum = sc.nextInt();
        int goalNum = sc.nextInt();
        int choiceNum = 3;

        int []cardArr = new int[cardNum];
        int []choiceArr = new int[cardNum];

        for(int i=0; i<cardNum; i++) {
            cardArr[i] = sc.nextInt();
        }

        combination(cardNum, choiceNum, 0, 0, cardArr, choiceArr, goalNum);

        System.out.println(answer);
    }
}
