import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int e;
		BigDecimal b, r;
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			b = sc.nextBigDecimal();
			e = sc.nextInt();
			r = b.pow(e).stripTrailingZeros();
			String res = r.toPlainString();
			if (res.startsWith("0.")) {
				res = res.substring(1);
			}
			System.out.println(res);
		}
	}

}
