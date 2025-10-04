import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String X = sc.next();
        String Y = sc.next();

        Map<String, Integer> order = new HashMap<>();
        order.put("Ocelot", 1);
        order.put("Serval", 2);
        order.put("Lynx", 3);

        if (order.get(X) >= order.get(Y)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
