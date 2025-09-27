import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), Q = sc.nextInt();

        // Build string of first N uppercase letters
        char[] s = new char[N];
        for (int i = 0; i < N; i++) s[i] = (char)('A' + i);

        // Bubble sort using interactive queries
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                System.out.println("? " + s[j] + " " + s[j + 1]);
                System.out.flush();
                String ans = sc.next();
                if (ans.equals(">")) {
                    char temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }

        // Output the final sorted string
        System.out.print("! ");
        for (int i = 0; i < N; i++) System.out.print(s[i]);
        System.out.println();
        System.out.flush();
        System.exit(0);
    }
}
