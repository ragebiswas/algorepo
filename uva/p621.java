import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ncases = sc.nextInt();
        while (ncases-- > 0) {
            String s = sc.next();
            s = s.trim();
            if (s.endsWith("35")) {
                System.out.println("-");
            } else if (s.startsWith("9") && s.endsWith("4")) {
                System.out.println("*");
            } else if (s.startsWith("190")) {
                System.out.println("?");
            } else {
                System.out.println("+");
            }
        }
        sc.close();
    }
}
