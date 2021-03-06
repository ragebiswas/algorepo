import java.math.BigInteger;
import java.util.Scanner;

class p465 {

	public static void main(String[] args) {
		BigInteger MAX = BigInteger.valueOf(Integer.MAX_VALUE);
		Scanner scanner = new Scanner(System.in);
		BigInteger b1, b2, b3;
		String op;
		while (scanner.hasNextLine()) {
			String nextLine = scanner.nextLine();
			Scanner sc = new Scanner(nextLine);
			b1 = sc.nextBigInteger();
			op = sc.next();
			b2 = sc.nextBigInteger();
			sc.close();
			System.out.println(nextLine);
			if (b1.compareTo(MAX) > 0) {
				System.out.println("first number too big");
			}
			if (b2.compareTo(MAX) > 0) {
				System.out.println("second number too big");
			}
			b3 = (op.equals("+") ? b1.add(b2) : b1.multiply(b2));
			if (b3.compareTo(MAX) > 0) {
				System.out.println("result too big");
			}
		}
		scanner.close();
	}
}
