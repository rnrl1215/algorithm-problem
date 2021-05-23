package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int answer = 0;

        for(int i = 10; i<N; i ++)
        {
            int divSum = i;
            int nmg = i;
            while (nmg != 0) {
                divSum += nmg%10;
                nmg /= 10;
            }

            if(divSum == N) {
                answer = i;
                break;
            }
        }
        System.out.println(answer);
    }
}
