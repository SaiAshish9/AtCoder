import java.util.*;

public class Main {
    static final int MAX_BIT = 30; 
    
    static class TrieNode {
        TrieNode[] child = new TrieNode[2];
        int count = 0;
    }

    static void insert(TrieNode root, int num) {
        TrieNode node = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (node.child[b] == null) node.child[b] = new TrieNode();
            node = node.child[b];
            node.count++;
        }
    }

    static int queryMinXOR(TrieNode node, int x) {
        int res = 0;
        for (int i = MAX_BIT; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (node.child[b] != null && node.child[b].count > 0) {
                node = node.child[b];
            } else {
                node = node.child[1 - b];
                res |= (1 << i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) A[i] = sc.nextInt();

        TrieNode root = new TrieNode();
        for (int a : A) insert(root, a);

        long sum = 0;
        for (int x = 0; x < M; x++) {
            sum += queryMinXOR(root, x);
        }

        System.out.println(sum);
    }
}
