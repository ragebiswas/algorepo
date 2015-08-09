#include <iostream>
using namespace std;

double pow(double x, int y) 
{
    if (y == 0) return 1;
    if (y & 01) {
        return x * pow(x, y - 1);
    }
    else {
        double d = pow(x, y >> 1);
        return d * d;
    }
}

int main()
{
    double x;
    int y;
    cout << "x: "; 
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << pow(x, y);
    return 0;
}
