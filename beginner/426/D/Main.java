import java.util.*;

public class Main {

    public static int solve(int n, String s) {
        int[] maxBlockLength = new int[2]; // max length of consecutive 0s and 1s
        int[] totalCount = new int[2];     // total count of 0s and 1s

        int left = 0;
        while (left < n) {
            int right = left + 1;
            while (right < n && s.charAt(left) == s.charAt(right)) {
                right++;
            }

            int digit = s.charAt(left) - '0';
            int length = right - left;

            maxBlockLength[digit] = Math.max(maxBlockLength[digit], length);
            totalCount[digit] += length;

            left = right;
        }

        int ans = 2 * n;
        for (int i = 0; i < 2; i++) {
            // (total of i minus max consecutive i) * 2 + total of other digit
            ans = Math.min(ans, (totalCount[i] - maxBlockLength[i]) * 2 + totalCount[i ^ 1]);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            String s = sc.next();
            System.out.println(solve(n, s));
        }
        sc.close();
    }
}
