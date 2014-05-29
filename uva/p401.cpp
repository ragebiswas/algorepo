// Palindromes (Level 1)
#include <iostream>
#include <string>
using namespace std;

bool mirrorchar(char a, char b) 
{
	string charmirrors = "AHIMOTUVWXY18";
	if(a == b && charmirrors.find(a) != string::npos) {
		return true;
	}
	if (a > b) {
		swap(a, b);
	}

	charmirrors = "3EJL2S5Z";
	for(int i = 0; i < charmirrors.size() - 1; i += 2) {
		if (charmirrors[i] == a && charmirrors[i + 1] == b) {
			return true;
		}
	}

	return false;
}

bool mirror(const string& s)
{
	int len = s.size();
	for(int i = 0; i < (len / 2) + 1; i++) {
		if(!mirrorchar(s[i], s[len - i - 1])) {
			return false;
		}
	}
	return true;

}

bool pal(const string& s)
{
	int len = s.size();
	for(int i = 0; i < len / 2; i++) {
		if(s[i] != s[len - i - 1]) {
			return false;
		}
	}
	return true;	
}


int main()
{	
	string s;
	while (cin >> s) {
		if (mirror(s) && pal(s)) {
			cout << s << " -- is a mirrored palindrome.\n\n";
		}
		else if(mirror(s) && !pal(s)) {
			cout << s << " -- is a mirrored string.\n\n";
		}
		else if(pal(s) && !mirror(s)) {
			cout << s << " -- is a regular palindrome.\n\n";
		}
		else {
			cout << s << " -- is not a palindrome.\n\n";
		}
	}
	return 0;
}