import java.util.*;

public class Main {

    private static Map<Integer, Integer> factorize(int n) {
        Map<Integer, Integer> factors = new HashMap<>();
        for (int p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                factors.put(p, factors.getOrDefault(p, 0) + 1);
                n /= p;
            }
        }
        if (n > 1) factors.put(n, 1);
        return factors;
    }

    private static long mul(long a, long b, long mod) {
        return (a * b) % mod;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int M = sc.nextInt();

        int MAX = 5000;

        List<Integer> primes = new ArrayList<>();
        boolean[] isPrime = new boolean[MAX + 1];
        Arrays.fill(isPrime, true);

        for (int i = 2; i <= MAX; i++) {
            if (isPrime[i]) {
                primes.add(i);
                for (int j = i * 2; j <= MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int[][] factExp = new int[MAX + 1][primes.size()];
        for (int i = 2; i <= MAX; i++) {
            int x = i;
            factExp[i] = factExp[i - 1].clone();
            for (int pi = 0; pi < primes.size(); pi++) {
                int p = primes.get(pi);
                while (x % p == 0) {
                    factExp[i][pi]++;
                    x /= p;
                }
            }
        }

        StringBuilder output = new StringBuilder();

        while (T-- > 0) {
            int N = sc.nextInt();
            int[] C = new int[N];
            int sum = 0;
            for (int i = 0; i < N; i++) {
                C[i] = sc.nextInt();
                sum += C[i];
            }

            int[] exp = factExp[sum].clone();
            for (int i = 0; i < N; i++) {
                int ci = C[i];
                for (int j = 0; j < primes.size(); j++) {
                    exp[j] -= factExp[ci][j];
                }
            }

            long ans = 1;
            for (int i = 0; i < primes.size(); i++) {
                int p = primes.get(i);
                int e = exp[i];
                while (e-- > 0) ans = mul(ans, p, M);
            }

            output.append(ans % M).append('\n');
        }

        System.out.print(output);
    }
}
