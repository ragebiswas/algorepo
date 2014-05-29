// Automatic poetry (Level 1)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int nc;
	cin >> nc;
	cin.ignore(256, '\n');
	string l1, l2;
	while (nc--) {
		getline(cin, l1);
		getline(cin, l2);
		int s2_start = -1, s2_end = -1;
		int s4_start = -1, s4_end = -1;
		string s1, s2, s3, s4, s5;
		s2_start = l1.find_first_of('<');
		s2_end = l1.find_first_of('>');
		s4_start = l1.find_last_of('<');
		s4_end = l1.find_last_of('>');
		s1 = l1.substr(0, s2_start);
		s2 = l1.substr(s2_start + 1, s2_end - s2_start - 1);
		s3 = l1.substr(s2_end + 1, s4_start - s2_end - 1);
		s4 = l1.substr(s4_start + 1, s4_end - s4_start - 1);
		s5 = l1.substr(s4_end + 1, l1.size() - s4_end);
		cout << (s1 + s2 + s3 + s4 + s5) << endl;
		l2 = l2.substr(0, l2.find("..."));
		l2 += (s4 + s3 + s2 + s5);
		cout << l2 << endl;
	}
	return 0;
}