import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long sum = 0;

        for (int i = 1; i <= N; i++) {
            long term = (long) i * i * i; // i^3
            if (i % 2 == 0) {
                sum += term;  // even i → +i^3
            } else {
                sum -= term;  // odd i → -i^3
            }
        }

        System.out.println(sum);
    }
}