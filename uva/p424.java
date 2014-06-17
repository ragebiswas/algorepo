import java.math.BigInteger;
import java.util.Scanner;

/**
 * P424: UVA
 * 
 * @author Rajorshi
 * 
 */
class p424 {

	public static void main(String[] args) {
		BigInteger i, sum = BigInteger.ZERO;
		Scanner sc = new Scanner(System.in);
		while (true) {
			i = sc.nextBigInteger();
			if (i.intValue() == 0) {
				break;
			}
			sum = sum.add(i);
		}
		sc.close();
		System.out.println(sum);
	}

}
