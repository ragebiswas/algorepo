import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigInteger p;
        int n;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            n = sc.nextInt();
            p = sc.nextBigInteger();
            solve(n, p);
        }
        sc.close();
    }

    private static void solve(int n, BigInteger p) {
        // find k such that k^n == p
        int k_lo = 1, k_hi = 1000000000, k_mid;
        while (k_lo <= k_hi) {
            k_mid = (k_lo + k_hi) / 2;
            BigInteger P = BigInteger.valueOf(k_mid).pow(n);
            if (P.equals(p)) {
                System.out.println(k_mid);
                break;
            }
            if (P.compareTo(p) < 0) {
                k_lo = k_mid + 1;
            }
            else {
                k_hi = k_mid - 1;
            }
        }
    }

}
