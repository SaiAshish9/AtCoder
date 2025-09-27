import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int Q = sc.nextInt();
        
        long[] A = new long[N];
        long[] prefix = new long[N + 1];
        
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
            prefix[i + 1] = prefix[i] + A[i];
        }

        int offset = 0;
        StringBuilder sb = new StringBuilder();

        while (Q-- > 0) {
            int type = sc.nextInt();
            
            if (type == 1) {
                int c = sc.nextInt();
                offset = (offset + c) % N;
            } else {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;

                int realL = (offset + l) % N;
                int realR = (offset + r) % N;

                long sum;
                if (realL <= realR) {
                    sum = prefix[realR + 1] - prefix[realL];
                } else {
                    sum = (prefix[N] - prefix[realL]) + prefix[realR + 1];
                }
                
                sb.append(sum).append("\n");
            }
        }

        System.out.print(sb.toString());
    }
}
