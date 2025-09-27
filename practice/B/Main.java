import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), Q = sc.nextInt();
        List<Character> sorted = new ArrayList<>();
        sorted.add('A');
        for (int i = 1; i < N; ++i) {
            char curr = (char)('A' + i);
            int pos = 0;
            for (int j = sorted.size() - 1; j >= 0; --j) {
                System.out.println("? " + sorted.get(j) + " " + curr);
                System.out.flush();
                String ans = sc.next();
                if (ans.equals("<")) {
                    pos = j + 1;
                    break;
                }
            }
            sorted.add(pos, curr);
        }
        System.out.print("! ");
        for (char c : sorted) System.out.print(c);
        System.out.println();
        System.out.flush();
        System.exit(0);
    }
}
