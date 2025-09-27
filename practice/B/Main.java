import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    // Interactive comparison: returns true if char1 < char2
    static boolean ask(char char1, char char2) {
        System.out.println("? " + char1 + " " + char2);
        System.out.flush();
        String response = sc.next();
        return response.equals("<");
    }

    static List<Character> mergeSortInteractive(List<Character> arr) {
        if (arr.size() <= 1)
            return arr;

        int mid = arr.size() / 2;
        List<Character> left = mergeSortInteractive(arr.subList(0, mid));
        List<Character> right = mergeSortInteractive(arr.subList(mid, arr.size()));
        return mergeInteractive(left, right);
    }

    static List<Character> mergeInteractive(List<Character> left, List<Character> right) {
        List<Character> result = new ArrayList<>();
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (ask(left.get(i), right.get(j))) {
                result.add(left.get(i++));
            } else {
                result.add(right.get(j++));
            }
        }
        while (i < left.size()) result.add(left.get(i++));
        while (j < right.size()) result.add(right.get(j++));
        return result;
    }

    public static void main(String[] args) {
        int N = sc.nextInt(), Q = sc.nextInt();
        List<Character> initialChars = new ArrayList<>();
        for (int i = 0; i < N; i++)
            initialChars.add((char)('A' + i));
        List<Character> sortedChars = mergeSortInteractive(initialChars);
        System.out.print("! ");
        for (char c : sortedChars) System.out.print(c);
        System.out.println();
        System.out.flush();
        System.exit(0);
    }
}
