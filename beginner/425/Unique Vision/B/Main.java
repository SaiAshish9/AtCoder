import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        boolean[] used = new boolean[N + 1];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            if (A[i] != -1) {
                if (used[A[i]]) { 
                    System.out.println("No");
                    return;
                }
                used[A[i]] = true;
            }
        }

        Queue<Integer> unused = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (!used[i]) unused.add(i);
        }

        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            if (A[i] != -1) {
                P[i] = A[i];
            } else {
                P[i] = unused.poll();
            }
        }

        System.out.println("Yes");
        for (int i = 0; i < N; i++) {
            System.out.print(P[i] + (i == N - 1 ? "\n" : " "));
        }
    }
}
