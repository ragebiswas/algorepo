#include <iostream>
using namespace std;

int main()
{
    int nc;
    string s;
    cin >> nc;
    while (nc--) {
    	cin >> s;
        char last = '-';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != last) {
                cout << s[i];
                last = s[i];
            }
        }
        cout << endl;
    }
    return 0;
}

