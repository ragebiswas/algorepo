#include <iostream>
#include <map>
using namespace std;
const int64_t MAX = 1E9;

int main()
{
    int64_t num;
    map<int64_t, bool> hexnums;
    for (int n = 0; n < 1E5; n++) {
        int64_t tmp = 3 * n * (n + 1) + 1;
        if (tmp > MAX) {
            break;
        }
        hexnums[tmp] = true;
    }
    while (1) {
        cin >> num;
        if (num == -1) {
            break;
        }
        if (hexnums.find(num) != hexnums.end()) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }
    }
    return 0;
}
