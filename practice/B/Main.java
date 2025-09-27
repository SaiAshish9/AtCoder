package practice.B;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), Q = sc.nextInt();

        List<Character> balls = new ArrayList<>();
        for (int i = 0; i < N; i++) balls.add((char)('A' + i));

        List<Character> sorted = new ArrayList<>();
        sorted.add(balls.get(0));

        for (int i = 1; i < N; i++) {
            char curr = balls.get(i);
            int left = 0, right = sorted.size();
            // Find where to insert 'curr' in 'sorted'
            while (left < right) {
                int mid = (left + right) / 2;
                System.out.println("? " + curr + " " + sorted.get(mid));
                System.out.flush();
                String ans = sc.next();
                if (ans.equals("<")) {
                    left = mid + 1; // curr is lighter
                } else {
                    right = mid; // curr is heavier or equal
                }
            }
            sorted.add(left, curr);
        }
        // Output the final answer
        System.out.print("! ");
        for (char c : sorted) System.out.print(c);
        System.out.println();
        System.out.flush();
        System.exit(0);
    }
}
