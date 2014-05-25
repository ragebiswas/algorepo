// The Collatz Sequence (level 0)
#include <iostream>
using namespace std;

int main()
{
	long long int A, L, n, c = 1;
	while (cin >> A >> L) {
		n = 0;
		if (A < 0 && L < 0) {
			break;
		}
		cout << "Case " << c << ": A = " << A << ", limit = " << L << ", number of terms = ";
		while (A <= L) {
			if (A == 1) {
				n++;
				break;
			}
			if (A % 2 == 0) {
				A /= 2;
			}
			else {
				A = 3*A + 1;
			}
			n++;
		} 
		cout << n << endl;
		c++;
	}
	return 0;
}