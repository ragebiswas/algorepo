import java.math.BigInteger;
import java.util.Scanner;

public class p10106 {
	public static void main(String[] args) {
		BigInteger i, prod = BigInteger.ZERO;
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextBigInteger()) {
			i = sc.nextBigInteger();
			prod = sc.nextBigInteger();
			prod = prod.multiply(i);
			System.out.println(prod);
		}
		sc.close();
	}

}

