#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 10) {
        cout << 1 << endl;
        cout << n % 10 << endl;
    }
    else {
        cout << 2 << endl;
    }
    return 0;
}

