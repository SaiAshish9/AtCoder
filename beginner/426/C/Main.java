import java.util.*;

public class Main {
    static int[] parent;
    static int[] count;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int Q = sc.nextInt();

        parent = new int[N + 1];
        count = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            count[i] = 1;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < Q; i++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();

            int upgrades = 0;

            while (true) {
                int px = find(X); 
                if (px == Y || px > X) break;
                upgrades += count[px];
                count[Y] += count[px];
                count[px] = 0;
                parent[px] = Y; 
                if (px == 0) break; 
                X = px - 1;
            }

            sb.append(upgrades).append("\n");
        }

        System.out.print(sb);
    }
}
