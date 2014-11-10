#include <iostream>
#include <string>
using namespace std;

bool ispalin(const string& str, int start, int end, bool discard)
{
    bool ispal = true;
    while (start < end) {
        if (str[start] != str[end]) {
            if (discard == false) {
                return false;
            }
            else {
                return ispalin(str, start + 1, end, false) || ispalin(str, start, end - 1, false);
            }
        }
        start++;
        end--;
    }
    return ispal;
}

int main()
{
    int nc;
    string str;
    cin >> nc;
    while (nc--) {
        cin >> str;
        if (ispalin(str, 0, str.size() - 1, true)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
