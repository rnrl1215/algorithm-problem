import java.util.Scanner;

public class Ex2292 {

	public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
    
        int n = 0;
        n = sc.nextInt();

        int dist = 1;
        int rangeStart = 1;
        int roomCount = 1;

        while (true) {

            rangeStart = rangeStart + roomCount;

            if (n < rangeStart) {
                break;
            }

            roomCount = dist * 6;
            dist++;
        }
        System.out.print(dist);
    }
}
