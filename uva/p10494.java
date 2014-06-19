import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String op;
		BigInteger opn1, opn2;
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			opn1 = sc.nextBigInteger();
			op = sc.next();
			opn2 = sc.nextBigInteger();
			if (op.equals("/")) {
				System.out.println(opn1.divide(opn2));
			} else {
				System.out.println(opn1.mod(opn2));
			}
		}
		sc.close();
	}
}
